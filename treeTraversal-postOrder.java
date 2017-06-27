//implementing postorder traversal - left subtree, right subtree, root

public class TreeNode{
	private int data;
	private TreeNode left;
	private TreeNode right;
	
	public TreeNode(int data){
		this.data = data;
	}
}
//------------------------------------------------------------------------

//recursive approach
public void postOrder(TreeNode root){
	if(root != null){
		postOrder(root.left);
		postOrder(root.right);
		System.out.println(root.data);
	}	
}

//iterative approach
public void postOrder(TreeNode root){
	if(root == null){
		return;
	}
	Stack stack = new Stack();
	TreeNode current = root;
	while(true){
		if(current != null){
			if(current.right!=null){
				stack.push(current.right);
			}
			stack.push(current);
			current = current.left;
			continue;
		}
		
		if(s.isEmpty()){
			return;
		}
		current = stack.pop();
		if(current.right!=null && !s.isEmpty() && current.right==stack.peek()){
			stack.pop();
			stack.push(current);
			current = current.right;
		}else{
			System.out.println(current.data);
			current = null;
		}
	}
	
	
}