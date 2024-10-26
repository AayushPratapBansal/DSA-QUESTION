class Solution {
public:
    int possibleStringCount(string word) {
        int count=0;
        for(int i=0;i<word.size()-1;i++){
            if(word[i]!=word[i+1]){
                count++;
            }
        }
        return word.size()-count;
    }
};