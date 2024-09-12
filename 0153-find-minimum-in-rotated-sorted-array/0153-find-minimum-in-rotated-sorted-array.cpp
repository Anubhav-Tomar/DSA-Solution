class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = nums[0];
        for(int i : nums){
            mini = min(mini, i);
        }    
        return mini;
    }
};