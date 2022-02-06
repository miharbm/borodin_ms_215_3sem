#pragma once
template<class T>
class Sequence{
public:
    //методы
    virtual int GetSize() const = 0;//получает размер
    virtual void ReSize(int size) = 0;//меняет размер
    virtual T& Get(int index) const = 0;//получает элемент по индексу
    virtual T GetFirst() const = 0;//Получает первый элемент в списке
    virtual T GetLast() const = 0;//Получает последний элемент в списке
    virtual T operator[](int index) const = 0;//Перегрузка оператора
    virtual T& operator[](int index) = 0;//перегрузка оператора
    virtual void Append(T& item) = 0;//Добавляет элемент в конец списка
    virtual void Prepend(T& item) = 0;//добавляет элемент в начало списка
    virtual void InsertAt(T& item, int index) = 0;//Вставляет элемент в заданную позицию
    virtual void Print() const = 0;//выводит
    virtual Sequence<T> *Concat(Sequence<T> &list) = 0;//сцепляет два списка
    virtual Sequence<T> *GetSubsequence(int startIndex, int endIndex) = 0;//получает список начиная и заканчивая опред. элементом
    virtual Sequence<T> *Clone() const = 0;//
    //Деструктор
    virtual ~Sequence<T>() = default;
};
