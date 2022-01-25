#ifndef ISORTER_H
#define ISORTER_H

#pragma once

#include "sequence.h"

// Интерфейс для алгоритмов сортировки
template <class T>
class ISorter {
public:
    virtual void Sort(Sequence<T> *seq, int (*cmp)(T, T)) = 0;
};

// 1. Пузырьковая сортировка - 3
template <typename T>
class BubbleSort : public ISorter<T> {
public:
    void Sort(Sequence<T> *seq, int (*cmp)(T, T));
};


// 2. Шейкерная сортировка - 5
template <typename T>
class ShakerSort : public ISorter<T> {
public:
    void Sort(Sequence<T> *seq, int (*cmp)(T, T));
};

// 9. Сортировка слиянием - 7
template <typename T>
class MergeSort : public ISorter<T> {
public:
    void Sort(Sequence<T> *seq, int (*cmp)(T, T));
    void mergeSort(Sequence<T> *seq, int left, int right, int (*cmp)(T, T));
    void merge(Sequence<T> *seq, int left, int split_index, int right, int (*cmp)(T, T));
};

// 10. Пирамидальная сортировка - 10
template <typename T>
class HeapSort : public ISorter<T> {
public:
    void heapify(Sequence<T> *seq, int n, int i, int (*cmp)(T, T));
    void Sort(Sequence<T> *seq, int (*cmp)(T, T));
};

// 11. Быстрая сортировка - 10
template <typename T>
class QuickSort : public ISorter<T> {
public:
    void Sort(Sequence<T> *seq, int (*cmp)(T, T));
    void qsort(Sequence<T> *seq, int left, int right, int (*cmp)(T, T));
};

#endif // ISORTER_H
