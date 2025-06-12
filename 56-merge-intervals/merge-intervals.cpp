class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {

        vector<vector<int>> res;
        sort(a.begin(),a.end());

        stack<pair<int,int>> st;
        st.push({a[0][0],a[0][1]});

        for(int i = 1; i<a.size(); i++){
            auto it = st.top();
            int num1 = it.first;
            int num2 = it.second;
            if(num2 >= a[i][0] && num2 <= a[i][1]){
                st.pop();
                st.push({num1,a[i][1]});
            }
            else if(num2 >= a[i][0] && num2 >= a[i][1]){
                st.pop();
                st.push({num1,num2});
            }
            else{
                st.push({a[i][0],a[i][1]});
            }
        }

        while(!st.empty()){
            res.push_back({st.top().first,st.top().second});
            st.pop();
        }

        return res;
    }
};