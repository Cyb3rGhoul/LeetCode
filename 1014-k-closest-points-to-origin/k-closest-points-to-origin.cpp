typedef pair<int,pair<int,int>> p;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<p> pq;
        int n = points.size();

        for(int i = 0; i<n; i++){
            int a = points[i][0];
            int b = points[i][1];
            int d = a*a + b*b;
            pq.push({d,{a,b}});
            if(pq.size()>k) pq.pop();
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            pair<int,int> a = pq.top().second;
            ans.push_back({a.first,a.second});
            pq.pop();
        }
        return ans;
    }
};
