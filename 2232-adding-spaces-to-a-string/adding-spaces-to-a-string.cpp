class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length();
        int k = spaces.size();
        string ans = "";
        int i=0;
        int j = 0;
        while(i<n){
            if(j < k && i==spaces[j]){ 
                ans += " ";
                j++;
            }
            ans += s[i];
            i++;
        }
        return ans;
    }
};