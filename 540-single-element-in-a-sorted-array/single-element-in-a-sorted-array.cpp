class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    int ans=-1;    
    int low=0; int high=nums.size()-1;
     int mid=0;
     while(low<=high){
        mid=(low+high)/2;
        if(mid==0||mid==nums.size()-1)  break;
        if(nums[mid]!=nums[mid+1]&&nums[mid]!=nums[mid-1]) break;
        if(mid%2==0){
            if(nums[mid]==nums[mid-1])
               high=mid-1;
             else low=mid+1;  
        }
        else if(mid%2!=0){
            if(nums[mid]==nums[mid-1])
                low=mid+1;
            else high=mid-1;
        }
     }

   return nums[mid];
    }
};