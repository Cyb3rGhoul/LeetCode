class Solution {
public:
    bool bfs(vector<vector<int>>& adj, int curr, vector<int>& col, int currCol){
        queue<int> q;
        q.push(curr);
        col[curr] = currCol;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int &v: adj[u]){
                if(col[v]==col[u]) return false;
                else if(col[v]==-1){
                    col[v] = 1-col[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();

        vector<int> col(V,-1);

        for(int i = 0; i<V; i++){
            if(col[i]==-1){
                if(bfs(adj,i,col,1)==false) return false;
            }
        }

        return true;
    }
};