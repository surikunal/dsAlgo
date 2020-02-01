public class addDelLeaf {
    public static class Node {
        int data = 0;
        Node left = null;
        Node right = null;
        Node(int data)
        {
            this.data = data;
        }
        Node(int data, Node right, Node left) {
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }

    static Node root = null;

    public static void addDelLeaf(int[] arr) {
        root = construct(arr);
    }

    static int idx = 0;

    public static Node construct(int[] arr) {
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

    public static void display(Node node) {
        if (node == null)
            return;

        StringBuilder sb = new StringBuilder();

        sb.append(node.left != null ? node.left.data : " . ");
        sb.append("=>" + node.data + "<=");
        sb.append(node.right != null ? node.right.data : " . ");
        System.out.println(sb.toString());
        display(node.left);
        display(node.right);
    }

    public static void deleteLeaf_01(Node node, int leaf) {
        if (node == null)
            return;

        if (node.left != null && node.left.data == leaf)
            node.left = null;
        if (node.right != null && node.right.data == leaf)
            node.right = null;

        deleteLeaf_01(node.left, leaf);
        deleteLeaf_01(node.right, leaf);
    }

    public static Node deleteLeaf_02(Node node, int leaf) {
        if (node == null)
            return null;

        if (node.left == null && node.right == null && node.data == leaf)
            return null;

        node.left = deleteLeaf_02(node.left, leaf);
        node.right = deleteLeaf_02(node.right, leaf);

        return node;
    }
    public static void addLeaf(Node node, int par, int leaf, boolean isLeft)
    {
        if(node == null)    return;

        if(node.data == par)
        {
            if(isLeft)  node.left = new Node(leaf);
            else        node.right = new Node(leaf);
        }
        addLeaf(node.left, par, leaf, isLeft);
        addLeaf(node.right, par, leaf, isLeft);
        }
    public static void main(String[] args) {
        int[] arr = { 50, 30, 10, -1, 20, -1, -1, 40, -1, -1, 80, 70, 60, -1, -1, -1, 90 };
        addDelLeaf(arr);
        display(root);
        System.out.println();
        // deleteLeaf_01(root, 40);
        // deleteLeaf_02(root, 40);
        addLeaf(root, 90, 1000, true);
        display(root);
    }
}