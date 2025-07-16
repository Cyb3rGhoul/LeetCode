class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        int sum = 1;
        if(n%3==0){
            return pow(3,n/3);
        }
        for(int i = 1; i<=n/3; i++){
            sum *= 3;
        }
        if(n%3 == 1){
            sum /= 3;
            sum *= 4;
        }else{
            sum *= n%3;
        }
        return sum;
    }
};