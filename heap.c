#include <stdio.h>
#define MAX_HEAP_SIZE 100
int heap[MAX_HEAP_SIZE];
int heapSize = 0;
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int index) {
    int parent = (index - 1) / 2;

    while (index > 0 && heap[index] > heap[parent]) {
        swap(&heap[index], &heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}
void insert(int value) {
    if (heapSize >= MAX_HEAP_SIZE) {
        printf("Heap is full. Cannot insert more elements.\n");
        return;
    }

    heap[heapSize] = value;
    heapifyUp(heapSize);
    heapSize++;
}
void displayHeap() {
    printf("Heap elements: ");
    for (int i = 0; i < heapSize; ++i) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int n, element;

    printf("Enter the number of elements to insert into the heap: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &element);
        insert(element);
    }

    displayHeap();

    return 0;
}
