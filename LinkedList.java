//implementation of singly linked list - has only head element as reference

class Node{
	private int data;
	private Node nextNode;
	
	public Node(int data){
		this.data = data;
	}
	
	public int getData(){
		return this.data;
	}
	
	public void setData(int data){
		this.data = data;
	}
	
	public Node getNextNode(){
		return this.nextNode;
	}
	
	public void setNextNode(Node nextNode){
		this.nextNode = nextNode;
	}
	
	@Override
	public String toString(){
		return "Data: " + this.data;
	} 
}
//--------------------------------------------------------------------------------------------------------
class LinkedList{
	
	private Node head;
	
	public void addAtHead(int data){
		Node newNode = new Node(data);
		newNode.setNextNode(this.head);
		this.head = newNode;
	}
	
	public void insert(int data){
		if(this.head == null || this.head.getData().compareTo(data) > 0 ){
			newNode.setNextNode(this.head);
			this.head = newNode;
			return;
		}
		Node current = this.head;
		while(current != null && current.getNextNode != null && current.getNextNode.getData.compareTo(data) < 0){
			current = current.getNextNode();
		}
		newNode.setNextNode(current.getNextNode());
		current.setNextNode(newNode);
	}
	
	public void deleteAtHead(){
		this.head = this.head.getNextNode();
	}
	
	public void delete(int data){
		Node current = this.head;
		if(this.head == null){
			return;
		}
		while(current != null && current.getNextNode != null){
			if(current.getNextNode.getData == data){
				current.setNextNode(current.getNextNode().getNextNode());
				return;
			}
		}
		return null;
	}
	
	public Node find(int data){
		Node currentNode = this.head;
		while(currentNode != null){
			if(currentNode.data == data){
				return currentNode;
			}
			currentNode = currentNode.getNextNode();
		}
		return null;
	}
	
	public int length(){
		Node currentNode = this.head;
		int count = 0;
		while(currentNode != null){
			count++;
			currentNode = currentNode.getNextNode();
		}
		return count;
	}
	
	@Override
	public String toString(){
		String result = "{";
		Node current = this.head;
		while(current != null){
			result = result + current.toString() + ",";
		}
		result = result + "}";
		return result;
	}
}
//-----------------------------------------------------------------------------------------------------------------
class LinkedListDemo{
	public static void main(String[] args){
		LinkedList list = new LinkedList();
		list.addAtHead(10);
		System.out.println(list);
	}
}

//------------------------------------------------------------------------------------------------------------------------



