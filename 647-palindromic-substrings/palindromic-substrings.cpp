class Solution {
public:

  bool check(string s ,int i, int j){
       while(i<j){
         if(s[i]==s[j]){
            i++,j--;
         }
         else return false;
       }
     return true;
    }

  
    int countSubstrings(string s) {
        int count=0;;
         for(int i=0;i<s.size();i++){
         for(int j=i;j<s.size();j++){
                if(s[i]==s[j]&&check(s, i , j))
                    count++;
         }

      }
     return count;
    }
};