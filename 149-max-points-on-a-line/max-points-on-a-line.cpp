class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        vector<int > A={2,1}; 
        vector<int > B={2,2};
        cal_m_c(A,B);
        if(points.size()<2){
            return points.size();
        }
        map<pair<double,double>,set<vector<int>>> mp;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                vector<int> A=points[i];
                vector<int> B=points[j];
                if(mp.find(cal_m_c(A,B))!=mp.end()){
                    mp[cal_m_c(A,B)].insert(A);
                    mp[cal_m_c(A,B)].insert(B);
                }
                else{
                    set<vector<int>> s;
                    s.insert(A);
                    s.insert(B);
                    mp[cal_m_c(A,B)]=s;
                }
            }
            
        }
        int ans=0;
        for(auto i:mp){
            int b=(i.second).size();
            ans=max(ans,b);
        }
        return ans;
    }
    pair<double,double> cal_m_c(vector<int> A,vector<int> B){
        if(A[0]==B[0]){
            return {A[0],INT_MAX};
        }
        double m=(A[1]-B[1])/((A[0]-B[0])/1.0);
        double  c=A[1]-m*A[0];
        return {m,c};
    }

};