class FoodRatings {
public:
    struct Compare {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        }
    };

    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, Compare>> rat;
    unordered_map<string, string> mp;           // food -> cuisine
    unordered_map<string, int> currentRating;   // food -> current rating
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++){
            rat[cuisines[i]].push({ratings[i], foods[i]});
            mp[foods[i]] = cuisines[i];
            currentRating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = mp[food];
        currentRating[food] = newRating;  // Update current rating
        rat[cuisine].push({newRating, food});  // Add new entry
    }
    
    string highestRated(string cuisine) {
        // Remove stale entries from top
        while(!rat[cuisine].empty() && 
              currentRating[rat[cuisine].top().second] != rat[cuisine].top().first) {
            rat[cuisine].pop();
        }
        return rat[cuisine].top().second;
    }
};