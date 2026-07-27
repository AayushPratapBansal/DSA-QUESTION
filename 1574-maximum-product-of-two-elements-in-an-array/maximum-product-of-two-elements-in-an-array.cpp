class Solution {
public:
    int maxProduct(vector<int>& nums) {
                 int largest=0; int secondlargest=0;
                 for(int i=0;i<nums.size();i++){
                    if(nums[i]>largest){
                        secondlargest=largest;
                        largest=nums[i];
                    }
                  else if(nums[i]>secondlargest){
                    secondlargest=nums[i];                 
                 }

    }
    return  (largest-1)*(secondlargest-1);
    }
   
};