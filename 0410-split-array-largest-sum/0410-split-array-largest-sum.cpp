class Solution {
public:
    int solve(vector<int>& nums, int m){
        int cnt = 1;
        long long sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(sum + nums[i] <= m){
                sum += nums[i];
            }
            else{
                cnt++;
                sum = nums[i];
            }
        }
        return cnt;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k){
            return -1;
        }

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high){
            int mid = (low + high) / 2;
            int ans = solve(nums, mid);

            if(ans > k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return low;
    }
};