public class isBST {
    public static class Node {
        int data = 0;
        Node left = null;
        Node right = null;

        Node() {
            this.data = 0;
        }

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

    public static void isBST(int[] arr) {
        root = constructor(arr);
    }

    static int idx = 0;

    public static Node constructor(int[] arr) {
        if (idx >= arr.length || arr[idx] == -1) {
            idx++;
            return null;
        }
        Node node = new Node(arr[idx]);
        idx++;
        node.left = constructor(arr);
        node.right = constructor(arr);

        return node;
    }

    static int prev = Integer.MIN_VALUE;

    public static boolean checkBST_inOrder(Node node) {
        if (node == null)
            return true;

        boolean left = checkBST_inOrder(node.left);
        if (!left)
            return false;

        if (prev <= node.data)
            prev = node.data;
        else
            return false;

        boolean right = checkBST_inOrder(node.right);
        if (!right)
            return false;

        return true;
    }

    public static void main(String[] args) {
        int[] arr = { 50, 25, 20, 10, -1, -1, -1, 37, 32, -1, -1, 40, -1, -1, 75, 65, 60, -1, -1, -1, 85, -1, -1 };
        isBST(arr);
        System.out.println(checkBST_inOrder(root));
    }
}