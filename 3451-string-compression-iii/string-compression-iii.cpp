class Solution {
public:
    string compressedString(string word) {
            string ans;
        
        for(int i=0;i<word.size();){
                char curr=word[i];
                int count=0;

            while(i<word.size()&&count<9&&word[i]==curr){
                count++;
                i++;
            }
            ans+=to_string(count);
            ans+=curr;

        }

          return ans;
    }
};