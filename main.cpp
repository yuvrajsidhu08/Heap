#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Add one value and bubble up
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

// Remove largest value and bubble down
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

// Remove all values
void removeAll(int heap[], int& size) {
    while (size > 0) {
        removeOne(heap, size);
    }
}

// Print heap sideways
void printTree(int heap[], int size, int index, int depth) {
    if (index > size)
        return;

    printTree(heap, size, index * 2 + 1, depth + 1);

    for (int i = 0; i < depth; i++)
        cout << "\t";

    cout << heap[index] << endl;

    printTree(heap, size, index * 2, depth + 1);
}

int main() {
    int heap[101];
    int size = 0;
    char command[20];

    while (true) {
        cout << "\nCommands: ADD, FILE, REMOVE, REMOVEALL, PRINT, QUIT\n";
        cin >> command;

        // Add numbers manually
        if (strcmp(command, "ADD") == 0) {
            cout << "Enter numbers (0 to stop): ";
            int num;
            cin >> num;

            while (num != 0 && size < 100) {
                if (num >= 1 && num <= 1000) {
                    add(heap, size, num);
                }
                cin >> num;
            }
        }

        // Add numbers from file
        else if (strcmp(command, "FILE") == 0) {
            char filename[100];
            cout << "Enter filename: ";
            cin >> filename;

            ifstream file(filename);
            int num;

            while (file >> num && size < 100) {
                if (num >= 1 && num <= 1000) {
                    add(heap, size, num);
                }
            }

            file.close();
        }

        // Remove largest value
        else if (strcmp(command, "REMOVE") == 0) {
            removeOne(heap, size);
        }

        // Remove all values
        else if (strcmp(command, "REMOVEALL") == 0) {
            removeAll(heap, size);
        }

        // Print tree structure
        else if (strcmp(command, "PRINT") == 0) {
            printTree(heap, size, 1, 0);
        }

        // Quit program
        else if (strcmp(command, "QUIT") == 0) {
            break;
        }
    }

    return 0;
}
