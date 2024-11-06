class Solution {
public:
    int strStr(string haystack, string needle) {
       if(haystack.length()<needle.length()) return -1;

         if(haystack.find(needle)==string::npos)
         return -1;


    return  haystack.find(needle);
    }
};