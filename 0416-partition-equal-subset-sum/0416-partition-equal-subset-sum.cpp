class Solution {
public:
    bool solve(int n, vector<int>& nums, int total){
        vector<int> curr(total+1, 0);
        vector<int> next(total+1, 0);

        curr[0] = 1;
        next[0] = 1;

        for(int index=n-1; index >= 0; index--){
            for(int target = 0; target <= total/2; target++){
                bool incl = 0;
                if(target - nums[index] >= 0){
                    incl = next[target - nums[index]];
                }
                bool excl = next[target - 0];
                curr[target] = incl or excl;
            }
            next = curr;
        }
        return next[total/2];
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