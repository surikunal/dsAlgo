
// import java.lang.reflect.Array;
import java.nio.ReadOnlyBufferException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;

import javax.swing.undo.StateEdit;

import javafx.stage.StageStyle;

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

        Node(int data) {
            this.data = data;
        }

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

    public static void display(Node node) {
        if (node == null) {
            return;
        }

        StringBuilder sb = new StringBuilder(); // JUST LIKE VECTOR

        sb.append(node.left != null ? node.left.data : " . ");
        sb.append("->" + node.data + "<-");
        sb.append(node.right != null ? node.right.data : " . ");
        System.out.println(sb.toString());
        display(node.left);
        display(node.right);
    }

    public static Node preIn(int[] pre, int[] in, int ps, int pe, int is, int ie) {
        if (ps > pe || is > ie) {
            return null;
        }

        Node node = new Node(pre[ps]);
        int idx = is;
        while (idx <= ie) {
            if (in[idx] == pre[ps])
                break;

            idx++;
        }

        int tne = idx - is;

        node.left = preIn(pre, in, ps + 1, ps + tne, is, idx - 1);
        node.right = preIn(pre, in, ps + tne + 1, pe, idx + 1, ie);

        return node;
    }

    public static Node postIn(int[] post, int[] in, int ps, int pe, int is, int ie) {
        if (ps > pe || is > ie) {
            return null;
        }

        Node node = new Node(post[pe]);
        int idx = is;
        while (idx <= ie) {
            if (in[idx] == post[pe])
                break;

            idx++;
        }

        int tne = idx - is;

        node.left = postIn(post, in, ps, ps + tne - 1, is, idx - 1);
        node.right = postIn(post, in, ps + tne, pe - 1, idx + 1, ie);

        return node;
    }
    // -----------------------------------------------------------------

    static Node head = null;
    static Node prev = null;

    public static void inorderDLL(Node curr) {
        if (curr == null) {
            return;
        }

        inorderDLL(curr.left);

        if (head == null) {
            head = curr;
        } else {
            prev.right = curr;
            curr.left = prev;
        }
        prev = curr;

        inorderDLL(curr.right);
    }

    public static void main(String[] args) {
        // int[] arr =
        // {10,20,40,80,-1,-1,90,-1,-1,50,100,-1,-1,-1,30,60,-1,110,-1,-1,70,120,-1,-1,-1};
        // int[] arr =
        // {10,20,40,-1,-1,50,-1,-1,30,60,1110,1120,-1,1130,-1,-1,-1,-1,70,80,-1,-1,90,100,-1,110,-1,-1,-1};
        // int[] arr = {50,30,10,-1,20,-1,-1,40,-1,-1,80,70,60,-1,-1,-1,90};
        // BTree(arr);

        int[] pre = { 10, 20, 40, 50, 60, 30, 70, 90, 80 };
        int[] in = { 40, 20, 60, 50, 10, 70, 90, 30, 80 };
        int[] post = { 40, 60, 50, 20, 90, 70, 80, 30, 10 };
        Node root = preIn(pre, in, 0, pre.length - 1, 0, in.length - 1);
        display(root);

        // root = postIn(post, in, 0, post.length - 1, 0, in.length - 1);
        // display(root);

        inorderDLL(root);
        Node itr = prev;
        while (itr != null) {
            System.out.print(itr.data + " ");
            itr = itr.left;
        }
    }
}