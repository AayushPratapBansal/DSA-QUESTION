class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        vector<int>degree(n,0);
        for(int i=0;i<edges.size();i++){
               degree[edges[i][1]]++;
        }
        int count=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(degree[i]==0){
             count++; 
              ans=i;
            }
        }
   return count>1?-1:ans;


    }
};