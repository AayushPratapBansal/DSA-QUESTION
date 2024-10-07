class Solution {
public:

   bool solve(vector<int>&nums,int i,vector<long int>&dp){

        if(i>=nums.size()-1)  return true; 
        if(dp[i]!=-1) return dp[i];
        if(nums[i]==0) return false;
        for(int k=1;k<=nums[i];k++){
           if(k<nums.size()&&solve(nums,i+k,dp)) return dp[i]=true;
       }
       return dp[i]=false;
         
   }

    bool canJump(vector<int>& nums) {
    // bool flag=false;
    vector<long int>dp(nums.size(),-1);
     return solve(nums,0,dp);
    }
};