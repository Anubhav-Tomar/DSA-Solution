class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> ans1(26, 0);
        vector<int> ans2(26, 0);

        for(char ch: word1){
            ans1[ch-'a']++;
        }

        for(char ch: word2){
            ans2[ch-'a']++;
        }

        for(int i=0; i<26; i++){
            if((ans1[i] == 0 && ans2[i] != 0) || (ans1[i] != 0 && ans2[i] == 0)){
                return false;
            }
        }

        sort(ans1.begin(), ans1.end());
        sort(ans2.begin(), ans2.end());

        return ans1 == ans2;
    }
};