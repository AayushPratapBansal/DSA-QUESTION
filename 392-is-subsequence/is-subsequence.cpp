class Solution {
public:

     void solve(string s,string t,int i,string ans,bool &flag){
           if(ans==s) flag=true;
           if(flag==true||i>=t.size()) return;
           solve(s,t,i+1,ans+t[i],flag);
           solve(s,t,i+1,ans,flag);

     }


    bool isSubsequence(string s, string t) {
        bool flag=false;
        int k=s.length();
        int l=t.length();
        int  i=0,j=0;
        while(i<k&&j<l){
              if(s[i]==t[j]){
                i++;
              }
               j++;
        }
        return i==k;
        
        
        }
};