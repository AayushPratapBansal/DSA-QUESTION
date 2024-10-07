class Solution {
public:  
    int solve(vector<int>&nums,int i,vector<int>&dp){
       if(i>=nums.size()-1)  return 0;
       if(dp[i]!=-1) return dp[i];
       int ans=1e5;
       for(int j=1;j<=nums[i];j++){
        int jump=1+solve(nums,i+j,dp);
          ans=min(ans,jump);
       }
          return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};