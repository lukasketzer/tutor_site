#include <stdio.h>
#include <stdlib.h>

// allocating array on stack
int* foo() {
    int a[] = {10, 20, 30, 40};
    return a;
}


// allocating array on heap (Correct way)
int* bar() {
    int *a = malloc(sizeof(int) * 4);
    if (!a) exit(1); // nullpointer check

    a[0] = 10; 
    a[1] = 20; 
    a[2] = 30; 
    a[3] = 40; 
    return a;
}


int main() {

    
    // Array allocated on heap.
    // Values should be printed
    int* heap = bar();
    printf("heap-pointer: %p\n", heap);
    for (int i = 0; i < 4; i++) {
        printf("%d\n", heap[i]);
    }
    free(heap);

    
    // Array allocaed on stack
    // Segfault because trying to acces a NULL-Pointer
    int* stack = foo();
    printf("stack-pointer: %p\n", stack);
    for (int i = 0; i < 4; i++) {
        printf("%d\n", stack[i]);
    }
}
