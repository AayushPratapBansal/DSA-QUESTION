class Solution {
public:
    bool is_pre_suf(string w1,string w2)
    {
        int len = w1.size();
        string dum = w1;
        reverse(dum.begin(),dum.end());
        string dummy = w2;
        reverse(dummy.begin(),dummy.end());
        if(w2.substr(0,len)==w1 && dummy.substr(0,len)==dum) return true;
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words.size();j++)
            {
                if(i<j && is_pre_suf(words[i],words[j]))   count++;
            }
        }
        return count;
    }
};