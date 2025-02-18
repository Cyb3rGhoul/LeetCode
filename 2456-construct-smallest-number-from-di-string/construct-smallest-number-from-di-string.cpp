class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        string ans = "";
        stack<int> st;
        int ctn = 1;
        for(int i = 0; i<=n; i++){
            if(i==n){
                st.push(ctn);
                while(!st.empty()){
                    ans += to_string(st.top());
                    st.pop();
                }
                break;
            }
            else if(pattern[i]=='I'){
                st.push(ctn);
                while(!st.empty()){
                    ans += to_string(st.top());
                    st.pop();
                }
                ctn++;
            }
            else{
                st.push(ctn);
                ctn++;
            }
        }
        return ans;
    }
};