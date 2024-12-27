class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        if(n==0) return values[0];

        vector<int> val(n,0);

        val[0] = values[0] + 0;
        for(int i = 1; i<n; i++){
            int v = values[i] + i;
            val[i] = max(val[i-1],v);
        }

        int maxVal = 0;

        for(int j = 1; j<n; j++){
            int x = values[j]-j;
            int y = val[j-1];
            maxVal = max(x+y,maxVal);
        }

        return maxVal;
    }
};