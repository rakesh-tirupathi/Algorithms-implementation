/* Implementing a singly linked list */

#include<iostream>
using std::cin;
using std::cout;
using std::flush;

class Node
{
    public:
        Node(int newvalue);
        void setnext(Node* newnext);
        Node* getnext();
        int getvalue();
        void print();
    private:
        int value;
        Node* next;
    
};

Node::Node(int newvalue)    //Parameterized constructor for class Node
{
    value=newvalue;
    next=0;
}

void Node::setnext(Node* newnext)
{
    next=newnext;
}

Node* Node::getnext()
{
    return next;
}

int Node::getvalue()
{
    return value;
}

void Node::print()
{
    cout<<"\nThe value entered in the created node is: "<<value<<flush;
    cout<<"\n\nThe value of the next pointer in the created node with the value "<<value<<" is: "<<(int) next<<flush<<"\n";
}

class OrderedLinkedList
{
    
        Node* head;
        Node* newadd;
        int list_length;
        int node_value;
    public:
        bool add(int);
        void print();
        OrderedLinkedList();
        int user_input();
};

OrderedLinkedList::OrderedLinkedList()      //constructor for class OrderedLinkedList
{
    head=0;
}

bool OrderedLinkedList::add(int newvalue)       //method definition for adding a node
{
    bool  result=true;
    Node* newadd=new Node(newvalue);
    if(newadd!=0)       //There is an existing node
    {
        Node* previous=0;
        Node* current=head;
        while(current!=0 && (current->getvalue() > newadd->getvalue()))
        {
            previous=current;
            current=current->getnext();
        }       //end of while statement
        newadd->setnext(current);
        if(previous!=0)     //there are more than 2 nodes that is a previous node exists before the node that is to be added
        {
            previous->setnext(newadd);
        }       //end of if statement
        else    //previous=0
        {
            head=newadd;
        }       //end of else statement
    }
    else        //newadd=0
    {
        cout<<"\n There is no node to be added";
        result=false; 
    }       //end of newadd=0
    return result;
}



void OrderedLinkedList::print()
{
    Node* current=head;
    while(current!=0)
    {
        cout<<current->getvalue()<<"\t"<<flush;
        current=current->getnext();
    }       //end of while statement
}

int OrderedLinkedList::user_input()
{
    cout<<"\n Please enter the number of nodes that you want to enter:  ";
    cin>>list_length;
    cout<<"\n Please enter the "<<list_length<<" elements:\n";
    for(int i=0;i<list_length;i++)
    {
        cin>>node_value;
        add(node_value);
        cout<<"\n The added element is:\t";
        print();
        cout<<"\n";
    }
}

int main()
{
    //checking wether the created node is functioning properly
   Node n(47);      //object creation and parameterized constructor invoking for the class node
   n.print();       //calling the node class print
   Node n1(57);
   n1.print();
   n.setnext(& n1);
   n.print();
   n1.print();
   
   //execution of the OrderedLinkedList
   OrderedLinkedList o;     //object creation and constructor invoking
   o.user_input();  
   /*o.add(56);
   o.add(63);
   o.add(45);
   o.add(98);*/
   cout<<"\n The elements in the ordered linked list are: ";
   o.print();       //calling the ordered linked list print
   return 0;
}
