class Solution {
public:
    int solve(int ind, int sum, vector<int>& nums, int target){
        if(ind == nums.size()){
            if(sum == target){
                return 1;
            }
            return 0;
        }

        int add = solve(ind+1, sum + nums[ind], nums, target);
        int sub = solve(ind+1, sum - nums[ind], nums, target);

        return add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, 0, nums, target);
    }
};