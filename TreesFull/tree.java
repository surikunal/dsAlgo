import java.util.Scanner;
import java.util.ArrayList;

public class tree {

    public static class Node {
        private int data = 0;
        private Node left = null;
        private Node right = null;

        Node (int data) {
            this.data = data;
        }

        Node (int data, Node left, Node right) {
            this.left = left;
            this.right = right;
            this.data = data;
        }
    }

    static Node root = null;

    private static void tree(int[] arr) {
        root = construct(arr);
    }

    static int idx = 0;

    public static Node construct(int[] arr) {
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

    public void display() {
        display(root);
    }

    public static void display(Node node) {
        if (node == null) {
            return;
        }

        StringBuilder sb = new StringBuilder();

        sb.append(node.left == null ? " . " : node.left.data);
        sb.append("=> " + node.data + " <=");
        sb.append(node.right == null ? " . " : node.right.data);
        System.out.println(sb.toString());
        display(node.left);
        display(node.right);
    }

    public static int height(Node node) {
        if (node == null) {
            return 0;
        }

        return Math.max(height(node.left), height(node.right)) + 1;
    }

    public static int size(Node node) {
        if (node == null) {
            return 0;
        }
        return size(node.left) + size(node.right) + 1;
    }

    public static void preorder(Node node) {
        if (node == null) {
            return;
        }

        System.out.print(node.data + " ");
        preorder(node.left);
        preorder(node.right);
    }

    public static void postorder(Node node) {
        if (node == null) {
            return;
        }
        postorder(node.left);
        postorder(node.right);
        System.out.print(node.data + " ");
    }

    public static void inorder(Node node) {
        if (node == null) {
            return;
        }
        inorder(node.left);
        System.out.print(node.data + " ");
        inorder(node.right);
    }
    // public static Scanner scn = new Scanner (System.in);
    public static void main(String[] args) {
        int[] arr = { 10, 20, 40, 80, -1, -1, 90, -1, -1, 50, 100, -1, -1, -1, 30, 60, -1, 110, -1, -1, 70, 120, -1, -1,
            -1 };
        tree(arr);
        System.out.println(height(root));
        System.out.println(size(root));
        //traversal
        preorder(root);
        System.out.println();
        postorder(root);
        System.out.println();
        inorder(root);
        System.out.println();
    }
}
