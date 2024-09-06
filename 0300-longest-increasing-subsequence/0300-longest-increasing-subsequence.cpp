class Solution {
public:
    int solve(int n, vector<int>& nums){
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr = n-1; curr >= 0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){
                int incl = 0;

                if(prev == -1 || nums[curr] > nums[prev]){
                    incl = 1 + nextRow[curr+1];
                }
                int excl = 0 + nextRow[prev+1];
                currRow[prev+1] = max(incl, excl);
            }  
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return solve(n, nums);
    }
};