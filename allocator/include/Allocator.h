#ifndef ALLOCATOR_H
#define ALLOCATOR_H
#define _DEBUG

#ifdef _DEBUG
#include <iostream>
#endif




class Allocator{
protected:
    size_t b_total;
    size_t b_offset = 0;
    size_t b_used = 0;
public:
    Allocator() = default;
    virtual ~Allocator() { b_total = 0; 
    #ifdef _DEBUG
        std::cout << "~Allocator\n";
    #endif
    };
    virtual void Init(const size_t byte_count) = 0;
    virtual void* allocate(const size_t b_num, const size_t b_alignment = 0) = 0;
    virtual void* deallocate(void* ptr, const size_t b_num) = 0;
};

#endif 