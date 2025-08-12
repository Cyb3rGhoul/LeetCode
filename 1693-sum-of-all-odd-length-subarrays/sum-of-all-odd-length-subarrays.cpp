class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = accumulate(arr.begin(),arr.end(),0);
        int n = arr.size();
        int win = 3;
        // cout<<sum<<endl;
        for(int i = 0; i < n-2; i++){
            int j = i;
            while(j+win<=n){
                sum += accumulate(arr.begin()+j,arr.begin()+(j+win),0);
                // cout<<j<<" : j "<<endl<<j+win<<" : j + win "<<endl<<sum<<endl;
                win += 2;
            }
            win = 3;
        }

        return sum;
    }
};