class SmallestInfiniteSet {
public:
    vector<bool> nums;
    int i;
    SmallestInfiniteSet() {
        i = 1;
        nums = vector<bool>(1000,true);
    }
    
    int popSmallest() {
        int res = i;
        nums[i] = false;
        for(int j = i+1; j<1001; j++){
            if(nums[j] == true){
                i = j;
                break;
            }
        }
        return res;
    }
    
    void addBack(int num) {
        nums[num] = true;
        if(num<i) i = num;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */