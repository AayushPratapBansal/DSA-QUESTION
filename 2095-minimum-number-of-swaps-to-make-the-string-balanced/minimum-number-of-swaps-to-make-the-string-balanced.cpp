class Solution {
public:
    int minSwaps(string s) {
         stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='[') st.push(s[i]);
            else if(!st.empty()&&st.top()=='[') st.pop();
            else st.push(s[i]);
        }
        int ans=-1;
        ans=st.size()/2;
        ans=ceil(ans/2.0);
       return ans;
    }
};