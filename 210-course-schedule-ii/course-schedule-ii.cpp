class Solution {
public:
    vector<int> solve(int n, unordered_map<int,vector<int>>& adj, vector<int>& ind){
        queue<int> q;
        vector<int> res;

        for(int i = 0; i<n; i++){
            if(ind[i]==0){
                res.push_back(i);
                q.push(i);
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int &v: adj[u]){
                ind[v]--;
                if(ind[v]==0){
                    res.push_back(v);
                    q.push(v);
                }
            }
        }

        if(res.size()==n) return res;
        return {};
    }



    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> ind(numCourses,0);
        for(auto &vec: prerequisites){
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);

            ind[a]++;
        }

        // vector<int> res;
        return solve(numCourses,adj,ind);
        // return res;
    }
};