class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        char currentChar = 'a';

        while(word.length() < k){
            string nextWord = "";
            for(char ch: word){
                char nextCh = (ch == 'z') ? 'a' : ch+1;
                nextWord += nextCh;
            }
            word += nextWord;
        }
        return word[k-1];
    }
};