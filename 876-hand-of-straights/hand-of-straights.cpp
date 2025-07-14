class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        //agar g remider n != 0 tab to false hai, kabhi divide ho hi nahi payega

        if(n%groupSize) return false;

        map<int,int> mp;

        for(int &num: hand){
            mp[num]++;
        }
        //map sorted hai to map mai ek ek karke curr + ii index dekhte hai and unki freq -- kar denge
        while(!mp.empty()){
            int curr = mp.begin()->first;
            for(int i = 0; i< groupSize; i++){
                if(mp[curr+i]==0) return false;
                mp[curr+i]--;
                if(mp[curr+i]==0) mp.erase(curr+i);
            }
        }
        return true;
    }
};