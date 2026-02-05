class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
               vector<int> ans(nums.size());
               int n=nums.size();
               for(int i=0;i<nums.size();i++){
                    ans[i]=   nums[(((i+nums[i])%n)+n)%n];

               }
       return ans;
    }

};