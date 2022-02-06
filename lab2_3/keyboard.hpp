#pragma once
#include "Hist.hpp"

#include "sequence/ArraySequence.hpp"
template<typename T>
hist<HelpArray<T>, T> keyboard_hist_parts_array(){
    cout<<"Input dimension:"<<"\n";
    int dimension;
    cin>>dimension;

    cout<<"Input parts amount:"<<"\n";
    int parts;
    cin>>parts;
    T* space = new T[dimension];
    Sequence<T>* pointer;
    cout<<"Input elements: "<<"\n";
    for(int i = 0; i < dimension; i++){
        T el;
        cin>>el;
        space[i] = el;
    }
    ArraySequence<T> arr = ArraySequence<T>(space, dimension);
    pointer = &arr;
    hist<HelpArray<T>, T> alpha = hist<HelpArray<T>, T>(parts, pointer);
    return alpha;
}
template<typename T>
hist<HelpArray<T>, T> keyboard_hist_count_elements_array(){
    cout<<"Input dimension:"<<"\n";
    int dimension;
    cin>>dimension;
    T* space = new T[dimension];
    cout<<"Input elements"<<"\n";
    for(int i = 0; i < dimension; i++){
        T el;
        cin>>el;
        space[i] = el;
    }
    ArraySequence<T> arr = ArraySequence<T>(space, dimension);
    Sequence<T> *pointer = &arr;
    hist<HelpArray<T>, T> alpha = hist<HelpArray<T>, T>(pointer);
    return alpha;
}
template<typename T>
hist<HelpArray<T>, T> hist_count_all_elements_in_group_keyboard_array(){
    cout<<"Input dimension:"<<"\n";
    int dimension;
    cin>>dimension;
    T* space = new T[dimension];
    Sequence<T> *pointer;
    cout<<"Input elements:"<<"\n";
    for(int i = 0; i < dimension; i++){
        T el;
        cin>>el;
        space[i] = el;
    }
    ArraySequence<T> arr = ArraySequence<T>(space, dimension);
    pointer = &arr;
    cout<<"Input ranges: "<<"\n";
    cout<<"First range: ";
    T first_range;
    cin>>first_range;
    cout<<"Second range: ";
    T second_range;
    cin>>second_range;
    hist<HelpArray<T>, T> alpha = hist<HelpArray<T>, T>(pointer, first_range, second_range, true);
    return alpha;
}

template<typename T>
hist<HelpArray<T>, T> hist_count_every_elements_in_group_keyboard_array(){
    cout<<"Input dimension:"<<"\n";
    int dimension;
    cin>>dimension;
    T* space = new T[dimension];
    Sequence<T> *pointer;
    cout<<"Input elements:"<<"\n";
    for(int i = 0; i < dimension; i++){
        T el;
        cin>>el;
        space[i] = el;
    }
    ArraySequence<T> arr = ArraySequence<T>(space, dimension);
    pointer = &arr;
    cout<<"Input ranges: "<<"\n";
    cout<<"First range: ";
    T first_range;
    cin>>first_range;
    cout<<"Second range: ";
    T second_range;
    cin>>second_range;
    hist<HelpArray<T>, T> alpha = hist<HelpArray<T>, T>(pointer, first_range, second_range, false);
    return alpha;
}

template<typename T>
hist<HelpArray<T>, T> keyboard_hist_parts_list(){
    cout<<"Input dimension:"<<"\n";
    int dimension;
    cin>>dimension;

    cout<<"Input parts amount:"<<"\n";
    int parts;
    cin>>parts;
    T* space = new T[dimension];
    Sequence<T>* pointer;
    cout<<"Input elements: "<<"\n";
    for(int i = 0; i < dimension; i++){
        T el;
        cin>>el;
        space[i] = el;
    }
    ListSequence<T> arr = ListSequence<T>(space, dimension);
    pointer = &arr;
    hist<HelpArray<T>, T> alpha = hist<HelpArray<T>, T>(parts, pointer);
    return alpha;
}
template<typename T>
hist<HelpArray<T>, T> keyboard_hist_count_elements_list(){
    cout<<"Input dimension:"<<"\n";
    int dimension;
    cin>>dimension;
    T* space = new T[dimension];
    cout<<"Input elements"<<"\n";
    for(int i = 0; i < dimension; i++){
        T el;
        cin>>el;
        space[i] = el;
    }
    ListSequence<T> arr = ListSequence<T>(space, dimension);
    Sequence<T> *pointer = &arr;
    hist<HelpArray<T>, T> alpha = hist<HelpArray<T>, T>(pointer);
    return alpha;
}
template<typename T>
hist<HelpArray<T>, T> hist_count_all_elements_in_group_keyboard_list(){
    cout<<"Input dimension:"<<"\n";
    int dimension;
    cin>>dimension;
    T* space = new T[dimension];
    Sequence<T> *pointer;
    cout<<"Input elements:"<<"\n";
    for(int i = 0; i < dimension; i++){
        T el;
        cin>>el;
        space[i] = el;
    }
    ListSequence<T> arr = ListSequence<T>(space, dimension);
    pointer = &arr;
    cout<<"Input ranges: "<<"\n";
    cout<<"First range: ";
    T first_range;
    cin>>first_range;
    cout<<"Second range: ";
    T second_range;
    cin>>second_range;
    hist<HelpArray<T>, T> alpha = hist<HelpArray<T>, T>(pointer, first_range, second_range, true);
    return alpha;
}

template<typename T>
hist<HelpArray<T>, T> hist_count_every_elements_in_group_keyboard_list(){
    cout<<"Input dimension:"<<"\n";
    int dimension;
    cin>>dimension;
    T* space = new T[dimension];
    Sequence<T> *pointer;
    cout<<"Input elements:"<<"\n";
    for(int i = 0; i < dimension; i++){
        T el;
        cin>>el;
        space[i] = el;
    }
    ListSequence<T> arr = ListSequence<T>(space, dimension);
    pointer = &arr;
    cout<<"Input ranges: "<<"\n";
    cout<<"First range: ";
    T first_range;
    cin>>first_range;
    cout<<"Second range: ";
    T second_range;
    cin>>second_range;
    hist<HelpArray<T>, T> alpha = hist<HelpArray<T>, T>(pointer, first_range, second_range, false);
    return alpha;
}