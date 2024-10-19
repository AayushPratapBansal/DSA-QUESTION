class Solution {
public:
    vector<vector<int>>temp;
    void solve(vector<int>nums, int i,vector<int>&ans){
           if(i==nums.size()) {
            temp.push_back(ans); 
            return;}
           if(i>=nums.size())   return ; 
           solve(nums,i+1,ans);
           ans.push_back(nums[i]);
           solve(nums,i+1,ans);
           ans.pop_back();

    }   
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        solve(nums,0,ans);
        return temp;
    }
};