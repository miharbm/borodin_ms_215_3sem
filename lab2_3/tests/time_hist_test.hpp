#pragma once

#include "../Hist.hpp"
#include<cstdlib>
#include <cassert>
#include <chrono>
#include "../CreateArray.hpp"
#include "../sequence/ArraySequence.hpp"
#include "../HelpArray.hpp"


struct time_for_hist{
    float parts_time;
    float count_time;
    float count_all_in_group;
    float count_every_in_group;
};
 time_for_hist time_test_for_int_array(int dimension){
     cout<<"Time test hist for array"<<"\n";
    int* a = MakeRandomArray<int>(dimension);
    ArraySequence<int> c = ArraySequence<int>(a, dimension);
    ArraySequence<int> b(a, dimension);
    ArraySequence<int> q(a, dimension);
    ArraySequence<int> z(a, dimension);
    Sequence<int>* pc = &c;
    Sequence<int>* pb = &b;
    Sequence<int>* pq = &q;
    Sequence<int>* pz = &z;
    time_for_hist time;
    auto start_time = chrono::steady_clock::now();
    hist<HelpArray<int>, int> hc(10, pc);
    auto end_time = chrono::steady_clock::now();
    time.parts_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();


     start_time = chrono::steady_clock::now();
     hist<HelpArray<int>, int> hb(pb);
     end_time = chrono::steady_clock::now();
     time.count_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();


     start_time = chrono::steady_clock::now();
     hist<HelpArray<int>, int> hq(pq, a[1], a[dimension - 2], true);
     end_time = chrono::steady_clock::now();
     time.count_all_in_group = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();


     start_time = chrono::steady_clock::now();
     hist<HelpArray<int>, int> hz(pz, a[1], a[dimension - 2], false);
     end_time = chrono::steady_clock::now();
     time.count_every_in_group = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    return time;
 }

time_for_hist time_test_for_int_list(int dimension){
     cout<<"Time test hist for list"<<"\n";
    int* a = MakeRandomArray<int>(dimension);
    ListSequence<int> c = ListSequence<int>(a, dimension);
    ListSequence<int> b(a, dimension);
    ListSequence<int> q(a, dimension);
    ListSequence<int> z(a, dimension);
    Sequence<int>* pc = &c;
    Sequence<int>* pb = &b;
    Sequence<int>* pq = &q;
    Sequence<int>* pz = &z;
    time_for_hist time;
    auto start_time = chrono::steady_clock::now();
    hist<HelpArray<int>, int> hc(10, pc);
    auto end_time = chrono::steady_clock::now();
    time.parts_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();


    start_time = chrono::steady_clock::now();
    hist<HelpArray<int>, int> hb(pb);
    end_time = chrono::steady_clock::now();
    time.count_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();


    start_time = chrono::steady_clock::now();
    hist<HelpArray<int>, int> hq(pq, a[1], a[dimension - 2], true);
    end_time = chrono::steady_clock::now();
    time.count_all_in_group = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();


    start_time = chrono::steady_clock::now();
    hist<HelpArray<int>, int> hz(pz, a[1], a[dimension - 2], false);
    end_time = chrono::steady_clock::now();
    time.count_every_in_group = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    return time;
}
void print_result_time_for_hist(time_for_hist time){
    cout<<"Division into parts time: "<<time.parts_time<<" microseconds"<<"\n";
    cout<<"Count all elements time: "<<time.count_time<<" microseconds"<<"\n";
    cout<<"Count all elements in group time: "<<time.count_all_in_group<<" microseconds"<<"\n";
    cout<<"Count every elements in group time: "<<time.count_every_in_group<<" microseconds"<<"\n";
 }