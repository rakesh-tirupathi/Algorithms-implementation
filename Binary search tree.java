//implementing a binary search tree

//writing the TreeNode class

public class TreeNode{
	
	private int data;
	private TreeNode left;
	private TreeNode right;
	private boolean isDeleted = false;
	
	/*creating getters and setters and a constructor*/
	public TreeNode(int data){
		this.data = data;
	}
	
	public int getData(){
		return this.data;
	}
	
	public TreeNode getLeft(){
		return this.left;
	}
	
	public TreeNode getRight(){
		return this.right;
	}
	
	public void setLeft(TreeNode left){
		this.left = left;
	}
	
	public void setRight(TreeNode right){
		this.right = right;
	}
	
	/*method to find the data recursively*/
	public int find(int data){
		if(this.data == data && !isDeleted){
			return this;
		}
		if(data<this.data && left!=null){
			return left.find(data);
		}
		if(right!=null){
			return right.find(data);
		}
		return null;
	}
	
	/*method to insert the data recursively*/
	public void insert(int data){
		if(data>=this.data){
			if(this.right==null){
				this.right = new TreeNode(data);
			}else{
				this.right.insert(data);
			}
		}else{
			if(this.left == null){
				this.left = new TreeNode(data);
			}else{
				this.left.insert(data);
			}
		}
	}
	
	/*soft deleting a node in a binary tree*/
		public void delete(){
			this.isDeleted = true;
		}
		
		public boolean isDeleted(){
			return isDeleted;
		}
		
	/*finding the smallest value in the tree*/
	public int smallest(){
		if(this.left == null){
			return this.data;
		}
		return this.left.smallest();
	}
	
	/*finding the largest value in the tree*/
	public int largest(){
		if(this.right == null){
			return this.data;
		}
		return this.right.largest();
	}
	
	
}

//------------------------------------------------------------------------------------------------------------------------
//Writing the binary search tree class

public class BinarySearchTree{
	TreeNode root;
	
	/*method to find a particular data*/
	public TreeNode find(int data){
		if(root!= null){
			return root.find(data);
		}
		return null;
	}
	
	/*method to insert a data into Binary Search Tree*/
	public void insert(int data){
		if(root == null){
			this.root = new TreeNode(data);
		}else{
			root.insert(data);
		}
	}
	
	/*method to delete the data iteratively*/
	/*public void delete(int data){
		TreeNode current = this.root;
		TreeNode parent = this.root;
		boolean isLeft = false;
		
		if(current == null){
			return;
		}
		
		while(current != null && current.getData()!= data){
			parent = current;
			if(data < current.getData()){
				current = current.getLeft();
				isLeft = true;
			}else{
				current = current.getRight();
				isLeft = false;
			}
		}
		
		if(current == null){
			return;
		}*/
		
		/*deleting the node with no children, that is deleting the leaf nodes*/
		/*if(current.getLeft() == null && current.getRight == null){
			if(current == root){
				root = null;
			}else{
				if(isLeft){
					parent.setLeft(null);
				}else{
					parent.setRight(null);
				}
			}
		}else if(current.getRight()==null){			//deleting a node having one child
			if(current == root){
				root = current.getLeft(); 
			}else if(isLeft){
				parent.setLeft(current.getLeft());
			}else{
				parent.setRight(current.getLeft());
			}
		}else if(current.getLeft()==null){
			if(current == root){
				root = current.getRight();
			}else if(isLeft){
				parent.setLeft(current.getRight());
			}else{
				parent.setRight(current.getRight());
			}
		}*/
		
		/*soft deleting a node in a Binary search tree*/
		public void delete (int data){
			TreeNode toDel = find(data);
			toDel.delete();
		}
		
		/*finding the smallest value in the binary tree*/
		public int smallest(){
			if(this.root != null){
				return root.smallest();
			}
			return null;
		}
		
		/*finding the largest value in the binary tree*/
		public int largest(){
			if(this.root != null){
				return root.largest();
			}
			return null;
		}
		
		
	}
}