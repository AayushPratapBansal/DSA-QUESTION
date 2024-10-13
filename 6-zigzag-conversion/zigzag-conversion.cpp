class Solution {
public:
    string convert(string s, int numRows) {
       if(numRows>=s.length()||numRows==1)  return s;
       
        vector<string>ans(numRows);
        int curr=0;
        bool flag=false;
        for(int i=0;i<s.length();i++){
            ans[curr]+=s[i];
            if(curr==0||curr==numRows-1){
                flag=!flag;
            }
        curr+=flag?1:-1;          
        }
        string result="";
        for(int i=0;i<numRows;i++){
            result+=ans[i];
        }

      return result;

    }
};