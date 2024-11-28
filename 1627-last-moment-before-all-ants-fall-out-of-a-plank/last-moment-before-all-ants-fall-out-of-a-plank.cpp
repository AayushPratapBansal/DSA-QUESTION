class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int fstleft=INT_MIN,fstright=INT_MAX;
        for(int i=0;i<left.size();i++) fstleft=max(fstleft,left[i]);
        for(int j=0;j<right.size();j++) fstright=min(fstright,right[j]);
        if(fstleft==INT_MIN) return n-fstright;
        if(fstright==INT_MAX) return fstleft;
        if(fstright>=fstleft) return max(n-fstright,fstleft);
    //Reduction of mid to original solution.
        //int mid=(fstleft+fstright)/2;
        //int time1=2*(fstleft-mid)+(n-fstleft);
        //int time2=2*(mid-fstright)+(fstright);
        //return max(time1,time2);
    //problem will occur if mid value is fraction in case of odd sum so we'll keep mid same and don't multiply while subtracting.
        //int mid=(fstleft+fstright);
        //int time1=2*(fstleft)-mid+(n-fstleft);
        //int time2=mid-2*(fstright)+(fstright);
        //return max(time1,time2);
    //Now substituting value of mid and simplifying the above equations you can come to original answer whcih is written below.
        

        return max(n-fstright,fstleft);
    }
};