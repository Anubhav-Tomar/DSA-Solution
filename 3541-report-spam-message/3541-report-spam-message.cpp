class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> s(bannedWords.begin(), bannedWords.end());
        int count = 0;
        for(auto& i: message){
            if(s.count(i) && ++count ==2){
                return true;
            }
        }
        return false;
        
    }
};