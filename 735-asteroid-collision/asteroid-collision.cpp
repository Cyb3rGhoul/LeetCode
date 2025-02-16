class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        stack<int> st;
        
        for (int asteroid : asteroids) {
            bool destroyed = false;
            
            while (!st.empty() && asteroid < 0 && st.top() > 0) { // Collision condition
                if (abs(asteroid) > st.top()) {
                    st.pop(); // Destroy the top asteroid and continue checking
                } 
                else if (abs(asteroid) == st.top()) {
                    st.pop(); // Both asteroids destroy each other
                    destroyed = true;
                    break;
                } 
                else { 
                    destroyed = true; // Current asteroid is destroyed
                    break;
                }
            }
            
            if (!destroyed) st.push(asteroid);
        }

        // Convert stack to vector in correct order
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
