class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int>m;
        unordered_map<char,int>k;

         for(int i=0;i<s.size();i++){
           if(m.find(s[i])==m.end()){
              m[s[i]]=i;
           }
           if(k.find(t[i])==k.end()){
              k[t[i]]=i;
           }
          if(m[s[i]]!=k[t[i]]){
            return false;
          }
         }

return true;
    }
};