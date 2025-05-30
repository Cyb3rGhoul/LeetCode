class Solution {
public:

    void dfs(vector<int>& edges, int node, vector<int>& dis, vector<bool>& vis){
        vis[node] = true;
        int v = edges[node];
        if(v!=-1 && !vis[v]){
            vis[v] = true;
            dis[v] = 1 + dis[node];
            dfs(edges, v, dis,vis);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dis1(n,INT_MAX);
        vector<int> dis2(n,INT_MAX);

        vector<bool> vis1(n,false);
        vector<bool> vis2(n,false);

        dis1[node1] = 0;
        dis2[node2] = 0;

        dfs(edges, node1, dis1, vis1);
        dfs(edges, node2, dis2, vis2);

        int minDis = -1;
        int min2 = INT_MAX;

        for(int i = 0; i<n; i++){
            int maxD = max(dis1[i],dis2[i]);

            if(min2 > maxD){
                min2 = maxD;
                minDis = i;
            }
        }

        return minDis;

    }
};