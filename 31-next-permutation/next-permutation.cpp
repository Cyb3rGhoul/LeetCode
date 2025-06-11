class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;

        //piche se sabse pehele pahad ka dip dhundho
        for(int i = n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                idx = i;
                break;
            }
        }

        //agar idx -1 raha matalb ki wo lexiographically sabse bada hai
        if(idx==-1) {
            reverse(nums.begin(),nums.end());
            return;
        }

        //aab piche se sabse pehele index nikalo jo ki nums[idx] se bada ho
        for(int i = n-1; i>idx; i--){
            if(nums[i]>nums[idx]){
                swap(nums[i],nums[idx]);
                break;
            }
        }


        //aab bas reverse kardo
        reverse(nums.begin()+idx+1,nums.end());

    }
};