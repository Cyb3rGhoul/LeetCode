class Solution {
    int n;
public:
    void dfs(unordered_map<int,vector<int>>& adj, int u, vector<bool>& vis){
        vis[u] = true;
        for(int& v: adj[u]){
            if(vis[v]==false){
                dfs(adj,v,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();

        //visited array bana li taki pata rahe visited hai
        vector<bool> vis(n,false);

        //adjcency list bana li humne dfs ke liye
        unordered_map<int,vector<int>> adj;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int ctn = 0;
        //aab dekho jab tak dfs call chal ri hai tab tak to connection hai
        //jess hi call khatam ho jaye iska matlab ki next wala naya province hai
        //ctn++ kkardo kyuki province hi to dhundhana hai
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(adj,i,vis);
                ctn++;
            }
        }
        return ctn;
    }
};