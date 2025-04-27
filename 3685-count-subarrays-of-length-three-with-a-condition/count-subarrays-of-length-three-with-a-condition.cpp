class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int answer = 0;
        if (nums.size() < 3) return 0;

        queue<int> q;
        for (int i = 0; i < 3; i++) {
            q.push(nums[i]);
        }

        for (int i = 3; i < nums.size(); i++) {
            int first = q.front(); q.pop();
            int middle = q.front();
            int last = q.back();

            if (first + last == (middle / 2.0)) {
                answer++;
            }

            q.push(nums[i]);
        }

        // Check for the last window
        int first = q.front(); q.pop();
        int middle = q.front();
        int last = q.back();

        if (first + last == (middle / 2.0)) {
            answer++;
        }

        return answer;
    }
};
