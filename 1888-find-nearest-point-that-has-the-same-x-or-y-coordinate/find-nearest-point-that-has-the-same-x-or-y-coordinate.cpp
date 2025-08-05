class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int res = INT_MAX;
        int ans = INT_MAX;
        int d = INT_MAX;
        int n = points.size();

        for(int i = 0; i<n; i++){
            int a = points[i][0];
            int b = points[i][1];
            
            if(x==a || y==b){
                d = abs(x-a) + abs(y-b);
                if(d<ans){
                    ans = d;
                    res = i;
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};