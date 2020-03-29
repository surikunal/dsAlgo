public class client {
    public static void main(String[] args) {
        // HuffmanED hed = new HuffmanED("qwertyuiopasdfghjklzxcvbnm");
        Huffman hed = new Huffman("qwertyuiopasdfghjklzxcvbnm"); // again for practice

        //// System.out.println(hed.encoding("imkunalsuri"));
        String str = args[0]; // * so that we can give input in the terminal itself

        String encode = hed.encoding(str);
        String decode = hed.decoding(encode);

        System.out.println(encode + " -> " + decode);
    }
}