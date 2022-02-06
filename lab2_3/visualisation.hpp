#pragma once

#include "Hist.hpp"
#include "sequence/sequence.hpp"
#include <cstdlib>
#include <chrono>
#include "fstream"
#include "CreateArray.hpp"
#include "sequence/ArraySequence.hpp"



float division_by_group_help(Sequence<int>* c){
    int parts = 5;
    auto start_time = chrono::steady_clock::now();
    hist<HelpArray<int>, int> r(parts, c);
    auto end_time = chrono::steady_clock::now();
    float time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    return time;
}

float count_all_elements_help(Sequence<int>* c){
    int parts = 5;
    auto start_time = chrono::steady_clock::now();
    hist<HelpArray<int>, int> r(c);
    auto end_time = chrono::steady_clock::now();
    float time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    return time;
}
float count_all_elements_in_group_help(Sequence<int>* c){
    int first = (*c)[1];
    int last = (*c)[c->GetSize() - 1];
    auto start_time = chrono::steady_clock::now();
    hist<HelpArray<int>, int> r(c, first, last, true);
    auto end_time = chrono::steady_clock::now();
    float time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    return time;
}
float count_every_elements_in_group_help(Sequence<int>* c){
    int first = (*c)[1];
    int last = (*c)[c->GetSize() - 1];
    auto start_time = chrono::steady_clock::now();
    hist<HelpArray<int>, int> r(c, first, last, false);
    auto end_time = chrono::steady_clock::now();
    float time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    return time;
}



// Запись в файлы
void division_by_group_hist_files(){
    float time;
    ofstream fout;
    fout.open("Division_by_parts.csv");
    fout<<"division_by_parts"<<"\n";
    for(int i = 10; i < 100; i+=10){
        int* arr = MakeRandomArray<int>(i);
        ArraySequence<int> c = ArraySequence<int>(arr, i);
        Sequence<int>* pointer = &c;
        time = division_by_group_help(pointer);
        fout<<time<<"\n";
    }
    fout.close();
}

void count_all_elements_hist_files(){
    float time;
    ofstream fout;
    fout.open("Count_all_elements.csv");
    fout<<"count_all_elements"<<"\n";
    for(int i = 10; i < 100; i+=10){
        int* arr = MakeRandomArray<int>(i);
        ArraySequence<int> c = ArraySequence<int>(arr, i);
        Sequence<int>* pointer = &c;
        time = count_all_elements_help(pointer);
        fout<<time<<"\n";
    }
    fout.close();
}
void count_all_elements_in_group_files(){
    float time;
    ofstream fout;
    fout.open("Count_all_elements_in_group.csv");
    fout<<"count_all_elements_in_group"<<"\n";
    for(int i = 10; i < 100; i+=10){
        int* arr = MakeRandomArray<int>(i);
        ArraySequence<int> c = ArraySequence<int>(arr, i);
        Sequence<int>* pointer = &c;
        time = count_all_elements_in_group_help(pointer);
        fout<<time<<"\n";
    }
    fout.close();
}

void count_every_elements_in_group_files(){
    float time;
    ofstream fout;
    fout.open("Count_every_elements_in_group.csv");
    fout<<"count_every_elements_in_group"<<"\n";
    for(int i = 10; i < 100; i+=10){
        int* arr = MakeRandomArray<int>(i);
        ArraySequence<int> c = ArraySequence<int>(arr, i);
        Sequence<int>* pointer = &c;
        time = count_every_elements_in_group_help(pointer);
        fout<<time<<"\n";
    }
    fout.close();
}



void files(){
    division_by_group_hist_files();
    count_all_elements_hist_files();
    count_all_elements_in_group_files();
    count_every_elements_in_group_files();
}