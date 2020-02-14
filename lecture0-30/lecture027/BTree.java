
// import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collections;

// import jdk.nashorn.internal.runtime.arrays.ArrayLikeIterator;

public class BTree {

    private static class Node {
        private int data = 0;
        private Node left = null;
        private Node right = null;

        // Node()
        // {
        // this.data = 0;
        // this.right=null;
        // this.left=null;
        // }

        Node(int data) {
            this.data = data;
        }

        Node(int data, Node left, Node right) {
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }

    static Node root = null;

    private static void BTree_(int[] arr) {
        root = construct(arr);
    }

    static int idx = 0;

    private static Node construct(int[] arr) {
        if (idx >= arr.length || arr[idx] == -1) {
            idx++;
            return null;
        }

        Node node = new Node(arr[idx], null, null);
        idx++;
        node.left = construct(arr);
        node.right = construct(arr);

        return node;
    }

    public static ArrayList<Node> rootToNodePath(Node node, int data) {
        if (node == null)
            return null;

        if (node.data == data) {
            ArrayList<Node> base = new ArrayList<>();
            base.add(node);
            return base;
        }

        ArrayList<Node> leftAns = rootToNodePath(node.left, data);
        if (leftAns != null) {
            leftAns.add(node);
            return leftAns;
        }

        ArrayList<Node> rightAns = rootToNodePath(node.right, data);
        if (rightAns != null) {
            rightAns.add(node);
            return rightAns;
        }
        return null;
    }

    public static Node commonAncestor_1(Node node, int data1, int data2) {
        ArrayList<Node> path1 = rootToNodePath(root, data1);
        ArrayList<Node> path2 = rootToNodePath(root, data2);

        if (path1 == null || path2 == null) {
            return null;
        }
        Node ans = null;
        int i = path1.size() - 1;
        int j = path2.size() - 1;
        while (i >= 0 && j >= 0) {
            if (path1.get(i).data == path2.get(j).data) {
                ans = path1.get(i);
            } else {
                break;
            }
            i--;
            j--;
        }
        return ans;
    }

    static Node LCA = null;

    public static boolean commonAncestor_2(Node node, int data1, int data2) {
        if (node == null)
            return false;

        boolean selfDone = node.data == data1 || node.data == data2;

        boolean left = commonAncestor_2(node.left, data1, data2);
        boolean right = commonAncestor_2(node.right, data1, data2);

        if ((left && right) || (left && selfDone) || (right && selfDone)) {
            LCA = node;
        }
        return left || right || selfDone;
    }

    public static class pair {
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        boolean isBst = true;
        int countBst = 0;
    }

    public static pair BST(Node node) {
        if (node == null)
            return new pair();

        pair left = BST(node.left);
        pair right = BST(node.right);
        pair mypair = new pair();
        mypair.isBst = false;

        if (left.isBst && right.isBst && left.max <= node.data && right.min >= node.data) {
            mypair.isBst = true;
            mypair.countBst = 1;
        }

        mypair.min = Math.min(node.data, Math.min(left.min, right.min));
        mypair.max = Math.max(node.data, Math.max(left.max, right.max));
        mypair.countBst += left.countBst + right.countBst;

        return mypair;
    }

    public static void main(String[] args) {
        // int[] arr = {10,
        // 20,40,80,-1,-1,90,-1,-1,50,100,-1,-1,-1,30,60,-1,110,-1,-1,70,120,-1,-1,-1};
        // int[] arr = { 10, 20, 40, -1, -1, 50, -1, -1, 30, 60, 1110, 1120, -1, 1130, -1, -1, -1, -1, 70, 80, -1, -1, 90,
        //         100, -1, 110, -1, -1, -1 };
        int[] arr = {50,30,10,-1,20,-1,-1,40,-1,-1,80,70,60,-1,-1,-1,90};
        BTree_(arr);
        // System.out.println(commonAncestor_1(root, 60, 70).data);

        // System.out.println(commonAncestor_2(root, 60, 70));
        // if (commonAncestor_2(root, 60, 70)) {
        //     System.out.println(LCA.data);
        // }

        System.out.println(BST(root).countBst);
        System.out.println(BST(root).isBst);
        System.out.println(BST(root).min);
        System.out.println(BST(root).max);
    }
}