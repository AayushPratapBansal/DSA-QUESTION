class Solution {
public:
    int longestString(int x, int y, int z) {
       if(x == y) return 2*z + 4*x;
       if(x > y) return 2*z+4*y+2;
       return 2*z+4*x+2; 
    }
};