#ifndef EXTRAFUNCTIONS_H
#define EXTRAFUNCTIONS_H

#pragma once

#include <iostream>
#include <fstream>
#include "sequence.h"
#include <chrono>
#include "isorter.h"
#include "isorter.cpp"

int cmp(int a, int b) {
    return (a < b) ? -1 : (a == b) ? 0 : 1;
}

template <class T>
void writeBubbleSortInFile(Sequence<T> *seq, int (*cmp)(T, T), bool add = false) {
    std::ofstream out;
    out.open("array.txt");
    if (out.is_open()) {
        for (int i = 0; i < seq->GetLength(); ++i)
            out << (*seq)[i] << " ";
    }
    out.close();

    BubbleSort<int> Sorter;
    auto timeStamp_1 = std::chrono::high_resolution_clock::now();
    Sorter.Sort(seq, cmp);
    auto timeStamp_2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(timeStamp_2 - timeStamp_1).count();
    add ? out.open("time.txt", std::ios::app) : out.open("time.txt");
    if (out.is_open()) {
        out << duration << std::endl;
    }
    out.close();

    out.open("sorted.txt");
    if (out.is_open()) {
        for (int i = 0; i < seq->GetLength(); ++i)
            out << (*seq)[i] << " ";
    }
    out.close();
}

template <class T>
void writeShakerSortInFile(Sequence<T> *seq, int (*cmp)(T, T), bool add = false) {
    std::ofstream out;
    out.open("array.txt");
    if (out.is_open()) {
        for (int i = 0; i < seq->GetLength(); ++i)
            out << (*seq)[i] << " ";
    }
    out.close();

    ShakerSort<int> Sorter;
    auto timeStamp_1 = std::chrono::high_resolution_clock::now();
    Sorter.Sort(seq, cmp);
    auto timeStamp_2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(timeStamp_2 - timeStamp_1).count();
    add ? out.open("time.txt", std::ios::app) : out.open("time.txt");
    if (out.is_open()) {
        out << duration << std::endl;
    }
    out.close();

    out.open("sorted.txt");
    if (out.is_open()) {
        for (int i = 0; i < seq->GetLength(); ++i)
            out << (*seq)[i] << " ";
    }
    out.close();
}

template <class T>
void writeMergeSortInFile(Sequence<T> *seq, int (*cmp)(T, T), bool add = false) {
    std::ofstream out;
    out.open("array.txt");
    if (out.is_open()) {
        for (int i = 0; i < seq->GetLength(); ++i)
            out << (*seq)[i] << " ";
    }
    out.close();

    MergeSort<int> Sorter;
    auto timeStamp_1 = std::chrono::high_resolution_clock::now();
    Sorter.Sort(seq, cmp);
    auto timeStamp_2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(timeStamp_2 - timeStamp_1).count();
    add ? out.open("time.txt", std::ios::app) : out.open("time.txt");
    if (out.is_open()) {
        out << duration << std::endl;
    }
    out.close();

    out.open("sorted.txt");
    if (out.is_open()) {
        for (int i = 0; i < seq->GetLength(); ++i)
            out << (*seq)[i] << " ";
    }
    out.close();
}

template <class T>
void writeHeapSortInFile(Sequence<T> *seq, int (*cmp)(T, T), bool add = false) {
    std::ofstream out;
    out.open("array.txt");
    if (out.is_open()) {
        for (int i = 0; i < seq->GetLength(); ++i)
            out << (*seq)[i] << " ";
    }
    out.close();

    HeapSort<int> Sorter;
    auto timeStamp_1 = std::chrono::high_resolution_clock::now();
    Sorter.Sort(seq, cmp);
    auto timeStamp_2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(timeStamp_2 - timeStamp_1).count();
    add ? out.open("time.txt", std::ios::app) : out.open("time.txt");
    if (out.is_open()) {
        out << duration << std::endl;
    }
    out.close();

    out.open("sorted.txt");
    if (out.is_open()) {
        for (int i = 0; i < seq->GetLength(); ++i)
            out << (*seq)[i] << " ";
    }
    out.close();
}

template <class T>
void writeQuickSortInFile(Sequence<T> *seq, int (*cmp)(T, T), bool add = false) {
    std::ofstream out;
    out.open("array.txt");
    if (out.is_open()) {
        for (int i = 0; i < seq->GetLength(); ++i)
            out << (*seq)[i] << " ";
    }
    out.close();

    QuickSort<int> Sorter;
    auto timeStamp_1 = std::chrono::high_resolution_clock::now();
    Sorter.Sort(seq, cmp);
    auto timeStamp_2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(timeStamp_2 - timeStamp_1).count();
    add ? out.open("time.txt", std::ios::app) : out.open("time.txt");
    if (out.is_open()) {
        out << duration << std::endl;
    }
    out.close();

    out.open("sorted.txt");
    if (out.is_open()) {
        for (int i = 0; i < seq->GetLength(); ++i)
            out << (*seq)[i] << " ";
    }
    out.close();
}

template <class T>
void generateRand(Sequence<T> *seq, int n, int maxValue = 100) {
    srand(time(NULL));
    for (int i = 0; i < n; ++i)
        seq->Append(std::rand() % maxValue);
}

template <class T>
void generateReversed(Sequence<T> *seq, int n) {
    for (int i = 0; i < n; ++i)
        seq->Append(n - i - 1);
}

template <class T>
void generateSorted(Sequence<T> *seq, int n) {
    for (int i = 0; i < n; ++i)
        seq->Append(i);
}

#endif // EXTRAFUNCTIONS_H
