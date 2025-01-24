class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLength = 0;

        for(int i=0; i<s.size(); i++){
            isPalindrome(s, i, i, start, maxLength);
            isPalindrome(s, i, i+1, start, maxLength);
        }
        return s.substr(start, maxLength);
    }

    void isPalindrome(string &s, int left, int right, int &start, int &maxLength){
        while(left>=0 && right<s.size() && s[left] == s[right]){
            left--;
            right++;
        }

        if(right - left - 1 > maxLength){
            start = left + 1;
            maxLength = right - left - 1;
        }
    }
};