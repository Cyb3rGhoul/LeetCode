class RecentCounter {
private:
   queue<int> requests;
public:

    RecentCounter() {}
    
    int ping(int t) {
        // Step 1: Add the new request's timestamp to the queue
        requests.push(t);

        // Step 2: Remove all requests older than t - 3000
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();
        }

        // Step 3: The size of the queue is the number of recent requests
        return requests.size();
    }
};
