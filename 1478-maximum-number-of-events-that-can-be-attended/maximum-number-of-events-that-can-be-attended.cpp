class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // Sort by end day
        });
        
        set<int> availableDays;
        for (int i = 1; i <= 100000; i++) {
            availableDays.insert(i);
        }
        
        int count = 0;
        for (auto& event : events) {
            auto it = availableDays.lower_bound(event[0]);
            if (it != availableDays.end() && *it <= event[1]) {
                count++;
                availableDays.erase(it);
            }
        }
        
        return count;
    }
};