public class BST {

    static class Node {
        int data = 0;
        Node left = null;
        Node right = null;

        Node(int data) {
            this.data = data;
        }

        Node(int data, Node left, Node right) {
            this.left = left;
            this.right = right;
            this.data = data;
        }
    }

    public static boolean find_01(Node node, int data) {
        if (node == null) {
            return false;
        }
        if (node.data == data) {
            return true;
        } else if (data < node.data) {
            return find_01(node.left, data);
        } else
            return find_01(node.right, data);
    }

    public static void display(Node node) {
        if (node == null)
            return;
        System.out.print((node.left != null ? node.left.data : "."));
        System.out.print(" -> " + node.data + " <- ");
        System.out.println((node.right != null ? node.right.data : "."));
        display(node.left); // display(2*idx+1);
        display(node.right); // display(2*idx+2);
    }

    public static Node constructBST(int[] arr, int si, int ei) {
        if (si > ei) {
            return null;
        }
        int mid = ((si + ei) >> 1);

        Node node = new Node(arr[mid]);

        node.left = constructBST(arr, si, mid - 1);
        node.right = constructBST(arr, mid + 1, ei);

        return node;
    }

    public static int size(Node node) {
        if (node == null)
            return 0;
        return size(node.left) + size(node.right) + 1;

    }

    public static int height(Node node) {
        if (node == null)
            return -1;
        return Math.max(height(node.left), height(node.right)) + 1;
    }

    public static Node addDate(Node node, int data) {
        if (node == null) {
            return new Node(data);
        }

        if (data < node.data)
            node.left = addDate(node.left, data);

        else
            node.right = addDate(node.right, data);

        return node;
    }

    public static boolean find_02(Node node, int data) {
        while (node != null) {
            
            if (node.data == data) {
                return true;
            } 
            
            else if (data < node.data) {
                node = node.left;
            }
            
            else
                node = node.right;
        }

        return false;
    }

    public class allSol {
        int height = -1;    //bcz height of null is -1
        int size = 0;
        boolean find = false;

        Node pred = null;
        Node succ = null;
        Node prev = null;

        int ceil = Integer.MIN_VALUE;
        int floor = Integer.MAX_VALUE;
    }

    /* for BTree */

    public static void allSolution(Node node, int data, int level, allSol pair) {
        if (node == null) {
            return;
        }

        pair.height = Math.max(pair.height, level);

        pair.size++;

        pair.find = pair.find || node.data == data;

        //===========CEIL AND FLOOR VALUE===============

        if (node.data > data && node.data < pair.ceil) {
            pair.ceil = node.data;
        }

        if (node.data < data && node.data > pair.floor) {
            pair.floor = node.data;
        }

        /* for Inorder */
        allSolution(node.left, data, level + 1, pair);

        if (node.data == data && pair.pred == null) {
            pair.pred = pair.prev;
        }
        else if (pair.prev != null && pair.succ == null && pair.prev.data == data) {
            pair.succ = node;
        }

        pair.prev = node;
        
        allSolution(node.right, data, level + 1, pair);
    }


    /* pred ans succ for BST */

    public static void predSuccForBST(Node node, int data) {
        Node pred = null;
        Node succ = null;

        while (node != null) {
            if (node.data == data) {
                if (node.right != null) {
                    succ = node.right;
                    while (succ.left != null) {
                        succ = succ.left;
                    }
                }

                if (node.left != null) {
                    pred = node.left;
                    while (pred.right != null) {
                        pred = pred.right;
                    }
                }

                System.out.println(succ != null ? succ.data : -1);
                System.out.println(pred != null ? pred.data : -1);
                return;
            }

            else if (node.data < data) {
                pred = node;
                node = node.right;
            }
            else {
                succ = node;
                node = node.left;
            }
        }
    }

    public static void BST_() {
        // int[] arr = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
        int[] arr = new int[10];
        for  (int i = 0; i < 10; i++) {
            arr[i] = (i + 1) * 10;
        }
        Node root = constructBST(arr, 0, arr.length - 1);
        display(root);
        // System.out.println(height(root));
        // System.out.println(size(root));
        // System.out.println(find_01(root, 40));      //recursively
        // System.out.println(find_02(root, 40));      //iteratively
        // addDate(root, 200);
        // display(root);

        // allSol(root, 40, 0, );                                       #doubt

        predSuccForBST(root, 30);

    }

    public static void main(String[] args) {
        BST_();
    }
}