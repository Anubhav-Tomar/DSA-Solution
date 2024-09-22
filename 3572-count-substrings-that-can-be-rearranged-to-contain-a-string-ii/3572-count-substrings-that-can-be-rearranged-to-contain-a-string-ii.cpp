class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        if(m > n){
            return 0;
        }

        unordered_map<char, int> ch1;
        unordered_map<char, int> ch2;

        for(char c: word2){
            ch2[c]++;
        }
        long long ans = 0;

        int req = ch2.size();
        int i = 0;
        int j = 0;

        for(int k=0; k<n; k++){
            char c = word1[k];
            ch1[c]++;

            if(ch2.count(c) && ch1[c] == ch2[c]){
                i++;
            }

            while(i == req) {
                ans += n-k;
                char w = word1[j];
                ch1[w]--;
                if(ch2.count(w) && ch1[w] < ch2[w]){
                    i--;
                }
                j++;
            }
        }
        return ans;
    }
};