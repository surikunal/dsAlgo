import java.util.Stack;

class greatestElement {
    public static void main(String[] args) {
        int[] arr = { 4, 5, 2, 25 };
        greatestElementRight(arr);
        System.out.println();

        greatestElementLeft(arr);
        System.out.println();

        smallestElementRight(arr);
        System.out.println();

        smallestElementLeft(arr);
        System.out.println();
    }

    public static void greatestElementRight(int[] arr) {
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < arr.length; i++) {
            if (st.size() == 0) {
                st.push(arr[i]);
                continue;
            }

            while (st.size() != 0 && arr[i] > st.peek()) {
                System.out.println(st.pop() + "->" + arr[i]);
            }
            st.push(arr[i]);
        }
        while (st.size() != 0) {
            System.out.println(st.pop() + "->-1");
        }
    }
 
    public static void greatestElementLeft(int[] arr) {
        Stack<Integer> st = new Stack<>();
        for (int i = arr.length - 1; i >= 0; i--) {
            if (st.size() == 0) {
                st.push(arr[i]);
                continue;
            }

            while (st.size() != 0 && arr[i] > st.peek()) {
                System.out.println(st.pop() + "->" + arr[i]);
            }
            st.push(arr[i]);
        }
        while (st.size() != 0) {
            System.out.println(st.pop() + "->-1");
        }
    }

    public static void smallestElementRight(int[] arr) {
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < arr.length; i++) {
            if (st.size() == 0) {
                st.push(arr[i]);
                continue;
            }

            while (st.size() != 0 && arr[i] < st.peek()) {
                System.out.println(st.pop() + "->" + arr[i]);
            }
            st.push(arr[i]);
        }
        while (st.size() != 0) {
            System.out.println(st.pop() + "->-1");
        }
    }

    public static void smallestElementLeft(int[] arr) {
        Stack<Integer> st = new Stack<>();
        for (int i = arr.length - 1; i >= 0; i--) {
            if (st.size() == 0) {
                st.push(arr[i]);
                continue;
            }

            while (st.size() != 0 && arr[i] < st.peek()) {
                System.out.println(st.pop() + "->" + arr[i]);
            }
            st.push(arr[i]);
        }
        while (st.size() != 0) {
            System.out.println(st.pop() + "->-1");
        }
    }
}