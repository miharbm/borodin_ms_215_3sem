#pragma once
#include "DictNodeList.h"
template<typename T1, typename T2>
class dict_list : public Idictionary<T1, T2>{
private:
    dict_node_list<T1, T2>* memory;
    int dimension;
public:
    dict_list<T1, T2>(){
        memory = new dict_node_list<T1, T2>[1];
        dimension = 1;
    }
    dict_list<T1, T2>(int dim, T1* arr1, T1 arr2){
        dimension = dim;
        memory = new dict_node_list<T1, T2>[dimension];
        for(int i = 0; i < dimension; i++){
            memory[i].setkey(arr1[i]);
            memory[i].setvalue(arr2[i]);
        }
    }
    dict_list<T1, T2>(T1 arr, int count){
        dimension = 1;
        memory = new dict_node_list<T1, T2>[1];
        memory[0].setkey(arr);
        memory[0].setvalue(count);
    }
    void print(){
        cout<<'{';
        for(int i = 0; i < dimension; i++){
            memory[i].print();
            if(i < dimension - 1){
                cout<<',';
            }
        }
        cout<<'}';
    }
    void setel(int index, T1 key, T2 value){
        memory[index].setkey(key);
        memory[index].setvalue(value);
    }
    dict_list<T1, T2> SetAdd(dict_node_list<T1, T2> el){
        if(!this->in(el)) {
            dict_list<T1, T2> res;
            res.memory = new dict_node_list<T1, T2>[this->dimension + 1];
            for (int i = 0; i < this->dimension; i++) {
                res.memory[i] = this->memory[i];
            }
            res.memory[this->dimension] = el;
            res.dimension = this->dimension + 1;
            return res;
        }
        else{
            return *this;
        }
    }

    dict_list<T1, T2> SetAdd(int index, T1 key, T2 value){
        dict_node_list<T1, T2> test = dict_node_list<T1, T2>(key, value);
        if(!this->in(test)){
            dict<T1, T2> res;
            res.memory = new dict_node_list<T1, T2>[this->dimension + 1];
            for (int i = 0; i < this->dimension; i++) {
                res.memory[i] = this->memory[i];
            }
            res.memory[this->dimension] = test;
            res.dimension = this->dimension + 1;
            return res;
        }
        else{
            return *this;
        }
    }
    T2 operator[](T1 val){
        for(int i = 0; i < dimension; i++){
            if(memory[i].getkey() == val){
                return memory[i].getvalue();
            }
        }
    }
    T2 FindMaxValue(){
        T2 max = this->memory[0].getvalue();
        for(int i = 0; i < this->dimension;i++){
            if(this->memory[i].getvalue() > max){
                max = this->memory[i].getvalue();
            }
        }
        return max;

    }
    bool in(dict_node_list<T1, T2> el){
        bool check;
        for(int i = 0; i < this->dimension; i++){
            if(memory[i] == el){
                check = true;
                break;
            }
            else{
                check = false;
            }
        }
        return check;
    }
};
