typedef pair<int,int> p;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<p, vector<p>, greater<p>> pq;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }

        for(auto it: mp){
            pq.push({it.second,it.first});
            if(pq.size()>k) pq.pop();
        }

        vector<int> ans; 
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};