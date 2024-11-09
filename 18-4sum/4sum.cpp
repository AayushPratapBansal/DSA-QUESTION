class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
          vector<vector<int>>ans;
    //  int target=0;
    
     set<vector< int>>s;
     sort(nums.begin(),nums.end());
     if(nums.size()<=3) return ans;
    // if(nums.size()<=3){
    //     int sum=0;
    //     for(int i=0;i<nums.size();i++){
    //        sum+=nums[i];
    //     }
    //     if(sum==target){
    //         ans.push_back(nums);
    //         return ans;
    //     }
    // }
    if(nums[0]>0&&target==0) return ans;
    for(int a=0;a<nums.size()-3;a++){
       for(int i=a+1;i<nums.size()-2;i++){
         int j=i+1;
         int k=nums.size()-1;
         while(j<k){
        //    long long sum=nums[i]+nums[j]+nums[a]+nums[k];
        long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[a] + nums[k];

           if(sum==target){
               s.insert({nums[a],nums[i],nums[j],nums[k]});
               j++;
               k--;
           }
           else if(sum<target){
            j++;
           }
           else k--;
         }
     }
    }
     for(auto i:s){
        ans.push_back(i);
     }

      return ans;
    }
};