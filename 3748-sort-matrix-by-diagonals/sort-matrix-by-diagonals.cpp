#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        unordered_map<int, vector<int>> mp;

        // Step 1: Collect elements along diagonals (key = i - j)
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int key = i - j;
                mp[key].push_back(grid[i][j]);
            }
        }

        // Step 2: Sort diagonals
        for(auto &p : mp) {
            int key = p.first;
            if(key < 0) {
                sort(p.second.begin(), p.second.end()); // ascending
            } else {
                sort(p.second.begin(), p.second.end(), greater<int>()); // descending
            }
        }

        // Step 3: Place back into grid
        unordered_map<int, int> idx; // pointer for each diagonal
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int key = i - j;
                grid[i][j] = mp[key][idx[key]++];
            }
        }
        
        return grid;
    }
};