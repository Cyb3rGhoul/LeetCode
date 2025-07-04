class Solution {
public:
    string minimizeStringValue(string s) {
       int qctn = 0; //question mark count
       int n = s.length();
       vector<int> cost(26,0);
       
       for(int i = 0; i<n; i++){
            if(s[i] >= 'a' && s[i]<='z'){
                cost[s[i]-'a']++;
            }else qctn++;
       }

        //ek wor string banao jisme wo sare charecter honge jo ki hume fill karne hai
       string filling = ""; 
       for(int i = 0; i<qctn; i++){
            int minIdx = 0;
            int minCtn = INT_MAX;

            for(int i = 0; i<26; i++){
                if(minCtn>cost[i]){
                    minIdx = i;
                    minCtn = cost[i];
                }
            }

            filling += ('a' + minIdx);
            cost[minIdx]++;
       }

       //sort karlo filling charecter taki lexiographycally smallest ho
       sort(begin(filling),end(filling));

        string res = "";
        int idx = 0;
        for(int i = 0; i<n; i++){
            if(s[i]=='?'){
                res += filling[idx];
                idx++;
            }else res += s[i];
        }

    
       return res;
    }
};