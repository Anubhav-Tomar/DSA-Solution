class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        vector<int>left(n,1);
        vector<int>right(n,1);
        
        for(int i=1; i<n; i++)
        {
            left[i] = left[i-1] * nums[i-1];
        }
        for(int i=n-2; i>=0; i--)
        {
            right[i] = right[i+1] * nums[i+1];
        }
        for(int i=0; i<nums.size(); i++)
        {
            ans.push_back(left[i] * right[i]);
        }
        return ans;
    }
};