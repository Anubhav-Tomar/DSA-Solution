class Solution {
public:
    bool solve(int n, vector<int>& nums, int total){
        vector<vector<int> > dp(n+1, vector<int>(total+1, 0));

        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }

        for(int index=n-1; index >= 0; index--){
            for(int target = 0; target <= total/2; target++){
                bool incl = 0;
                if(target - nums[index] >= 0){
                    incl = dp[index+1][target - nums[index]];
                }
                bool excl = dp[index+1][target - 0];
                dp[index][target] = incl or excl;
            }
        }
        return dp[0][total/2];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int total = 0;
        for(int i=0; i<n; i++){
            total += nums[i];
        }

        if(total & 1){
            return 0;
        }

        return solve(n, nums, total);
    }
};