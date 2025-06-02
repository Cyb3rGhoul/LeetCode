#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

typedef pair<int, int> p;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        // Count frequencies
        for (int num : nums) {
            mp[num]++;
        }
        
        // Custom comparator for the priority queue
        auto comp = [](const p& a, const p& b) {
            if (a.first == b.first) {
                return a.second < b.second; // If freq equal, larger value comes first
            }
            return a.first > b.first; // Otherwise, lower freq comes first
        };
        
        priority_queue<p, vector<p>, decltype(comp)> pq(comp);
        
        // Push into the priority queue
        for (auto it : mp) {
            pq.push({it.second, it.first});
        }
        
        vector<int> ans;
        
        // Build the result
        while (!pq.empty()) {
            int freq = pq.top().first;
            int num = pq.top().second;
            pq.pop();
            
            for (int i = 0; i < freq; i++) {
                ans.push_back(num);
            }
        }
        
        return ans;
    }
};