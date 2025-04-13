class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        int len = 0;
        int count = 0;

        while(j < n){
            if(nums[j] == 0){
                count++;
            }

            if(count > 1){
                if(nums[i] == 0){
                    count--;
                }
                i++;
            }

            if(count <= 1){
                len = j - i + 1 - count;
                ans = max(ans, len);
            }
            j++;
        }
        if(ans == n){
            return ans-1;
        }

        return ans;
    }
};