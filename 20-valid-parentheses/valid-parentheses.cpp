class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char c : s){
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                if(st.empty()) return false; // Prevents stack underflow
                
                if((c == ')' && st.top() != '(') ||
                   (c == '}' && st.top() != '{') ||
                   (c == ']' && st.top() != '[')) {
                    return false;
                }
                
                st.pop();
            }
        }
        
        return st.empty(); // Stack should be empty if valid
    }
};
