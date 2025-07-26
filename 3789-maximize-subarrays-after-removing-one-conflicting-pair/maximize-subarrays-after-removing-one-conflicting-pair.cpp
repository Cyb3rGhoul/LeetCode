#define ll long long
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        int m = conflictingPairs.size();

        vector<vector<pair<int,int>>> start(n+1);
        for(int i = 0; i<m; i++){
            int a = min(conflictingPairs[i][0],conflictingPairs[i][1]);
            int b = max(conflictingPairs[i][0],conflictingPairs[i][1]);

            start[a].push_back({b,i});
        }

        set<pair<int,int>> active;
        vector<int> cnt(n+1,0);
        ll base = 0;
        vector<ll> imp(m,0);

        for(int i =n; i>=1; i--){
            for(auto [r,k] : start[i]){
                active.insert({r,k});
                cnt[r]++;
            }

            if(active.empty()){
                base += (ll)(n+1-i);
            }

            else{
                int minR = active.begin()->first;
                base += (ll)(minR - i); 
                if(cnt[minR]==1){
                    int k_i = active.begin()->second;
                    auto next_it = active.upper_bound({minR,m});
                    int minR2 = (next_it != active.end()) ? next_it->first : n + 1;
                    imp[k_i] += (ll)(minR2-minR);
                }
            }
        }

        return base += *max_element(imp.begin(),imp.end());
        

    }
};