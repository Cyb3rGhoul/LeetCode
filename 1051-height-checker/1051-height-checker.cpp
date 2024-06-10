class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> ans1 = heights;
        sort(heights.begin(), heights.end());
        int ctn = 0;
        for(int i =0; i<heights.size(); i++){
            if(heights[i]!=ans1[i]) ctn++;
        }
        return ctn;
    }
};