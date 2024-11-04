class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
     string ans="";
     int mini=INT_MAX;
       if(strs.size()==0) return " ";
       for(int i=0;i<strs.size();i++){
           if(strs[i].size()<mini)
            mini=strs[i].size();
       }

    string compare=strs[0];
    for(int i=0;i<compare.size();i++){
        for(int j=1;j<strs.size();j++){
              if(strs[j][i]!=compare[i]){
                  return compare.substr(0,i);
              }

        }
    }


   return compare;
    }
};