class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //ek approach soch ra hu ki map mai dal dunga jesse hi repeat ho to ek minus kar  dunga
        //agar zero ho jayega to element nikal dunga and size map ka size rakh lunga

        //nahi ye work nahi karegi

        //two pointer sliding window

        int n = s.length();
        unordered_map<char,int> freq;

        if(n==0) return 0;

        int l=0;
        int r=0;         
        int maxi = 1;
        while(r<n){
            freq[s[r]]++;
            if(freq[s[r]]==2){
                while(s[l]!=s[r]){
                    freq[s[l++]]--;
                }
                freq[s[l++]]--;
            }
            r++;
            maxi = max(r-l,maxi);
        }
        return maxi;
    }
};