class Solution {
public:
    bool isBalanced(string nums) {
        int even=0;
        int odd=0;
        for(int i=0;i<nums.size();i++){
           if(i%2==0) even+=nums[i]-'0';
           else odd+=nums[i]-'0';
        }
        return  odd==even;

    }
};