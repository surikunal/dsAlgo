public class AVL {

    public static class Node {
        int data = 0;
        Node left = null;
        Node right = null;
        int height = -1;
        int bal = 0;

        Node(int data) {
            this.data = data;
        }

        Node(int data, int height, int bal, Node left, Node right) {
            this.data = data;
            this.height = height;
            this.bal = bal;
            this.left = left;
            this.right = right;
        }
    }

    // Node root = null;

    public static Node constructTree(int[] arr, int si, int ei) {
        if (si > ei) {
            return null;
        }

        if (si == ei) {
            Node node = new Node(arr[si]);
            return node;
        }

        int mid = (si + ei) >> 1;

        Node node = new Node(arr[mid]);

        node.left = constructTree(arr, si, mid - 1);
        node.right = constructTree(arr, mid + 1, ei);

        node.height = updateHeight(node);
        node.bal = updateHeight(node);

        return node;
    }

    public static void display(Node node) {
        if (node == null) {
            return;
        }

        StringBuilder sb = new StringBuilder();

        sb.append(node.left == null ? " . " : node.left.data);
        sb.append("-> " + node.data + " <-");
        sb.append(node.right == null ? " . " : node.right.data);

        System.out.println(sb.toString());
        display(node.left);
        display(node.right);
    }

    public static int updateHeight(Node node) {
        if (node == null) {
            return -1;
        }

        int lh = -1;
        int rh = -1;

        if (node.left != null) {
            lh = node.left.height;
        }

        if (node.right != null) {
            rh = node.right.height;
        }

        return Math.max(lh, rh) + 1;
    }

    public static int updateBalanceFactor(Node node) {
        if (node == null) {
            return 0;
        }

        int lh = -1;
        int rh = -1;

        if (node.left != null) {
            lh = node.left.height;
        }

        if (node.right != null) {
            rh = node.right.height;
        }

        return (lh - rh);
    }

    public static void updateFactors(Node node) {
        node.bal = updateBalanceFactor(node);
        node.height = updateHeight(node);
    }

    public static Node rrRotation(Node x) {
        Node y = x.left;
        Node yRight = y.right;

        y.right = x;
        x.left = yRight;

        updateFactors(x);
        updateFactors(y);

        return y;
    }

    public static Node llRotation(Node x) {
        Node y = x.right;
        Node yLeft = y.left;

        y.left = x;
        x.right = yLeft;

        updateFactors(x);
        updateFactors(y);

        return y;
    }

    public static Node rotation(Node node) {
        if (updateBalanceFactor(node) == 2) {
            if (updateBalanceFactor(node.left) == 1) {
                node = rrRotation(node);
            } else if (updateBalanceFactor(node) == -1){
                node.left = llRotation(node.left);
                node = rrRotation(node);
            }
        } else if (updateBalanceFactor(node) == -2) {
            if (updateBalanceFactor(node.right) == -1) {
                node = llRotation(node);
            } else if (updateBalanceFactor(node) == 1){
                node.right = rrRotation(node.right);
                node = llRotation(node);
            }
        }
        return node;
    }

    public static Node addData(Node node, int data) {
        if (node == null) {
            Node base = new Node(data);
            updateFactors(base);
            return base;
        }

        if (node.data < data) {
            node.right = addData(node.right, data);
        } else {
            node.left = addData(node.left, data);
        }

        updateFactors(node);
        node = rotation(node);
        return node;
    }

    public static int minimum(Node node) {
        Node curr = node;
        while (curr.left != null) {
            curr = curr.left;
        }
        return curr.data;
    }

    public static Node removeNode(Node node, int data) {
        if (node == null) {
            return null;
        }

        if (node.data < data) {
            node.right = removeNode(node.right, data);
        }

        else if (node.data > data) {
            node.left = removeNode(node.left, data);
        }

        else {
            if (node.left == null || node.right == null) {
                Node rnode = node.left == null ? node.right : node.left;
                return rnode;
            }

            int min_ = minimum(node.right);
            node.data = min_;
            node.right = removeNode(node.right, min_);
        }

        updateFactors(node);
        node = rotation(node);
        return node;
    }

    public static void main(String[] args) {
        int[] arr = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
        Node root = constructTree(arr, 0, arr.length - 1);
        display(root);
        // System.out.println();
        // addData(root, 42);
        // display(root);
        System.out.println();
        removeNode(root, 70);
        display(root);
    }

}

//=================== again =======================

// public class AVL {
//     public static class Node {
//         int data = 0;
//         Node left = null;
//         Node right = null;
//         int height = -1;
//         int bal = 0;

//         public Node() {

//         }

//         public Node(int data) {
//             this.data = data;
//         }
        
//         public Node(int data, int height, int bal, Node left, Node right) {
//             this.data = data;
//             this.height = height;
//             this.bal = bal;
//             this.left = left;
//             this.right = right;
//         }

//         public Node(int data, Node left, Node right) {
//             this.left = left;
//             this.right = right;
//             this.data = data;
//         }

//         @Override
//         public String toString() {
//             String str = "";
//             str += ((left != null ? left.data : " . "))
//             str += (" -> " + data + " <- ");
//             str += ((right != null ? right.data : " . "))
//             str += "\n";

//             if (left != null) {
//                 str += left.toString();
//             }

//             if (right != null) {
//                 str += right.toString();
//             }

//             return str;
//         }
//     }

//     public static 

// }