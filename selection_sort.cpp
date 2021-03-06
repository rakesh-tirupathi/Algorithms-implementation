/* Implementation of insertion sort for 100, 1000,
   10000, 30000 elements*/
   
#include<iostream>
#include<conio.h>
#include<new>
#include<stdlib.h>
#include<ctime>
using std::cin;
using std::cout;
using namespace std;
class Selection
{
	public:
	Selection();
	input();
	input_print();
	output();
	selection_sort();
	
	private:
	int size;
	int choice;
	int count;
	int * p;
	int comparisions;
};

Selection :: Selection()
{
	size = 0;
	choice = 0, count = 0, comparisions=0;
}

Selection :: input_print()
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

Selection :: output()
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
	cout<<"\n The number of comparasions done in selection sort is: "<<comparisions;
	delete[] p;
}

Selection :: input()
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

Selection :: selection_sort()
{
	int min_pos;
	for (int i=0; i < size-1; i++)
	{
	    min_pos = i;//set minimum position to the current index of array
		for (int j=i+1; j < size; j++)
		{
			if (p[j] < p[min_pos])
				min_pos=j;	//keeps track of the min index, needed when the swap happens
			comparisions++;
		}	//end of for loop
		if (min_pos != i) // i is not the min position
		{
			int temp = p[i];
			p[i] = p[min_pos];
			p[min_pos] = temp;
		}
	}	//end of for loop	
}

int main()
{
	Selection s;
	s.input();
	double start_s=clock();
	s.selection_sort();
	double stop_s=clock();
	s.output();
	cout<<"\n The value of stop is:  "<<stop_s;
	cout<<"\n The value of start is: " <<start_s;
	cout << "\n Time taken for selection sort function is: " <<(stop_s-start_s)/double(CLOCKS_PER_SEC);
	cout<<"\n";
	return 0;
}