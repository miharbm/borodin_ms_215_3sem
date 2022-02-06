#pragma once

#include <iostream>

using namespace std;


template<typename T>
class HelpArray{
private:
    T* memory;
    int dimension;
public:
    HelpArray(){
        memory = new T[1];
        dimension = 0;
    }
    explicit HelpArray(T value){
        memory = new T[1];
        dimension = 1;
        memory[0] = value;
    }
    HelpArray(T* alpha, int dim){
        memory = new T[dim];
        dimension = dim;
        for(int i = 0; i < dimension; i++){
            memory[i] = alpha[i];
        }
    }
    void print(){
        cout<<'[';
        for(int i = 0; i < dimension; i++){
            cout<<memory[i];
            if(i < dimension - 1){
                cout<<',';
            }
        }
        cout<<']';
    }
    T operator[](int index){
        return memory[index];
    }
    int GetDim(){
        return dimension;
    }
    HelpArray<T> operator=(const HelpArray<T> &a){
        this->memory = new T[a.dimension];
        this->dimension = a.dimension;
        for(int i = 0; i < this->dimension; i++){
            this->memory[i] = a.memory[i];
        }
        //return *this;
    }
    bool operator ==(HelpArray<T> a){
        bool alpha;
        if(this->dimension == a.dimension){
            for(int i = 0; i < this->dimension;i++){
                if(this->memory[i] == a.memory[i]){
                    alpha = true;
                }
                else{
                    alpha = false;
                    break;
                }
            }
        }
        else{
            alpha = false;
        }
        return alpha;
    }
    void DeleteAll(){
        delete memory;
        dimension = 0;
        memory = new T[1];
    }
    void append(T el){
        T* help = new T[dimension];
        for(int i = 0; i < dimension; i++){
            help[i] = memory[i];
        }
        delete memory;
        memory = new T[dimension+1];
        dimension+=1;
        for(int i = 0; i < dimension; i++){
            if(i < dimension - 1){
                memory[i] = help[i];
            }
            else{
                memory[i] = el;
            }
        }
        //return *this;

    }
    T get(int index){
        return memory[index];
    }
};
