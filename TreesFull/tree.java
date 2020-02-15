
/**
 * made by Kunal
 */
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;

public class tree {

    public static class Node {
        private int data = 0;
        private Node left = null;
        private Node right = null;

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

    public static void tree_(int[] arr) {
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

        sb.append(node.left == null ? "." : node.left.data);
        sb.append(" => " + node.data + " <= ");
        sb.append(node.right == null ? "." : node.right.data);
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

    public static int max(Node node) {
        if (node == null) {
            return Integer.MIN_VALUE;
        }
        return Math.max(Math.max(max(node.left), max(node.right)), node.data);
    }

    public static int min(Node node) {
        if (node == null) {
            return Integer.MAX_VALUE;
        }
        return Math.min(Math.min(min(node.left), min(node.right)), node.data);
    }

    public static boolean find(Node node, int data) {
        if (node == null)
            return false;
        if (node.data == data)
            return true;

        return find(node.left, data) || find(node.right, data);
    }

    // not good with memory
    public static ArrayList<Node> rootToNodePath_01(Node node, int data) {
        if (node == null) {
            return null;
        }

        if (node.data == data) {
            ArrayList<Node> base = new ArrayList<>();
            base.add(node);
            return base;
        }

        ArrayList<Node> leftAns = rootToNodePath_01(node.left, data);
        if (leftAns != null) {
            leftAns.add(node);
            return leftAns;
        }

        ArrayList<Node> rightAns = rootToNodePath_01(node.right, data);
        if (rightAns != null) {
            rightAns.add(node);
            return rightAns;
        }
        return null;
    }

    // better in saving memory
    public static boolean rootToNodePath_02(Node node, int data, ArrayList<Node> ans) {
        if (node == null) {
            return false;
        }

        if (node.data == data) {
            ans.add(node);
            return true;
        }

        if (rootToNodePath_02(node.left, data, ans)) {
            ans.add(node);
            return true;
        }

        if (rootToNodePath_02(node.right, data, ans)) {
            ans.add(node);
            return true;
        }

        return false;
    }

    // prit all the leafNodes in a tree
    public static void leafNode(Node node) {
        if (node == null) {
            return;
        }

        if (node.left == null && node.right == null) {
            System.out.print(node.data + " ");
        }

        leafNode(node.left);
        leafNode(node.right);
    }

    public static void levelOrder(Node node) {
        LinkedList<Node> queue = new LinkedList<>();
        queue.addLast(node);

        while (!queue.isEmpty()) {
            Node q = queue.removeFirst(); // also returns the removes value
            System.out.print(q.data + " ");

            if (q.left != null) {
                queue.addLast(q.left);
            }

            if (q.right != null) {
                queue.addLast(q.right);
            }
        }
    }

    public static void levelOrder_01(Node node) {
        LinkedList<Node> queue = new LinkedList<>();
        queue.addLast(node);
        queue.addLast(null);

        while (!queue.isEmpty()) {
            Node q = queue.removeFirst();

            if (q == null && queue.size() > 0) {
                queue.addLast(null);
                System.out.println();
            }

            else {
                if (q != null) {
                    System.out.print(q.data + " ");

                    if (q.left != null) {
                        queue.addLast(q.left);
                    }

                    if (q.right != null) {
                        queue.addLast(q.right);
                    }
                }
            }
        }
    }

    public static void levelOrder_02(Node node) {
        LinkedList<Node> queue1 = new LinkedList<>();
        LinkedList<Node> queue2 = new LinkedList<>();

        queue1.addLast(node);
        while (!queue1.isEmpty()) {
            Node q = queue1.removeFirst();
            System.out.print(q.data + " ");

            if (q.left != null) {
                queue2.addLast(q.left);
            }

            if (q.right != null) {
                queue2.addLast(q.right);
            }

            if (queue1.size() == 0) {
                System.out.println();
                LinkedList<Node> temp = queue1;
                queue1 = queue2;
                queue2 = temp;
            }
        }
    }

    public static void levelOrder_03(Node node) {
        LinkedList<Node> queue = new LinkedList<>();

        queue.addLast(node);

        while (!queue.isEmpty()) {

            int size = queue.size();
            while (size-- > 0) {
                Node q = queue.removeFirst();
                System.out.print(q.data + " ");

                if (q.left != null) {
                    queue.addLast(q.left);
                }

                if (q.right != null) {
                    queue.addLast(q.right);
                }
            }
            System.out.println();
        }
    }

    public static Node LCA_01(Node node, int data1, int data2) {
        if (node == null) {
            return null;
        }

        ArrayList<Node> path1 = rootToNodePath_01(node, data1);
        ArrayList<Node> path2 = rootToNodePath_01(node, data2);

        if (path1 == null || path2 == null) {
            return null;
        }

        Node ans = null;
        int i = path1.size() - 1;
        int j = path2.size() - 1;
        while (i >= 0 && j >= 0) {
            if (path1.get(i).data == path2.get(j).data) {
                ans = path1.get(i);
            }

            else {
                break;
            }
            i--;
            j--;
        }
        return ans;
    }

    /*
     * here the fact is when we traverse a tree in post order then least common
     * ancestor will always lie on the right side of both of given data
     */

    static Node ans1 = null;

    public static boolean LCA_02(Node node, int data1, int data2) {
        if (node == null) {
            return false;
        }

        boolean selfDone = node.data == data1 || node.data == data2;

        /*
         * point to notice we are traversing here in postOrder
         */
        boolean leftAns = LCA_02(node.left, data1, data2);
        boolean rightAns = LCA_02(node.right, data1, data2);

        if ((leftAns && rightAns) || (leftAns && selfDone) || (rightAns && selfDone)) {
            ans1 = node;
        }

        return leftAns || rightAns || selfDone;
    }

    static class pair {
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        boolean isBST = true;
        int countBST = 0;
    }

    public static pair BST(Node node) {
        if (node == null) {
            return new pair();
        }

        pair left = BST(node.left);
        pair right = BST(node.right);
        pair mypair = new pair();
        mypair.isBST = false;

        if (left.isBST && right.isBST && left.max <= node.data && right.min >= node.data) {
            mypair.isBST = true;
            mypair.countBST = 1;
        }

        mypair.min = Math.min(Math.min(left.min, right.min), node.data);
        mypair.max = Math.max(Math.max(left.max, right.max), node.data);
        mypair.countBST += left.countBST + right.countBST;

        return mypair;
    }

    /* here the fact is
    if we traverse in InOrder then the previous node must be smaller than current node in BST*/

    static int prev = Integer.MIN_VALUE;
    public static boolean isBST(Node node) {
        if (node == null) {
            return true;
        }

        boolean left = isBST(node.left);
        if (!left)
            return false;

        if (prev < node.data) {
            prev = node.data;
        }
        else {
            return false;
        }
        
        boolean right = isBST(node.right);
        if (!right)
            return false;

        return true;
    }

    /* diameter in terms of nodes */
    
    public static int diameter_01(Node node) {
        if (node == null) {
            return 0;
        }

        int lh = height(node.left);
        int rh = height(node.right);

        int rd = diameter_01(node.right);
        int ld = diameter_01(node.left);

        return Math.max(Math.max(rd, ld), rh + lh + 1);
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

    /* here it is preferable to go in InOrder */

    public static void deleteLeaf(Node node, int data) {
        if (node == null) {
            return;
        }

        if (node.left != null && node.left.data == data) {
            node.left = null;
        }

        if (node.right != null && node.right.data == data) {
            node.right = null;
        }

        deleteLeaf(node.left, data);
        deleteLeaf(node.right, data);
    }

    public static Node deleteLeaf_01(Node node, int data) {
        if (node == null) {
            return null;
        }

        if (node.left == null && node.right == null && node.data == data) {
            return null;
        }

        node.left = deleteLeaf_01(node.left, data);
        node.right = deleteLeaf_01(node.right, data);

        return node;
    }

    public static Node preIn(int[] pre, int[] in, int ps, int pe, int is, int ie) {
        if (is > ie || ps > pe) {
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

    public static Node postIn(int[] in, int[] post, int is, int ie, int ps, int pe) {
        if (is > ie || ps > pe) {
            return null;
        }

        Node node = new Node(post[pe]);

        int idx = is;
        while (idx <= ie) {
            if (post[pe] == in[idx]) {
                break;
            }
            idx++;
        }

        int tne = idx - is;
        node.left = postIn(in, post, is, idx - 1, ps, ps + tne - 1);
        node.right = postIn(in, post, idx + 1, ie, ps + tne, pe - 1 );

        return node;
    }

    static Node head = null;
    static Node prev1 = null;
    public static void DLL(Node curr) {
        if (curr == null) {
            return;
        }

        DLL(curr.left);

        if (head == null) {
            head = curr;
        }
        else {
            prev1.right = curr;
            curr.left = prev1;
        }

        prev1 = curr;

        DLL(curr.right);
    }
    public static void main(String[] args) {
        // int[] arr = { 10, 20, 40, 80, -1, -1, 90, -1, -1, 50, 100, -1, -1, -1, 30,
        // 60, -1, 110, -1, -1, 70, 120, -1, -1,
        // -1 };
        // tree(arr);

        // int[] arr1 = { 10, 20, 40, -1, -1, 50, -1, -1, 30, 60, 1110, 1120, -1, 1130,
        // -1, -1, -1, -1, 70, 80, -1, -1, 90, 100, -1, 110, -1, -1, -1};
        // tree_(arr1);
        // System.out.println(height(root));

        // System.out.println(size(root));

        // //simple traversals
        // preorder(root);
        // System.out.println();

        // postorder(root);
        // System.out.println();

        // inorder(root);
        // System.out.println();

        // System.out.println(max(root));

        // System.out.println(min(root));

        // System.out.println(find(root, 1230));

        // ArrayList<Node> ans = new ArrayList<>();
        // ans = rootToNodePath_01(root, 100);
        // // Collections.reverse(ans); //to reverse the ans
        // for (Node ele : ans) {
        // System.out.print(ele.data + " ");
        // }
        // System.out.println();

        // ArrayList<Node> ans1 = new ArrayList<>();
        // rootToNodePath_02(root, 100, ans1);
        // for (Node ele : ans1) {
        // System.out.print(ele.data + " ");
        // }
        // System.out.println();

        // leafNode(root);
        // System.out.println();

        // //level order traversals

        // levelOrder(root);
        // System.out.println();

        // // methods for level order traversal
        // levelOrder_01(root);
        // System.out.println();

        // levelOrder_02(root);
        // System.out.println();

        // levelOrder_03(root);
        // System.out.println();

        // System.out.println(LCA_01(root, 1110, 100).data);
        // System.out.println();

        // //more optimised way for Least Common Ancestor
        // System.out.println(LCA_02(root, 90, 100));
        // if (LCA_02(root, 90, 100)) {
        // System.out.println(ans1.data);
        // }

        // // how to make a binary Tree

        // int[] arr2 = { 50, 30, 10, -1, 20, -1, -1, 40, -1, -1, 80, 70, 60, -1, -1, -1, 90, -1, -1 };
        // tree_(arr2);

        // System.out.println(BST(root).countBST);
        // System.out.println(BST(root).isBST);
        // System.out.println(BST(root).min);
        // System.out.println(BST(root).max);

        // System.out.println(isBST(root));

        /* find maximum length diameter of a BST */

        // System.out.println(diameter_01(root));

        // System.out.println(diameter_02(root).dia);   //diameter
        // System.out.println(diameter_02(root).height);    //height

        // deleteLeaf(root, 20);
        // display(root);
        
        // deleteLeaf_01(root, 20);
        // display(root);

        // //to convert post , in and pre order arrays into a tree
        // int[] pre = {10, 20, 40, 50, 60, 30, 70, 90, 80};
        // int[] in = {40, 20, 60, 50, 10, 70, 90, 30, 80};
        // int[] post = {40, 60, 50, 20, 90, 70, 80, 30, 10};

        /* generate a tree  using in and pre order */
        // Node root = preIn(pre, in, 0, pre.length - 1, 0, in.length - 1);
        // display(root);

        // Node root = postIn(in, post, 0, in.length - 1, 0, post.length - 1);
        // display(root);

        // DLL(root);
        // Node itr = prev1;
        // while (itr != null) {
        //     System.out.print(itr.data + " ");
        //     itr = itr.left;
        // }
    }
}
