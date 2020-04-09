class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        if (n == 0)
            return 0;
        
        int[][] dp = new int[n][n];
        // return burstBalloons(nums, 0, nums.length - 1, dp);
        return burstBalloonsDP(nums, 0, nums.length - 1, dp);
    }
    
    public int burstBalloons(int[] arr, int si, int ei, int[][] dp) {
        if (dp[si][ei] != 0)
            return dp[si][ei];
        
        int l = (si - 1) == -1 ? 1 : arr[si - 1];
        int r = (ei + 1) == arr.length ? 1 : arr[ei + 1];
        
        int maxAns = 0;
        for (int cut = si; cut <= ei; cut++) {
            int left = (cut == si) ? 0 : burstBalloons(arr, si, cut - 1, dp);
            int right = (cut == ei) ? 0 : burstBalloons(arr, cut + 1, ei, dp);
            
            int myCost = left + l * arr[cut] * r + right;
            
            if (myCost > maxAns)
                maxAns = myCost;
        }
        
        dp[si][ei] = maxAns;
        return dp[si][ei];
    }
    
    public int burstBalloonsDP(int[] arr, int si, int ei, int[][] dp) {
        for (int gap = 0; gap < arr.length; gap++) {
            for (si = 0, ei = gap; ei < arr.length; si++, ei++) {
                int l = (si - 1 == -1) ? 1 : arr[si - 1];
                int r = (ei + 1 == arr.length) ? 1 : arr[ei + 1];
                
                int myAns = 0;
                for (int cut = si; cut <= ei; cut++) {
                    int left = (cut == si) ? 0 : dp[si][cut - 1];
                    int right = (cut == ei) ? 0 : dp[cut + 1][ei];
                    
                    int myCost = left + l * arr[cut] * r + right;
                    
                    if (myAns < myCost)
                        myAns = myCost;
                }
                dp[si][ei] = myAns;
            }
        }
        return dp[0][arr.length - 1];
    }
}