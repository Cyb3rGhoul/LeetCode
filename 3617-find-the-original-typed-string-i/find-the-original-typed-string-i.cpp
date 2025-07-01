class Solution {
public:
    int possibleStringCount(string word) {
        stack<char> st;
        st.push(word[0]);
        int sum = 1;
        for(int i = 1; i<word.length(); i++){
            if(st.top() == word[i]){
                sum++;
            }else{
                st.push(word[i]);
            }
        }
        return sum;
    }
};