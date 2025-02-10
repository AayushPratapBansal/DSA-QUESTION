class Solution {
public:
    string clearDigits(string s) {
        string ans="";

    for(auto i:s){
        if(isdigit(i)){
            if(!ans.empty()){
                 ans.pop_back();
            }
        }
        else{
            ans.push_back(i);
        }
    }
   return ans;
    }
};