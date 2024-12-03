class Solution {
public:
    
    vector<int> manacher(string &s1){
        int n=s1.size();
        
        vector<int> lps(n, 0);
        
        int c=0;
        int r=0;
        
        for (int i=1;i<n-1;i++){
            int mirr= c-(i-c);
            if (i<r){
                lps[i]= min(lps[mirr], r-i);
            }
            while (s1[i+lps[i]+1]==s1[i-lps[i]-1]){
                lps[i]++;
            }
            if (i+lps[i]>r){
                c=i;
                r=i+lps[i];
            }
        }
        
        vector<int> res;
        for (int i=2;i<n-1;i+=2){
            res.push_back(lps[i]);
        }
        
        // now 1 3 3 1 3 1 for "ababbb"
        
        return res;
    }
    
    long long maxProduct(string s) {
        int n=s.size();
        string temp="@";
        temp+='#';
        for (int i=0;i<n;i++){
            temp+=(s[i]);
            temp+=('#');
        }
        temp+=('$');
        
        vector<int> lps = manacher(temp);
        int sz=lps.size();
        
        vector<int> left(sz, 1);
        for (int i=1;i<sz-1;i++){
            int id= i+lps[i]/2;
            left[id]= max(left[id], lps[i]);
        }
        // update the right boundary
        
        for (int i=sz-2;i>=0;i--){
            left[i]= max(left[i], left[i+1]-2);
        }
        // update the shorter ones
        
        // now take preSum
        
        for (int i=1;i<sz;i++){
            left[i]= max(left[i], left[i-1]);
        }
        
        // done for left
        
        vector<int> right(sz, 1);
        for (int i=sz-2;i>=0;i--){
            right[i-lps[i]/2]= max(right[i-lps[i]/2], lps[i]);
        }
        
        for (int i=1;i<sz;i++){
            right[i]= max(right[i], right[i-1]-2);
        }
        
        for (int i=sz-2;i>=0;i--){
            right[i]= max(right[i], right[i+1]);
        }
        
        long long res=0;
        
        for (int i=0;i<sz-1;i++){
            res= max(res, (long long) left[i] *1LL* right[i+1]);
        }
        
        return res;
    }
};