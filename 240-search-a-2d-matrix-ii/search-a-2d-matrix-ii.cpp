class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col=matrix[0].size(), row=matrix.size();
        int low=0,high=col-1;
        while(low<row&&high<col&&high>=0&&low>=0){
               int mid=matrix[low][high];
               if(mid==target)  return true;
               else if(target<mid)  high--;
               else low++;  



        }






        return false;
    }
};