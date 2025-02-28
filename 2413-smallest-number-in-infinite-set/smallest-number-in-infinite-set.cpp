class SmallestInfiniteSet {
public:
    int currEle;
    set<int> st;

    SmallestInfiniteSet() {
        currEle = 1;
    }
    
    int popSmallest() {
        int res;
        if(!st.empty()){
            res = *st.begin(); 
            st.erase(st.begin());
        }else{
            res = currEle;
            currEle += 1;
        }
        return res;
    }
    
    void addBack(int num) {
        if(num>=currEle || st.find(num) != st.end()){
            return;
        }
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */