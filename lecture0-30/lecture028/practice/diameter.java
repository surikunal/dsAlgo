public class diameter {
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

    public static void diameter(int[] arr) {
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

    public static int height(Node node) {
        if (node == null)
            return 0;

        int left = height(node.left);
        int right = height(node.right);

        return Math.max(left, right) + 1;
    }

    public static int diameter_01(Node node) {
        if (node == null)
            return 0;

        int lh = height(node.left);
        int rh = height(node.right);

        int left = diameter_01(node.left);
        int right = diameter_01(node.right);

        return Math.max(rh + lh + 1, Math.max(left, right));
    }

    public static class diaPair{
        int height = 0;
        int dia = 0;
    }
    public static diaPair diameter_02(Node node)
    {
        if(node == null)    return new diaPair();

        diaPair left = diameter_02(node.left);
        diaPair right = diameter_02(node.right);

        diaPair mypair = new diaPair();

        mypair.height = Math.max(left.height, right.height) + 1;
        mypair.dia = Math.max(Math.max(left.dia, right.dia), left.height + right.height + 1);

        return mypair;
    }
    public static void main(String[] args) {
        int[] arr = { 50, 30, 10, -1, 20, -1, -1, 40, -1, -1, 80, 70, 60, -1, -1, -1, 90 };
        diameter(arr);
        // System.out.println(diameter_01(root));
        // System.out.println(diameter_02(root).dia);
        // System.out.println(diameter_02(root).height);
    }
}