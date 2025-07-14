class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();

        unordered_set<int> st;

        for(auto &vec: triplets){
            if(vec[0]>target[0] || vec[1]>target[1] || vec[2]>target[2]){
                continue;
            }
            for(int i = 0; i<vec.size(); i++){
                if(vec[i]==target[i]) st.insert(i);
            }
        }

        return st.size()==3;
    }
};

