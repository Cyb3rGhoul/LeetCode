class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>& adj, int u, vector<bool>& vis, vector<bool>& inRec){

        vis[u] = true;
        inRec[u] = true;

        for(int &v: adj[u]){
            if(!vis[v] && dfs(adj,v,vis,inRec)){
                return true; //cycle to hai
            }
            else if(inRec[v]==true) return true;
        }
        inRec[u] = false;
        return false;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses,false);
        vector<bool> inRec(numCourses,false);

        unordered_map<int,vector<int>> adj;

        for(auto &vec: prerequisites){
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
        }

        for(int i = 0; i<numCourses; i++){
            if(!vis[i] && dfs(adj,i,vis,inRec)){
                return false;
            }
        }

        return true;
    }
};