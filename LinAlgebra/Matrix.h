#ifndef MATRIX_H
#define MATRIX_H

#include "../allocator/include/Allocator.h"
#include "../allocator/include/LinAllocator.h"

template <template <typename> class AllocatorT, typename T>
class Matrix {
private:
    uint n;
    uint m;
    T* First;
    AllocatorT<T>* alloc;
public:
    Matrix(uint n, uint m) : n{n}, m{m} {};
    
    T operator() (const uint row, const uint column); 
    Matrix operator+ (const Matrix& mx) const;
    Matrix operator* (const Matrix& mx) const;
    
};

template<template<typename> class AllocatorT, typename T>
Matrix<AllocatorT, T>::Matrix(uint n, uint m){
    alloc = new AllocatorT<T>(n*m);
    First = alloc->allocate(n*m);
};

template<template<typename> class AllocatorT, typename T>
T Matrix<AllocatorT, T>::operator() (const uint row, const uint column){

}

#endif