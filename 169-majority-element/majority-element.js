/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let freq={};
    let n=nums.length;
   for(let i=0;i<n;i++){
          freq[nums[i]]=(freq[nums[i]]||0)+1;
       if(freq[nums[i]]>n/2){
        return nums[i];
       }
   }
    


};