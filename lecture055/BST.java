public class BST {
    // public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        BST();
    }
    public static void BST() {
        int[] arr = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
        Node root = constructBST(arr, 0, 9);
        // display(root);
        // System.out.println(height(root));
        // System.out.println(size(root));
        // System.out.println(find_01(root, 40));      //recursively
        // System.out.println(find_02(root, 300));      //iteratively
        // addDate(root, 200);
        // System.out.println(maxInTree(root));
        // System.out.println(minInTree(root));
        // deleteNode(root, 50);
        // display(root);
        /* moris traversal for inOder and preOrder */
        morisInOrder(root);
        System.out.println();
        morisPreOrder(root);
    }

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

    public static void display(Node node) {
        if (node == null)
            return;
        System.out.print((node.left != null ? node.left.data : "."));
        System.out.print(" -> " + node.data + " <- ");
        System.out.println((node.right != null ? node.right.data : "."));
        display(node.left); // display(2*idx+1);
        display(node.right); // display(2*idx+2);
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
            } else if (data < node.data) {
                return find_02(node.left, data);
            } else
                return find_02(node.right, data);
        }
        return false;
    }

    public static int maxInTree(Node node) {
        if (node == null) {
            return Integer.MIN_VALUE;
        }

        while (node.right != null) {
            node = node.right;
        }
        return node.data;
    }

    public static int minInTree(Node node) {
        if (node == null) {
            return Integer.MAX_VALUE;
        }

        while (node.left != null) {
            node = node.left;
        }
        return node.data;
    }

    public static Node deleteNode(Node node, int data) {
        if (node == null) {
            return null;
        }
        if (node.data == data) {
            if (node.left == null || node.right == null) {
                return node.left == null ? node.right : node.left;
            }

            int max = maxInTree(node.left);
            node.data = max;
            node.left = deleteNode(node.left, data);

        } else if (data < node.data) {
            deleteNode(node.left, data);
        } else
            deleteNode(node.right, data);

        return node;
    }

    public static Node rightMostOfLeft(Node node, Node curr) {
        while (node.right != null && node.right != curr) {
            node = node.right;
        }
        return node;
    }

    public static void morisInOrder(Node node) {
        Node curr = node;
        while (curr != null) {
            Node next = curr.left;
            if (next == null) {
                System.out.print(curr.data + " ");
                curr = curr.right;
            }
            else {
                Node rightMost = rightMostOfLeft(next, curr);
                if (rightMost.right == null) {
                    rightMost.right = curr;
                    curr = curr.left;
                }
                else {
                    System.out.print(curr.data + " ");
                    rightMost.right = null;
                    curr = curr.right;
                }
            }
        }
    }

    public static void morisPreOrder(Node node) {
        Node curr = node;
        while (curr != null) {
            Node next = curr.left;
            if (next == null) {
                System.out.print(curr.data + " ");
                curr = curr.right;
            }
            else {
                Node rightMost = rightMostOfLeft(next, curr);
                if (rightMost.right == null) {
                    System.out.print(curr.data + " ");
                    rightMost.right = curr;
                    curr = curr.left;
                }
                else {
                    rightMost.right = null;
                    curr = curr.right;
                }
            }
        }
    }
}

