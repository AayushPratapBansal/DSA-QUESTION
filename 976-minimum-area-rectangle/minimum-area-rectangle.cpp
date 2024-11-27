class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> mp;
        int min_area = INT_MAX;
        for(auto point: points){
            mp[point[0]].insert(point[1]);
        }
        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                int x_1 = points[i][0];
                int y_1 = points[i][1];
                int x_2 = points[j][0];
                int y_2 = points[j][1];
                if(x_1==x_2 || y_1==y_2){
                    continue;
                }
                if(mp[x_1].count(y_2) && mp[x_2].count(y_1)){
                    int area = abs(x_1-x_2) * abs(y_1-y_2);
                    min_area = min(min_area, area);
                }
            }
        }
        return min_area == INT_MAX? 0: min_area;
    }
};