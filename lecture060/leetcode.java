/* leet code question 735 */
import java.util.Stack;
public class leetcode {
    public static void main(String[] args) {
        int[] arr = { 5, 10, -5 };
        astroidCollision_735(arr);
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
}