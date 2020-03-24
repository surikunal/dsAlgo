class Solution {
    public int trap(int[] arr) {
        Stack<Integer> st = new Stack<>();
        st.push(-1);
        int ans = 0;
        for (int i = 0; i < arr.length; i++) {
            while (st.peek() != -1 && arr[i] > arr[st.peek()]) {
                int h = arr[st.pop()];
                if (st.peek() == -1)
                    break;
                
                int width = i - st.peek() - 1;
                int height = (Math.min(arr[st.peek()], arr[i]) - h);
                
                ans += (height * width);
            }
            st.push(i);
        }
        return ans;
    }
}