class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
    long long ans=0;
    long long maxi=INT_MIN;
    
    priority_queue<int>pq(nums.begin(),nums.end());
       for(int i=0;i<k;i++){
            maxi=pq.top(); pq.pop();
            ans+=maxi;
            maxi=ceil(maxi/3.0);
            pq.push(maxi);
       }

    return ans;
    }
};