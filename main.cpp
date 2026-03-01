#include <iostream>
#include <fstream>//for file input
using namespace std;

const int MAX_SIZE= 100;
int heap [MAX_SIZE +1]; // heap array,index starts at 1
int size = 0; // number of elemets in heap



void insert(int value)
{
    if (size >= MAX_SIZE)
    {
        cout << "Heap full!" << endl;
        return;
    }

    size++;
    heap[size] = value;

    int index = size;

    // Heapify up
    while (index > 1 && heap[index] > heap[index / 2])
    {
        swap(heap[index], heap[index / 2]);
        index = index / 2;
    }
}

void printTree(int array[], int lastIndex, int curIndex, int depth)
{
    if (curIndex > lastIndex)
        return;

    // Right child first
    if ((curIndex * 2) + 1 <= lastIndex)
        printTree(array, lastIndex, (curIndex * 2) + 1, depth + 1);

    // Print tabs for depth
    for (int i = 0; i < depth; i++)
        cout << "\t";

    cout << array[curIndex] << endl;

    // Left child
    if ((curIndex * 2) <= lastIndex)
        printTree(array, lastIndex, (curIndex * 2), depth + 1);
}

int main()
  {
    insert(100);
    insert(99);
    insert(96);
    insert(98);
    insert(97);
    insert(95);
    insert(94);
    printTree(heap, size, 1, 0);
    return 0;

  }









