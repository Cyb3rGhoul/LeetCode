class Solution {
public:
private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int> &vis, vector<int> &pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(dfs(it, adj, vis, pathVis) == true) return true;
            }
            else if(pathVis[it]) return true;
        }

        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        
        // No need to create a separate adjacency list since graph is already in that format
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        vector<int> safe;

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, graph, vis, pathVis);
            }
        }
        
        // A node is safe if it's not part of any cycle
        for(int i = 0; i < V; i++) {
            if(vis[i] && !pathVis[i]) {
                safe.push_back(i);
            }
        }
        
        return safe;
    }
};