class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& nums) {
        double ans=0;
        double max_diagonal=0;
       for(int i=0;i<nums.size();i++){
              int one=pow(nums[i][0],2);
              int two=pow(nums[i][1],2);

             int curr_diagonal=one+two;
             if(curr_diagonal>max_diagonal||(curr_diagonal==max_diagonal&&(nums[i][0]*nums[i][1])>ans)){
                  ans=nums[i][0]*nums[i][1];
                  max_diagonal=curr_diagonal;
             }


       }
      return ans;
    }
};