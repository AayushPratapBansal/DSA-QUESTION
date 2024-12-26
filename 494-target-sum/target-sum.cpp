class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) sum += num;

        // If target is out of reachable range
        if (target > sum || target < -sum) return 0;

        // DP array to store counts
        vector<int> dp(2 * sum + 1, 0);
        dp[sum] = 1; // Offset at 0 (no numbers considered yet)

        for (int num : nums) {
            vector<int> next(2 * sum + 1, 0);
            for (int i = 0; i < 2 * sum + 1; i++) {
                if (dp[i] > 0) {
                    next[i + num] += dp[i];
                    next[i - num] += dp[i];
                }
            }
            dp = next;
        }

        return dp[sum + target];
    }
};
