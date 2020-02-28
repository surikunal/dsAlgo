import java.util.Stack;
public class leetcode {
    public static void main(String[] args) {
        int[] arr = {1,2,3,4,4,6,6,6,5,2,4,6,5};
        System.out.println(largestRectangleArea(arr));
    }

    public static int largestRectangleArea(int[] arr) {
        int maxArea = 0;
        Stack<Integer> st = new Stack<>();
        st.push(-1);
        
        for (int i = 0; i < arr.length; i++) {
            while (st.peek() != -1 && arr[i] <= arr[st.peek()]){
                int height = arr[st.pop()];
                int width = (i - st.peek() - 1);
                int area = height * width;
                
                if (area > maxArea) {
                    maxArea = area;
                }
            }
            
            st.push(i);
        }
        
        while (st.peek() != -1) {
            int height = arr[st.pop()];
            int width = (arr.length - st.peek() - 1);
            int area = height * width;
            
            if (area > maxArea) {
                maxArea = area;
            }
        }
        
        return maxArea;
    }
}