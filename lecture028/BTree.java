
// import java.lang.reflect.Array;
import java.nio.ReadOnlyBufferException;
import java.util.ArrayList;
import java.util.Collections;
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

    private static void BTree_(int[] arr) {
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

    static int prev = Integer.MIN_VALUE;

    public static boolean isBST(Node curr) {
        if (curr == null)
            return true;

        boolean left = isBST(curr.left);
        if (!left)
            return false;

        if (prev < curr.data)
            prev = curr.data;
        else
            return false;

        boolean right = isBST(curr.right);
        if (!right)
            return false;

        return true;
    }

    public static int height(Node node) {
        if (node == null)
            return 0;

        return Math.max(height(node.left), height(node.right)) + 1;
    }

    public static int diameter_01(Node node) {
        if (node == null)
            return 0;

        int lh = height(node.left);
        int rh = height(node.right);

        int ld = diameter_01(node.left);
        int rd = diameter_01(node.right);

        return Math.max(Math.max(ld, rd), lh + rh + 1);
    }

    public static class diaPair {
        int height = 0;
        int dia = 0;
    }

    public static diaPair diameter_02(Node node) {
        if (node == null) {
            return new diaPair();
        }

        diaPair left = diameter_02(node.left);
        diaPair right = diameter_02(node.right);

        diaPair mypair = new diaPair();

        mypair.height = Math.max(left.height, right.height) + 1;
        mypair.dia = Math.max(Math.max(left.dia, right.dia), left.height + right.height + 1);

        return mypair;
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

    public static void deleteLeaf_01(Node node, int leaf) {
        if (node == null)
            return;

        if (node.left != null && node.left.data == leaf) {
            node.left = null;
        }
        if (node.right != null && node.right.data == leaf) {
            node.right = null;
        }

        deleteLeaf_01(node.left, leaf);
        deleteLeaf_01(node.right, leaf);
    }

    public static Node deleteLeaf_02(Node node, int leaf) {
        if (node == null) {
            return null;
        }

        if (node.left == null && node.right == null && node.data == leaf) {
            return null;
        }
        node.left = deleteLeaf_02(node.left, leaf);
        node.right = deleteLeaf_02(node.right, leaf);

        return node;
    }

    public static void addLeaf_01(Node node, int par, int leaf, boolean isLeft) {
        if (node == null)
            return;

        if (node.data == par) {
            if (isLeft)
                node.left = new Node(leaf);
            else
                node.right = new Node(leaf);
        }

        addLeaf_01(node.left, par, leaf, isLeft);
        addLeaf_01(node.right, par, leaf, isLeft);
    }

    public static void main(String[] args) {
        // int[] arr = {10,
        // 20,40,80,-1,-1,90,-1,-1,50,100,-1,-1,-1,30,60,-1,110,-1,-1,70,120,-1,-1,-1};
        // int[] arr = {10,
        // 20,40,-1,-1,50,-1,-1,30,60,1110,1120,-1,1130,-1,-1,-1,-1,70,80,-1,-1,90,100,-1,110,-1,-1,-1};
        int[] arr = { 50, 30, 10, -1, 20, -1, -1, 40, -1, -1, 80, 70, 60, -1, -1, -1, 90 };
        BTree_(arr);
        // TO CHECK IF THE GIVEN ARR IS A BST OR NOT
        // System.out.println(isBST(root));

        // TO PRINT THE DIAMETER
        // System.out.println(diameter_01(root));

        // TO PRINT THE DIAMETER USING CLASS
        // System.out.println(diameter_02(root).dia);

        // display(root);
        // deleteLeaf_01(root, 40);
        // System.out.println();
        // display(root);

        // deleteLeaf_02(root, 40);
        // System.out.println();
        // display(root);

        addLeaf_01(root, 90, 1000, true);
        System.out.println();
        display(root);
    }
}