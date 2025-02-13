class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double ts = 0;
        for(int i = 0; i<nums.size(); i++){
            ts += nums[i];
            pq.push(nums[i]);
        }

        double rn = ts/2;
        int ctn = 0;
        while(ts>rn){
            double el = pq.top();
            pq.pop();
            ts -= (el/2);
            pq.push(el/2);
            ctn++;
        }
        return ctn;
    }
};