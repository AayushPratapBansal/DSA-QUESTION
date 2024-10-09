class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans=1;
        int prev=-999;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
             if(nums[i]==ans&&prev!=nums[i])
             ans+=1;
             prev=nums[i];
        }
        return ans;



    }
};