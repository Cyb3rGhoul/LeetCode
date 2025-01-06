class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n,0);
        int cv=0;
        int cvs=0;
        for(int i = 0; i<n; i++){
            ans[i] = cvs;
            cv += boxes[i] == '0' ? 0 : 1;
            cvs += cv;
        }
        cv = 0;
        cvs = 0;
        for(int i = n-1; i>=0; i--){
            ans[i] += cvs;
            cv += boxes[i] == '0' ? 0 : 1;
            cvs += cv;
        }

        return ans;
    }
};