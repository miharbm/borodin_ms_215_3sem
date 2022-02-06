#pragma once
template<typename T>
T* MakeRandomArray(int dimension){
    srand(1000);
    T* memory = new T[dimension];
    for(int i = 0; i < dimension; i++){
        memory[i] = rand();
    }
    return memory;
}
