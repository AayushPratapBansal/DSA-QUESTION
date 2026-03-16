/**
 * @param {string} s
 * @return {number}
 */
var maxDifference = function(s) {
      
     let freq={};
     for(let i of s){
        freq[i]=(freq[i]||0)+1;
     }
     let maxi_odd=0;
     let mini_even=101;

     for(let i in freq){
        if(freq[i]%2===1)  maxi_odd=Math.max(maxi_odd,freq[i]);
        else{
            mini_even=Math.min(mini_even,freq[i]);
        }

     }

     return (maxi_odd-mini_even);
       
};