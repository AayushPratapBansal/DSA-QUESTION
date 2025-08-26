class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& nums) {
        double ans=0;
        double max_diagonal=0;
       for(int i=0;i<nums.size();i++){
              int one=nums[i][0];
              int two=nums[i][1];

             int curr_diagonal=one*one+two*two;
             if(curr_diagonal>max_diagonal||(curr_diagonal==max_diagonal&&one*two>ans)){
                  ans=one*two;
                  max_diagonal=curr_diagonal;
             }


       }
      return ans;
    }
};