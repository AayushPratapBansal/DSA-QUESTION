class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>m(nums.begin(),nums.end());
    //    if(nums.size()==0)  return 0;
        int ans=0;
       for(int i=0;i<nums.size();i++ ){
          if(m.find(nums[i]-1)==m.end()){
               int j=1;
               while(m.find(nums[i]+j)!=m.end())
                j++;
                ans=max(ans,j);
               
          }
       }
     return ans;
    }
};