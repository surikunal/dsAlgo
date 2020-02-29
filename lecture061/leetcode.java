
/* leetcode 84 and 85 */

import java.util.Stack;

public class leetcode {
    public static void main(String[] args) {
        int[] arr = {1,2,3,4,4,6,6,6,5,2,4,6,5};
        System.out.println(largestRectangleArea(arr));

        char[][] matrix = {
            {'1','0','1','0','0'},
            {'1','0','1','1','1'},
            {'1','1','1','1','1'},
            {'1','0','0','1','0'}
        };
        System.out.println(maximalArea(matrix));
    }

    /* leetcode 84 */
    public static int largestRectangleArea(int[] arr) {
        int maxArea = 0;
        Stack<Integer> st = new Stack<>();
        st.push(-1);

        for (int i = 0; i < arr.length; i++) {
            while (st.peek() != -1 && arr[i] <= arr[st.peek()]) {
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

    /* leetcode 85 */

    public static int maximalArea(char[][] matrix) {
        int[] height = new int[matrix[0].length];
        int area = 0;

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                int val = matrix[i][j] - '0';
                if (val == 1) {
                    height[j] += val;
                } else {
                    height[j] = 0;
                }
            }
            area = Math.max(area, largestRectangleArea(height));
        }
        return area;
    }
}