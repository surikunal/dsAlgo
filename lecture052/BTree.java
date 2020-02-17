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

    public static Node LCA01(Node node, int data1, int data2) {

        ArrayList<Node> path1 = rootToNodePath(node, data1);
        ArrayList<Node> path2 = rootToNodePath(node, data2);

        // here checkpoint for "if any node is null" is not required due to AND in while loop

        Node ans = null;
        int i = path1.size() - 1;
        int j = path2.size() - 1;
        while (i >= 0 && j >= 0) {
            if (path1.get(i).data == path2.get(j).data) {
                ans = path1.get(i);
            }
            else {
                break;
            }
            i--;
            j--;
        }
        return ans;
    }

    // =====================================================
    // leetcode 863 
    // print all nodes at distance K from a given node

    public static void kDown(Node node, Node pnode, int level) {        // function to go down in tree form a node to the target
        if (node == null || node == pnode) {
            return;
        }

        if (level == 0) {
            System.out.print(node.data + " ");
        }

        kDown(node.left, pnode, level - 1);
        kDown(node.right, pnode, level - 1);
    }

    public static void kAway_01(Node node, int data, int k) {
        ArrayList<Node> list1 = rootToNodePath(node, data);
        Node pnode = null;

        for (int i = 0; i < list1.size(); i++) {
            kDown(list1.get(i), pnode, k - i);
            pnode = list1.get(i);
        }
    }

    public static int kAway_02(Node node, int data, int k) {
        if (node == null) {
            return -1;
        }

        if (node.data == data) {
            kDown(node, null, k);
            return 1;
        }

        int leftDis = kAway_02(node.left, data, k);
        if (leftDis != -1) {
            kDown(node, node.left, k - leftDis);
            return leftDis + 1;
        }

        int rightDis = kAway_02(node.right, data, k);
        if (rightDis != -1) {
            kDown(node, node.right, k - rightDis);
            return rightDis + 1;
        }

        return -1;
    }

    public static void displayNodeList(ArrayList<Node> arr)
    {
        for (Node n : arr)
        {
            System.out.print(n.data + " ");
        }
        System.out.println();
    }

    public static void solve() {
        // int[] tree1 = { 10, 20, 30, 40, -1, -1, 50, -1, -1, 60, -1, 70, -1, -1, 80, 90, 100, 120, -1, -1, 130, -1, -1,
        //         110, -1, -1, 140, -1, -1 };
        
        int[] arr = { 10, 20, 30, -1, -1, 40, 50, -1, -1, 60, -1, -1, 70, 80, 100, 101, 102, -1, -1, -1, -1,
            110, 140, 139, -1, 142, 146, -1, -1, -1, 141, 143, 147, -1, -1, 148, -1, -1, -1, -1, 90, 191, -1,
            -1, 180, 190, -1, -1, 200, -1, -1};
        Node root = createTree(arr);
        System.out.println(root);
        // displayNodeList(rootToNodePath(root, 100));
        // System.out.println(LCA01(root, 30, 40).data);

        // kAway_01(root, 110, 4);
        kAway_02(root, 110, 4);
    }

    public static void main(String[] args) {
        solve();
    }
}