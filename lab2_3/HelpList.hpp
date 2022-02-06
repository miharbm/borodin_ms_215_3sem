#pragma once
#include<stdexcept>
template<typename T>
struct HelpNode {
    T value;
    HelpNode<T> *prev = nullptr;
    HelpNode<T> *next = nullptr;
    HelpNode(T value1, HelpNode<T> *prev1, HelpNode<T> *next1) : value(value1), prev(prev1), next(next1) {}
    ~HelpNode() = default;
};
template<typename T>
class HelpList{
private:
    HelpNode<T> *first = nullptr;
    HelpNode<T> *last = nullptr;
    int list_size;
public:
    HelpList(){
        first = nullptr;
        last = nullptr;
        list_size = 0;
    }
    HelpList(T* list, int size){
        list_size = 0;
        for(int i = 0; i < size; i++){
            Append(list[i]);
        }
    }
    HelpList(T el){
        list_size = 0;
        Append(el);
    }
    HelpList(const HelpList<T> &list){
        list_size = list.GetSize();
        for(HelpNode<T> *i = list.first; i != nullptr; i = i->next){
            auto *item = new HelpNode<T>(i->value, last, nullptr);
            if(first == nullptr){
                first = item;
            }
            if(last != nullptr){
                last->next = item;
            }
            last = item;
        }
    }
    T GetFirst() const {
        if(first == nullptr){
            throw out_of_range("index out of range");
        }
        return first->value;
    }
    T GetLast() const {
        if (last == nullptr)
            throw out_of_range("Index out of range");
        return last->value;
    }
    int GetSize() const {
        return list_size;
    }
    void ReSize(int size){
        if(size < 0){
            throw bad_array_new_length();
        }
        int old_size = GetSize();
        if(size < old_size){
            while(old_size != size){
                HelpNode<T> *item = last;
                last = last->prev;
                delete item;
                old_size--;
            }
            last->next = nullptr;
        }
        else {
            while(old_size != size){
                auto *item = new HelpNode<T>(0, last, nullptr);
                last->next = item;
                last = item;
                old_size++;
            }
        }
        list_size = size;
    }
    T& Get(int index) const {
        if (index < 0 || index >= GetSize()) {
            throw out_of_range("index out of range");
        }
        int j = 0;
        for (HelpNode<T> *i = first; i != nullptr; i = i->next) {
            if (j == index) {
                return i->value;
            }
            j++;
        }
    }
    T operator[](int index) const {
        return Get(index);
    }
    void Append(T& item){
        auto* elem = new HelpNode<T>(item, last, nullptr);
        if(first == nullptr)
            first = elem;
        if(last != nullptr)
            last->next = elem;
        last = elem;
        list_size++;
    }
    void print() const {
        cout << "[";
        for (HelpNode<T> *i = first; i != nullptr; i = i->next) {
            T value = i->value;
            cout << value;
            if (i->next != nullptr) cout << ", ";
        }
        cout << "]";
    }
    bool operator==(const HelpList<T>& a){
        bool alpha;
        if(a.GetSize() == this->GetSize()){
            alpha = true;
            for(int i = 0; i < a.GetSize();i++){
                if(a[i] != this->Get(i)){
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
    HelpList<T>operator=(const HelpList<T> &list){
        this->list_size = list.GetSize();
        for(HelpNode<T> *i = list.first; i != nullptr; i = i->next){
            auto *item = new HelpNode<T>(i->value, last, nullptr);
            if(this->first == nullptr){
                this->first = item;
            }
            if(this->last != nullptr){
                this->last->next = item;
            }
            this->last = item;
        }
        return *this;
    }
    ~HelpList() {
        while (first != nullptr) {
            HelpNode<T> *item = first;
            first = first->next;
            delete item;
        }
        first = nullptr;
        last = nullptr;
    }
};

