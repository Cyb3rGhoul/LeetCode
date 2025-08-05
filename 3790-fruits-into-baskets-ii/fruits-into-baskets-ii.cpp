class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int m = baskets.size();
        int res = 0;
        for(int i = 0; i<n; i++){
            int f = fruits[i];
            for(int j = 0; j<m; j++){
                if(f<=baskets[j]){
                    res++;
                    baskets[j] = -1;
                    break;
                }
            }
        }
        return n-res;
    }
};