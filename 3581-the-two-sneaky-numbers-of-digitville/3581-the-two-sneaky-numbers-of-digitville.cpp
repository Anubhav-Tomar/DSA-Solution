class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> map;

        for(int i=0; i<nums.size(); i++){
            map[nums[i]]++;
        }

        for(auto i: map){
            if(i.second == 2){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};