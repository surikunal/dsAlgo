import java.util.ArrayList;

public class LCA {

    private static class Node {
        int data = 0;
        Node left = null;
        Node right = null;

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

    private static void LCA(int[] arr)
    {
        root = constructor(arr);
    }
    static int idx = 0;

    public static Node constructor(int[] arr) {
        if (idx >= arr.length || arr[idx] == -1) {
            idx++;
            return null;
        }
        Node node = new Node(arr[idx]);
        idx++;
        node.left = constructor(arr);
        node.right = constructor(arr);

        return node;
    }

    public static ArrayList<Node> rootToNodePath(Node node, int data) {
        if (node == null)
            return null;

        if (node.data == data) {
            ArrayList<Node> base = new ArrayList<>();
            base.add(node);
            return base;
        }

        ArrayList<Node> leftAns = rootToNodePath(node.left, data);
        if (leftAns != null) {
            leftAns.add(node);
            return leftAns;
        }
        ArrayList<Node> rightAns = rootToNodePath(node.right, data);
        if (rightAns != null) {
            rightAns.add(node);
            return rightAns;
        }
        return null;
    }

    public static Node LCA_01(Node node, int data1, int data2) {
        ArrayList<Node> path1 = rootToNodePath(root, data1);
        ArrayList<Node> path2 = rootToNodePath(root, data2);

        if (path1 == null || path2 == null) {
            return null;
        }
        Node ans = null;
        int i = path1.size() - 1;
        int j = path2.size() - 1;
        while (i >= 0 && j >= 0) {
            if (path1.get(i).data == path2.get(j).data) {
                ans = path1.get(i);
            } else {
                break;
            }
            i--;
            j--;
        }
        return ans;
    }

    static Node LCA = null;
    public static boolean LCA_02(Node node, int data1, int data2)
    {
        if(node == null)    return false;
        
        boolean selfDone = node.data == data1 || node.data == data2;

        boolean left = LCA_02(node.left, data1, data2);
        boolean right = LCA_02(node.right, data1, data2);

        if((left && right) || (left && selfDone) || (right && selfDone))
        {
            LCA = node;
        }
        return left || right || selfDone;
    }
    public static void main(String[] args) {
        int[] arr = { 10, 20, 40, -1, -1, 50, -1, -1, 30, 60, 1110, 1120, -1, 1130, -1, -1, -1, -1, 70, 80, 90, 100, -1,
                110, -1, -1, -1 };
        LCA(arr);
        // System.out.println(LCA_01(root, 60, 70).data);
        
        // if(LCA_02(root, 60, 70));
        // {
        //     System.out.println(LCA.data);
        // }

    }
}