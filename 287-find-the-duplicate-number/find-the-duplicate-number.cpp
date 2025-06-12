class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        slow = nums[slow];
        fast = nums[nums[fast]];


        // THIS LOOP IS TO FIND THE LOOP AND IT IS BASICALLY THE FIRST STEP IN GETTING THE LOOP STARTING POINT
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }


        //WE AGAIN PUT THE SLOW TO START AND AS THE SLOW WILL REACH THE LOOP STARTING POINT MAGICALLY THE FAST WILL ALSO REACH THE LOOP STARTING POINT
        slow = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        //RETURN FAST
        return fast;
    }
};