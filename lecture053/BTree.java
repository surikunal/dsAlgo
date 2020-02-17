import java.util.Scanner;
import java.util.ArrayList;

public class BTree {
    public static class Node {
        int data;
        Node left;
        Node right;

        public Node() {
            this(0, null, null);
        }

        public Node(int data) {
            this(data, null, null);
        }

        public Node(int data, Node left, Node right) {
            this.data = data;
            this.left = left;
            this.right = right;
        }

        @Override
        public String toString() {
            String str = "";
            str += ((left != null ? left.data : "."));
            str += (" -> " + data + " <- ");
            str += ((right != null ? right.data : "."));
            str += "\n";
            if (left != null)
                str += left.toString();
            if (right != null)
                str += right.toString();
            return str;
        }
    }

    private static int idx = 0;

    public static Node createTree(int[] arr) {
        if (idx >= arr.length || arr[idx] == -1) {
            idx++;
            return null;
        }
        Node node = new Node(arr[idx]);
        idx++;
        node.left = createTree(arr);
        node.right = createTree(arr);
        return node;
    }

    public static void display(Node node) {
        if (node == null)
            return;
        System.out.print((node.left != null ? node.left.data : "."));
        System.out.print(" -> " + node.data + " <- ");
        System.out.println((node.right != null ? node.right.data : "."));
        display(node.left); // display(2*idx+1);
        display(node.right); // display(2*idx+2);
    }

    // basic.============================

    public static int maximumInTree(Node node) {
        if (node == null)
            return (int) -1e8;

        int lmax = maximumInTree(node.left);
        int rmax = maximumInTree(node.right);
        int oMax = Math.max(lmax, rmax);

        return Math.max(node.data, oMax);
    }

    public static int minimumInTree(Node node) {
        if (node == null)
            return (int) 1e8;

        int lmin = minimumInTree(node.left);
        int rmin = minimumInTree(node.right);
        int oMin = Math.min(lmin, rmin);

        return Math.min(node.data, oMin);
    }

    public static boolean find(Node node, int data) {
        if (node == null)
            return false;
        if (node.data == data)
            return true;
        boolean res = false;
        res = res || find(node.left, data);
        res = res || find(node.right, data);
        return res;
    }

    public static int size(Node node) {
        if (node == null)
            return 0;
        return size(node.left) + size(node.right) + 1;

    }

    public static int height(Node node) {
        if (node == null)
            return -1;
        return Math.max(height(node.left), height(node.right)) + 1;

    }

    public static int diameter_01(Node node) {
        if (node == null) {
            return 0;
        }

        int ld = diameter_01(node.left);
        int rd = diameter_01(node.right);

        int lh = height(node.left);
        int rh = height(node.right);

        return Math.max(Math.max(ld, rd), lh + rh + 2);
    }

    public static int[] diameter_02_edges(Node node) {
        if (node == null) {
            return new int[] {0, -1};
        }

        int[] ld = diameter_02_edges(node.left);
        int[] rd = diameter_02_edges(node.right);
        
        int[] myAns = new int[2];
        myAns[0] = Math.max(Math.max(ld[0], rd[0]), ld[1] + rd[1] + 2);
        myAns[1] = Math.max(ld[1], rd[1]) + 1;

        return myAns;
    }

    public static int[] diameter_02_nodes(Node node) {
        if (node == null) {
            return new int[] {0, 0};
        }

        int[] ld = diameter_02_nodes(node.left);
        int[] rd = diameter_02_nodes(node.right);
        
        int[] myAns = new int[2];
        myAns[0] = Math.max(Math.max(ld[0], rd[0]), ld[1] + rd[1] + 1);
        myAns[1] = Math.max(ld[1], rd[1]) + 1;

        return myAns;
    }

    static int maxDia = 0;
    public static int diameter_03(Node node) {
        if (node == null) {
            return -1;
        }

        int lh = diameter_03(node.left);
        int rh = diameter_03(node.right);

        maxDia = Math.max(maxDia, lh + rh + 2);
        return Math.max(lh, rh) + 1;
    }

    static int maxSum = Integer.MIN_VALUE;
    public static int leafToLeafMaxSum(Node node) {
        if (node == null) {
            return Integer.MIN_VALUE;
        }

        if (node.left == null && node.right == null) {      //leaf node
            return node.data;
        }

        int lmaxSum = leafToLeafMaxSum(node.left);
        int rmaxSum = leafToLeafMaxSum(node.right);

        if (node.left != null && node.right != null) {
            maxSum = Math.max(maxSum, lmaxSum + rmaxSum + node.data);
        }

        return Math.max(lmaxSum, rmaxSum) + node.data;
    }

    static int maxSum1 = Integer.MIN_VALUE;
    public static int nodeToNodeMaxSum(Node node) {
        if (node == null) {
            return 0;
        }

        int lmaxSum1 = nodeToNodeMaxSum(node.left);
        int rmaxSum1 = nodeToNodeMaxSum(node.right);

        int maxBranch = Math.max(lmaxSum1, rmaxSum1);

        maxSum1 = Math.max(Math.max(maxSum1, node.data), Math.max(maxBranch + node.data, lmaxSum1 + rmaxSum1 + node.data));

        return Math.max(maxBranch + node.data, node.data);
    }

    static int cameras = 0;
    public static int minCameras_(Node node) {
        if (node == null) {
            return 0;
        }

        int left = minCameras_(node.left);
        int right = minCameras_(node.right);

        if (left == -1 || right == -1) {
            cameras++;
            return 1;
        }

        if (left == 1 || right == 1) {
            return 0;
        }

        return -1;
    }

    public static int minCameras(Node node) {
        int val = minCameras_(node);
        if (val == -1) {
            cameras++;
        }
        return cameras;
    }

    public static void solve() {
        // int[] tree1 = { 10, 20, 30, 40, -1, -1, 50, -1, -1, 60, -1, 70, -1, -1, 80, 90, 100, 120, -1, -1, 130, -1, -1,
        //         110, -1, -1, 140, -1, -1 };
        
        int[] arr = { 10, 20, 30, 40, -1, -1, 50, -1, -1, 60, -1, 70, -1, -1, 80, 90, 100, 120, -1, -1, 130, -1, -1, 110, -1, -1, 140, -1, -1};   
        Node root = createTree(arr);
        // System.out.println(root);
        // System.out.println(diameter_01(root));        
        // System.out.println(diameter_02_edges(root)[0]);   //for diameter     
        // System.out.println(diameter_02_nodes(root)[0]);   //for diameter     
        // diameter_03(root);   //for diameter

        // System.out.println(maxDia);
        
        // leafToLeafMaxSum(root);     // this function is not returning the answer we want
        // System.out.println(maxSum); // this is the real answer

        // nodeToNodeMaxSum(root);
        // System.out.println(maxSum1);

        System.out.println(minCameras(root));
    }

    public static void main(String[] args) {
        solve();
    }
}