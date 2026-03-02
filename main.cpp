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
