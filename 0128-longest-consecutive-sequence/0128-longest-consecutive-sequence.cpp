class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int count = 0;
        int ans = 1;
        int prev = INT_MIN;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(nums[i] - 1 == prev){
                prev = nums[i];
                count++;
            }
            else if(prev != nums[i]){
                count = 1;
                prev = nums[i];
            }
            ans = max(count, ans);
        }
        return ans;
    }
};