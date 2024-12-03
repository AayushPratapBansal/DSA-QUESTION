const int MAX=1e5+5;
typedef unsigned long long ll;
#define rep(i,j,k) for(int i=j;i<k;i++)
const ll m=1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll a=uniform_int_distribution<>(1.8e8, 2e8)(rng);
const ll b=uniform_int_distribution<>(1.8e8, 2e8)(rng);
ll powaA[MAX]{1};
ll powiA[MAX]{1};
ll powaB[MAX]{1};
ll powiB[MAX]{1};
ll powar(ll A,ll B,ll m){
    ll ans=1;
    while(B){
        if(B&1) (ans*=A)%=m;
        (A*=A)%=m;
        B>>=1;
    }
    return ans;
}
void init(){
    for(int i=1;i<MAX;i++){
        powaA[i]=(powaA[i-1]*a)%m;
        powaB[i]=(powaB[i-1]*b)%m;
    }
    ll invA=powar(a,m-2,m);
    ll invB=powar(b,m-2,m);
    for(int i=1;i<MAX;i++){
        powiA[i]=(powiA[i-1]*invA)%m;
        powiB[i]=(powiB[i-1]*invB)%m;
    }
}

struct Hash{
    vector<ll> hA,hrA,hB,hrB;
    int n;
    Hash(vector<int> &s){
        n=s.size();
        hA.resize(n+1,0);
        hrA.resize(n+1,0);
        hB.resize(n+1,0);
        hrB.resize(n+1,0);
        for(int i=1;i<=n;i++){
            hA[i]=(hA[i-1]+s[i-1]*powaA[i-1])%m;
            hrA[i]=(hrA[i-1]+s[n-i]*powaA[i-1])%m;
            hB[i]=(hB[i-1]+s[i-1]*powaB[i-1])%m;
            hrB[i]=(hrB[i-1]+s[n-i]*powaB[i-1])%m;
        }
    }
    pair<ll,ll> subhash(int l,int r,bool empty_flag=false){
        if(empty_flag) return {0,0};
        if(l<=r){
            auto HA = (hA[r+1]+m-hA[l])%m;
            auto HB = (hB[r+1]+m-hB[l])%m;
            return { (powiA[l]*HA)%m, (powiB[l]*HB)%m};
        } else {
            auto HA = (hrA[n-r]+m-hrA[n-l-1])%m;
            auto HB = (hrB[n-r]+m-hrB[n-l-1])%m;
            return { (powiA[n-l-1]*HA)%m, (powiB[n-l-1]*HB)%m };
        }
    }
};

bool check(vector<Hash> & hashes, int len){
    set<pair<ll,ll>> se;
    for(int l = 0, r = l + len - 1; r<hashes[0].n; l++, r++){
        se.insert(hashes[0].subhash(l,r));
    }
    rep(i,1,hashes.size()){
        set<pair<ll,ll>> temp;
        for(int l = 0, r = l + len - 1; r<hashes[i].n; l++, r++){
            auto h = hashes[i].subhash(l,r);
            if(se.count(h)){
                temp.insert(h);
            }
        }
        swap(temp,se);
    }
    return se.size();
}
class Solution {
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        vector<Hash> hashes; init();
        int mini=1e6;
        for(auto &g:paths){
        int x = g.size();
            mini = min(mini, x);
            hashes.emplace_back(Hash(g));
        }
        int l = 1, r = mini, ans = 0;
        while(l<=r){
            int m = (l+r)/2;
            if(check(hashes,m)){

                // cout << m << endl;
                l = m + 1;
                ans = m;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }
};