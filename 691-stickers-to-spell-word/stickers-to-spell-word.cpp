class Solution {
public:
    int solve(int mask, vector<string>& stickers, string target, int n, int m, vector<int>& dp) {
        // Base case: If all characters in the target are covered by stickers, return 0.
        if (mask == (1 << m) - 1) {
            return 0;
        }
        // If the state represented by the mask has been calculated before, return the result.
        if (dp[mask] != -1) {
            return dp[mask];
        }
        // Initialize answer to a large value.
        int ans = 1e9;
        
        // Iterate through each sticker.
        for (int i = 0; i < n; i++) {
            // Count the frequency of each character in the current sticker.
            vector<int> freq(26, 0);
            for (auto ele : stickers[i]) {
                freq[ele - 'a']++;
            }
            int new_mask = 0;
            // Check if the characters in the target can be covered by the current sticker.
            for (int j = 0; j < m; j++) {
                if (((1 << j) & mask) == 0) {
                    if (freq[target[j] - 'a']) {
                        freq[target[j] - 'a']--;
                        new_mask |= (1 << j);
                    }
                }
            }
            // If new_mask is not zero, update the answer and make a recursive call.
            if (new_mask != 0) {
                ans = min(ans, 1 + solve(new_mask | mask, stickers, target, n, m, dp));
            }
        }
        // Memoize the result for the current state.
        return dp[mask] = ans;
    }
    
    int minStickers(vector<string>& stickers, string target) {
        int mask = 0;
        int n = stickers.size();
       int m = target.size();
        // Initialize memoization table with -1.
        vector<int> dp(1 << m, -1);
        // Call the recursive function to calculate the minimum stickers required.
        int ans = solve(mask, stickers, target, n, m, dp);
        // If ans is still 1e9, it means no combination of stickers can cover the target.
        return ans == 1e9 ? -1 : ans;
    }
};