
#define ll long long

int xf;

vector<ll> xm{-2, -2, +2, +2, -1, +1, -1, +1};
vector<ll> ym{-1, +1, -1, +1, -2, -2, +2, +2};

int dp[70000][16][2];

void find(int pos, vector<vector<ll>> &arr, map< pair<int, int>, int> &m, vector< vector<ll> > &g)
{
    int x = arr[pos][0];
    int y = arr[pos][1];
 
    vector<ll> t(51, 0);
    vector< vector<ll> > vis(51, t); // visited array of size 51*51. 
    
    ll n = arr.size();

    queue< tuple<int, int, int> > q;
    q.push({0, x, y}); // push initial postion inside the queue to start bfs search.
    
    tuple<int, int, int> tp;
    int dec = 0;

    while(q.size() > 0 && dec < n) // when dec = n, all positions are visited. 
    {
        tp = q.front(); 
        q.pop();
            
        int step = get<0>(tp);
        x = get<1>(tp);
        y = get<2>(tp);
        
        if(vis[x][y] == 1)
            continue;
        
        vis[x][y] = 1;
        
        if(m.find({x ,y}) != m.end()) // check if (x, y) is a required position. 
        {
            ++dec;
            
            ll p1 = pos;
            ll p2 = m[{x, y}]; // get the index of (x,y) from map.
            
            g[p1][p2] = step; // distance matrix updation (p1 to p2).
        }
        
        for(int i=0; i<8; ++i) // checking all 8 moves. 
        {
            ll nx = x + xm[i];
            ll ny = y + ym[i];
            
            if(nx >= 0 && nx < 50 && ny >= 0 && ny < 50 && vis[nx][ny] == 0) // make sure the new position is not out of the board and its not visited previously. 
            {
                q.push({step+1, nx, ny});
            }
        }
    }
}


int find(int pos, int mask, int stat, vector<vector<ll>> &arr, vector< vector<ll> > &g)
{
    if(mask == xf) // xf = value of mask when all position is visited 
        return 0;
    
    if(dp[mask][pos][stat] != -1)
        return dp[mask][pos][stat];
    
    ll ans;
    
    if(stat == 0)
    {
        ans = 0;
    
        for(int i=1; i<arr.size(); ++i)
        {
            ll rp = i-1;       
            int bit = (mask >> rp) & 1;
            
            if(!bit)
            {
                mask = mask | (1<<rp);
                ans = max(ans, g[pos][i] + find(i, mask, 1, arr, g)); // g[pos][i] = steps required to go from pos to i.
                mask = mask ^ (1<<rp);
            }
        }
    }

    else if(stat == 1)
    {
        ans = 1e9;
        
        for(int i=1; i<arr.size(); ++i)
        {
            ll rp = i-1;       
            int bit = (mask >> rp) & 1;
            
            if(!bit)
            {
                mask = mask | (1<<rp);
                ans = min(ans, g[pos][i] + find(i, mask, 0, arr, g));
                mask = mask ^ (1<<rp);
            }
        }
    }

    return dp[mask][pos][stat] = ans;
}



class Solution {
public:
    int maxMoves(int kx, int ky, vector<vector<int>>& pos) {
        
        memset(dp, -1, sizeof(dp));
        
        vector<vector<ll>> arr; // creating new array with starting position included. 
        arr.push_back({kx, ky});
        
        map< pair<int, int>, int> m; // map to keep track of index of each position. 
        m[{kx, ky}] = 0; // index of starting position = 0.
        
        for(int i=0; i<pos.size(); ++i)
        {
            arr.push_back({pos[i][0], pos[i][1]}); 
            m[{pos[i][0], pos[i][1]}] = i+1; 
        }
        
        ll n = arr.size();
            
        vector< ll > v(n+1, 0);
        vector< vector<ll> > g(n+1, v); // distance matrix.
        
        for(int i=0; i<arr.size(); ++i)
        {
            find(i, arr, m, g); // pre-computing from each position.
        }
        
        n = n-1;
        xf = pow(2, n)-1; // xf = value of mask when all positions are visited.
        
        ll ans = find(0, 0, 0, arr, g);
        
        return ans;
    }
};

