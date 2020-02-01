public class isBST {
    public static class Node{
        int data = 0;
        Node left = null;
        Node right = null;

        Node(int data, Node left, Node right)
        {
            this.data = 0;
            this.right = right;
            this.left = left;
        }
    }
    
    static Node root = null;

    private static void isBST(int[] arr) {
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

    public static class Node2 {
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        boolean isBST = true;
        int countBST = 0;
    }

    public static Node2 isBST(Node node) {
        if (node == null)
            return new Node2();

        // here we should work in post order

        Node2 left = isBST(node.left);
        Node2 right = isBST(node.right);

        Node2 mypair = new Node2();
        mypair.isBST = false;
        if (left.isBST && right.isBST && right.min >= node.data && left.max <= node.data) {
            mypair.isBST = true;
            mypair.countBST = 1;
        }

        mypair.min = Math.min(node.data, Math.min(left.max, right.max));
        mypair.max = Math.max(node.data, Math.max(left.max, right.max));

        mypair.countBST += left.countBST + right.countBST ;

        return mypair;
    }

    public static void main(String[] args) {
        int[] arr = {10,
        20,40,80,-1,-1,90,-1,-1,50,100,-1,-1,-1,30,60,-1,110,-1,-1,70,120,-1,-1,-1};
        // int[] arr = { 10, 20, 40, -1, -1, 50, -1, -1, 30, 60, 1110, 1120, -1, 1130, -1, -1, -1, -1, 70, 80, -1, -1, 90,
        //     100, -1, 110, -1, -1, -1 };
        // int[] arr = {50,30,10,-1,20,-1,-1,40,-1,-1,80,70,60,-1,-1,-1,90};
        root = constructor(arr);
        System.out.println(isBST(root).countBST);
    }
}