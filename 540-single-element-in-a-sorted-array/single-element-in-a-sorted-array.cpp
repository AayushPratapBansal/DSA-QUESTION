class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
            int ans=-1;
         int low=0,high=nums.size()-1;
         while(low<high){
            int mid=(low+high)/2;
            if(mid%2!=0) mid--;
            if(nums[mid]==nums[mid+1]) low=mid+2;
            else high=mid;


         }



            return nums[low];
    }
};