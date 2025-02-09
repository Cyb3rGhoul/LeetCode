class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size();
        int m = s.size();
        int l = 0, r=0;
        int ans = 0;
        while(l<n){
            while(r<m){
                if(g[l]<=s[r]){
                    r++;
                    ans++;
                    break;
                }
                else if(g[l]>s[r]){
                    r++;
                }
            }
            l++;
        }
        return ans;
    }
};