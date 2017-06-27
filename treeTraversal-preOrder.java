/* Tree Traversals 
pre order - Root, left Subtree, right subtree
in order - Left subtree, root, right Subtree
post order - left subtree, right subtree, root
-----------------------------------------------*/
//implementing preOrder traversal - root, left subtree, right subtree

public class TreeNode{
	private int data;
	TreeNode left;
	TreeNode right;
	
	public TreeNode(int data){
		this.data = data;
	}
} 
//---------------------------------------------------------

//recursive solution
public void preOrder(TreeNode root){
	if(root != null){
		System.out.println(root.data);
	preOrder(root.left);
	preOrder(root.right);
	}
}

//iterative solution
public void preOrder (TreeNode root){
	if(root == null){
		return;
	}
	Stack stack = new Stack();
	stack.push(root);
	while(!stack.isEmpty()){
		TreeNode n = stack.pop();
		System.out.println(n.data);
		if(n.right!= null){
			stack.push(n.right);
		}
		if(n.left != null){
			stack.push(n.left);
		}
	}
}

//---------------------------------------------------------------------------------------
