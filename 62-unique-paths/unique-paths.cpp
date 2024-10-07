class Solution {
public:
int solve(vector<vector<int>>&nums,int i, int j){
     if(i==nums.size()-2&&j==nums[0].size()-2)  return 1;
     if(nums[i][j]!=-1) return nums[i][j];
     if(i>=nums.size()-1||j>=nums[0].size()-1) return 0;
     return nums[i][j]=(solve(nums,i+1,j)+solve(nums,i,j+1));
}
    int uniquePaths(int m, int n) {
     vector<vector<int>>nums(m+1,vector<int>(n+1,-1));
     return solve(nums,0,0);   
    }
};