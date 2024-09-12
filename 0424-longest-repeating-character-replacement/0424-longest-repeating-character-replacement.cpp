class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(); 
        int i = 0;
        int j = 0;
        int len = 0;
        int ans = 0;

        vector<int> hash(26,0);

        while(j < n){
            hash[s[j]-'A']++;
            len = max(len, hash[s[j]-'A']);
            if((j - i + 1) - len > k){
                hash[s[i]-'A']--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};