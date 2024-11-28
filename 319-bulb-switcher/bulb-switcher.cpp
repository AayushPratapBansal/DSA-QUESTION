class Solution {
public:
    int bulbSwitch(int n) {
        int i = 1;
        int g = 0;
        int count = 0 ;
        while(g < n)
        {
            i = i + 2 ;
            g = g + i;
            count = count + 1;
        }
        return count;
    }
};