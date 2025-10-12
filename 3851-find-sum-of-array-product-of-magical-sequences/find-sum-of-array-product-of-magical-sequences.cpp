static constexpr int MOD = 1e9 + 7;
static int combinations[31][31] = {{0}}; 
static int memo[31][31][50][31];

class Solution {
    int totalPositions, requiredSetBits, arraySize;
    
    void buildCombinationsTable() { 
        if (combinations[0][0] == 1) return; 
        
        for (int n = 1; n <= 30; n++) { 
            combinations[n][0] = combinations[n][n] = 1; 
            for (int r = 1; r <= n/2; r++) { 
                int value = combinations[n-1][r-1] + combinations[n-1][r]; 
                combinations[n][r] = combinations[n][n-r] = value; 
            } 
        }
    }
   
    int solve(int positionsLeft, int setBitsNeeded, int currentIndex, unsigned binaryState, vector<int>& values) {
        int setBitsInState = __builtin_popcount(binaryState);
        
        if (positionsLeft < 0 || setBitsNeeded < 0 || positionsLeft + setBitsInState < setBitsNeeded)
            return 0;
            
        if (positionsLeft == 0)
            return (setBitsNeeded == setBitsInState) ? 1 : 0;
            
        if (currentIndex >= arraySize) 
            return 0;

        if (memo[positionsLeft][setBitsNeeded][currentIndex][binaryState] != -1) 
            return memo[positionsLeft][setBitsNeeded][currentIndex][binaryState];

        long long totalSum = 0;
        long long valuePower = 1;
        int currentValue = values[currentIndex];
        
        for (int frequency = 0; frequency <= positionsLeft; frequency++) {
            long long arrangementsTimesProduct = combinations[positionsLeft][frequency] * valuePower % MOD;

            unsigned updatedState = binaryState + frequency;
            unsigned stateForNextIndex = updatedState >> 1;
            bool createdSetBit = updatedState & 1;

            long long waysFromHere = solve(
                positionsLeft - frequency, 
                setBitsNeeded - createdSetBit, 
                currentIndex + 1, 
                stateForNextIndex, 
                values
            );
            
            totalSum = (totalSum + arrangementsTimesProduct * waysFromHere) % MOD;
            valuePower = (valuePower * currentValue) % MOD;
        }

        memo[positionsLeft][setBitsNeeded][currentIndex][binaryState] = totalSum;
        return totalSum;
    }

public:
    int magicalSum(int m, int k, vector<int>& nums) {
        buildCombinationsTable();
        
        totalPositions = m;
        requiredSetBits = k; 
        arraySize = nums.size();
        
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= m; j++)
                for (int idx = 0; idx < arraySize; idx++)
                    memset(memo[i][j][idx], -1, sizeof(int) * (m + 1));

        return solve(m, k, 0, 0, nums);
    }
};