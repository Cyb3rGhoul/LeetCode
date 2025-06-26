class Solution {
public:

    vector<int> par;
    vector<int> rank;
    int find(int x){
        if(x==par[x]) return x;
        return par[x] = find(par[x]);
    }

    void Union(int x, int y){
        int x_par = find(x);
        int y_par = find(y);

        if(rank[x_par]>y_par){
            par[y_par] = x_par;
        }

        else if(rank[y_par] > x_par){
            par[x_par] = y_par;
        }

        else{
            par[x_par] = y_par;
            rank[y_par]++;
        }

    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        par.resize(n);
        rank.resize(n,0);


        for(int i = 0; i<n; i++){
            par[i] = i;
        }

        //step 2 = making components using dsu
        for(auto &vec: edges){
            int u = vec[0];
            int v = vec[1];

            Union(u,v);
        }

        unordered_map<int,int> mp;
        
        
        //step -3 (map bana lo)
        for(int i =0; i<n; i++){
            int papa = find(i);
            mp[papa]++;
        }

        // formula hai fir aab wo to nikala padega meri jaan
        // size*(remainingNodes - size) --> issase hume sare components ke connection mil jayenge
        // repeat bhi nahi hoga kyuki remainingNode se hum ek ek karke minus bhi kar re hai
        long long res = 0;
        long long remNodes = n;

        for(auto &it: mp){
            long long s = it.second;
            res += (s)*(remNodes-s);
            remNodes -= s;
        }

        return res;
    }
};