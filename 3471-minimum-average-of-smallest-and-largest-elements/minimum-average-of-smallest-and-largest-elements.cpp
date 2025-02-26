class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        priority_queue<double,vector<double>,greater<double>> pq;
        sort(begin(nums),end(nums));
        int l = 0;
        int r = n-1;
        while(l<r){
            double avg = (nums[l]+nums[r])/2.0;
            pq.push(avg);
            l++;
            r--;
        }
        return pq.top();
    }
};