public class BTree {
    private static class Node {
        private int data = 0;
        private Node left = null;
        private Node right = null;

        // Node()
        // {
        // this.data=0;
        // this.left=null;
        // this.right=null;
        // }

        Node(int data) {
            this.data = data;
        }

        Node(int data, Node left, Node right) {
            this.data = 0;
            this.left = left;
            this.right = right;
        }
    }

    static Node root = null;

    private static void BTree(int[] arr) {
        root = contruct(arr);
    }

    static int idx = 0;

    private static Node contruct(int[] arr) {
        if (idx >= arr.length || arr[idx] == -1) {
            idx++;
            return null;
        }

        Node node = new Node(arr[idx], null, null);
        idx++;
        node.left = contruct(arr);
        node.right = contruct(arr);
        return node;
    }
    public static void display(Node node) {
        if (node == null) {
            return;
        }

        StringBuilder sb = new StringBuilder();

        sb.append(node.left == null ? " . " : node.left.data);
        sb.append("->" + node.data + "<-");
        sb.append(node.right == null ? " . " : node.right.data);
        System.out.println(sb.toString());
        display(node.left);
        display(node.right);
    }
    public static void main(String[] args) {
        int[] arr = { 1, 2, 4, 11, -1, -1, 12, 13, 15, -1, -1, -1, 17, -1, -1, 5, -1, 8, 9, -1, 10, 14, 17, 18, -1, 19,
                -1, -1, -1, -1, 13, 14, -1, 15, 16, -1, -1, -1, -1, 3, 6, -1, 7, -1, -1, 7, 16, 18, -1, -1, 19, 20, -1,
                -1, 21, -1, -1, 17, -1, -1 };
        

    }

}