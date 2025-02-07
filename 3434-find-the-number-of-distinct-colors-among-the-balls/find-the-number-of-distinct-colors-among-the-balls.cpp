class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> res(n);
        unordered_map<int,int> mp;
        unordered_map<int,int> ball;

        for(int i = 0; i<n; i++){
            int b = queries[i][0];
            int col = queries[i][1];

            if(ball.count(b)){
                int pre = ball[b];
                mp[pre]--;
                if(mp[pre]==0){
                    mp.erase(pre);  
                }
            }
            ball[b] = col;
            mp[col]++;
            res[i] = mp.size();
        }

        return res;
    }
};