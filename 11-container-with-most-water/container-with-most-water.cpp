class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea=0,left=0,right=height.size()-1;
        while(left<=right){
             int currarea=min(height[left],height[right])*(right-left);
             maxarea=max(maxarea,currarea);
            if(height[left]<height[right]){
                left++;
            }
            else right--;
        }
      return maxarea;
    }
};