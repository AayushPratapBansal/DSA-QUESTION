class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();   
        int col=matrix[0].size();
        int low=0; int high=row*col-1;
        while(low<=high){
            int mid=(low+high)/2;
             int curr_row=mid/col;  int curr_col=mid%col;
             int curr=matrix[curr_row][curr_col];
            
             if(curr==target) return true;
             if(curr<target) low=mid+1;
             else high=mid-1;
    
    
    
        }




        return false;
    }
};