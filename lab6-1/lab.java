import java.util.Scanner;

class MyNode {
	public int data;
	public MyNode left, right;
}

public class lab {
	static MyNode addNode(MyNode root, int data) {
		if( root == null ) {
			MyNode node = new MyNode();
			node.data = data;
			node.left = null;
			node.right = null;
			return node;
		}
		if(data < root.data) root.left = addNode(root.left, data);
		else root.right = addNode(root.right, data);
		return root;
	}
	static boolean searchNode(MyNode root, int data) {
		if(root == null) return false;
		if(data == root.data) return true;
		if(data < root.data) return searchNode(root.left, data);
		return searchNode(root.right, data);
	}
	static MyNode removeNode(MyNode root, int data) {
		if(root == null) return null;
		if(data < root.data) {
			root.left = removeNode(root.left, data);
			return root;
		}
		if(data > root.data) {
			root.right = removeNode(root.right, data);
			return root;
		}
		if(root.left == null && root.right == null) return null;
		if(root.left == null) return root.right;
		if(root.right == null) return root.left;
		MyNode tmp = root.right, p = null;
		while(tmp.left != null) {
			p = tmp;
			tmp = p.left;
		}
		if(p == null) root.right = tmp.right;
		else p.left = tmp.right;
		root.data = tmp.data;
		return root;
	}
	public static void main(String[] args) {
		MyNode root = null;

		Scanner scan = new Scanner(System.in);
		while(true) {
			String cmd = scan.next();
			if(cmd.charAt(0) == 'q') break;
			int data = scan.nextInt();
			if(cmd.charAt(0) == 'a') root = addNode(root, data);
			else if(cmd.charAt(0) == 's') System.out.println(searchNode(root, data));
			else if(cmd.charAt(0) == 'd') root = removeNode(root, data);
		}
	}
}
