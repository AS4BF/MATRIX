#ifndef LINALLOCATOR_H
#define LINALLOCATOR_H
#define _DEBUG
#include "Allocator.h"

#ifdef _DEBUG
#include <iostream>
#endif



class LinAllocator : public Allocator {
protected:
    void* start_ptr = nullptr;
public:
    LinAllocator();
    virtual ~LinAllocator();
    
    virtual void Init(const size_t byte_count) override;
    virtual void* allocate(const size_t b_num, const size_t b_alignment) override;
    virtual void* deallocate(void* ptr, const size_t b_num) override;
};

#endif