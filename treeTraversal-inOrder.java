//implementing inorder traversal - left subtree, root, right subtree

public class TreeNode{
	private int data;
	TreeNode left;
	TreeNode right;
	
	public TreeNode(int data){
		this.data = data;
	}
}
//-------------------------------------------------------------

//recursive approach
public void inOrder(TreeNode root){
	if(root != null){
		inorder(root.left);
		System.out.println(root.data);
		inorder(root.right);
	}
}

//iterative solution
public void inOrder(TreeNode root){
	if(root == null){
		return;
	}
	
	Stack stack = new Stack();
	TreeNode current = root;
	while(!stack.isEmpty() || current != null){
		if(current != null){
			stack.push(current);
			current = current.left;
		}else{
			TreeNode n = stack.pop();
			System.out.println(n.data);
			current = n.right;
		}
	}
}



