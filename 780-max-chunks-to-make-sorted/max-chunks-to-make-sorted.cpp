class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        int maxEle = -1;
        int ctn = 0;

        for(int i = 0; i<n; i++){
            maxEle = max(maxEle,arr[i]);

            if(maxEle == i){
                ctn++;
            }
        }

        return ctn;
    }
};