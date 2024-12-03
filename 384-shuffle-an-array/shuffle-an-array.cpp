class Solution {
public:
vector<int>v1,v2;
    Solution(vector<int>& nums) {
        v1=v2=nums;
    }
    
    vector<int> reset() {
        return v1;
    }
    
    vector<int> shuffle() {
        int t1=rand()%v1.size();
        int t2=rand()%v1.size();
        int temp=v2[t1];
        v2[t1]=v2[t2];
        v2[t2]=temp;
        return v2;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */