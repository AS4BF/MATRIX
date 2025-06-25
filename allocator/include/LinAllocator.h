#ifndef LINALLOCATOR_H
#define LINALLOCATOR_H
#define _DEBUG
#include "Allocator.h"

#ifdef _DEBUG
#include <iostream>
#endif



template <typename T>
class LinAllocator : public Allocator<T> {
public:
    LinAllocator(const uint count_obj);

    virtual ~LinAllocator();
    virtual T* allocate(const uint num) override;
    virtual T* deallocate(T* ptr, const uint num) override;
};

template<typename T>
LinAllocator<T>::~LinAllocator(){
    #ifdef _DEBUG
        std::cout << "~LinAllocator\n";
    #endif

    delete[] this->current_addr;
    this->current_addr = nullptr;
};

template<typename T>
LinAllocator<T>::LinAllocator(const uint count_obj) : Allocator<T>::Allocator(count_obj) {
    if (count_obj != 0){
        this->current_addr = new T[count_obj];
    };

    #ifdef _DEBUG
        std::cout << "total_size:\t" << this->total_size << "addr:\t" << this->current_addr << "offset:\t" << this->offset << "\n";
    #endif
};



template<typename T>
T* LinAllocator<T>::allocate(const uint num){
    if(this->offset + num > this->total_size){
        return nullptr;
    };

    uint start = this->offset;
    this->offset += num;

    #ifdef _DEBUG
        std::cout << "addr:\t" << this->current_addr + start << "offset:\t" << this->offset << "\n";
    #endif

    return this->current_addr + start;
}


template <typename T>
T* LinAllocator<T>::deallocate(T* ptr, uint num){
    if (this->offset < num){
        return nullptr;
    }
    this->offset -= num;
    return this->current_addr + this->offset;
}


#endif 