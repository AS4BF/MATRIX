#include "Allocator.h"
#include "LinAllocator.h"

int main(){
    uint total_size = 100;
    LinAllocator<int> *Alloc = new LinAllocator<int>(total_size);
    int* ptr = Alloc->allocate(10);
    ptr = Alloc->allocate(10);
    ptr = Alloc->deallocate(ptr+10, 10);
    ptr = Alloc->deallocate(ptr+10, 10);

    delete Alloc;
};