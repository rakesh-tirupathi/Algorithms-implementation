/*implementation of Doubly ended lists - it is nothing but a singly linked list 
with two ends that is a head and a tail*/

class Node{
	private int data;
	private Node next;
	
	public Node(int data){
		this.data = data;
	}
	
	public int getdata(){
		return this.data;
	}
	
	public void setdata(int data){
		this.data = data;
	}
	
	public Node getNext(){
		return this.next;
	}
	
	public void setNext(Node next){
		this.next = next;
	}
	
	@Override
	public String toString(){
		return "Data: " + this.data;
	}
}
//----------------------------------------------------------------------------------------------------------
public class DoubleEndedList{
	
	private Node head;
	private Node tail;
	
	public void insertAtHead(int data){
		Node newnode = new Node(data);
		newnode.setNext(this.head);
		this.head = newnode;
	}
	
	public void inserAtTail(int data){
		Node newnode = new Node(data);
		if(this.head == null){
			this.head = newnode;
		}
		if(this.tail != null){
			this.tail.setNext(newnode);
		}
		this.tail = newnode;
	}
	
	@Override
	public String toString(){
		String result = "{";
		Node current = this.head;
		while(current != null){
			result = result + current.toString() + ",";
			current = current.next();
		}
		result = result + "}";
		return result;
	}
	
}