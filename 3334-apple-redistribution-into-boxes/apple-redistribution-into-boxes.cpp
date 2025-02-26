class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        int totalApple = 0;
        for(int i = 0; i<n ; i++){
            totalApple += apple[i];
        }
        int ctn = 0;
        sort(begin(capacity), end(capacity));
        for(int i = m-1; i>=0; i--){
            ctn++;
            int a = capacity[i];
            totalApple -= a;
            if(totalApple<=0) break;
        }
        return ctn;
    }
};