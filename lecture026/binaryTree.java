import java.util.Scanner;
// import java.lang.invoke.ConstantCallSite;
import java.util.ArrayList;
import java.util.LinkedList;

public class binaryTree {
    public class Node {
        private int data = 0;
        private Node left = null;
        private Node right = null;

        Node() {
            this.data = 0;
            this.right = null;
            this.left = null;
        }

        Node(int data) {
            this.data = data;
        }

        Node(int data, Node left, Node right) {
            this.data = data;
            this.right = right;
            this.left = left;
        }
    }

    Node root = null;

    public binaryTree(int[] arr) {
        root = constructor(arr);
    }

    private static int idx = 0;

    private Node constructor(int[] arr) {
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

    public void levelOrder01() {
        levelOrder01(this.root);
    }

    private void levelOrder01(Node root) {
        LinkedList<Node> que = new LinkedList<>();
        que.addLast(root);
        while (!que.isEmpty()) {
            Node node = que.removeFirst();
            System.out.print(node.data + " ");

            if (node.left != null) {
                que.addLast(node.left);
            }

            if (node.right != null) {
                que.addLast(node.right);
            }
        }
    }

    public void levelOrder02_method_02() {
        levelOrder_02_method_02(this.root);
    }

    private void levelOrder_02_method_02(Node root) {
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

    public void levelOrder02_method_01() {
        levelOrder_02_method_01(this.root);
    }

    private void levelOrder_02_method_01(Node root) {
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

    public void levelOrder02_method_03() {
        levelOrder_02_method_03(this.root);
    }

    public void levelOrder_02_method_03(Node root) {
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

}
