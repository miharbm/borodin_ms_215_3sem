#pragma once
template<typename T1, typename T2>
class Idictionary{
public:
    virtual void print() = 0;
    virtual T2 operator[](T1 val) = 0;
    //virtual void Add(T1 key, T2 val);
    virtual ~Idictionary() = default;
};
