class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        if(s.length()<=2)   return s;
      
        for(int i=0;i<s.length();i++){
             
             if(ans.length()<2)   ans+=s[i];
             else if(s[i]==s[i-2]&&s[i]==s[i-1])
               continue; 
              else  ans+=s[i];
      
        }


        return ans;
    }
};