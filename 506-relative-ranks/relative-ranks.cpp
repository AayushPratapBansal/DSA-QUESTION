class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
             vector<string>ans(score.size(),"");
             priority_queue<pair<int,int>>pq;
             for(int i=0;i<score.size();i++){
                pq.push({score[i],i});
             }
             int index=-1;   int i=1;
            while(!pq.empty()){
                index= pq.top().second;
                 if(i==1)    ans[index]="Gold Medal";
                 else if(i==2)   ans[index]="Silver Medal";
                 else if(i==3)    ans[index]="Bronze Medal";
                   else ans[index]=to_string(i);
                   i++;
                   pq.pop();
            }
   return ans;
    }
};