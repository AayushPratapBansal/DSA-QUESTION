class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int ans=1;
        int n=b.size()/a.size();
        string s=a;

   for(int i=0;i<=n+1;i++){
      if(s.find(b)!=string::npos)
        return ans;
     
     s+=a;
     ans++;
   }



   return -1;
    }
};