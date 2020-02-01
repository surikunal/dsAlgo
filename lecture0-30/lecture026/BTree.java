import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;

// import jdk.nashorn.internal.runtime.arrays.ArrayLikeIterator;

public class BTree {

    private static class Node {
        private int data = 0;
        private Node left = null;
        private Node right = null;

        // Node()
        // {
        // this.data = 0;
        // this.right=null;
        // this.left=null;
        // }

        // Node(int data)
        // {
        // this.data=data;
        // }

        Node(int data, Node left, Node right) {
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }

    static Node root = null;

    private static void BTree(int[] arr) {
        root = construct(arr);
    }

    static int idx = 0;

    private static Node construct(int[] arr) {
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

    public static void levelOrder_01(Node root) {
        LinkedList<Node> myQueue = new LinkedList<>();
        myQueue.addLast(root);
        while (!myQueue.isEmpty()) {
            Node node = myQueue.removeFirst();
            System.out.print(node.data + " ");

            if (node.left != null) {
                myQueue.addLast(node.left);
            }
            if (node.right != null) {
                myQueue.addLast(node.right);
            }
        }
    }

    public static void levelOrder_02_method_2(Node root) {
        LinkedList<Node> myQueue = new LinkedList<>();
        myQueue.addLast(root);
        while (!myQueue.isEmpty()) {
            int size = myQueue.size();
            while (size-- > 0) {
                Node proc = myQueue.removeFirst();
                System.out.print(proc.data + " ");

                if (proc.left != null)
                    myQueue.addLast(proc.left);
                if (proc.right != null)
                    myQueue.addLast(proc.right);
            }
            System.out.println();
        }
    }

    public static void levelOrder_02_method_1(Node root) {
        LinkedList<Node> que1 = new LinkedList<>();
        LinkedList<Node> que2 = new LinkedList<>();
        que1.addLast(root);
        while (!que1.isEmpty()) {
            Node node = que1.removeFirst();
            System.out.print(node.data + " ");
            if (node.left != null)
                que2.addLast(node.left);

            if (node.right != null)
                que2.addLast(node.right);

            if (que1.size() == 0) {
                System.out.println();
                LinkedList<Node> temp = que1;
                que1 = que2;
                que2 = temp;
            }
        }
    }

    public static void levelOrder_02_method_3(Node root) {
        LinkedList<Node> myQueue = new LinkedList<>();
        myQueue.addLast(root);
        myQueue.addLast(null);
        while (!myQueue.isEmpty()) {
            Node node = myQueue.removeFirst();
            if (node == null && myQueue.size() > 0) {
                myQueue.addLast(null);
                System.out.println();
            } else {
                if (node != null) {
                    System.out.print(node.data + " ");
                    if (node.left != null) {
                        myQueue.add(node.left);
                    }
                    if (node.right != null) {
                        myQueue.add(node.right);
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = { 10, 20, 40, 80, -1, -1, 90, -1, -1, 50, 100, -1, -1, -1, 30, 60, -1, 110, -1, -1, 70, 120, -1, -1,
                -1 };
        BTree(arr);

        levelOrder_01(root);
        System.out.println();
        // levelOrder_02_method_1(root);
        // levelOrder_02_method_2(root);
        // levelOrder_02_method_3(root);
    }
}
