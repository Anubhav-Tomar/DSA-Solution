class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int inc = 1;
        int des = 1;
        int ans = 0;

        if(n == 1){
            return 1;
        }

        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]){
                inc++;
                des = 1;
            }
            else if(nums[i] < nums[i-1]) {
                des++;
                inc = 1;
            }
            else {
                des = inc = 1;
            }
            ans = max(ans, max(inc, des));
        }
        return ans;
    }
};