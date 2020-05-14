#include <omp.h>
#include <stdio.h>

int main(void){
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        printf("Thread id: %d",id);
    }
    getchar();
}