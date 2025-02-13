class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq(begin(nums), end(nums));
        int ans = 0;
        while(!pq.empty() && pq.top()<k){
            long s1 = pq.top();
            pq.pop();
            long s2 = pq.top();
            pq.pop();
            pq.push(s1*2 + s2);
            ans++;
        }
        return ans;
    }
};