	//implementation of merge sort

public class MergeSort{
	
	public void mergeSort(int[] data){
		mergeSorter(data, 0, data.length-1);
	}
	
	public void mergeSorter(int[] data, int start, int end){
		if(start<end){
			int middle = (int)Math.Floor((start+end)/2);
			mergeSorter(data, start, middle);
			mergeSorter(data, middle+1, end);
			merge(data, start, middle, end);
		}
	}
	
	public void merge(int[] data, int start, int middle, int end){
		int sizeOfLeftArray = middle-start+1;
		int sizeOfRightArray = end-middle;
		int[] left = new int[sizeOfLeftArray];
		int[] right = new int [sizeOfRightArray];
		for(int i=0; i<sizeOfLeftArray; i++){
			left[i] = data[start+i];
		}
		for(int j=0; j<sizeOfRightArray; j++){
			right[i] = data[middle+1+j];
		}
		
		int i=0; j=0;
		for(int k=start; k<=end; k++){
			if(j>=sizeOfRightArray || i<sizeOfLeftArray && left[i]<=right[j]){
				data[k]=left[i];
				i++;
			}else{
				data[k]=right[j];
				j++;
			}
		}
	}
}