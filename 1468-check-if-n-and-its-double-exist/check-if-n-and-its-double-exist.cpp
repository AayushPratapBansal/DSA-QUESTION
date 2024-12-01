class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>map;
        map[0]=-1;
        for(auto i:arr){
            map[i]++;
           }

         for(auto val:arr){
           if(val%2){
              if(map[val+val])
               return true;
           }   
           else if(map[val/2])  return true;
         }

    return false;
    }
};