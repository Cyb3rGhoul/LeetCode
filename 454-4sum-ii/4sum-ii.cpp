class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> mp;
        for(int num1: nums1){
            for(int num2: nums2){
                mp[num1+num2]++;
            }
        }
        int ctn = 0;
        for(int num3: nums3){
            for(int num4: nums4){
                int tar = -(num3+num4);
                if(mp.find(tar)!=mp.end()) ctn+=mp[tar];
            }
        }

        return ctn;
    }
};