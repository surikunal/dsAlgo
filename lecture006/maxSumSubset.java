public class maxSumSubset {
    public static void main(String[] args) {
        int[] arr = {-2, -3, 4, -1, -2, 1, 5, -3};
        System.out.println(maxSum(arr));
    }

    public static int maxSum(int[] arr) {
        int imax = 0;
        int omax = Integer.MIN_VALUE;
        for (int i = 0; i < arr.length; i++) {
            imax += arr[i];

            if (imax < 0) {
                imax = 0;
            }

            else if (imax > omax) {
                omax = imax;
            }
        }
        return omax;
    }
}