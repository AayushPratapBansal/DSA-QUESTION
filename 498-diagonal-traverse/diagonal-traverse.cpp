class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> result;   // no size reserved

        int row = 0, col = 0;
        for (int i = 0; i < m * n; i++) {
            result.push_back(mat[row][col]);

            // Moving up-right
            if ((row + col) % 2 == 0) {
                if (col == n - 1) row++;
                else if (row == 0) col++;
                else { row--; col++; }
            }
            // Moving down-left
            else {
                if (row == m - 1) col++;
                else if (col == 0) row++;
                else { row++; col--; }
            }
        }
        return result;
    }
};
