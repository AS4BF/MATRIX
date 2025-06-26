#ifndef MATRIX_H
#define MATRIX_H

#include "../allocator/include/Allocator.h"
#include "../allocator/include/LinAllocator.h"
#include <cstdint>


template <typename T, typename Alloc>
class Matrix {
private:
    typedef T* pT;
    typedef size_t sT;
    uint32_t rows;
    uint32_t columns;
    sT size = sizeof(T);
    pT data;
    Alloc alloc;
public:
    Matrix(uint32_t n, uint32_t m, const Alloc& UAlloc = Alloc()) : rows{n}, columns{m}, alloc{UAlloc} {
        data = reinterpret_cast<T*>(alloc.allocate(n*m*size, size));
    };
    // ~Matrix(){};
    T& operator() (const uint32_t row, const uint32_t column); 
    // Matrix operator+ (const Matrix& mx) const;
    // Matrix operator* (const Matrix& mx) const;
    
};

// template<typename T, typename Alloc>
// Matrix<T, Alloc>::Matrix(uint32_t n, uint32_t m, const Alloc& UAlloc = Alloc()) {
//     data = reinterpret_cast<T*>(alloc->allocate(n*m*sizeof(T)));
// };

// template<typename T, typename Alloc>
// Matrix<T, Alloc>::~Matrix(){

// }

template<typename T, typename Alloc>
T& 
Matrix<T, Alloc>::operator() (const uint32_t row, const uint32_t column){
    return data[row*columns+column];
}

#endif