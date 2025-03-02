class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> res;
        int i = 0;
        int j = 0;
        while(i<n && j<m){
            int a = nums1[i][0];
            int b = nums2[j][0];
            if(a == b){
                res.push_back({a,nums1[i][1]+nums2[j][1]});
                i++;
                j++;
            }
            else if(a<b){
                res.push_back(nums1[i]);
                i++;
            }else{
                res.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            res.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            res.push_back(nums2[j]);
            j++;
        }
        
        return res;
    }
};