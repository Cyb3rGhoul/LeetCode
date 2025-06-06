class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long res = 0;
        int zctnnum1 = 0;
        int zctnnum2 = 0;
        long sum1 = 0;
        long sum2 = 0;
        for(int num : nums1){
            sum1 += num;
            if(num==0) zctnnum1++, sum1+=1;
        }
        for(int num : nums2){
            sum2 += num;
            if(num==0) zctnnum2++, sum2+=1;
        }

        if(sum1<sum2 && zctnnum1 ==0) return -1;
        if(sum2<sum1 && zctnnum2 ==0) return -1;
        
        return max(sum1,sum2);
    }
};