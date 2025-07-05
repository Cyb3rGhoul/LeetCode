class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i = 0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        vector<int> temp;
        for(auto &it: mp){
            if(it.first==it.second){
                temp.push_back(it.first);
            }
        }
        sort(temp.begin(),temp.end());
        if(temp.size()==0) return -1;
        return temp[temp.size()-1];
    }
};