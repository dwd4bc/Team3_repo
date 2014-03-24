#include "Heap.h"
#include "HeapItem.h"
#include <iostream>

using namespace std;

int main()
{
     Heap *theHeap = new Heap(10);  // Create a heap of the default size

     cout << "Building the heap and adding items\n\n";

     // Add some items
     theHeap->Enqueue(123, 1.23);
     theHeap->Enqueue(345, 3.45);
     theHeap->Enqueue(234, 2.34);
     theHeap->Enqueue(678, 6.78);
     theHeap->Enqueue(456, 4.56);
     theHeap->Enqueue(567, 5.67);
     theHeap->Enqueue(789, 7.89);

     // This will build a heap that looks like this
     //                    789 
     //                   /   \
     //                456     678
     //                / \     / \
     //              123 345 234 567

     // See what we got
     cout << "Elements in the heap.\n";
     theHeap->printAll();

          cout << "Dequeuing items from the heap.\n\n";
	  /*	  Heap temp = theHeap.>Dequeue();
     while((temp) != NULL)
     {
		cout << "Dequeueing " << temp->getKey() << endl;
		delete temp; // delete this one
		// See what we have left
		cout << "Elements in the heap.\n";
		theHeap->printAll();
		cout << endl;
		}*/
}
