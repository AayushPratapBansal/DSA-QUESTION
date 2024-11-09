class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(); int maxi=0; int index=-1;
        int left=0; int right=0; int ans=0;
      // finding max height in array
        for(int i=0;i<n;i++){
            if(height[i]>maxi){
                maxi=height[i];
                index=i;
            }
        }
       //find left ans
       for(int i=0;i<index;i++){
          if(left>height[i])   ans+=left-height[i];
          else left=height[i];
       }
       // find right ans
        for(int i=n-1;i>index;i--){
          if(right>height[i])   ans+=right-height[i];
          else right=height[i];
       }

   return ans;
    }
};