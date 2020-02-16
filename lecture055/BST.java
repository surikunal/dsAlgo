import java.util.Stack;
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
            node.left = deleteNode(node.left, max);

        } else if (data < node.data) {
            node.left = deleteNode(node.left, data);
        } else
            node.right = deleteNode(node.right, data);

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

    /* now its our method to print all PRE , POST AND IN order traversal */

    public static class Tpair {
        Node node = null;
        boolean sd = false;
        boolean ld = false;
        boolean rd = false;

        Tpair (Node node) {
            this.node = node;
        }
    }

    public static void preOrder(Node node) {
        Stack<Tpair> st = new Stack<>();
        st.add(new Tpair(node));

        while (st.size() != 0) {
            Tpair tnode = st.peek();

            if (!tnode.sd) {
               tnode.sd = true;
               System.out.print(tnode.node.data + " "); 
            }

            else if (!tnode.ld) {
                tnode.ld = true;
                if (tnode.node.left != null) {
                    st.add(new Tpair(tnode.node.left));
                }
            }

            else if (!tnode.rd) {
                tnode.rd = true;
                if (tnode.node.right != null) {
                    st.add(new Tpair(tnode.node.right));
                }
            }

            else {
                st.pop();
            }
        }
    }

    public static void inOrder(Node node) {
        Stack<Tpair> st = new Stack<>();
        st.add(new Tpair(node));

        while (st.size() != 0) {
            Tpair tnode = st.peek();

            if (!tnode.ld) {
                tnode.ld = true;
                if (tnode.node.left != null) {
                    st.add(new Tpair(tnode.node.left));
                }
            }

            else if (!tnode.sd) {
                tnode.sd = true;
                System.out.print(tnode.node.data + " "); 
            }

            else if (!tnode.rd) {
                tnode.rd = true;
                if (tnode.node.right != null) {
                    st.add(new Tpair(tnode.node.right));
                }
            }

            else {
                st.pop();
            }
        }
    }

    public static void postOrder(Node node) {
        Stack<Tpair> st = new Stack<>();
        st.add(new Tpair(node));

        while (st.size() != 0) {
            Tpair tnode = st.peek();

            if (!tnode.ld) {
                tnode.ld = true;
                if (tnode.node.left != null) {
                    st.add(new Tpair(tnode.node.left));
                }
            }

            else if (!tnode.rd) {
                tnode.rd = true;
                if (tnode.node.right != null) {
                    st.add(new Tpair(tnode.node.right));
                }
            }
            
            else if (!tnode.sd) {
                tnode.sd = true;
                System.out.print(tnode.node.data + " "); 
            }

            else {
                st.pop();
            }
        }
    }
    
    public static void BST_() {
        int[] arr = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
        Node root = constructBST(arr, 0, 9);
        // display(root);

        // System.out.println(maxInTree(root));
        // System.out.println(minInTree(root));
        // deleteNode(root, 50);
        // display(root);

        /* moris traversal for inOder and preOrder */
        // morisInOrder(root);
        // System.out.println();
        // morisPreOrder(root);

        /* our method */
        preOrder(root);
        System.out.println();
        inOrder(root);
        System.out.println();
        postOrder(root);
    }
    public static void main(String[] args) {
        BST_();
    }
}

