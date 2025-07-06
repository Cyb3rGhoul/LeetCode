class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(x<=y) return y-x;

        queue<pair<int,int>> q;
        unordered_map<int,bool> vis;
        unordered_map<int ,int> dis;
        q.push({x,0});
        vis[x] = true;
        dis[x] = 0;

        while(!q.empty()){
            int sz = q.size(); // level order traversal

            while(sz--){
                pair<int,int> p = q.front();
                q.pop();

                int node = p.first;
                int d = p.second;

                if(node-1>=1 && vis[node-1]==false){
                    vis[node-1] = true;
                    dis[node-1] = d + 1;
                    q.push({node-1,d+1});
                }
                if(node%5==0 && vis[node/5]==false){
                    vis[node/5] = true;
                    dis[node/5] = d + 1;
                    q.push({node/5,d+1});
                }
                if(node%11==0 && vis[node/11]==false){
                    vis[node/11] = true;
                    dis[node/11] = d + 1;
                    q.push({node/11,d+1});
                }
                if(node+1<=x+15 && vis[node+1]==false){
                    vis[node+1] = true;
                    dis[node+1] = d + 1;
                    q.push({node+1,d+1});
                }
            }
        }

        return dis[y];
    }
};