class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans;
        int sum = 0;
        vector<int> alt;
        int n = gain.size();
        alt.push_back(0);

        for(int i=0; i<n; i++){
            sum += gain[i];
            alt.push_back(sum); 
        }

        ans = *max_element(alt.begin(), alt.end());
        return ans;
    }
};