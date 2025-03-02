class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> res;
        vector<int> small;
        int i = 0;
        int j = 0;
        while(i<n && j<m){
            int a = nums1[i][0];
            int b = nums2[j][0];
            if(a == b){
                small.push_back(a);
                small.push_back(nums1[i][1]+nums2[j][1]);
                res.push_back(small);
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
            small.clear();
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