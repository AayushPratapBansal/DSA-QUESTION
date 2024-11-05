class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        map<string,vector<string>>m;

        for(auto i:strs){
             string curr=i;
             sort(i.begin(),i.end());
             m[i].push_back(curr);
        }

        for(auto i:m){
            ans.push_back(i.second);
        }

  return ans;
    }
};