class Solution {
public:
    string removeStars(string s) {
       int n = s.length();

       stack<char> st;

       for(int i = 0; i<n; i++){
            if(s[i]>='a' && s[i]<='z'){
                st.push(s[i]);
            }
            else if(s[i]=='*'){
                st.pop();
            }
       }
       string ans = "";
       while(!st.empty()){
            ans += st.top();
            st.pop();
       }
       reverse(begin(ans),end(ans));
       return ans;
    }
};