typedef pair<int, int> p;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<p> pq;
        int n = arr.size();

        for(int i = 0; i<n; i++){
            pq.push({abs(arr[i]-x),arr[i]});
            if(pq.size()>k) pq.pop();
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};