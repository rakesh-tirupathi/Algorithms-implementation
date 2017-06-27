//level order traversal - in this traversal the tree is traversed by each level

public class TreeNode{
	private int data;
	private TreeNode left;
	private TreeNode right;
	
	public TreeNode(int data){
		this.data = data;
	}
}
//-----------------------------------------------------------------------------------

public void levelOrderTraversal(TreeNode root){
	if(root == null){
		return;
	}
	Queue queue = new LinkedList();
	queue.add(root);
	
	while(!queue.isEmpty()){
		TreeNode node = queue.poll();
		System.out.println(node.data);
		if(node.left!=null){
			queue.add(node.left);
		}
		if(node.right!=null){
			queue.add(node.right);
		}
	}
}
