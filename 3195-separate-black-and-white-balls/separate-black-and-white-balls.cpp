class Solution {
public:
    long long minimumSteps(string s) {
        long long int ans=0;
        int white=0;  int k=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0')
            ans+=white;
            else white++;
        }

   return ans;
    }
};