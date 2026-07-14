class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose matrix first  
         int row=matrix.size();
         int col=matrix[0].size();
         
         for(int i=0;i<row;i++){
                 for(int j=i+1;j<col;j++){
                    swap(matrix[i][j],matrix[j][i]);
                 }
         }

        // reverse the row
        for(int i=0;i<row;i++){
             int first=0; int last=col-1;
             while(first<last){
                swap(matrix[i][first],matrix[i][last]);
                first++;
                last--;
             }
        }
    }
};