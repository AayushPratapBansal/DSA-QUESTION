class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string ans1,ans2= "";
        for(auto i:word1){
            ans1+=i;
        }
        for(auto i:word2){
            ans2+=i;
        }
        return ans1==ans2;
        
    }
};