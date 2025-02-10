class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        stack<char> st;

        for(char ch: s){
            if(ch>='0' && ch<='9' && (!st.empty())){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }

        s = "";

        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }

        reverse(s.begin(), s.end());
        return s;
    }
};