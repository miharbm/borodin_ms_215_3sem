#pragma once

#include <iostream>
#include "isorter.h"
#include "sequence.h"
#include "arraysequence.h"
#include "arraysequence.cpp"

template<class T>
void BubbleSort<T>::Sort(Sequence<T> *seq, int (*cmp)(T, T))  {
    for (int i = 0; i < seq->GetLength(); i++)
        for (int j = i + 1; j < seq->GetLength(); j++)
            if (cmp((*seq)[j], (*seq)[i]) < 0) seq->Swap((*seq)[i], (*seq)[j]);
}

template<class T>
void ShakerSort<T>::Sort(Sequence<T> *seq, int (*cmp)(T, T))  {
    int leftMark = 1;
    int rightMark = seq->GetLength() - 1;
    while (leftMark <= rightMark) {
        for (int i = rightMark; i >= leftMark; i--)
            if (cmp((*seq)[i], (*seq)[i - 1]) < 0) seq->Swap((*seq)[i - 1], (*seq)[i]);
        leftMark++;
        for (int i = leftMark; i <= rightMark; i++)
            if (cmp((*seq)[i], (*seq)[i - 1]) < 0) seq->Swap((*seq)[i - 1], (*seq)[i]);
        rightMark--;
    }
}

template<typename T>
void HeapSort<T>::Sort(Sequence<T> *seq, int (*cmp)(T, T)) {
    for (int i = seq->GetLength() / 2 - 1; i >= 0; i--)
        heapify(seq, seq->GetLength(), i, cmp);
    for (int i= seq->GetLength() - 1; i >= 0; i--) {
        seq->Swap((*seq)[0], (*seq)[i]);
        heapify(seq, i, 0, cmp);
    }
}

template<typename T>
void HeapSort<T>::heapify(Sequence<T> *seq, int n, int i, int (*cmp)(T, T)) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < n && cmp((*seq)[largest], (*seq)[left]) < 0)
        largest = left;
    if (right < n && cmp((*seq)[largest], (*seq)[right]) < 0)
        largest = right;
    if (largest != i) {
        seq->Swap((*seq)[largest], (*seq)[i]);
        heapify(seq, n, largest, cmp);
    }
}

template<typename T>
void QuickSort<T>::Sort(Sequence<T> *seq, int (*cmp)(T, T)) {
    qsort(seq, 0, seq->GetLength(), cmp);
}


template<typename T>
void MergeSort<T>::Sort(Sequence<T> *seq, int (*cmp)(T, T)) {
    mergeSort(seq, 0, seq->GetLength() - 1, cmp);
}


template<typename T>
void MergeSort<T>::mergeSort(Sequence<T> *seq, int left, int right, int (*cmp)(T, T)) {
    int split_index;
    if (left < right) {
        split_index = (left + right) / 2;
        mergeSort(seq, left, split_index, cmp);
        mergeSort(seq, split_index + 1, right, cmp);
        merge(seq, left, split_index, right, cmp);
    }
}

template<typename T>
void MergeSort<T>::merge(Sequence<T> *seq, int left, int split_index, int right, int (*cmp)(T, T)) {
    int position_first_seq = left;
    int position_second_seq = split_index + 1;
    Sequence<T> *tmp = (Sequence<T> *) new ArraySequence<T>;

    while (position_first_seq <= split_index && position_second_seq <= right) {
        if (cmp((*seq)[position_first_seq], (*seq)[position_second_seq]) < 0)
            tmp->Append((*seq)[position_first_seq++]);
        else
            tmp->Append((*seq)[position_second_seq++]);
    }

    while (position_second_seq <= right)
        tmp->Append((*seq)[position_second_seq++]);
    while (position_first_seq <= split_index)
        tmp->Append((*seq)[position_first_seq++]);

    for (int i = 0; i < tmp->GetLength(); i++)
        (*seq)[left + i] = (*tmp)[i];
}

template<typename T>
void QuickSort<T>::qsort(Sequence<T> *seq, int left, int right, int (*cmp)(T, T)) {
    if (right - left <= 1) return;
    int mid = (*seq)[left + std::rand() % (right - left)];
    int x = left, y = left;
    for (int i = left; i < right; ++i) {
        if (cmp((*seq)[i], mid) < 0) {
            seq->Swap((*seq)[x], (*seq)[i]);
            if (x != y) {
                seq->Swap((*seq)[y], (*seq)[i]);
            }
            ++x;
            ++y;
        }
        else {
            if (cmp((*seq)[i], mid) == 0) {
                seq->Swap((*seq)[y], (*seq)[i]);
                ++y;
            }
        }
    }
    qsort(seq, left, x, cmp);
    qsort(seq, y, right, cmp);
}
