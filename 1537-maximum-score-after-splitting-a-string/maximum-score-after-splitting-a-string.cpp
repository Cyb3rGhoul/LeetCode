class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int maxi = INT_MIN;
        int zeroCtn = 0;
        int oneCtn = 0;
        if(s[0]=='0') zeroCtn++;
        for(int i=1; i<n; i++){
            if(s[i]=='1') oneCtn++;
        }
        maxi = max(maxi,zeroCtn+oneCtn);
        for(int i = 1; i<n-1; i++){
            if(s[i]=='1') oneCtn--;
            else if(s[i]=='0') zeroCtn++;
            maxi = max(maxi,zeroCtn+oneCtn);
        }

        return max(maxi,zeroCtn+oneCtn);
    }
};