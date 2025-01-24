class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto i:flights){
            adj[i[0]].push_back({i[1], i[2]});
        }
        queue<pair<int, pair<int,int>>> q;
        vector<int> dis(n, 1e9);
        q.push({0, {src, 0}});
        dis[src] = 0;

        while(!q.empty()){
            auto i=q.front();
            q.pop();
            int stops = i.first;
            int node = i.second.first;
            int cost = i.second.second;

            for(auto i: adj[node]){
                int adjNode = i.first;
                int edgW = i.second;
                if(cost + edgW < dis[adjNode] && stops<=k){
                    dis[adjNode] = cost + edgW;
                    q.push({1+stops, {adjNode, cost+edgW}});
                }
            }
        }
        if(dis[dst] == 1e9){
            return -1;
        }
        return dis[dst];
    }
};