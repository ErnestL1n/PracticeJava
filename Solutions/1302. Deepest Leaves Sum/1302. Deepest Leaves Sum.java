/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//reference:https://leetcode.com/gthor10/
//Leetcode.1302
class TreeNode{
	int value;
	TreeNode leftchild;
	TreeNode rightchild;
	TreeNode(){};
	TreeNode(int value){this.value=value;};
	TreeNode(TreeNode leftchild,TreeNode rightchild,int value){
		this.leftchild=leftchild;
		this.rightchild=rightchild;
		this.value=value;
	}
}

public class Deepest_Leaves_Sum {
	
	private static int sum=0,maxlevel=0;
	
	//given Integer[] to build tree
	public static TreeNode BuildTree(Integer[] nodes) {
		if(nodes==null||nodes.length==0)return null;
		Queue<TreeNode> TreeNodeQueue=new LinkedList<>();
		Queue<Integer> IntegerQueue= new LinkedList<>();
		for(int i=1;i<nodes.length;i++)IntegerQueue.offer(nodes[i]);
		
		TreeNode root=new TreeNode(nodes[0]);
		TreeNodeQueue.offer(root);
		System.out.println("I am root ,value is "+root.value);
		while(!IntegerQueue.isEmpty()) {
			Integer leftvalue=IntegerQueue.isEmpty()?null:IntegerQueue.poll();
			Integer rightvalue=IntegerQueue.isEmpty()?null:IntegerQueue.poll();
			TreeNode current=TreeNodeQueue.poll();
			if(leftvalue!=null) {
				TreeNode left=new TreeNode(leftvalue);
				current.leftchild=left;
				TreeNodeQueue.offer(left);
				System.out.println("I am leftchild  of value "+current.value+" , my value is "+left.value);
			}
			if(rightvalue!=null) {
				TreeNode right=new TreeNode(rightvalue);
				current.rightchild=right;
				TreeNodeQueue.offer(right);
				System.out.println("I am rightchild of value "+current.value+" , my value is "+right.value);
			}
			
		}
		return root;
		
	}
	public static int deepestLeavesSum(TreeNode root) {
        getsum(root,0);
        return sum;
    }
	public static void getsum(TreeNode node,int level) {
		if(node==null) return;
		
		//if this is the leave node,root level begins at 1
		if(node.leftchild==null&&node.rightchild==null&&level>=maxlevel) {
			// ">" case =>new deepest, start over with the sum
			if(level>maxlevel) {
				sum=node.value;
				maxlevel=level;
			}
			// "=" case =>same as current deepest - accumulate this node value
			else {
				sum+=node.value;
			}
		}
		
		//recursively compute left and right
		
		getsum(node.leftchild,level+1);
		getsum(node.rightchild,level+1);
	}
	

	/**
	 * @param args
	 */
	
	public static void main(String[] args) {
		Integer[] nodes=new Integer[] {1,2,3,4,5,null,6,7,null,null,null,null,8};
		System.out.println("Input nodes = "+Arrays.toString(nodes)+"\n");
		System.out.println("\nDeepestLeavesSum is "+deepestLeavesSum(BuildTree(nodes)));
		

	}

}





//implemented by queue(BFS)
class Solution {
    public int deepestLeavesSum(TreeNode root) {
        int res=0,i;
        Queue<TreeNode> q=new LinkedList<>();
        q.offer(root);
        while(q.size()>0){
            res=0;
            for (i=q.size()-1;i>=0;--i){
                var node=q.poll();
                res+=node.val;
                if(node.left!=null)
                    q.offer(node.left);
                if(node.right!=null)
                    q.offer(node.right);
            }
        }     
        return res;
    }
}