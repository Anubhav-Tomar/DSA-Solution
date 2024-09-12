class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        int len = 0;
        vector<int> map(256, -1);

        while(j < n){
            if(map[s[j]] != -1){
                i = max(i, map[s[j]] + 1);
            }
            len = max(len, j-i+1);
            map[s[j]] = j;
            j++;
        }
        return len;
    }
};