/* Implementation of heap sort for 100, 1000,
   10000, 30000 elements*/
   
#include<iostream>
#include<conio.h>
#include<new>
#include<stdlib.h>
#include<ctime>
using std::cin;
using std::cout;
using namespace std;
class Heap
{
	public:
	Heap();
	input();
	input_print();
	output();
	heap_sort();
	heapify(int p[], int size, int i);
	
	private:
	int size;
	int choice;
	int count;
	int * p;
	int comparisions;
};

Heap :: Heap()
{
	size = 0;
	choice = 0, count = 0, comparisions=0;
}

Heap :: input_print()
{
	count=0;
	cout<<"\n The input elements before sorting are:\n";
	for(int i=0; i<size; i++)
	{
		cout<<p[i]<<"\t";
		count++;
		if(count==10)
		{
			cout<<"\n";
			count=0;
		}
	}
}

Heap :: output()
{
	count=0;
	cout<<"\n The output elements after sorting are:\n";
	for(int i=0; i<size; i++)
	{
		cout<<p[i]<<"\t";
		count++;
		if(count==10)
		{
			cout<<"\n";
			count=0;
		}
	}
	cout<<"\n The number of comparasions done in heap sort is: "<<comparisions;
	delete[] p;
}

Heap :: input()
{
	cout<<"\n Please Enter the size of the array: ";
	cin>>size;
	p = new int [size];	//dynamically allocating the array
	cout<<"\n Enter the type of input:\n";
	cout<<"\n 1. Increasing order \n";
	cout<<"\n 2. Decreasing order \n";
	cout<<"\n 3. Random order \n";
	cout<<"\n choice of input: ";
	cin>>choice;
	switch (choice)
	{
		case 1: for(int i=0; i<size; i++)
					p[i]=i+1;
				input_print();
				break;
		
		case 2: for(int i=0; i<size; i++)
					p[i]=size-i;
				input_print();
				break;
				
		case 3: srand(time(NULL));
				for(int i=0;i<size;i++)
					p[i]=rand()%100;
				input_print();
				break;
		
		default: cout<<"\n Please enter the choice from 1 - 3 ";
				 break;
	}
}

Heap :: heap_sort()
{
	// Build heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapify(p, size, i);
		comparisions++;
	}
        
    // One by one extract an element from heap
    for (int i=size-1; i>=0; i--)
    {
        swap(p[0], p[i]);	//move current root to end
        heapify(p, i, 0);	//calling heapify on the heap
		comparisions++;
    }	
}

Heap :: heapify(int p[], int size, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < size && p[l] > p[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < size && p[r] > p[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(p[i], p[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(p, size, largest);
    }
}

int main()
{
	Heap h;
	h.input();
	double start_s=clock();
	h.heap_sort();
	double stop_s=clock();
	h.output();
	cout<<"\n The value of stop is:  "<<stop_s;
	cout<<"\n The value of start is: " <<start_s;
	cout << "\n Time taken for heap sort function is: " <<(stop_s-start_s)/double(CLOCKS_PER_SEC);
	cout<<"\n";
	return 0;
}