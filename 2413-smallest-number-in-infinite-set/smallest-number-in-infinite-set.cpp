class SmallestInfiniteSet {
public:
    int currEle;
    unordered_set<int> st;
    priority_queue<int,vector<int>, greater<int>> pq;

    SmallestInfiniteSet() {
        currEle = 1;
    }
    
    int popSmallest() {
        int res;
        if(!pq.empty()){
            res = pq.top();
            pq.pop();
            st.erase(res);
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
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */