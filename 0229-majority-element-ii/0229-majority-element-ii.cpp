class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        vector<int> ans;

        for(int i=0; i<n; i++){
            int key = nums[i];
            map[key]++;
            if(map[key] > n/3 && find(ans.begin(), ans.end(), nums[i]) == ans.end()){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};