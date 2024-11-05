class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_map<int,int>m;
       for(int i=0;i<nums.size();i++){
         int curr=nums[i];
        if(m.find(curr)!=m.end()&&abs(i-m[curr])<=k)
            return true;
        else m[curr]=i;
       }
      return false;
    }
};