#pragma once
#include <iostream>
#include "../HelpList.hpp"
using namespace std;
template<typename T1, typename T2>
class dict_node_list{
private:
    T1 key;
    T2 value;
public:
    dict_node_list(){
        key = HelpList<T2>();
        value = 0;
    }
    dict_node_list(T1 a, T2 val){
        key = a;
        value = val;
    }
    void setkey(T1 a){
        key = a;
    }
    void setvalue(T2 alpha){
        value = alpha;
    }
    T1 getkey(){
        return key;
    }
    T2 getvalue(){
        return value;
    }
    T2 operator[](T1& a){
        if(key == a){
            return value;
        }
    }
    bool operator==(const dict_node_list<T1, T2>& alpha){
        bool check;
        if(this->getkey() == alpha.key && this->getvalue() == alpha.value){
            check = true;
        }
        else{
            check = false;
        }
        return check;
    }
    void print(){
        key.print();
        cout<<':';
        cout<<value;
    }


};
