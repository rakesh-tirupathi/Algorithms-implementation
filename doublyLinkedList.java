//implementation of doubly linked list

class doubleNode {
	private int data;
	private doubleNode next;
	private doubleNode previous;
	
	public doubleNode(int data){
		this.data = data;
	}
	
	public int getData(){
		return this.data;
	}
	
	public void setData(int data){
		this.data = data;
	}
	
	public doubleNode getNext(){
		return this.next;
	}
	
	public void setNext(doubleNode next){
		this.next = next;
	}
	
	public doubleNode getPrevious(){
		return this.previous;
	}
	
	public void setPrevious(doubleNode previous){
		this.previous = previous;
	}
	
	@Override
	public String toString(){
		return "Data: " + this.data;
	}
}
//-------------------------------------------------------------------------------------------------------------------

class doublyLinkedList {
	doubleNode head;
	
	public void insertAtHead(int data){
		doublyLinkedList newNode = new doublyLinkedList(data);
		newNode.setNext(this.head);
		if(this.head != null){
			this.head.setPrevious(newNode);
		}
		this.head = newNode;
	}
	
	public int length(){
		int count = 0;
		doubleNode current = this.head;
		while(current!=null){
			count++;
			current = current.getNext();
		}
		return count;
	}
}
-----------------------------------------------------------------------------------------------------------------------------