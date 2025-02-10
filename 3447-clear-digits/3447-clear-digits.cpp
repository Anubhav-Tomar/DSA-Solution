class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        string ans = "";

        for(char i: s){
            if(i >= '0' && i <= '9'){
                if(!ans.empty()){
                    ans.pop_back();
                }
            }
            else{
                ans.push_back(i);
            }
        }

        return ans;
    }
};