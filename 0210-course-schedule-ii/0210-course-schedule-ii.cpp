class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto i: prerequisites){
            int u = i[0];
            int v = i[1];
            adj[v].push_back(u);
        }

        vector<int> indegree(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            for(auto j: adj[i]){
                indegree[j]++;
            }
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto i: adj[node]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }

        if(ans.size() == numCourses){
            return ans;
        }

        return {};
    }
};