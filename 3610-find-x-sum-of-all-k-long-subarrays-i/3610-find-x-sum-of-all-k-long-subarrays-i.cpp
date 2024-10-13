class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> answer;
        for(int i=0; i<=n-k; i++){
            unordered_map<int, int> map;
            for(int j=i; j<i+k; j++){
                map[nums[j]]++;
            }
            vector<pair<int,int>> ans;
            for(auto& w: map){
                ans.push_back({w.second, w.first});
            }
            sort(ans.begin(), ans.end(), [](pair<int,int>& a, pair<int,int> &b) {
                if(a.first == b.first){
                    return a.second > b.second;
                }
                return a.first > b.first;
            });
            int sum = 0;
            int total = 0;
            for(auto& p: ans){
                if(total >= x){
                    break;
                }
                sum += p.first * p.second;
                total++;
            }
            answer.push_back(sum);
        }
        return answer;
    }
};