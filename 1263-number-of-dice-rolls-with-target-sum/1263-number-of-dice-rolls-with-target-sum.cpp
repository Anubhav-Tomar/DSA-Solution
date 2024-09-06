class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int d, int f, int t){
    vector<int> prev(t+1, 0);
    vector<int> curr(t+1, 0);

    prev[0] = 1;

    for(int dice = 1; dice <= d; dice++){
        for(int target = 1; target <= t; target++){
            int ans = 0;
            for(int i=1; i<=f; i++){
                if( target - i >= 0){
                    ans = (ans + prev[target-i]) % mod;
                }
            }
            curr[target] = ans;
            }
            prev = curr;
        }
        return prev[t];
    }

    int numRollsToTarget(int n, int k, int target) {
        return solve(n, k, target);
    }
};