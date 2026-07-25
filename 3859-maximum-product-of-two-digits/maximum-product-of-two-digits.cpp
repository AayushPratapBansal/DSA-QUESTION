class Solution {
public:
    int maxProduct(int n) {
        int largest=0; int secondlargest=0;
         int number=n;
          while(number>0){
            int curr;
            curr=number%10;
            if(curr>largest){
                secondlargest=largest;
               largest=curr;
             }
             else if(curr>secondlargest){
                secondlargest=curr;
             }
             number=number/10;
          }
         return (largest*secondlargest);
    }
};