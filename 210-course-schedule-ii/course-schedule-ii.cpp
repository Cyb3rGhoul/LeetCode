class Solution {
public:
    //dfs mari hai simple
    bool hasCycle;
    void dfs(unordered_map<int,vector<int>>& adj, int u, vector<bool>& vis, stack<int>& st, vector<bool>& inR){
        vis[u] = true;
        inR[u] = true;

        for(int &v: adj[u]){
            if(inR[v]==true){
                hasCycle = true;
                return;
            }
            if(!vis[v]){
                dfs(adj,v,vis,st,inR);
            }
        }

        st.push(u);
        inR[u] = false;
    }



    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<bool> vis(numCourses,false);
        vector<bool> inR(numCourses,false);

        for(auto &vec: prerequisites){
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);

        }
        

        stack<int> st;

        for(int i = 0; i<numCourses; i++){
            if(!vis[i]){
                dfs(adj,i,vis,st,inR);
            }
        }

        if(hasCycle==true){
            return {};
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();   
        }

        return res;
    }
};