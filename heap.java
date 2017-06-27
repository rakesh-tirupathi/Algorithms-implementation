//implementation of heaps

public class Heap{
	private int[] items;
	private int currentPostition = -1;
	
	public Heap(int size){
		this.items = new int[size];
	}
	
	public boolean isFull(){
		return currentPostition == items.length-1;
	}
	
	public void insert(int data){
		if(isFull()){
			throw new RuntimeException ("the heap is full");
		}
		this.items[++currentPostition] = data;
		fixup(currentPostition);
	}
	
	private void fixup(int index){
		int i = (index-1)/2;
		while(i>=0 && items[i] < items[index]){
			int temp = items[i];
			items[i] = items[index];
			items[index] = temp;
			index = i;
			i = (index-1)/2;
		}
	}
	
	public int deleteRoot(){
		int result = items[0];
		items[0] = items[currentPostition--];
		items[currentPostition+1] = null;
		fixdown(0,-1);
		return result;
	}
	
	private void fixdown(int index, int upto){
		if(upto < 0){
			upto = currentPostition;
		}
		while(index<=upto){
			int leftChild = (2*index)+1;
			int rightChild = (2*index)+2;

			if(leftChild <= upto){
				int childToSwap;
				if(rightChild>upto){
					childToSwap = leftChild;
				}else{
					childToSwap = (items[leftChild] > items[rightChild])? leftChild:rightChild;
				}
				
				if(items[index] < items[childToSwap]){
					int temp = items[index];
					items[index] = items[childToSwap];
					items[childToSwap] = temp;
				} else{
					break;
				}
				index = childToSwap;
			}else{
				break;
			}
		}
	}
}