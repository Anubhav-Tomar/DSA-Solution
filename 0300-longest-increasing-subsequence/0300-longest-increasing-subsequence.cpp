class Solution {
public:
    int solve(int n, vector<int>& nums){
        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));

        for(int curr = n-1; curr >= 0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){
                int incl = 0;

                if(prev == -1 || nums[curr] > nums[prev]){
                    incl = 1 + dp[curr+1][curr+1];
                }
                int excl = 0 + dp[curr+1][prev+1];
                dp[curr][prev+1] = max(incl, excl);
            }  
        }
        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return solve(n, nums);
    }
};