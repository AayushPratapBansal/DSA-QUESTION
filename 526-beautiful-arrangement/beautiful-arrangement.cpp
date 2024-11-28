class Solution {
public:

    // Method 1 - Find all permutations and check if it is beautiful
    // TC = O(N* N!) , SC = O(N) -> for making vector of 1 to N
    // But TLE
    // bool isBeautiful(vector<int> & v){
    //     for(int i = 0; i < v.size() ; i++){
    //         if( ((v[i] % (i+1)) !=0 ) && ( ((i+1) % v[i])!= 0) ){
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // int countArrangement(int n) {
    //     vector<int> v;
    //     for(int i = 1 ; i <= n ; i++){
    //         v.push_back(i);
    //     }

    //     int ans = 0;
    //     // for 1st permutation
    //     if(isBeautiful(v)){
    //         ans++;
    //     }

    //     while(next_permutation(v.begin(),v.end())){
    //         if(isBeautiful(v)){
    //             ans++;
    //         }
    //     }
    //     return ans;
    // }


    // Logic -
    // keep each element on eac index and check if we can keep that there
    // create vector of size n + 1 bec of 1 based indexing
    // if v[i] == 0 means that pos is empty and we can keep element there if givem 2 conditions meet
    // Back Tracking - While returning when we dont have to keep element at that pos, remove it by doing v[i] = 0

    void solve(vector<int> &v , int n ,int currNum, int &ans){
        
        // BC
        // when we placed 1 -> n elemenets
        if(currNum == n+1){
            ans++;
            return ;
        }


        // solve 1 case
        for(int i =1 ; i <=n ; i++){
            // if pos is empty and 2 conditions meet
            if( v[i] == 0 && ( currNum % i == 0 || i % currNum == 0) ){

                // place element 
                v[i] = currNum;
                
                // RC for other elements
                solve(v,n,currNum+1, ans);

                // BT - unplace element
                v[i] = 0;
            }
        }
    }

    int countArrangement(int n) {
        vector<int> v (n+1,0);
        int ans = 0;
        int currNum  = 1;
        solve(v, n, currNum, ans);
        return ans;
    }
};