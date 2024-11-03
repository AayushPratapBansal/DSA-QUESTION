class Solution {
public:
    bool rotateString(string s, string goal) {
        bool flag=true;
        if(s.length()!=goal.length())   return false;
        return (s+s).find(goal)!=string::npos;

    }
};