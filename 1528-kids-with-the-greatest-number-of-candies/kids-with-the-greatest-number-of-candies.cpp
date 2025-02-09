class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int great = INT_MIN;
        int n = candies.size();
        for(int i = 0; i<n; i++){
            great = max(great, candies[i]);
        }
        vector<bool> res(n);
        for(int i = 0; i<n; i++){
            if((candies[i]+extraCandies)>=great){
                res[i] = true;
            }
            else{
                res[i] = false;
            }
        }
        return res;
    }
};