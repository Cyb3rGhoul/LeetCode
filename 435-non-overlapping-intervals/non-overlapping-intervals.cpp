class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        stack<pair<int,int>> st;
        int cnt = 0;
        st.push({intervals[0][0],intervals[0][1]});
        for(int i = 1; i<n; i++){
            int s = intervals[i][0];
            int e = intervals[i][1];

            int currS = st.top().first;
            int currE = st.top().second;

            if(s < currE){
                cnt++;
                st.pop();
                if(e<currE){
                    st.push({s,e});
                }else{
                    st.push({currS,currE});
                }
            }else{
                st.push({s,e});
            }
        }

        return cnt;
    }
};
