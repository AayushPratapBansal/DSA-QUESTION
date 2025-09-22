class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> m;
        
        // Count frequencies
        
        int maxFreq = 0;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
           
        }

        // Find maximum frequency
        
        for(auto &p : m){
            maxFreq = max(maxFreq, p.second);
        }

        // Count total elements with max frequency
        int ans = 0;
        for(auto &p : m){
            if(p.second == maxFreq){
                ans += p.second;
            }
        }

        return ans;
    }
};
