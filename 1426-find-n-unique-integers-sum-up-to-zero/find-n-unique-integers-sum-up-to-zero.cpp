class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n);
        int k = -1*n/2;
        if(n%2==0){
            for(int i = 0; i<n/2; i++){
                res[i] = k;
                k++;
            }
            k=1;
            for(int i = n/2; i<n; i++){
                res[i] = k;
                k++;
            }
        }
        else{
           for(int i = 0; i<n/2; i++){
                res[i] = k;
                k++;
            }
            k=1;
            res[n/2] = 0;
            for(int i = (n/2)+1; i<n; i++){
                res[i] = k;
                k++;
            } 
        }

        return res;
    }
};