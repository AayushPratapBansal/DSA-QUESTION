class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
      ans.push_back(1);
     long long int start=1;
      for(int i=0;i<rowIndex;i++){
        start=start*(rowIndex-i);
        start=start/(i+1);
       ans.push_back(start);
      }
      return ans;
    }
};