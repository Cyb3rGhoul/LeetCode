class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int area = 0;
        while(l<r){
            int curr = (min(height[l],height[r]))*(r-l);
            area = max(area,curr);
            if(height[l]<=height[r]){
                l++;
            }else{
                r--;
            }
        }
        return area;
    }
};