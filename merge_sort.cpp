/* Implementation of merge sort for 100, 1000,
   10000, 30000 elements*/
   
#include<iostream>
#include<conio.h>
#include<new>
#include<stdlib.h>
#include<ctime>
using std::cin;
using std::cout;
using namespace std;
class Merge
{
	public:
	Merge();
	input();
	input_print();
	output();
	mergeSort();
	merge_sort(int p[], int l, int r);
	merge(int arr[], int l, int m, int r);
	
	private:
	int size;
	int choice;
	int count;
	int * p;
	int comparisions;
};

Merge :: Merge()
{
	size = 0;
	choice = 0, count = 0, comparisions=0;
}

Merge :: input_print()
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

Merge :: output()
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
	cout<<"\n The number of comparasions done in merge sort is: "<<comparisions;
	delete[] p;
}

Merge :: input()
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

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
Merge :: merge_sort(int p[], int l, int r)
{
	if (l < r)
    {
        int m = l+(r-l)/2;
        // Sort first and second halves
        merge_sort(p, l, m);
        merge_sort(p, m+1, r);
 
        merge(p, l, m, r);
    }
}

Merge :: merge(int p[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = p[l + i];
    for (j = 0; j < n2; j++)
        R[j] = p[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            p[k] = L[i];
            i++;
        }
        else
        {
            p[k] = R[j];
            j++;
        }
        k++;
		comparisions++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        p[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        p[k] = R[j];
        j++;
        k++;
    }
}

Merge :: mergeSort()
{
	merge_sort(p,0,size-1);
}

int main()
{
	Merge m;
	m.input();
	double start_s=clock();
	m.mergeSort();
	double stop_s=clock();
	m.output();
	cout<<"\n The value of stop is:  "<<stop_s;
	cout<<"\n The value of start is: " <<start_s;
	cout << "\n Time taken for merge sort function is: " <<(stop_s-start_s)/double(CLOCKS_PER_SEC);
	cout<<"\n";
	return 0;
}
   