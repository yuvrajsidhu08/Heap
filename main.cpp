#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void add(int heap[], int& size, int value) {
    size++;
    heap[size] = value;

    int i = size;

    while (i > 1 && heap[i] > heap[i / 2]) {
        int temp = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = temp;
        i = i / 2;
    }
}

void removeOne(int heap[], int& size) {
    if (size == 0) {
        cout << "Heap is empty." << endl;
        return;
    }

    cout << heap[1] << endl;

    heap[1] = heap[size];
    size--;

    int i = 1;

    while (true) {
        int left = i * 2;
        int right = i * 2 + 1;
        int largest = i;

        if (left <= size && heap[left] > heap[largest])
            largest = left;

        if (right <= size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            i = largest;
        }
        else {
            break;
        }
    }
}

void removeAll(int heap[], int& size) {
    while (size > 0) {
        removeOne(heap, size);
    }
}

void printTree(int heap[], int size, int index, int depth) {
    if (index > size)
        return;

    printTree(heap, size, index * 2 + 1, depth + 1);

    for (int i = 0; i < depth; i++)
        cout << "\t";

    cout << heap[index] << endl;

    printTree(heap, size, index * 2, depth + 1);
}
