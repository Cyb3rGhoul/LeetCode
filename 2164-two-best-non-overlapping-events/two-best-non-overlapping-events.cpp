class Solution {
public:
    int n;
    int t[100001][3];
    int bSearch(vector<vector<int>>& events, int endTime){
        int l = 0;
        int r = n - 1;
        int res = n;
        while(l<=r){
            int mid = l + (r - l)/2;
            if(events[mid][0]>endTime){
                res = mid;
                r = mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
    int solve(vector<vector<int>>& events, int i, int count){
        if(count==2 || i>=n) return 0;

        if(t[i][count] != -1) return t[i][count];

        int nextValIdx = bSearch(events,events[i][1]);
        int take = events[i][2] + solve(events, nextValIdx, count+1);
        int not_take = solve(events,i+1,count);

        return t[i][count] = max(take,not_take);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(events.begin(), end(events));

        memset(t, -1, sizeof(t));
        int count = 0;
        return solve(events,0,count);
    }
};