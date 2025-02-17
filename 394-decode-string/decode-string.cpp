class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        stack<char> st;
        for(int i = 0; i<n; i++){
            string res = "";
            string num = "";
            if(s[i]==']'){
                while(!st.empty() && st.top()!='['){
                    res += st.top();
                    st.pop();
                }
                st.pop();
                reverse(begin(res),end(res));
                while(!st.empty() && st.top()>='0' && st.top()<='9'){
                    num += st.top();
                    st.pop();
                }
                reverse(begin(num),end(num));
                int i = 0;
                while(i<stoi(num)){
                    for(int j = 0; j<res.length(); j++){
                        st.push(res[j]);
                    }
                    i++;
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string r = "";
        while(!st.empty()){
            r += st.top();
            st.pop();
        }
        reverse(begin(r),end(r));
        return r;
    }
};