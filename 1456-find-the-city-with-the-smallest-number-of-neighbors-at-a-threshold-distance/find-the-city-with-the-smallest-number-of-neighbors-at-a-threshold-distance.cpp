

class Solution {
public:
#define p pair<int,int>
    void dikstra(int n, unordered_map<int,vector<p>> &adj, vector<int> &res, int source){
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0,source});

        fill(res.begin(),res.end(),INT_MAX);
        res[source] = 0;

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &v: adj[node]){
                int adjNode = v.first;
                int dis = v.second;

                if(d+dis<res[adjNode]){
                    res[adjNode] = d+dis;
                    pq.push({res[adjNode],adjNode});
                }
            }
        }
    }

    int findResCity(int n, vector<vector<int>> &SPM, int D){
        int resCity = -1;
        int leastReach = INT_MAX;

        for(int i = 0; i<n; i++){
            int countReach = 0;
            for(int j = 0; j<n; j++){
                if(i!=j && SPM[i][j]<=D) countReach++;
            }
            if(countReach <= leastReach){
                leastReach = countReach;
                resCity = i;
            }
        }

        return resCity;
    }


    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> SPM(n,vector<int>(n,1e9+7));

        for(int i = 0; i<n; i++){
            SPM[i][i] = 0;
        }

        unordered_map<int,vector<p>> adj;

        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        for(int i = 0; i <n; i++){
            dikstra(n,adj, SPM[i], i);
            //i source hai, spm shortest path from the source ka vector hai and baki dikstra usme store kar dega and bas humko wo value deni hai jisme ki sabse kaam neighbours ho. same hua to maximum value de deni hai
        }

        //find the city iterating over SPM
        return findResCity(n,SPM,distanceThreshold);
    }
};