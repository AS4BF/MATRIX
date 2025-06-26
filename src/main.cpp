#include "../allocator/include/Allocator.h"
#include "../allocator/include/LinAllocator.h"
#include "../LinAlgebra/include/Matrix.h"

template<typename T, typename Alloc>
void display(int n, int m, Matrix<T, Alloc> mat){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            std::cout << mat(i, j) << "\t"; 
        }
        std::cout << "\n";
    }
}

int main(){
    int n = 10;
    int m = 10;
    LinAllocator UAlloc;
    UAlloc.Init(n*m*sizeof(int)*2);
    Matrix<int, LinAllocator> myMat1 = Matrix<int, LinAllocator>(n, m, UAlloc);
    Matrix<int, LinAllocator> myMat2 = Matrix<int, LinAllocator>(n, m, UAlloc);
    display<int, LinAllocator>(n, m, myMat1);
    display<int, LinAllocator>(n, m, myMat2);
};