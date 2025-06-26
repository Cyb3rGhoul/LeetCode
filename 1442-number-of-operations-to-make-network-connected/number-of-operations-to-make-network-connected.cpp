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

        if(rank[x_par] > rank[y_par]){
            par[y_par] = x_par;
        }
        else if(rank[y_par] > rank[x_par]){
            par[x_par] = y_par;
        }
        else{
            par[x_par] = y_par;
            rank[y_par]++;
        }
    }



    int makeConnected(int n, vector<vector<int>>& connections) {
        par.resize(n);
        rank.resize(n,0);
        if(connections.size()<n-1) return -1;
        
        for(int i = 0; i<n; i++){
            par[i] = i;
        }

        int comp = n; // sabka apna ilaka hai

        for(auto &vec: connections){
            if(find(vec[0]) != find(vec[1])){


                Union(vec[0],vec[1]);
                comp--;

            }
        }

        return comp-1;
    }
};