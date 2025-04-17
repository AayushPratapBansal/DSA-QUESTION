class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> valueToIndices;
        int count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            valueToIndices[nums[i]].push_back(i);
        }

        for (auto& entry : valueToIndices) {
            vector<int>& indices = entry.second;
            for (int i = 0; i < indices.size() - 1; ++i) {
                for (int j = i + 1; j < indices.size(); ++j) {
                    if ((1LL * indices[i] * indices[j]) % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};