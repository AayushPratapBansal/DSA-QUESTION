class Solution {
public:
    string solve(int last,int mask,int &n,map<int,map<int,int>>&mp,vector<string>&words,vector<vector<string>>&dp){
        if(mask==((1<<n)-1)){
            return "";
        }
        if(dp[last+1][mask]!="")
            return dp[last+1][mask];
        string curr="";
        for(int i=0;i<n;i++){
            if((mask>>i)&1)
                continue;
            string temp=words[i].substr(mp[last][i]);
            temp+=solve(i,mask|(1<<i),n,mp,words,dp);
            if(curr=="" || temp.size()<curr.size()){
                curr=temp;
            }
        }
        return dp[last+1][mask]=curr;
    }
    string shortestSuperstring(vector<string>& words) {
        map<int,map<int,int>> mp;
        int n=words.size();
        for(int i=0;i<n;i++){
            mp[-1][i]=0;
            for(int j=0;j<n;j++){
                int m=words[i].size();
                int m2=words[j].size();
                mp[i][j]=0;
                for(int l=1;l<=min(m,m2);l++){
                    string temp=words[i].substr(m-l);
                    string temp2=words[j].substr(0,l);
                    if(temp==temp2){
                        mp[i][j]=l;
                    }
                }
            }
        }
        vector<vector<string>> dp(n+1,vector<string>(1<<n,""));
        return solve(-1,0,n,mp,words,dp);
    }
};