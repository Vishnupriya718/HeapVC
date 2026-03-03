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


void removeRoot()
{
    if (size == 0)
    {
        cout << "Heap is empty!" << endl;
        return;
    }

    cout << "Removed: " << heap[1] << endl;

    heap[1] = heap[size];
    size--;

    int index = 1;

    while (true)
    {
        int left = index * 2;
        int right = index * 2 + 1;
        int largest = index;

        if (left <= size && heap[left] > heap[largest])
            largest = left;

        if (right <= size && heap[right] > heap[largest])
            largest = right;

        if (largest == index)
            break;

        swap(heap[index], heap[largest]);
        index = largest;
    }
}
void removeAll()
{
    while (size > 0)
    {
        removeRoot();
    }
}

// Allows user to enter numbers manually
void manualInput()
{
    int number;
    cout << "Enter numbers between 1 and 1000 (enter -1 to stop):\n";

    while (true)
    {
        cin >> number;

        if (number == -1)
            break;

        if (number < 1 || number > 1000)
        {
            cout << "Invalid number. Try again.\n";
            continue;
        }

        insert(number);
    }
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
    cout << "Original Heap:\n";
    printTree(heap, size, 1, 0);

    cout << "\nAfter Removing Root:\n";
    removeRoot();
    printTree(heap, size, 1, 0);
 
    return 0;

  }









