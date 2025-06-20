class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        int maxi = 0;
        int mini = s.size();

        for(auto ch: s){
            freq[ch - 'a']++;
        }

        for(auto i: freq) {
            if(i % 2 != 0){
                maxi = max(maxi, i);
            }
            else if(i != 0) {
                mini = min(mini, i);
            }
        }

        return maxi - mini;
    }
};