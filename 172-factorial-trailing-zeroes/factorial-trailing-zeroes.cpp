class Solution {
public:

    // Trailing zeros

    // count the pairs 2 * 5 becauss that will make 10 that have 1 zero 


    
    int trailingZeroes(int n) {
        int count = 0;

        while(n>=5){
            n /= 5;
            count += n;
        }
        return count;
    }

    
};