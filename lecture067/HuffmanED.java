import java.util.PriorityQueue;
import java.util.HashMap;

public class HuffmanED {
    private static HashMap<String, String> encode = new HashMap<>();
    private static HashMap<String, String> decode = new HashMap<>();

    // we dont want it to be overrided by anyone, so make it private
    private class Node implements Comparable<Node> { // guides the nodes that on what behaf nodes will be compared
        String data = "";
        int freq = 0;   // in huffman code, we will work on the basis of freq (so data is not needed at all)
        //* priorityQueue we be filled on the basis of freqency
        Node left = null;
        Node right = null;

        public Node(String data, int freq, Node left, Node right) {
            this.data = data;
            this.freq = freq;
            this.left = left;
            this.right = right;
        }

        ////  this compareTo will override the default Syso to print that we have write
        ////  inside it
        //* Syso can be only override by toString not by compareTo
        //* compareTo function will only tell that what will we get to the top of priorityQueue 
        @Override
        public int compareTo(Node o) {  //* related to comparable
            return this.freq - o.freq; // our freq - other freq
        }
    }

    public HuffmanED(String str) { // constructor
        HuffManTree(str);
    }

    private void HuffManTree(String str) { // construct huffman tree
        int[] freqMap = new int[26]; // * size is 26 because we know we will only give small alphabets , otherwise we
                                     // can take array of 256

        // * here we will observe frequency of every different character and increases
        // it in array
        // * and then we will keep decreasing it, after using or printing
        for (int i = 0; i < str.length(); i++) {
            freqMap[str.charAt(i) - 'a']++;
        }

        PriorityQueue<Node> pq = new PriorityQueue<>();
        for (int i = 0; i < freqMap.length; i++) {
            if (freqMap[i] > 0) {
                pq.add(new Node((char) (i + 'a') + "", freqMap[i], null, null));
                // * extra "" after character is noting but a type of typecasting from char to
                // *string
            }
        }

        // here we putted != 1, insted of != 0 bec that can give nullPointException bcz we are taking out 2 nodes at a time
        while (pq.size() != 1) {
            Node one = pq.poll();
            Node two = pq.poll();
            pq.add(new Node("", one.freq + two.freq, one, two));
        }

        // now there will be left only one node and that should be root
        Node root = pq.poll();
        HuffmanTraversal(root, "");
    }

    private void HuffmanTraversal(Node root, String BinaryCode) {

        // as we know there will be no node which will have only one child, so we are compirmed to write this checkpoint
        if (root.left == null && root.right == null) {
            encode.put(root.data, BinaryCode);
            decode.put(BinaryCode, root.data);
            return;
        }

        HuffmanTraversal(root.left, BinaryCode + "0");
        HuffmanTraversal(root.right, BinaryCode + "1");
    }

    public String encoding(String str) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < str.length(); i++) {
            String s = str.charAt(i) + ""; // * type casting from char to String
            sb.append(encode.get(s));
        }

        return sb.toString();
    }

    public String decoding(String str) {
        StringBuilder sb = new StringBuilder();
        int i = 0;
        for (int j = 1; j <= str.length(); j++) {
            String s = str.substring(i, j);
            if (decode.containsKey(s)) {
                sb.append(decode.get(s));
                i = j;
            }
        }
        return sb.toString();   
    }
}