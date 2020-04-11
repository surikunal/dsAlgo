import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class rootToNodePath{

    public static class Node{
        int data = 0;
        Node left = null;
        Node right = null;

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
            this.data= data;
            this.right = right;
            this.left = left;
        }
    }
    static Node root = null;

    private static void rootToNodePath(int[] arr)
    {
        root = constructor(arr);
    }
    public static int idx = 0;

    public static Node constructor(int[] arr)
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
    public static void display(Node node)
    {
        if(node == null)
        return;

        StringBuilder sb = new StringBuilder();
        sb.append(node.left == null ? " . " : node.left.data);
        sb.append("=>" + node.data + "<=");
        sb.append(node.right == null ? " . " : node.right.data);
        System.out.println(sb.toString());

        display(node.left);
        display(node.right);
    }
    public static int max(Node node)
    {
        if(node == null)
        return Integer.MIN_VALUE;

        int minn = node.data;
        int max1 = max(node.left);
        int max2 = max(node.right);

        return Math.max(Math.max(max1, max2), minn);
    }
    public static int min(Node node)
    {
        if(node == null)
        return Integer.MAX_VALUE;

        int minn = node.data;
        int min1 = min(node.left);
        int min2 = min(node.right);

        return Math.min(Math.min(min1 , min2), minn);
    }
    public static boolean find(Node node, int data)
    {
        if(node == null)
        return false;

        if(node.data == data)
        {
            return true;
        }

        return find(node.left, data) || find(node.right, data);
    }
    public static ArrayList<Node> rootToNodePath_01(Node node, int data)
    {
        if(node == null)    return null;

        if(node.data == data)   
        {
            ArrayList<Node> base = new ArrayList<>();
            base.add(node);
            return base;
        }

        ArrayList<Node> leftAns = rootToNodePath_01(node.left, data);
        if(leftAns != null)
        {
            leftAns.add(node);
            return leftAns;
        }
        ArrayList<Node> rightAns = rootToNodePath_01(node.right, data);
        if(rightAns != null)
        {
            rightAns.add(node);
            return rightAns ;
        }
        return null;
    }
    public static boolean rootToNodePath_02(Node node, int data, ArrayList<Node> path)
    {
        if(node == null)    return false;

        if(node.data == data)
        {
            path.add(node);
            return true;
        }
        if(rootToNodePath_02(node.left, data, path))
        {
            path.add(node);
            return true;
        }
        if(rootToNodePath_02(node.right, data, path))
        {
            path.add(node);
            return true;
        }
        return false;
    }

    public static void leafNode(Node node)
    {
        if(node == null)
        return;

        if(node.left == null && node.right == null)
        {
            System.out.print(node.data + " ");
        }

        leafNode(node.left);
        leafNode(node.right);
    }
    public static void main(String[] args)
    {
        int[] arr = {10, 20, 40, 80, -1, -1, 90, -1, -1, 50, 100, -1, -1, -1, 30, 60, -1, 110, -1, -1, 70, 120, -1, -1,
            -1 };
        rootToNodePath(arr);
        // display(root);
        // System.out.println(min(root));
        // System.out.println(max(root));
        // System.out.println(find(root, 55));

        // ArrayList<Node> ans = new ArrayList<>();
        // ans = rootToNodePath_01(root, 120);
        // Collections.reverse(ans);
        // for(Node node : ans)
        // {
        //     System.out.println(node.data);
        // }
        
        // ArrayList<Node> ans = new ArrayList<>();
        // rootToNodePath_02(root, 120, ans);
        // Collections.reverse(ans);
        // for(Node node : ans)
        // {
        //     System.out.println(node.data);
        // }

        leafNode(root);
    }

}