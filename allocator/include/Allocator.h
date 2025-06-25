#ifndef ALLOCATOR_H
#define ALLOCATOR_H
#define _DEBUG

#ifdef _DEBUG
#include <iostream>
#endif

typedef unsigned int uint;

template <typename T>
class Allocator{
protected:
    uint total_size;
    uint offset = 0;
    T* current_addr = nullptr;
public:
    Allocator(uint obj_count) : total_size{obj_count} {};
    virtual ~Allocator() {total_size = 0; 
    #ifdef _DEBUG
        std::cout << "~Allocator\n";
    #endif
    };
    virtual T* allocate(const uint num) = 0;
    virtual T* deallocate(T* ptr, const uint num) = 0;
};

#endif 