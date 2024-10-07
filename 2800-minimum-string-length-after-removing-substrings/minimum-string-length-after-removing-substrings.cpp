class Solution {
public:
    int minLength(string s) {
        stack<char>st;
           st.push(s[0]);
           for(int i=1;i<s.length();i++){
                 if(st.empty()) st.push(s[i]);
                else if(s[i]=='B'&&st.top()=='A')   st.pop();
                else if(s[i]=='D'&&st.top()=='C') st.pop();
                else st.push(s[i]);

           }

      return st.size();
    }
};