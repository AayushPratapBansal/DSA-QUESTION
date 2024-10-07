class Solution {
public:
    vector<vector<int>> generate(int n) {
        // int n=numRows;
       vector<vector<int>>a;
    for(int i=0;i<n;i++){
       vector<int>ans;
        long long int start=1;
       ans.push_back(start);
       for(int j=0;j<i;j++){
           start=start*(i-j);
           start=start/(j+1);
           ans.push_back(start);
       }
       a.push_back(ans);
       ans.clear();
}
       
return a;

    }
};