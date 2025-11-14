class Solution {
public:
    int compress(vector<char>& chars) {
         string temp="";
         int n= chars.size();
         for( int i=0;i<n;){
                char curr =chars [i];
                int count =0;
                while(i<n&& chars[i]==curr){
                    count++;
                    i++;
                }
               temp+=curr;
               if(count>1){
                temp+= to_string(count);
               }
         }
   for(int i=0;i<temp.size();i++){
    chars[i]=  temp[i];
   }

cout<<temp.size();
   return temp.size();

    }
};
