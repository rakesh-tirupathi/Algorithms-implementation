/* Implementing a Binary Tree */

#include<iostream>
using std::cin;
using std::cout;
using std::flush;

class Node
{
    public:
        Node(int newvalue);
        void setnext(Node* newnext);
        void setleft(Node* newleft);
        void setright(Node* newright);
        Node* getnext();
        Node* getleft();
        Node* getright();
        int getvalue();
        void print();
    private:
        int value;
        Node* next;
        Node* left;
        Node* right;
    
};

Node::Node(int newvalue)        //Parameterized constructor for class node
{
    value=newvalue;
    next=0;
    left=0;
    right=0;
}

void Node::setnext(Node* newnext)
{
    next=newnext;
}

void Node::setleft(Node* newleft)
{
	left=newleft; 
	
}
void Node::setright(Node* newright)
{
	right=newright; 
	
}

Node* Node::getnext()
{
    return next;
}

Node* Node::getleft()
{
    return left;
}

Node* Node::getright()
{
    return right;
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

class BinarySearchTree
{
    //by default all methods are private unless specified
        Node* root;
        Node* newadd;
        int list_length;
        int node_value;
    public:
        bool add(int);
        bool print();
        bool print(Node* root);
        BinarySearchTree();
        int user_input();
};

BinarySearchTree::BinarySearchTree()        //constructor for class BinarySearchTree
{
    root=0;
}

bool BinarySearchTree::add(int newvalue)      //method for adding a new node
{
    bool  result=true;
    Node* newadd=new Node(newvalue);
    if(newadd!=0)       //There is an existing node
    {
        Node* previous=0;
        Node* current=root;
        while(current!=0)       //a current pointer exists
        {
            previous=current;
            if(current->getvalue()>newadd->getvalue())
            {
                current=current->getleft();
            }       //end of if statement
            else
            {
                current=current->getright();
            }       //end of else statement
        } 
        if(previous!=0)     //there are more than 2 nodes that is a previous node exists before the node that is to be added
        {
            if(previous->getvalue() > newadd->getvalue())
            {
                previous->setleft(newadd);
            }       //end of if statement
        
            else    //previous=0
            {
                previous->setright(newadd);
            }       //end of else statement
        }           // end of 1 st if statement
        else        //root=0
        {
            root=newadd;
        }       //end of else statement
    }
    else        //newadd=0
    {
        cout<<"\n There is no node to be added";
        result=false; 
    }       //end of else statement
    return result;
}       //end of main if statement

bool BinarySearchTree::print(Node* root)        //method for printing a node
{
    if(root!=0)
    {
        print(root->getleft());     //recursive print function call
        cout<<root->getvalue()<<"\t"<<flush;
        print(root->getright());
    }       //end of if statement
}

bool BinarySearchTree::print()
{
    print(root);        //calling the parameterized print method
}

int BinarySearchTree::user_input()
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
   n.setnext(& n1); //passing the address of the object n1 to setnext
   n.print();
   n1.print();
   
   //execution of the binary search tree
   BinarySearchTree b;      //object creation and constructor invoking
   b.user_input();
   /*b.add(56);
   b.add(63);
   b.add(45);
   b.add(98);*/
   cout<<"\n The elements in the Binary Search Tree are: ";
   b.print();
   return 0;
}
