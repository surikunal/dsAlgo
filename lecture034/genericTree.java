import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.LinkedList;

public class genericTree {
    public static class Node {

        int data = 0;
        ArrayList<Node> childs = new ArrayList<>();

        Node(int data) {
            this.data = data;
        }
    }

    static Node root = null;

    public static Node constructor(int[] arr) {
        LinkedList<Node> st = new LinkedList<>();

        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] != -1) {
                Node node = new Node(arr[i]);
                st.addFirst(node);
            } else {
                Node rchild = st.removeFirst();
                st.getFirst().childs.add(rchild);
            }
        }
        return st.removeFirst();
    }

    public static void display(Node node) {
        StringBuilder sb = new StringBuilder();

        sb.append(node.data + "--> [");

        for (Node child : node.childs) {
            sb.append(child.data + " ,");
        }
        sb.append("]");
        System.out.println(sb.toString());

        for (Node child : node.childs) {
            display(child);
        }
    }

    public static int size(Node node) {
        int size = 0;
        for (Node child : node.childs) {
            size += size(child);
        }
        return size + 1;
    }

    public static int height(Node node) {
        int ht = -1;
        for (Node child : node.childs) {
            int recH = height(child);
            ht = Math.max(recH, ht);
        }
        return ht + 1;
    }

    public static boolean find(Node node, int data) {
        if (node.data == data) {
            return true;
        }
        boolean res = false;

        for (Node child : node.childs) {
            res = res || find(child, data);
        }
        return res;
    }

    public static int mini(Node node) {
        int min_ = Integer.MAX_VALUE;

        for (Node child : node.childs) {
            min_ = Math.min(min_, mini(child));
        }
        return Math.min(min_, node.data);
    }

    public static int maxi(Node node) {
        int max_ = Integer.MIN_VALUE;

        for (Node child : node.childs) {
            max_ = Math.max(max_, maxi(child));
        }
        return Math.max(max_, node.data);
    }

    // FOLDABLE__________________________________________________________________

    public static boolean isFoldable(Node node1, Node node2) {
        if ((node1 == null && node2 != null) || (node1 != null && node2 == null))
            return false;

        if (node1.childs.size() != node2.childs.size())
            return false;

        if (node1.data != node2.data)
            return false;

        for (int i = 0, j = node2.childs.size() - 1; i < node1.childs.size(); i++, j--) {
            Node child1 = node1.childs.get(i);
            Node child2 = node2.childs.get(j);

            boolean res = isFoldable(child1, child2);

            if (!res)
                return false;
        }
        return true;
    }

    // FLATTERN________________________________________________________

    public static void flattern(Node node, ArrayList<Node> child) {
        child.add(node);
        for (Node n : node.childs) {
            flattern(n, child);
        }
        node.childs = new ArrayList<>();
    }

    public static void flattern_01(Node node) {
        ArrayList<Node> ch = new ArrayList<>();
        for (Node n : node.childs) {
            flattern_01(n);
            ch.add(n);
            ch.addAll(n.childs);
            n.childs = new ArrayList<>();
            // for(int i=n.childs.size()-1; i>=0; i--)
            // {
            // ch.add(n.childs.remove(n.childs.size()-1));
            // }
        }
        node.childs = ch;
    }

    public static void removeLeaves(Node node) {
        for (int i = node.childs.size() - 1; i >= 0; i--) {
            Node child = node.childs.get(i);

            if (child.childs.size() == 0) {
                node.childs.remove(i);
                continue; // because if we checked for the size of null then it will show null point exception
            }

            removeLeaves(child);
        }
    }

    public static Node linearize(Node node)
    {
        if(node.childs.size() == 0)
        {
            return node;
        }
        
        Node lastTail = linearize(node.childs.get(node.childs.size() -1));

        for(int i = node.childs.size() -1 ; i>0; i--)
        {
            Node secondLastTail = linearize(node.childs.get(i-1));
            secondLastTail.childs.add(node.childs.remove(i));
        }
        return lastTail;
    }

    public static void main(String args[]) {
        // int[] arr = { 10, 20, 30, -1, 40, -1, -1, 50, 60, 70, -1, 80, -1, -1, 90,
        // 100, -1, 110, -1, -1, 120, -1, -1, 30, -1, -1 };
        // int[] arr = { 10, 20, 30, -1, 40, -1, -1, 50, 60, 70, -1, 80, -1, -1, 90, -1,
        // 60, 80, -1, 70, -1, -1, -1, 20, 40,
        // -1, 30, -1, -1 , -1};

        int[] arr = { 10, 20, 30, -1, 40, -1, -1, 50, 60, 70, -1, 80, -1, -1, 90, 100, -1, 110, -1, -1, 120, -1, -1, 20,
                -1, -1 };
        root = constructor(arr);
        // display(root);
        // System.out.println(height(root));
        // System.out.println(size(root));
        // System.out.println(find(root, 30));
        // System.out.println(mini(root));
        // System.out.println(maxi(root));
        // System.out.println(isFoldable(root, root));

        // ArrayList<Node> child = new ArrayList<>();
        // flattern(root, child);
        // child.remove(0);
        // root.childs = child;
        // display(root);

        // flattern_01(root);
        // display(root);

        // removeLeaves(root);
        // display(root);
        
        linearize(root);
        display(root);
    }
}
