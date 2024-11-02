class Solution {
public:
    bool isCircularSentence(string s) {
     
      bool flag=true;
      if(s[0]!=s[s.length()-1])   return false;
       
       for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                 if(s[i-1]!=s[i+1])
                    return false;
            }
            else continue;
       }


   return flag;
    }
};