class Solution {
public:
    int uniquePaths(int m, int n) {
        // this question will be solved using n(C)r 
        // why this
        // so if we look deeper in the problem to reach from the starting to the end we require a certain no. of combination of either right or down
        // for example: in the case of 3*4 we require the combination of 3 right and 2 down only
        // i.e we need the combination of row-1 and col -1;

        // to find this we will get n and then c and then we will use res and then with the help of a loop we will find ncr

        int N = n+m-2;
        int r = n-1;
        double res = 1;
        for(int i = 1; i<=r; i++){
            res = res*(N-r+i)/i;
        }
        return (int)res;        
    }
};