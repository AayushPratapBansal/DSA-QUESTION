class Solution {
public:
    int maximumGap(vector<int>& nums) {
       
        if(nums.size()<=1)   return 0;
        sort(nums.begin(),nums.end());
        int ans=INT_MIN;
        for(int i=1;i<nums.size();i++){
             
             if(nums[i]-nums[i-1]>ans){
                 ans=nums[i]-nums[i-1];
             }

        }

      return ans;
    }
};