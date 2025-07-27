class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        int ctn = 0;
        vector<int> arr;
        arr.push_back(nums[0]);
        for(int i = 0; i<n; i++){
            if(nums[i] != arr.back()) arr.push_back(nums[i]);
        }

        for(int i = 1; i<arr.size()-1; i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                ctn++;
            }else if(arr[i]<arr[i-1] && arr[i]<arr[i+1]){
                ctn++;
            }
        }
        return ctn;
    }
};