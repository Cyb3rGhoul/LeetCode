class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;
        for(char ch: s){
            mp[ch]++;
        }

        int mini = INT_MAX;
        int maxi = 0;

        for(auto it: mp){
            if(it.second%2!=0) {maxi = max(maxi,it.second);cout<<maxi<<endl;}
            if(it.second%2==0) {mini = min(mini,it.second);cout<<mini<<endl;}
        }
    
        return maxi - mini;
    }
};