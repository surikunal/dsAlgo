import java.util.Scanner;
import javax.swing.plaf.synth.SynthLookAndFeel;
import java.util.ArrayList;
import java.util.LinkedList;

public class practice {
    private static class Node {
        private int data = 0;
        private Node left = null;
        private Node right = null;

        Node(int data, Node left, Node right) {
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }

    static Node root = null;

    private static void practice(int[] arr) {
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

    public static void levelOder1(Node root) {
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

    public static void levelOder2_method_1(Node root) {
        LinkedList<Node> que1 = new LinkedList<>();
        LinkedList<Node> que2 = new LinkedList<>();
        que1.addLast(root);
        while (!que1.isEmpty()) {
            Node node = que1.removeFirst();
            System.out.print(node.data + " ");

            if (node.left != null) {
                que2.addLast(node.left);
            }
            if (node.right != null) {
                que2.addLast(node.right);
            }
            if (que1.size() == 0) {
                System.out.println();
                LinkedList<Node> temp = que1;
                que1 = que2;
                que2 = temp;
            }
        }
    }

    public static void levelOder2_method_2(Node root) {
        LinkedList<Node> que = new LinkedList<>();
        que.addLast(root);
        while (!que.isEmpty()) {
            int size = que.size();
            while (size-- > 0) {
                Node node = que.removeFirst();
                System.out.print(node.data + " ");

                if (node.left != null) {
                    que.addLast(node.left);
                }
                if (node.right != null) {
                    que.addLast(node.right);
                }
            }
            System.out.println();
        }
    }

    public static void levelOder2_method_3(Node root) {
        LinkedList<Node> que = new LinkedList<>();
        que.addLast(root);
        que.addLast(null);
        while (!que.isEmpty()) {
            Node node = que.removeFirst();

            if (node == null && que.size() > 0) {
                que.addLast(null);
                System.out.println();
            } else {
                if (node != null) {
                    System.out.print(node.data + " ");
                    if (node.left != null) {
                        que.addLast(node.left);
                    }
                    if (node.right != null) {
                        que.addLast(node.right);
                    }
                }
            }
        }
    }

    public static void zigzag(Node root) {
        LinkedList<Node> que = new LinkedList<>();
        que.addLast(root);
        while (!que.isEmpty()) {
            int size = que.size();
            while (size-- > 0) {
                Node node = que.removeFirst();
                System.out.print(node.data + " ");
                if (node.right != null) {
                    que.addLast(node.right);
                }
                if (node.left != null) {
                    que.addLast(node.left);
                }
                if (size == 0) {
                    System.out.println();
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = { 10, 20, 40, 80, -1, -1, 90, -1, -1, 50, 100, -1, -1, -1, 30, 60, -1, 110, -1, -1, 70, 120, -1, -1,
                -1 };
        practice(arr);

        levelOder1(root);
        // System.out.println();
        // levelOder2_method_1(root);
        // levelOder2_method_2(root);
        // levelOder2_method_3(root);
        // zigzag(root);
    }
}