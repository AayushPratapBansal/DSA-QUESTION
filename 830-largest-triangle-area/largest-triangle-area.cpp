class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxTriangleArea = INT_MIN;
        int numPoints = size(points);

        for (int p1 = 0; p1 < numPoints; p1++) {
            for (int p2 = p1 + 1; p2 < numPoints; p2++) {
                for (int p3 = p2 + 1; p3 < numPoints; p3++) {
                    int x1 = points[p1][0], y1 = points[p1][1];
                    int x2 = points[p2][0], y2 = points[p2][1];
                    int x3 = points[p3][0], y3 = points[p3][1];

                    double triangleArea = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
                    maxTriangleArea = max(maxTriangleArea, 0.5 * triangleArea);
                }
            }
        }
        return maxTriangleArea;
    }
};