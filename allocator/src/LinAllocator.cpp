#include "include/LinAllocator.h"
#include <cstdint>
#include <malloc.h>


LinAllocator::~LinAllocator(){
    #ifdef _DEBUG
        std::cout << "~LinAllocator\n";
    #endif

    delete[] this->start_ptr;
    this->start_ptr = nullptr;
};


LinAllocator::LinAllocator() : Allocator::Allocator() {
    // if (b_num != 0){
    //     this->start_ptr = new uint8_t[b_num];
    // };

    // #ifdef _DEBUG
    //     std::cout << "total_size:\t" << this->b_total << "offset:\t" << this->b_offset << "\n";
    // #endif
};

void
LinAllocator::Init(const size_t b_num){
    if (b_num != 0){
        if(this->start_ptr != nullptr){
            delete[] start_ptr;
        }
        this->b_total = b_num;
        this->start_ptr = new uint8_t[b_num];
        this->b_offset = 0;
    };

    #ifdef _DEBUG
        std::cout << "total_size:\t" << this->b_total << "offset:\t" << this->b_offset << "\n";
    #endif

}






void*
LinAllocator::allocate(const size_t num, const size_t b_alignment = 0){

    if(this->start_ptr == nullptr){
        Init(num);
    };

    if(b_alignment != 0 && this->b_offset % b_alignment != 0){
        this->b_offset = (this->b_offset/b_alignment + 1) * b_alignment;
    }

    if(this->b_offset + num > this->b_total){
        return nullptr;
    };
    
    uintptr_t m_addr = reinterpret_cast<uintptr_t>(this->start_ptr)+this->b_offset;
    this->b_offset += num;

    #ifdef _DEBUG
        std::cout << "addr:\t" <<  (void*)m_addr << "offset:\t" << this->b_offset << "\n";
    #endif

    return reinterpret_cast<void*>(m_addr);
}


void* LinAllocator::deallocate(void* ptr, const size_t b_num){
    this->b_offset = 0;
    return this->start_ptr;
}







