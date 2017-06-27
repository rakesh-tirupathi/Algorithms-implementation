/*Implementation of queues using arrays - First in First out (FIFO)
inserted at tail and deleted at head*/

public class Queue{
	private int[] queue = new int[5];
	private int head = -1;
	private int tail = -1;
	private int no_of_elements = 0;
	
	public boolean isEmpty(){
		return no_of_elements == 0;
	}
	
	public boolean isFull(){
		return no_of_elements == queue.length;
	}
	
	public void enqueue(int data){
		if(isFull()){
			throw new RuntimeException("The queue is full");
		}
		if(tail == queue.length-1){
			tail=-1;
		}
		queue[++tail] = data;
		no_of_elements++;
	}
	
	public int dequeue(){
		if(isEmpty()){
			throw new RuntimeException("The queue is empty");
		}
		if(head==queue.length-1){
			head = -1;
		}
		no_of_elements--;
		return queue[++head];
	}
	
	public int peek(){
		if(isEmpty()){
			throw new RuntimeException("the queue is empty");
		}
		return queue[head+1];
	}
} 