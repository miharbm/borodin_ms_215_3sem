//
// Created by micha on 25.01.2022.
//
#ifndef GRAPH
#define GRAPH
#pragma once

#include <iostream>
#include "sequence.h"
#include "listsequence.h"
#include "listsequence.cpp"
#include "arraysequence.h"
#include "arraysequence.cpp"
#include "isorter.h"
#include "isorter.cpp"
#include <fstream>
#include "extrafunctions.h"

void testListRandBubleSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 3000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ListSequence<int>;
        if (i > 1000) i += 100;
        generateRand(seq, i, 1000);
        writeBubbleSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testListSortedBubleSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 3000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ListSequence<int>;
        if (i > 1000) i += 100;
        generateSorted(seq, i);
        writeBubbleSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testListReversedBubleSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 3000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ListSequence<int>;
        if (i > 1000) i += 100;
        generateReversed(seq, i);
        writeBubbleSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testListRandShakerSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 3000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ListSequence<int>;
        if (i > 1000) i += 100;
        generateRand(seq, i, 1000);
        writeShakerSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testListSortedShakerSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 3000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ListSequence<int>;
        if (i > 1000) i += 100;
        generateSorted(seq, i);
        writeShakerSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testListReversedShakerSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 3000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ListSequence<int>;
        if (i > 1000) i += 100;
        generateReversed(seq, i);
        writeShakerSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testListRandMergeSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 10000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ListSequence<int>;
        if (i > 1000) i += 100;
        if (i > 3000) i += 300;
        generateRand(seq, i, 1000);
        writeMergeSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testListSortedMergeSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 10000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ListSequence<int>;
        if (i > 1000) i += 100;
        if (i > 3000) i += 300;
        generateSorted(seq, i);
        writeMergeSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testListReversedMergeSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 10000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ListSequence<int>;
        if (i > 1000) i += 100;
        if (i > 3000) i += 300;
        generateReversed(seq, i);
        writeMergeSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testListRandHeapSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 10000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ListSequence<int>;
        if (i > 1000) i += 100;
        if (i > 3000) i += 300;
        generateRand(seq, i, 1000);
        writeHeapSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testListSortedHeapSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 10000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ListSequence<int>;
        if (i > 1000) i += 100;
        if (i > 3000) i += 300;
        generateSorted(seq, i);
        writeHeapSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testListReversedHeapSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 10000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ListSequence<int>;
        if (i > 1000) i += 100;
        if (i > 3000) i += 300;
        generateReversed(seq, i);
        writeHeapSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testListRandQuickSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 10000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ListSequence<int>;
        if (i > 1000) i += 100;
        if (i > 3000) i += 300;
        generateRand(seq, i, 1000);
        writeQuickSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testListSortedQuickSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 10000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ListSequence<int>;
        if (i > 1000) i += 100;
        if (i > 3000) i += 300;
        generateSorted(seq, i);
        writeQuickSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testListReversedQuickSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 10000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ListSequence<int>;
        if (i > 1000) i += 100;
        if (i > 3000) i += 300;
        generateReversed(seq, i);
        writeQuickSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testArrayRandBubleSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 3000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ArraySequence<int>;
        if (i > 1000) i += 100;
        generateRand(seq, i, 1000);
        writeBubbleSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testArraySortedBubleSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 3000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ArraySequence<int>;
        if (i > 1000) i += 100;
        generateSorted(seq, i);
        writeBubbleSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testArrayReversedBubleSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 3000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ArraySequence<int>;
        if (i > 1000) i += 100;
        generateReversed(seq, i);
        writeBubbleSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testArrayRandShakerSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 3000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ArraySequence<int>;
        if (i > 1000) i += 100;
        generateRand(seq, i, 1000);
        writeShakerSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testArraySortedShakerSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 3000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ArraySequence<int>;
        if (i > 1000) i += 100;
        generateSorted(seq, i);
        writeShakerSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testArrayReversedShakerSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 3000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ArraySequence<int>;
        if (i > 1000) i += 100;
        generateReversed(seq, i);
        writeShakerSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testArrayRandMergeSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 10000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ArraySequence<int>;
        if (i > 1000) i += 100;
        if (i > 3000) i += 300;
        generateRand(seq, i, 1000);
        writeMergeSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testArraySortedMergeSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 10000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ArraySequence<int>;
        if (i > 1000) i += 100;
        if (i > 3000) i += 300;
        generateSorted(seq, i);
        writeMergeSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testArrayReversedMergeSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 10000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ArraySequence<int>;
        if (i > 1000) i += 100;
        if (i > 3000) i += 300;
        generateReversed(seq, i);
        writeMergeSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testArrayRandHeapSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 10000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ArraySequence<int>;
        if (i > 1000) i += 100;
        if (i > 3000) i += 300;
        generateRand(seq, i, 1000);
        writeHeapSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testArraySortedHeapSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 10000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ArraySequence<int>;
        if (i > 1000) i += 100;
        if (i > 3000) i += 300;
        generateSorted(seq, i);
        writeHeapSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testArrayReversedHeapSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 10000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ArraySequence<int>;
        if (i > 1000) i += 100;
        if (i > 3000) i += 300;
        generateReversed(seq, i);
        writeHeapSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testArrayRandQuickSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 10000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ArraySequence<int>;
        if (i > 1000) i += 100;
        if (i > 3000) i += 300;
        generateRand(seq, i, 1000);
        writeQuickSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testArraySortedQuickSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 10000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ArraySequence<int>;
        if (i > 1000) i += 100;
        if (i > 3000) i += 300;
        generateSorted(seq, i);
        writeQuickSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

void testArrayReversedQuickSort() {
    std::ofstream out;
    out.open("time.txt");
    out.close();
    for (int i = 0; i <= 10000; i += 100) {
        Sequence<int> *seq = (Sequence<int> *) new ArraySequence<int>;
        if (i > 1000) i += 100;
        if (i > 3000) i += 300;
        generateReversed(seq, i);
        writeQuickSortInFile(seq, cmp, true);
        seq->~Sequence();
    }
}

#endif