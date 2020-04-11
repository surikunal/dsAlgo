public class PrePostIn {

    public static class Node {
        int data = 0;
        Node left = null;
        Node right = null;

        Node() {
            this.data = 0;
            this.left = null;
            this.right = null;
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

    private static void PrePostIn(int[] arr) {
        root = constructor(arr);
    }

    static int idx = 0;

    public static Node constructor(int[] arr) {
        if (idx >= arr.length || arr[idx] == -1) {
            idx++;
            return null;
        }
        Node node = new Node(arr[idx], null, null);
        idx++;
        node.left = constructor(arr);
        node.right = constructor(arr);

        return node;
    }

    public static void display(Node node) {
        if (node == null) {
            return;
        }
        StringBuilder sb = new StringBuilder();
        sb.append(node.left == null ? " . " : node.left.data);
        sb.append("=>" + node.data + "<=");
        sb.append(node.right == null ? " . " : node.right.data);
        System.out.println(sb.toString());

        display(node.left);
        display(node.right);
    }

    public static int height(Node node) {
        if (node == null) {
            return 0;
        }
        return Math.max(height(node.left), height(node.right)) + 1;
    }

    public static int size(Node node) {
        if (node == null)
            return 0;

        return size(node.left) + size(node.right) + 1;
    }

    public static void pre(Node node) {
        if (node == null)
            return;

        System.out.print(node.data + " ");
        pre(node.left);
        pre(node.right);
    }

    public static void post(Node node) {
        if (node == null)
            return;

        pre(node.left);
        pre(node.right);
        System.out.print(node.data + " ");
    }

    public static void in(Node node) {
        if (node == null)
            return;

        pre(node.left);
        System.out.print(node.data + " ");
        pre(node.right);
    }

    public static void main(String[] args) {
        int[] arr = { 10, 20, 40, 80, -1, -1, 90, -1, -1, 50, 100, -1, -1, -1, 30, 60, -1, 110, -1, -1, 70, 120, -1, -1,
                -1 };
        PrePostIn(arr);
        System.out.println(height(root));
        System.out.println(size(root));
        display(root);
        pre(root);
        System.out.println();
        in(root);
        System.out.println();
        post(root);
    }
}