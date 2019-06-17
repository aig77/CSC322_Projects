include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define SIZE 5

typedef int *intptr;
typedef int Iarr[SIZE];
typedef int *Parr[SIZE];

void init(Iarr intArr, Parr ptrArr) {
    srand(getpid());
    for(int i = 0; i < SIZE; i++) {
        int val = rand();
        //intArr[i] = val;
        //ptrArr[i] = &intArr[i];
        *(intArr+i) = val;
        *(ptrArr+i) = intArr+i;
    }
}

void printIntArr(Iarr arr) {
    for(int i = 0; i < SIZE; i++) {
    //printf("%d : %d\n", i, arr[i]);
    printf("%d : %d\n", i, *(arr+i));
    }
}

void printPtrArr(Parr arr) {
    for(int i = 0; i < SIZE; i++) {
    //printf("%d : (Address) %p, (Value) %d\n", i, *arr[i], **(arr+i));
    printf("%d : (Address) %p, (Value) %d\n", i, *(arr+i), **(arr+i));
    }
}

void swap(int *this, int *that) {
    int temp;
    temp = *this;
    *this = *that;
    *that = temp;
}

void sortIntegers(Iarr arr) {
    int i, j;
    for(int i = 0; i < SIZE-1; i++) {
        for(int j = 0; j < SIZE-i-1; j++) {
            if(*(arr+j) > *(arr+j+1))
                swap(arr+j, arr+j+1);
            }
        }
}

void sortPointers(Parr arr) {
    for(int i = 0; i < SIZE-1; i++) {
        for(int j = 0; j < SIZE-i-1; j++) {
            if(**(arr+j) > **(arr+j+1))
                swap(*(arr+j), *(arr+j+1));
        }
    }
}

int main(int argc, char* argv[]) {
    Iarr intArr;
    Parr ptrArr;

    init(intArr, ptrArr);

    printf("---- Initialized array of integers ----\n");
    printIntArr(intArr);

    printf("---- Array of pointers ----\n");
    printPtrArr(ptrArr);

    printf("---- Sorted array of pointers ----\n");
    sortPointers(ptrArr);
    printPtrArr(ptrArr);

    printf("---- Sorted array of integers ----\n");
    sortIntegers(intArr);
    printIntArr(intArr);


    return 0;
}
