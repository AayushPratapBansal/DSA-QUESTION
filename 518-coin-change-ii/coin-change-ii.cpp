class Solution {
public:
   int solve(int  amount,vector<int>&nums, int index,vector<vector<int>>&dp){
        if(amount==0) return 1;
        if(amount<0)  return 0;
        if(dp[amount][index]!=-1) return dp[amount][index];
         int ans1,ans2=0;
        for(int i=index;i<nums.size();i++){
            ans2+=solve(amount-nums[i],nums, i ,dp);
        }
             dp[amount][index]=ans2;
           return dp[amount][index];
   }
    int change(int amount, vector<int>& coins) {
       vector<vector<int>>dp(amount+2,vector<int>(coins.size()+1,-1));
        return solve(amount,coins,0,dp);
    }
};