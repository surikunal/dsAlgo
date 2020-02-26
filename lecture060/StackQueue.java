import java.util.Stack;

public class StackQueue {
    public static void main(String[] args) {
        solve();
    }

    public static void solve() {
        int[] arr = {9, -1, 7, 3, 11, -2, 25, 20, -4};
        nextGreaterRight(arr);
        System.out.println();

        nextGreaterLeft(arr);
        System.out.println();

        nextLowestRight(arr);
        System.out.println();

        nextLowestLeft(arr);
        System.out.println();
    }

    public static void nextGreaterRight(int[] arr) {
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < arr.length; i++) {
            if (st.size() == 0) {
                st.push(arr[i]);
                continue;
            }

            while (st.size() != 0 && st.peek() < arr[i]) {
                System.out.println(st.pop() + " -> " + arr[i]);
            }

            st.push(arr[i]);
        }

        while (st.size() != 0) {
            System.out.println(st.pop() + " -> " + "no element exist");
        }
    }

    public static void nextGreaterLeft(int[] arr) {
        Stack<Integer> st = new Stack<>();
        for (int i = arr.length - 1; i > -1; i--) {
            if (st.size() == 0) {
                st.push(arr[i]);
                continue;
            }

            while (st.size() != 0 && st.peek() < arr[i]) {
                System.out.println(st.pop() + " -> " + arr[i]);
            }

            st.push(arr[i]);
        }

        while (st.size() != 0) {
            System.out.println(st.pop() + " -> " + "no element exist");
        }
    }

    public static void nextLowestRight(int[] arr) {
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < arr.length; i++) {
            if (st.size() == 0) {
                st.push(arr[i]);
                continue;
            }

            while (st.size() != 0 && st.peek() > arr[i]) {
                System.out.println(st.pop() + " -> " + arr[i]);
            }

            st.push(arr[i]);
        }

        while (st.size() != 0) {
            System.out.println(st.pop() + " -> " + "no element exist");
        }
    }

    public static void nextLowestLeft(int[] arr) {
        Stack<Integer> st = new Stack<>();
        for (int i = arr.length - 1; i > -1; i--) {
            if (st.size() == 0) {
                st.push(arr[i]);
                continue;
            }

            while (st.size() != 0 && st.peek() > arr[i]) {
                System.out.println(st.pop() + " -> " + arr[i]);
            }

            st.push(arr[i]);
        }

        while (st.size() != 0) {
            System.out.println(st.pop() + " -> " + "no element exist");
        }
    }
}