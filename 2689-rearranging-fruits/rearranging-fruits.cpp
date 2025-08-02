class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> mp;

        int n = basket1.size();
        int mini = INT_MAX;
        for(int i = 0; i<n; i++){
            mp[basket1[i]]++;
            mp[basket2[i]]--;

            mini = min(mini,min(basket1[i],basket2[i]));
        }
        vector<int> temp;
        for(auto &it: mp){
            if(it.second%2!=0){
                return -1;
            }
            else if(it.second != 0){
                // cout<<it.second<<endl;
                int t = abs(it.second)/2;
                while(t--){
                    temp.push_back(it.first);
                }
            }
        }

        sort(temp.begin(),temp.end());

        long long cos = 0;
        for(int i = 0; i<temp.size()/2; i++){
            cos += min((long long)temp[i],(long long)mini*2);
        }

        return cos;
    }
};