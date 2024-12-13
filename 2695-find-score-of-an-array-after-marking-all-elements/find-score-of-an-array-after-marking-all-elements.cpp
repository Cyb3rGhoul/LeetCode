class Solution {
public:
    long long findScore(std::vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        
       
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> minHeap;
        
        
        for (int i = 0; i < n; ++i) {
            minHeap.push({nums[i], i});
        }
        
        
        std::vector<bool> visited(n, false);
        
        
        while (!minHeap.empty()) {
            auto [val, idx] = minHeap.top();
            minHeap.pop();
            
            
            if (visited[idx]) continue;
            
            
            res += val;
            
            
            visited[idx] = true;
            if (idx > 0) visited[idx - 1] = true;
            if (idx < n - 1) visited[idx + 1] = true;
        }
        
        return res;
    }
};