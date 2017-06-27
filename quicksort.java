//implementation of quicksort

import java.util.Arrays;

public class quicksort{
	
	public void sort(int[] data){
		QuickSort(data, 0, data.length-1);
	}
	
	public void QuickSort(int[] data, int start, int end){
		if(start<end){
			int pivot = partition(data, start, end);
			QuickSort(data, start, pivot-1);
			QuickSort(data, pivot+1, end);
		}
	}
	
	public int partition(int[] data, int start, int end){
		int pivot = data[end];
		int i = start;
		for(int j = start; j<=end-1; j++){
			if(data[j] < pivot){
				int temp = data[i];
				data[i] = data[j];
				data[j] = temp;
				i++;
			}
		}
		data[end] = data[i];
		data[i] = pivot;
		return i;
	}
	
	public static void main(String[] args){
		quicksort quick = new quicksort();
		int[] data = {9, 12, 95, 25, 78,30};
		quick.sort(data);
		System.out.println(Arrays.toString(data));
	}
}