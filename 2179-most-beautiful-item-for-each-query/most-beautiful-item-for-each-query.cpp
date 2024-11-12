class Solution {
public:
  vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries){
         sort(items.begin(),items.end());
        vector<int>ans;
      int maxi=items[0][1];
       for(int i=0;i<items.size();i++){
              maxi=max(maxi,items[i][1]);   
              items[i][1]=maxi;
       }
//   sort(queries.begin(),queries.end());
      
       for(int i=0;i<queries.size();i++){
            int low=0,high=items.size()-1;
            int curr=0;
            while(low<=high){
               long long int mid=(low+high)/2;
                if(items[mid][0]<=queries[i]){
                    curr=items[mid][1];
                    low=mid+1;
                }
                else high=mid-1;
            }
         ans.push_back(curr);
       }




    return ans;
  }

//     vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
//         vector<int>ans;
//         sort(items.begin(),items.end());
//            for(int i=0;i<queries.size();i++){
//                     int maxi=0; int j=0;
//                      while(j<items.size()&&items[j][0]<=queries[i] ){
//                             maxi=max(maxi,items[j][1]);
//                             j++;
//                     }
//                ans.push_back(maxi);
//            }

//   return ans;
//     }
};