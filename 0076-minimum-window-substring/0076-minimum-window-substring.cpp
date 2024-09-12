class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int m = t.size();
        int len = INT_MAX;
        int count = 0;
        int startIndex = -1;

        int map[256] = {0};
        for(int ch=0; ch<m; ch++){
            map[t[ch]]++;
        }

        while(j < n){
            map[s[j]]--;

            if(map[s[j]] >= 0){
                count++; 
            }

            while(count == m ){
                if(len > j-i+1){
                    len = j-i+1;
                    startIndex = i;
                }
                map[s[i]]++;

                if(map[s[i]] > 0){
                    count--;
                }
                i++;
            }
            j++;
        }
        return startIndex == -1 ? "" : s.substr(startIndex, len);
    }
};