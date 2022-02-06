#pragma once
#include <iostream>
#include "../HelpArray.hpp"
template<typename T1, typename T2>
class dict_node{
private:
    T1 key;
    T2 value;
public:
    dict_node() {
        key = T1(); //key = HelpArray<T2>();
        value = 0;
    }
    dict_node(T1 arr, T2 val){
        key = arr;
        value = val;
    }
    void setkey(T1 alpha){
        key = alpha;
    }
    void setvalue(T2 val){
        value = val;
    }
    T1 getkey(){
        return key;
    }
    T2 getvalue(){
        return value;
    }
    void print(){
        key.print();
        cout<<':';
        cout<<value;
    }
    T2 operator[](T1 val){
        if(key == val){
            return value;
        }
    }
    bool operator==(const dict_node<T1, T2>& alpha){
        bool check;
        if(this->getkey() == alpha.key && this->getvalue() == alpha.value){
            check = true;
        }
        else{
            check = false;
        }
        return check;
    }
    dict_node<T1, T2>operator=(const dict_node<T1, T2>& alpha){
        this->value = alpha.value;
        this->key = alpha.key;
        return *this;
    }
};
