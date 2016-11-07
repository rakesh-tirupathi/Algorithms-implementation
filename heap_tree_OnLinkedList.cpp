/* Implementing a Heap Tree */

#include<iostream>
using std::cout;
using std::cin;

class MaxHeap
{
    //by default all methods are private unless specified
        
        int size;
        int data[100];
        //data=new float[size];
        //int no_of_nodes;
        int current;
        int parent;
    public:
        int add(int);
        int remove();
        MaxHeap();
        //int user_input();
        int print_heap();
};

MaxHeap::MaxHeap()        //constructor for class BinarySearchTree
{
    size=0;
}

int MaxHeap::add(int newvalue)       //method definition for adding a node
{
        data[size]=newvalue;
        if(size>0)
        {
            current=size;
            parent=(current-1)/2;
            while(data[current]>data[parent])
            {
                int temp=data[current];
                data[current]=data[parent];
                data[parent]=temp;
                current=parent;
                parent=(current-1)/2;
            }
        }
        size++; 
    return 0;
}

int MaxHeap::remove()
{
        bool success=true;      //assuming that the nodes are present
        if(size==0)      //there are no nodes                    
        {
                success=false;       
        }
        else            //there are nodes present in the heap
        {
             int result=data[0];        //storing the root in the result variable
             size--;            //decrementing the size of the heap
             //parent=0;
             data[0]=data[size];              //assuming that there are no nodes in the heap
             bool done=false;
             
             int left_child=(2*parent)+1;            //initializing the left child 
             int right_child=(2*parent)+2;           //initializing the right child   
             while(!done)               //there are nodes in the heap
             {
                if((2*parent+1)<=size) //has two children
                {
                        if(data[left_child]>data[right_child])  //comparing the 2 children
                        {       //left is greater
                                if(data[left_child]>data[parent])       //comparing the max child with the parent
                                {       //left child is greater than the parent
                                        //swapping parent and left child
                                        int temp=data[left_child];
                                        data[left_child]=data[parent];
                                        data[parent]=temp;
                                        parent=left_child;      //making the left child as parent for comparing again
                                        left_child=(2*parent)+1;        //re-initializing the left child for the new parent            
                                        right_child=(2*parent)+2;       //re-initializing the right child for the new parent
                                        
                                }
                        }
                        else 
                        {       //right is greater
                                if(data[right_child]>data[parent])       //comparing the max child with the parent
                                {       //right child is greater than the parent
                                        //swapping parent and right child
                                        int temp=data[right_child];
                                        data[right_child]=data[parent];
                                        data[parent]=temp;
                                         parent=right_child;    //making the right child as parent for comparing again
                                        left_child=(2*parent)+1;        //re-initializing the left child for the new parent         
                                        right_child=(2*parent)+2;       //re-initializing the right child for the new parent
                                }
                                else    //parent is greater
                                {
                                        done = true;
                                }
                        }
                }
                else if((2*parent+1)==size)   //has one child
                {
                        if(data[left_child]>data[parent])       //comparing the one child with the parent
                        {       //one child is greater
                                //swapping parent and left child
                                int temp=data[left_child];
                                data[left_child]=data[parent];
                                data[parent]=temp;     
                        }
                        else
                        {
                                done = true;
                        }
                }
                else // if((2*parent+1)>size)           //no children
                {
                        done = true;
                }
             }
             return result;
        }
        
}

/*int MaxHeap::user_input()
{
    cout<<"\n Please enter the no of nodes that you want to enter:  ";
    cin>>no_of_nodes;
    size=no_of_nodes;
    //float data[size];
    data=new int[size];
    for(int i=0;i<no_of_nodes;i++)
    {
        cin>>data[i];
        add(data[i]);
    }  
}*/

int MaxHeap::print_heap()
{
    cout<<"\n\n The no of nodes entered in the heap are:  "<<size;
    cout<<"\n The values in the heap are:  ";
    for(int i=0;i<size;i++)
    {
        cout<<data[i]<<"\t";
    }  
}

int main()
{
   MaxHeap m;
   m.add(10);
   m.print_heap();
   m.add(50);
   m.print_heap();
   m.add(100);
   m.print_heap();
   m.add(25);
   m.print_heap();
   m.add(75);
   m.print_heap();
   m.remove();
   m.print_heap();
   m.remove();
   m.print_heap();
   m.remove();
   m.print_heap();
    m.remove();
   m.print_heap();
   return 0;
}

