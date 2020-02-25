public class AVL {
    
    public static class Node {
        int data = 0;
        int bal = 0;
        int height = -1;
        Node left = null;
        Node right = null;

        public Node () {

        }
        
        public Node(int data) {
            this.data = data;
        }

        public Node(int data, Node left, Node right) {
            this.left = left;
            this.right = right;
            this.data = data;
        }

        @Override
        public String toString() {
            String str = "";
            str += ((left != null ? left.data : " . "));
            str += (" -> " + data + " <- ");
            str += ((right != null ? right.data : " . "));
            str += "\n";

            if (left != null) {
                str += left.toString();
            }

            if (right != null) {
                str += right.toString();    
            }
            return str;
        }
    }

    /* public static Node constructBST(int[] arr, int si, int ei) {
        if (si > ei) {
            return null;
        }
        int mid = ((si + ei) >> 1);
        Node node = new Node(arr[mid]);
        node.left = constructBST(arr, si, mid - 1);
        node.right = constructBST(arr, mid + 1, ei);
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
    } */

    // or we can do 
    // construct and display together

    public static void display(Node node) {
        if (node == null) {
            return;
        }

        String ans = "";
        ans += (node.left != null) ? node.left.data : " . ";
        ans += " => " + node.data + "(" + node.bal + ")" + " <= ";
        ans += (node.right != null) ? node.right.data : " . ";
        System.out.println(ans);

        display(node.left);
        display(node.right);
    }

    public static void updateHeightAndBalanceFactor(Node node) {
        int rh = -1;
        int lh = -1;

        if (node.left != null) {
            lh = node.left.height;
        }

        if (node.right != null) {
            rh = node.right.height;
        }

        node.height = Math.max(lh, rh) + 1;
        node.bal = (lh - rh);
    }

    public static Node leftRotation(Node x) { // ll
        Node y = x.left;
        Node yright = y.right;

        y.right = x;
        x.left = yright;

        updateHeightAndBalanceFactor(x);
        updateHeightAndBalanceFactor(y);

        return y;
    }

    public static Node rightRotation(Node x) { // rr
        Node y = x.right;
        Node yleft = y.left;

        y.left = x;
        x.right = yleft;

        updateHeightAndBalanceFactor(x);
        updateHeightAndBalanceFactor(y);

        return y;
    }

    public static Node rotation(Node node) {
        updateHeightAndBalanceFactor(node);
        if (node.bal == 2) {
            if (node.left.bal == 1) {
                return leftRotation(node);
            }
            else  {
                node.left = rightRotation(node.left);
                return leftRotation(node);
            }
        }

        else if (node.bal == -2) {
            if (node.right.bal == -1) {
                return rightRotation(node);
            }

            else {
                node.right = leftRotation(node.right);
                return rightRotation(node);
            }
        }
        return node;
    }

    public static int maxInTree(Node node) {
        if (node == null) {
            return Integer.MIN_VALUE;
        }

        Node rnode = node;
        while (rnode.right != null) {
            rnode = node.right;
        }
        return rnode.data;
    }
    
    public static Node addData(Node node, int data) {
        if (node == null) {
            return new Node(data);
        }

        if (data < node.data)
            node.left = addData(node.left, data);

        else
            node.right = addData(node.right, data);

         // update everything to correct
        node = rotation(node); // call rotation before returning
        return node;
    }

    public static Node deleteNode(Node node, int data) {
        if (node == null) {
            return null;
        }

        if (node.data == data) {
            if (node.left == null || node.right == null) {
                return (node.left == null ? node.right : node.left);
            }

            int max_ = maxInTree(node.left);
            node.data = max_;
            node.left = deleteNode(node.left, max_);
        }
        
        else if (data < node.data) {
            node.left = deleteNode(node.left, data);
        }
        
        else {
            node.right = deleteNode(node.right, data);
        }

        // first update everything to correct
        node = rotation(node); // call rotation before returning
        return node;
    }

    public static void AVL_() {
        // Node root = constructBST(arr, 0, arr.length - 1);
        Node root = null;

        // int[] arr = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
        for (int i = 1; i <= 10; i++) {
            root = addData(root, i * 10);
        }

        display(root);
        System.out.println();
        // System.out.println(height(root));
        // System.out.println(size(root));
        // System.out.println(find_01(root, 40)); //recursively
        // System.out.println(find_02(root, 300)); //iteratively
        // addDate(root, 200);
        // display(root);
        // System.out.println();
        // System.out.println(maxInTree(root));
        // System.out.println(minInTree(root));
        deleteNode(root, 50);
        display(root);
        // display(root);

        // System.out.println(rotation(root).data);
    }

    public static void main(String[] args) {
        AVL_();
    }
}
