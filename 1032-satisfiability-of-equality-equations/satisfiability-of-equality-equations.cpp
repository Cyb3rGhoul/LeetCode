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
        
        if(x_par == y_par){
            return;
        }
        
        if(rank[x_par]>rank[y_par]){
            par[y_par] = x_par;
        }
        else if(rank[x_par]<rank[y_par]){
            par[x_par] = y_par;
        }else{
            par[x_par] = y_par;
            rank[y_par]++;
        }
        
    }
    bool equationsPossible(vector<string>& equations) {
        par.resize(26);
        rank.resize(26,0);

        for(int i = 0; i<26; i++){
            par[i] = i;
        }

        //first do the union of equal char
        for(string &s: equations){
            if(s[1]=='='){
                Union(s[0]-'a', s[3]-'a');
            }
        }

        //find != wale case and check validity
        for(string &s: equations){
            if(s[1]=='!'){  
                char f = s[0];
                char sec = s[3];

                int par_f = find(f-'a');
                int par_sec = find(sec-'a');

                if(par_f==par_sec) return false;
            }
        }

        return true;
    }
};