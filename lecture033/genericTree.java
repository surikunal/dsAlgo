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

        for (int i = 0; i < arr.length -1; i++) {
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

    public static void main(String args[]) {
        int[] arr = { 10, 20, 30, -1, 40, -1, -1, 50, 60, 70, -1, 80, -1, -1, 90, 100, -1, 110, -1, -1, 120, -1, -1, 30,
                -1, -1 };
        root = constructor(arr);
        display(root);
    }
}
