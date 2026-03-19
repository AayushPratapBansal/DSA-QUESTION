class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=nums.size();
        return ((nums[i-1]-1)*(nums[i-2]-1));
    }
};