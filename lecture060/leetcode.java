
/* leet code question 735, 402 */
import java.util.Stack;

public class leetcode {
    public static void main(String[] args) {
        int[] arr = { 5, 10, -5 };
        astroidCollision_735(arr);
        removeKdigits_402();
    }

    public static int[] astroidCollision_735(int[] arr) {
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > 0) {
                st.push(arr[i]);
            } else {
                while (st.size() != 0 && st.peek() > 0 && st.peek() < -arr[i]) {
                    st.pop();
                }

                if (st.size() != 0 && st.peek() == -arr[i])
                    st.pop();

                else if (st.size() == 0 || st.peek() < 0)
                    st.push(arr[i]);
            }
        }
        int[] ans = new int[st.size()];
        for (int i = arr.length - 1; i >= 0; i--) {
            ans[i] = st.pop();
        }
        return ans;
    }

    public String removeKdigits(String num, int k) {
        char[] arr = num.toCharArray();
        Stack<Character> st = new Stack<>();

        for (int i = 0; i < arr.length; i++) {
            while (st.size() != 0 && st.peek() > arr[i]) {
                st.pop();
                k--;
            }
            st.push(arr[i]);
        }

        while (k-- > 0) {
            st.pop();
        }

        StringBuilder sb = new StringBuilder();
        while (st.size() != 0) {
            sb.append(st.pop());
        }

        if (sb.length() != 0 && sb.charAt(sb.length() - 1) == '0') {
            int i = sb.length() - 2;
            for (; i >= 0; i--) {
                if (sb.charAt(i) != 0) {
                    break;
                }
            }
            sb = new StringBuilder(sb.substring(0, i + 1));
        }
        sb.reverse();
        String ans = sb.toString();
        return ans.length() != 0 ? ans : "0";
    }
}