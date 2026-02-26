#include <iostream>
#include <fstream>//for file input
using namespace std;

const int MAX_SIZE= 100;
int heap [MAX_SIZE +1]; // heap array,index starts at 1
int size = 0 // number of elemets in heap

int main()
  {
    cout << "Heap program " << endl;
    return 0;

  }







/*
void printTree(int array[] int last index, int car index, int depth)
{if( curIndex*2)+1 <lastIndex){// Assumes index starting at 1,might be off by one w/your last index
  printTree (array,lastIndex, (curIndex*2)+1,depth +1);//right recustion
}

for (int i=0 ; i <depth;i++){
  cout << "\t"; //print tabs
 }
cout << array [curIndex] << endl;

//recursion for left side
*/
