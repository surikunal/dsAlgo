import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class binaryTree{
    public class Node{
        private int data = 0;
        private Node left = null;
        private Node right = null;

        Node()
        {
            this.data = 0;
            this.left = null;
            this.right = null;
        }

        Node(int data)
        {
            this.data = data;
        }

        Node(int data, Node left, Node right)
        {
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }

    Node root = null;

    public binaryTree(int[] arr)
    {
        root=constructor(arr);
    }

    private static int idx = 0;

    private Node constructor(int[] arr)
    {
        if(idx >= arr.length || arr[idx] == -1)
        {
            idx++;
            return null;
        }

        Node node = new Node(arr[idx], null, null);

        idx++;
        node.left = constructor(arr);
        node.right = constructor(arr);

        return node;
    }

    public boolean find(int data)
    {
        return find(this.root, data);
    }
    private boolean find(Node node, int data)
    {
        if(node == null)    return false;

        if(node.data == data)   return true;

        return find(node.left, data) || find(node.right, data);
    }

    public int max()
    {
        return max(this.root);
    }
    private int max(Node node)
    {
        if(node == null)
        return Integer.MIN_VALUE;

        return Math.max(node.data, Math.max(max(node.left), max(node.right)));
    }

    public int min()
    {
        return min(this.root);
    }

    private int min(Node node)
    {
        if(node == null)
        return Integer.MAX_VALUE;
        
        return Math.min(node.data, Math.min(min(node.left), min(node.right)));
    }
}