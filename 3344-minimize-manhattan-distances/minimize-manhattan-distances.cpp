class Solution {
public:
    
    int minimumDistance(vector<vector<int>>& points) {
        map<int,int>mp1,mp2;
        int N=points.size();
         for (int i = 0; i < N; i++) {
          mp1[points[i][0] + points[i][1]]++;
          mp2[points[i][0] - points[i][1]]++;
        
         }
   
 
       int minV=INT_MAX;
        
        for(int i=0;i<N;i++)
        {
            int val1=points[i][0] + points[i][1];
            int val2=points[i][0] - points[i][1];
            mp1[val1]--;
            mp2[val2]--;

            if(!mp1[val1])mp1.erase(val1);
            if(!mp2[val2])mp2.erase(val2);


            int ans1=mp1.rbegin()->first-mp1.begin()->first;
            int ans2=mp2.rbegin()->first-mp2.begin()->first;


            int maxV=max(ans1,ans2);
            minV=min(minV,maxV);
            mp1[val1]++;
            mp2[val2]++;   

        }
    return minV;
    }
};