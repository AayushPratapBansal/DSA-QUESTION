class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int &i:nums){
            m[i]++;
        }
        for(int i = 0;i<32;i++){
            if(!m.count(1<<i)){
                return 1<<i;
            }
        }
        return 1<<32;
    }
};