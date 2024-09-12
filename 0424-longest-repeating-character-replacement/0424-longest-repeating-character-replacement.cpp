class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int n = s.length();

        for(int ch='A'; ch<='Z'; ch++){
            int i = 0;
            int j = 0;
            int count = 0;

            while(j < n){
                if(s[j] != ch){
                    count++;
                }

                while(count > k){
                    ans = max(ans, j-i);
                    if(s[i++] != ch){
                        count--;
                    } 
                }
                j++;
            }
            ans = max(ans, j-i);
        }
        return ans;
    }
};