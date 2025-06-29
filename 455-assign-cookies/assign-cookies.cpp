class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        //sort kar liya taki hum loog isme two pointer laga paayee
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int n = g.size();
        int m = s.size();

        int l = 0;
        int r = 0;

        int ans=0;
        while(l<n){
            while(r<m){
                if(g[l]<=s[r]){
                    r++;
                    ans++;
                    break;
                }
                r++;
            }

            l++;
        }

        return ans;


    }
};