

public class AVL {
    public static class Node {
        private int data = 0;
        private int height = -1;
        private int balance = 0;
        private Node left = null;
        private Node right = null;

        // Node() {
        // this.data = 0;
        // this.height = 0;
        // this.balance = 0;
        // this.right = null;
        // this.left = null;
        // }

        Node(int data) {
            this.data = data;
        }

        Node(int data, Node left, Node right, int height, int balance) {
            this.data = data;
            this.height = height;
            this.balance = balance;
            this.right = right;
            this.left = left;
        }
    }

    Node root = null;

    // public AVL(int[] arr) {
    // root = constructor(arr);
    // }

    // private static int idx = 0;

    public static Node constructor(int[] arr, int si, int ei) {
        if (si > ei) {
            return null;
        }
        if (si == ei) {
            Node node = new Node(arr[si]);
            return node;
        }
        // int mid = ((si + ei) >> 1);
        int mid = (si + ei) / 2;

        Node node = new Node(arr[mid]);

        node.left = constructor(arr, si, mid - 1);
        node.right = constructor(arr, mid + 1, ei);

        node.height = getHeight(node);
        // so that we also get the height
        node.balance = getBalance(node);
        // so that we also get the balance

        // or we can also do
        // getFactors(node);
        return node;
    }

    public static void display(Node node) {
        if (node == null) {
            return;
        }

        StringBuilder sb = new StringBuilder(); // JUST LIKE VECTOR

        sb.append(node.left != null ? node.left.data : " . ");
        sb.append("->" + node.data + "(" + node.balance + ")" + "<-");
        sb.append(node.right != null ? node.right.data : " . ");
        System.out.println(sb.toString());
        display(node.left);
        display(node.right);
    }

    public static int getHeight(Node node) {
        if (node == null) {
            return -1;
        }
        int lh = -1;
        int rh = -1;

        if (node.left != null)
            lh = node.left.height;
        if (node.right != null)
            rh = node.right.height;

        return Math.max(lh, rh) + 1;
    }

    public static int getBalance(Node node) {
        if (node == null) {
            return 0;
        }
        int lh = -1;
        int rh = -1;

        if (node.left != null)
            lh = node.left.height;
        if (node.right != null)
            rh = node.right.height;

        return (lh - rh);         //dont do right - left , then rotations will change
    }

    public static void updateFactors(Node node) {
        node.height = getHeight(node);
        node.balance = getBalance(node);
    }

    public static Node leftRotation(Node node) {
        Node n = node.right;
        Node a = n.left;

        n.left = node;
        node.right = a;

        updateFactors(node);
        updateFactors(n);

        return n;
    }

    public static Node rightRotation(Node node) {
        Node n = node.left;
        Node a = n.right;

        n.right = node;
        node.left = a;

        updateFactors(node);      // this must be updated first 
        updateFactors(n);

        return n;
    }

    public static Node rotation(Node node)
    {
        if(getBalance(node) > 1)    //ll, lr
        {
            if(getBalance(node.left) > 0)   //ll
                node = rightRotation(node);

            else if (getBalance(node.left) < 0){         //lr
                node.left = leftRotation(node.left);
                node = rightRotation(node);
            }
        }
        else if(getBalance(node) < -1)  //rr, rl
        {
            if(getBalance(node.right) < 0)  //rr
                node = leftRotation(node);

            else if (getBalance(node.right) > 0) {                       
                node.right = rightRotation(node.right);
                node = leftRotation(node);
            }
        }
        return node;
    }
    //===============================================
    // AVL is till here
    // after this whatever we write , it is to make any tree avl
    public static Node addData(Node node, int data) {
        if (node == null) {
            Node base = new Node(data);
            updateFactors(base);
            return base;
        }

        if (node.data < data) {
            node.right = addData(node.right, data);
        }
        else {
            node.left = addData(node.left, data);
        }
        updateFactors(node);
        node = rotation(node);
        return node;
    }

    public static int maximum(Node node)
    {
        Node curr = node;
        while(curr.right != null)
        {
            curr = curr.right;
        }
        return curr.data;
    }

    public static Node deleteData(Node node, int data)
    {
        if(node == null)
        {
            return null;
        }
        if(node.data > data)
        {
            node.left = deleteData(node.left, data);
        }
        else if(node.data < data)
        {
            node.right = deleteData(node.right, data);
        }
        else{
            if(node.left == null || node.right == null)
            {
                Node n = node.left != null ? node.left : node.right;
                //here we dont need to do delete node 
                // this function will automatically be happen in java

                // if(n!=null){
                // updateFactors(n);
                // n= rotation(n);
                // }
                //node=null;
                //   System.out.print(node);
                return n;
            }

            int max_ = maximum(node.left);
            node.data = max_;
            node.left = deleteData(node.left, max_);
        }
        updateFactors(node);
        node = rotation(node);
        return node;
    }
    public static void main(String[] args) {
        int[] arr = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
        Node root = constructor(arr, 0, arr.length - 1);
        display(root);
        System.out.println();

        // rightRotation(root);
        // display(root);
        // leftRotation(root);
        // display(root);
        
        // addData(root, 42);
        // addData(root, 43);
        // display(root);
        // System.out.println();
        deleteData(root, 70);
        display(root);
    }
}   