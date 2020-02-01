
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

        // Node(int data)
        // {
        // this.data=data;
        // }

        Node(int data, Node left, Node right) {
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }

    static Node root = null;

    private static void BTree(int[] arr) {
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

    public void display() {
        display(root);
    }

    public static void display(Node node) {
        if (node == null) {
            return;
        }

        StringBuilder sb = new StringBuilder(); // JUST LIKE VECTOR

        sb.append(node.left != null ? node.left.data : " . ");
        sb.append("->" + node.data + "<-");
        sb.append(node.right != null ? node.right.data : " . ");
        System.out.println(sb.toString());
        display(node.left);
        display(node.right);
    }

    public static boolean find(Node node, int data) {
        if (node == null)
            return false;

        if (node.data == data)
            return true;

        return find(node.left, data) || find(node.right, data);
    }

    public static int max(Node node) {
        if (node == null)
            return Integer.MIN_VALUE;

        int maxn = node.data;
        int max1 = max(node.left);
        int max2 = max(node.right);

        return Math.max(maxn, Math.max(max1, max2));
    }

    public static int min(Node node) {
        if (node == null)
            return Integer.MAX_VALUE;

        int minn = node.data;
        int min1 = max(node.left);
        int min2 = max(node.right);

        return Math.min(minn, Math.min(min1, min2));
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

    public static boolean rootToNodePath_01(Node node, int data, ArrayList<Node> path) {
        if (node == null)
            return false;

        if (node.data == data) {
            path.add(node);
            return true;
        }

        if (rootToNodePath_01(node.left, data, path)) {
            path.add(node);
            return true;
        }

        if (rootToNodePath_01(node.right, data, path)) {
            path.add(node);
            return true;
        }
        return false;
    }

    public static void leafNodes(Node node) {
        if (node == null)
            return;

        if (node.left == null && node.right == null) {
            System.out.println(node.data + " ");
            return;
        }

        leafNodes(node.left);
        leafNodes(node.right);
    }

    public static void main(String[] args) {
        int[] arr = { 10, 20, 40, 80, -1, -1, 90, -1, -1, 50, 100, -1, -1, -1, 30, 60, -1, 110, -1, -1, 70, 120, -1, -1,
                -1 };
        BTree(arr);
        // System.out.println(find(root, 50));

        // System.out.println(max(root));

        // System.out.println(min(root));

        // ArrayList<Node> ans = new ArrayList<>();
        // ans = rootToNodePath(root, 110);
        // Collections.reverse(ans);
        // for(Node node : ans)
        // {
        // System.out.println(node.data + " ");
        // }

        // ArrayList<Node> ans = new ArrayList<>();
        // rootToNodePath_01(root, 110, ans);
        // Collections.reverse(ans);
        // for(Node node : ans)
        // {
        // System.out.println(node.data + " ");
        // }

        leafNodes(root);
    }
}
