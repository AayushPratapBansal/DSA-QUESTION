class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi=0;
         for(int i=0;i<nums.size();i++){
               int curr=abs(nums[(i+1)%nums.size()]-nums[i]);
               maxi=max(maxi,curr);
         }
         return maxi;
    }
};