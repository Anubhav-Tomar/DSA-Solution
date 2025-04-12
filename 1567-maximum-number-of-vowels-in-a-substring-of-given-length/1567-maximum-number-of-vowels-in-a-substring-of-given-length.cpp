class Solution {
public:
    int isVovel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return 1;
        }
        return 0;
    }
    int maxVowels(string s, int k) {
        int ans = 0;
        int count = 0;
        int n = s.length();

        for(int i=0; i<n; i++){
            count += isVovel(s[i]);

            if(i >= k){
                count -= isVovel(s[i - k]);
            }

            ans = max(ans, count);
        }
        return ans;
    }
};