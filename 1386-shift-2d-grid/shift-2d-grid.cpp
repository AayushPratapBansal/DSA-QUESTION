class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        k %= (m * n);

        int index = 0, size = m * n;
        queue<int> q;

        while (q.size() < k) {
            q.push(grid[index / n][index % n]);
            index = (index + 1) % size;
        }

        while (index < size) {
            q.push(grid[index / n][index % n]);
            grid[index / n][index % n] = q.front();
            q.pop();
            index++;
        }

        index = 0;
        while (!q.empty()) {
            grid[index / n][index % n] = q.front();
            q.pop();
            index++;
        }

        return grid;
    }
};