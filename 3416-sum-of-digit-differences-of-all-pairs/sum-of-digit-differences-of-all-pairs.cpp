class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        long long ctn = 0;

        int len = to_string(nums[0]).length();

        for(int i = 0; i<len; i++){
            unordered_map<int,int> mp;
            for(int j = 0; j<n; j++){
                string num = to_string(nums[j]);
                int dig = num[i] - '0';
                mp[dig]++;
            }

            vector<int> s;
            for(auto& it: mp){
                s.push_back(it.second);
            }

            for(int i = 0; i<s.size(); i++){
                for(int j = i+1; j<s.size(); j++){
                    ctn += (long long)s[i]*(long long)s[j];
                }
            }
        }

        return ctn;
    }
};