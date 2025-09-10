class Solution {
public:
    bool findIt(int a, int b, vector<vector<int>>& lan){
        unordered_set<int> bset;
        for(int i = 0; i<lan[b-1].size(); i++){
            bset.insert(lan[b-1][i]);
        }
        // cout<<a<<" "<<b<<endl;
        int ctn = 0;
        for(int i = 0; i<lan[a-1].size(); i++){
            if(bset.count(lan[a-1][i])) return true;
        }
        return false;
    }
    int minimumTeachings(int n, vector<vector<int>>& lan, vector<vector<int>>& f) {
        int m = f.size();
        unordered_map<int,int> notPoss;
        int ctn = INT_MAX;
        for(int i = 0; i<m; i++){
            int a = f[i][0];
            int b = f[i][1];

            if(!findIt(a,b,lan)){
                // cout<<a<<" "<<b<<endl;
                // cout<<endl;
                notPoss[a]++;
                notPoss[b]++;
            }
        }

        for(int i = 1; i<=n; i++){
            int temp = 0;
            for(auto& it: notPoss){
                bool isPres = false;
                // cout<<"ind: "<<it.first<<endl;
                for(int j = 0; j<lan[it.first-1].size(); j++){
                    if(lan[it.first-1][j]==i) {
                        // cout<<lan[it.first-1][j]<<" "<<i<<" check"<<endl;
                        isPres = true;
                        break;
                    }
                }
                if(!isPres) temp++;
                // else cout<<"index changing"<<endl;
            }   
            // cout<<ctn<<" "<<temp<<endl;
            ctn = min(temp,ctn);
            // cout<<endl;
        }
        return ctn;
        
    }
};