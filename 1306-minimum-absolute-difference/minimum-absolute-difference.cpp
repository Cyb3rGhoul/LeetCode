class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        int n = arr.size();
        sort(begin(arr),end(arr));

        int mindif = INT_MAX;
        
        //finding min dif
        for(int i = 0; i<n-1; i++){
            mindif = min(mindif,abs(arr[i] - arr[i+1]));
        }

        cout<<mindif<<endl;
        int curr = 0;
        vector<int> smallRes;
        for(int i = 0; i<n-1; i++){
            curr = arr[i+1] - arr[i];
            if(curr==mindif){
                smallRes.push_back(arr[i]);
                smallRes.push_back(arr[i+1]);
                res.push_back(smallRes);
                smallRes.clear();
            }
        }
        return res;
    }
};