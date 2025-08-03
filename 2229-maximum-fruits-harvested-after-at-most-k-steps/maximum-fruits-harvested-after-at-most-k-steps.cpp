class Solution {
public:
    
    int maxTotalFruits(vector<vector<int>>& fruits, int p, int k) {
        int n = fruits.size();
        vector<int> prefSum(n), pos(n);
        pos[0] = fruits[0][0];
        prefSum[0] = fruits[0][1];

        for(int i = 1; i<n; i++){
            pos[i] = fruits[i][0];
            prefSum[i] = prefSum[i-1] + fruits[i][1];
        }
        int ans = 0; 
        for(int d = 0; d<=k/2; d++){

            int i = p - d;
            int j = p + (k-2*d);

            int l = lower_bound(pos.begin(),pos.end(),i)-begin(pos);
            int r = upper_bound(pos.begin(),pos.end(),j)-begin(pos) - 1;

            if(l<=r){
                int tot = prefSum[r]- (l <=0 ? 0 : prefSum[l-1]);
                ans = max(ans, tot);
            }

            i = p - (k-2*d);
            j = p + d;

            l = lower_bound(pos.begin(),pos.end(),i)-begin(pos);
            r = upper_bound(pos.begin(),pos.end(),j)-begin(pos) - 1;

            if(l<=r){
                int tot = prefSum[r]- (l <=0 ? 0 : prefSum[l-1]);
                ans = max(ans, tot);
            }

        }

        return ans;
    }
};