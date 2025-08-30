class Solution {
public:
    int bulbSwitch(int n) {
        if(n==0) return 0;
        int temp = 3;
        int ans = 1;
        while(n-temp>0){
            ans++;
            n -= temp;
            temp += 2;
        }
        return ans;
    }
};