#include<stdio.h>
#include<stdlib.h>

typedef struct MaxHeap {
    int* array;
    int size;
    int capacity;
}MaxHeap;

/* Initialize the heap with a given capacity */
MaxHeap* createHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->capacity = capacity;
    heap->size=0;
    heap->array = (int*)malloc(capacity * sizeof(int));
    return heap;
}

/* Swap two integers using pointers */
void swap(int*a, int*b){
    int temp = *a;
    *a=*b;
    *b = temp;
}

/* Insert a new element and maintain Heap property (Heapify Up) */
void insert(MaxHeap* heap, int data) {
    if(heap->size == heap->capacity) return;

    int i = heap->size;
    heap->array[i] = data;
    heap->size++;

    /* Move the new node up to satisfy Max Heap property */
    /* Parent index = (i -1) / 2 */
    while (i != 0 && heap->array[(i -1) /2] < heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i-1)/2]);
        i= (i-1) / 2;
    }
}

/* Print the array representation of the heap */
void printHeap(MaxHeap* heap) {
    for (int i=0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

int main() {
    MaxHeap* heap = createHeap(10);

    /* Inserting elements */
    insert(heap, 10);
    insert(heap, 20);
    insert(heap, 15);
    insert(heap, 40);
    insert(heap, 50);
    insert(heap, 100);

    printf("Max Heap Array : ");
    printHeap(heap); /* Root Should be 100 */

    return 0;
}