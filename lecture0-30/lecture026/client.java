public class client {
    public static void main(String[] args) {
        int[] arr = { 10, 20, 40, 80, -1, -1, 90, -1, -1, 50, 100, -1, -1, -1, 30, 60, -1, 110, -1, -1, 70, 120, -1, -1,
                -1 };
        binaryTree bt = new binaryTree(arr);

        bt.levelOrder01();
        System.out.println();
        bt.levelOrder02_method_01();
        bt.levelOrder02_method_02();
        bt.levelOrder02_method_03();
    }
}