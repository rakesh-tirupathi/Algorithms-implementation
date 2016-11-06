/* Implementation of quick sort for 100, 1000,
   10000, 30000 elements*/
   
#include<iostream>
#include<conio.h>
#include<new>
#include<stdlib.h>
#include<ctime>
using std::cin;
using std::cout;
using namespace std;
class Quick
{
	public:
	Quick();
	input();
	input_print();
	output();
	quicksort();
	quick_sort(int p[], int start_index, int end_index);
	partition(int p[], int start_index, int end_index);
	swap(int* a, int* b);
	
	private:
	int size;
	int choice;
	int count;
	int * p;
	int comparisions;
};

Quick :: Quick()
{
	size = 0;
	choice = 0, count = 0, comparisions=0;
}

Quick :: input_print()
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

Quick :: output()
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
	cout<<"\n The number of comparasions done in quick sort is: "<<comparisions;
	delete[] p;
}

Quick :: input()
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

Quick :: quick_sort(int p[], int start_index, int end_index)
{
	 if (start_index < end_index)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(p, start_index, end_index);
 
        // Separately sort elements before partition and after partition
        quick_sort(p, start_index, pi - 1);
        quick_sort(p, pi + 1, end_index);
    }
}

Quick :: swap(int* a, int* b)
{
	int t = *a;
    *a = *b;
    *b = t;
}

Quick :: partition(int p[], int start_index, int end_index)
{
    int pivot = p[end_index];    // pivot
    int i = (start_index - 1);  // Index of smaller element
 
    for (int j = start_index; j <= end_index- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (p[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&p[i], &p[j]);
        }
		comparisions++;
    }
    swap(&p[i + 1], &p[end_index]);
    return (i + 1);
}

Quick :: quicksort()
{
	quick_sort(p,0,size-1);
}

int main()
{
	Quick q;
	q.input();
	double start_s=clock();
	q.quicksort();
	double stop_s=clock();
	q.output();
	cout<<"\n The value of stop is:  "<<stop_s;
	cout<<"\n The value of start is: " <<start_s;
	cout << "\n Time taken for heap sort function is: " <<(stop_s-start_s)/double(CLOCKS_PER_SEC);
	cout<<"\n";
	return 0;
}