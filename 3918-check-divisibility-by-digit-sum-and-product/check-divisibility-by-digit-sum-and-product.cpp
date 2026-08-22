class Solution {
public:
    bool checkDivisibility(int n) {
        int add=0; int mul=1;    int original = n;
           while(n){
              int curr=n%10;
              add+=curr;
              mul*=curr;
              n=n/10;
           }
        // if(mul/add==0) return true;
        int total=add+mul;
            return original%total==0;
    }
};