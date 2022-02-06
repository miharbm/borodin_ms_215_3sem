#pragma once
#include "../Hist.hpp"
#include "../sequence/ArraySequence.hpp"
#include "../HelpArray.hpp"
#include "../sequence/ListSequence.hpp"
void ready_hist_int_array_test(){
    cout<<"Test for int array hist"<<"\n";
    int a[10] = {5, 3, 13, 14, 87, 1, 10, 34, 92, 92};
    ArraySequence<int> c = ArraySequence<int>(a, 10);
    cout<<"Tested Sequence: "<<"\n";
    c.Print();
    Sequence<int>* pointer = &c;
    hist<HelpArray<int>, int> parts = hist<HelpArray<int>, int>(2, pointer);
    cout<<"Hist division into parts:"<<"\n";
    parts.print();
    cout<<"\n";
    hist<HelpArray<int>, int> counter = hist<HelpArray<int>, int>(pointer);
    cout<<"Count elements:"<<"\n";
    counter.print();
    cout<<"\n";
    cout<<"Count elements in group:"<<"\n";
    hist<HelpArray<int>, int> alphatrue = hist<HelpArray<int>, int>(pointer, 14, 87, true);
    alphatrue.print();
    cout<<"\n";
    hist<HelpArray<int>, int> alphafalse = hist<HelpArray<int>, int>(pointer, 14, 87, false);
    cout<<"Count every element in group:"<<"\n";
    alphafalse.print();
}

void ready_hist_int_list_test(){
    cout<<"Test for int list hist"<<"\n";
    int a[10] = {5, 3, 13, 14, 87, 1, 10, 34, 92, 92};
    ListSequence<int> c = ListSequence<int>(a, 10);
    cout<<"Tested Sequence: "<<"\n";
    c.Print();
    Sequence<int>* pointer = &c;
    hist<HelpArray<int>, int> parts = hist<HelpArray<int>, int>(2, pointer);
    cout<<"Hist division into parts:"<<"\n";
    parts.print();
    cout<<"\n";
    hist<HelpArray<int>, int> counter = hist<HelpArray<int>, int>(pointer);
    cout<<"Count elements:"<<"\n";
    counter.print();
    cout<<"\n";
    cout<<"Count elements in group:"<<"\n";
    hist<HelpArray<int>, int> alphatrue = hist<HelpArray<int>, int>(pointer, 14, 87, true);
    alphatrue.print();
    cout<<"\n";
    hist<HelpArray<int>, int> alphafalse = hist<HelpArray<int>, int>(pointer, 14, 87, false);
    cout<<"Count every element in group:"<<"\n";
    alphafalse.print();
}