#pragma once

#include "sequence/sequence.hpp"
#include "Dict/Dict.hpp"
#include "sort.hpp"
#include "iostream"
using namespace std;

template <typename T1, typename T2>
class hist{
private:
    dict<T1, T2> data; //dfafafafadf
public:
    hist(int parts, Sequence<T2>* c){
        QuickSort(c, 0, c->GetSize() -  1);
        int count = 0;
        int other_dim = c->GetSize() / parts;
        int last_dim = c->GetSize() % parts;
        auto big = new T1[parts];                 //auto big = new HelpArray<T2>[parts];
        T1 amount;                                //T1 amount = HelpArray<T2>();
        int ch;
        int alpha;
        for(int i = 0; i < parts; i++){
            T1 med;                               //T1 med = HelpArray<T2>();
            if(count < c->GetSize() - last_dim - other_dim) {
                ch = 0;
                for (int k = count; k < count + other_dim; k++) {
                    int el = (*c)[k];
                    if(k == count || el != (*c)[k-1]) {
                        med.append(el);
                    }
                    ch+=1;
                }
                alpha = count;
                count += other_dim;
            }
            else{
                ch=0;
                for (int k = count; k < count + other_dim + last_dim; k++) {
                    int el = (*c)[k];
                    if(k == count || el != (*c)[k-1]) {
                        med.append(el);
                    }
                    ch+=1;
                }
            }
            big[i] = med;
            amount.append(ch);
        }
        int l = amount.GetDim();
        int size = c->GetSize();
        data = dict<T1, T2>(parts, big,amount); //fal;fja;f;lafma;lfjm adlvfla
    }
    explicit hist(Sequence<T2>* c){
        QuickSort(c, 0, c->GetSize() - 1);
        int count; // количество одинаковых элементов(например, число троек в массиве)
        int repeat = 0; // количество повторяющихся элементов
        int prev = 1;
        T1 amount;                   //T1 amount = HelpArray<T2>();
        T1 values;                  //T1 values = HelpArray<T2>();
        for(int i = 0; i < c->GetSize(); i+=prev){
            count = 1;
            for(int j = i+1; j < c->GetSize(); j++){
                if((*c)[i] == (*c)[j] /*&& (i == 0 || (*c)[i] != (*c)[i-1])*/){
                    count+=1;
                }
                prev = count;
            }
            values.append((*c)[i]);
            if(count > 1){
                repeat+=1;

            }
            amount.append(count);
        }
        auto big = new HelpArray<T2>[c->GetSize() - repeat + 1];
        for(int i = 0;  i < c->GetSize() - repeat + 1; i++){
            big[i] = T1(values[i]);                   //big[i] = HelpArray<T2>(values[i]);
        }
        data = dict<T1, T2>(amount.GetDim(), big, amount);
    }
    hist(Sequence<T2>* c, T2 first, T2 second, bool alpha){ // alpha == true считаем элементы из группы
        QuickSort(c, 0, c->GetSize() - 1);
        if(alpha){
            int count = 0;
            T1 h;               //T1 h = HelpArray<T2>();
            for(int i = 0; i < c->GetSize(); i++){
                if((first <= (*c)[i]) &&  (*c)[i] <= second){
                    if((*c)[i] != (*c)[i-1]) {
                        h.append((*c)[i]);
                    }
                    count++;
                }
            }
            data = dict<T1, T2>(h, count);
        }
        else{
            int count = 1;
            T1 h;                                     //T1 h = HelpArray<T2>();
            for(int i = 0; i < c->GetSize(); i++){
                if(first <= (*c)[i] && (*c)[i] <= second) {
                    h.append((*c)[i]);
                }
            }
            T1 values;                         //T1 values = HelpArray<T2>();
            T1 amount;                         //T1 amount = HelpArray<T2>();
            for(int i = 0; i < h.GetDim(); i++){
                if(i < h.GetDim() - 1 && h[i] == h[i+1]){
                    count++;
                }
                else{
                    if(i == h.GetDim() - 1 && h[i] == h[i-1]){
                        values.append(h[i]);
                        amount.append(count);
                    }
                    else{
                        values.append(h[i]);
                        amount.append(count);
                        count = 1;
                    }
                }
            }
            auto big = new T1[values.GetDim()];       //auto big = new HelpArray<T2>[values.GetDim()];
            for(int i = 0; i < values.GetDim(); i++){
                big[i] = T1(values[i]);     //big[i] = HelpArray<T2>(values[i]);
            }
            data = dict<T1, T2>(values.GetDim(), big, amount);
        }
    }

    void print(){
        data.print();
    }
};
