class Solution {
public:
    int solve(int digit){
           int sum=0;
          while(digit>0){
            int k=digit%10;
            sum+=k*k;
            digit=digit/10;
          }
    return sum;
    }

    bool isHappy(int n) {
       unordered_map<int,int>map;
       while(n!=1&&map.find(n)==map.end()){
           map[n]++;
           n=solve(n);
       }
     return n==1;
    }
};