class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int,unordered_set<char>> mp;
        int n = rings.length();
        for(int i = n-1; i>0; i-=2){
            int r = rings[i];
            int c = rings[i-1];
            mp[r].insert(c);
        }

        int ans = 0;
        for(auto& it: mp){
            if(it.second.size()==3) ans++;
        }
        return ans;
    }
};