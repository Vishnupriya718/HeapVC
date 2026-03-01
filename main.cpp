#include <iostream>
#include <fstream>//for file input
using namespace std;

const int MAX_SIZE= 100;
int heap [MAX_SIZE +1]; // heap array,index starts at 1
int size = 0; // number of elemets in heap


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
    size = 7;
    heap[1] = 100;
    heap[2] = 99;
    heap[3] = 96;
    heap[4] = 98;
    heap[5] = 97;
    heap[6] = 95;
    heap[7] = 94;

    printTree(heap, size, 1, 0);
    return 0;

  }









