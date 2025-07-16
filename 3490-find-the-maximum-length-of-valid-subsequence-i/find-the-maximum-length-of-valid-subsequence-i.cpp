class Solution {
public:
//isme 3 case ban sakte hai 
//1. logest tab hoga ya to sare eve ho %2 == 0
//2. ya to sare odd ho == %2 == 0
//3. ya to alternating ho == %2 == 1

    int maximumLength(vector<int>& nums) {
        int currEve = 0;
        int currOdd = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i]%2==0) currEve++;
            else currOdd++;
        }

        int alt = 1;

        int par = nums[0]%2;

        for(int i = 1; i<n; i++){
            int currPar = nums[i]%2;
            if(currPar != par){
                alt++;
                par = currPar;
            }
        }

        return max({currEve,currOdd,alt});
    }
};