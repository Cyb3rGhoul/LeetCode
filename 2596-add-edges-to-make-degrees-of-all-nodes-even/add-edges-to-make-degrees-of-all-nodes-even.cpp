class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        unordered_map<int,unordered_set<int>> adj;
        for(auto& e: edges){
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }

        vector<int> oddNode;
        for(int i = 1; i<=n; i++){
            if(adj[i].size()%2==1) oddNode.push_back(i);
        }

        if(oddNode.size()==0) return true;

        if(oddNode.size()==2){
            int a = oddNode[0], b = oddNode[1];
            if(!adj[a].count(b)) return true;
            for(int c = 1; c<=n; c++){
                if(c!=a && c!=b && !adj[c].count(a) && !adj[c].count(b)) return true;
            }
        }

        if(oddNode.size()==4){
            int a = oddNode[0], b = oddNode[1], c = oddNode[2], d = oddNode[3];

            return((!adj[a].count(b) && !adj[c].count(d)) || (!adj[a].count(d) && !adj[c].count(b)) || (!adj[c].count(a) && !adj[d].count(b)));
        }

        return false;
    }
};