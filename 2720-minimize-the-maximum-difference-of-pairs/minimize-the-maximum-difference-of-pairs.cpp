class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0) return 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();

        //humko basically wo essa no. dhundhana hai jo ki minimum diff jo ki possibaly 0 hai and maximum diff jo ki left-right element hoga nums ka ussi ke bich lie karega

        //to element dhundhana hai - chize sorted hai - idea mila ki chize binary search se ho sakti hai
        int l = 0;
        int r = nums.back()-nums.front();
        int ans = r;

        while(l<=r){
            int mid = l + (r-l)/2;
            int ctn = 0; // ek count variable rakh lenge jo ki count karke batayega ki kitane esse pair hai ki agar mid difference hota to ussase chote ya equal
            for(int i = 0; i<n-1; ){
                if(nums[i+1]-nums[i]<=mid){
                    ctn++;
                    i += 2; // skip kardo taki pair repeat no ho
                }
                else{
                    //nahi hai to next;
                    i++;
                }
                //check karo kya count ke euqal aa gaya
                if(ctn >= p){
                    break;
                }
            }
            //check karo wapas ki aaya hai ki nahi
            if(ctn>=p){
                //agar aaya hai to matalb aur chota possible ho sakkta hai tab tak is ko answer mai store karlo
                ans = mid;
                r = mid-1;
            }
            else{
                //agar nahi aaya hai to bada dekhte hai
                l = mid + 1; 
            }
        }
        return ans;
    }
};