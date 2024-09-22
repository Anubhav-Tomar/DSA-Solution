class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int ans[26] = {0};
        for(char c: word2){
            ans[c - 'a']++;
        }

        int temp[26] = {0};
        int l = 0;
        int n = word2.length();
        long long res = 0;

        for(int i=0; i<word1.length(); i++){
            char c = word1[i];

            if(ans[c - 'a'] > 0){
                if(temp[c - 'a'] < ans[c - 'a']){
                   n--;
                }
            }
            temp[c - 'a']++;

            while(n == 0){
                res += word1.length() - i;
                char sc = word1[l];
                temp[sc - 'a']--;

                if(ans[sc - 'a'] > 0 && temp[sc - 'a'] < ans[sc - 'a']){
                    n++;
                }
                l++;
            }
        }
        return res;
    }
};