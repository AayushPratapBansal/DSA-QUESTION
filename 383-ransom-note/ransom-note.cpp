class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>one;
        unordered_map<char,int>two;
        
      for(auto i:ransomNote){
           one[i]++;
        }
       
      for(auto i:magazine){
           two[i]++;
        } 
       for(auto i:one){
         if(two.find(i.first)==two.end()||two[i.first]<i.second)
            return false;
           }
        
     return true;
    }
};