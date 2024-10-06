class Solution {
public:

    void markSus(vector<vector<int>>& graph, vector<bool>& sus, int k){
        stack<int> st;
        st.push(k);
        sus[k] = true;

        while(!st.empty()){
            int method = st.top();
            st.pop();

            for(auto i: graph[method]){
                if(!sus[i]){
                    sus[i] = true;
                    st.push(i);
                }
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        vector<int> incoming(n, 0);
        vector<bool> sus(n, false);

        for(const auto& i: invocations){
            graph[i[0]].push_back(i[1]);
            incoming[i[1]]++;
        }

        markSus(graph, sus, k);

        for(int i=0; i<n; i++){
            if(!sus[i]){
                for(auto k: graph[i]){
                    if(sus[k]){
                        vector<int> result;
                        for(int j=0; j<n; j++){
                            result.push_back(j);
                        }
                        return result;
                    }
                }
            }
        }

        vector<int> result;
        for(int i=0; i<n; i++){
            if(!sus[i]){
                result.push_back(i);
            }
        }
        return result;
    }
};