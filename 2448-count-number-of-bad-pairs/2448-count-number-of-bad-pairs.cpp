class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        long long n = nums.size();

        unordered_map<int, int> freq;

        for(int i=0; i<n; i++){
            int key = nums[i] - i;
            ans += freq[key];
            freq[key]++;
        }
        return (n * (n-1)) / 2 - ans;
    }
};