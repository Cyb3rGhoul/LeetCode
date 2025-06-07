class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        string res = "";

        stack<char> st;
        st.push(s[0]);
        int i = 1;

        while(i<n){
            if(!st.empty() && st.top()==s[i]) st.pop();
            else st.push(s[i]);
            i++;
        }

        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        reverse(res.begin(),res.end());
        return res;

    }
};