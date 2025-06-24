class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> keys;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i]==key){
                keys.push_back(i);
            }
        }
        
        vector<int> res;

        for(int num: keys){
            cout<<num<<endl;
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<keys.size(); j++){
                if(abs(i-keys[j])<=k) {
                    res.push_back(i);
                    break;
                }
            }
        }

        return res;
    }
};