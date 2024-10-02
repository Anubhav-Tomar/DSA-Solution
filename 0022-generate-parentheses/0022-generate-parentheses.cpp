class Solution {
public:
    void solve(int i, int j, int n, string s,vector<string>& ans){
        if(i == j && i+j == n*2){
            ans.push_back(s);
            return;
        }
        if(i < n){
            solve(i+1, j, n, s+'(', ans);
        }
        if(j < i){
            solve(i, j+1, n, s+')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0, 0, n, "", ans);
        return ans;
    }
};