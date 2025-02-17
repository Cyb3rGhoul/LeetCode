class RecentCounter {
private:
    vector<int> rec;
    int start;
public:

    RecentCounter() : start(0) {}
    
    int ping(int t) {
        rec.push_back(t);
        while(rec[start] < t-3000){
            start++;
        }
        return rec.size()-start;
    }
};
