// using client method
// by making a saperate file and calling this file from there

import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

/* Binary Tree */

public class binaryTree{
    public class Node{
        private int data = 0 ;
        private Node left= null ;
        private Node right = null ;

        //default constructor
        // Node name = new Node();

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
        Node(int data, Node left, Node right){
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }
    Node root = null;
    //constructor during static index
    // -1 in array means no branch

    public binaryTree(int[] arr){
        root = construct_static(arr);
    }

    private static int idx = 0;

    private Node construct_static(int[] arr)
    {
        if(idx >= arr.length || arr[idx] == -1)
        {
            idx++;
            return null;
        }

        Node node = new Node(arr[idx], null, null);

        idx++;
        node.left = construct_static(arr);
        node.right = construct_static(arr);

        return node;
    }

    // contruct wihtout static index
    // -1 means no branch

    /*
    
    public binaryTree(int[] arr, Node idx)
    {
        root = construct(arr, idx);
    }

    private Node construct(int[] arr, Node idx){
        if(idx.data >= arr.length || arr[idx.data] == -1)
        {
            idx.data++;
            return null;
        }

        Node node = new Node(arr[idx.data], null, null);

        idx.data++;
        idx.left = construct(arr, idx);
        idx.right = construct(arr, idx);

        return node;
    }

    */

    //function to display tree
    //pre-order traversal
    public void display(){
        display(this.root);
    }
    
    private void display(Node node)
    {
        if(node == null){
        return;
        }
        
    StringBuilder sb = new StringBuilder();
    sb.append(node.left == null ? " . " : node.left.data);
    sb.append(" -> " + node.data + " <- ");
    sb.append(node.right == null ? " . " : node.right.data);
    System.out.println(sb.toString());

    display(node.left);
    display(node.right);
    }

    public void preOrder()
    {
        preOrder(this.root);
    }
    private void preOrder(Node node)
    {
        if(node == null)    return;

        System.out.print(node.data + " ");
        preOrder(node.left);
        preOrder(node.right);
    }
    
    public void inOrder()
    {
        inOrder(this.root);
    }
    private void inOrder(Node node)
    {
        if(node == null)    return;

        inOrder(node.left);
        System.out.print(node.data + " ");
        inOrder(node.right);
    }

    public void postOrder()
    {
        postOrder(this.root);
    }
    private void postOrder(Node node)
    {
        if(node == null)    return;

        postOrder(node.left);
        postOrder(node.right);
        System.out.print(node.data + " ");
    }
}