class Solution {
public:
    string predictPartyVictory(string s) {
        int n = s.length();
        queue<int> r, d;

        for(int i = 0; i<n; i++){
            if(s[i]=='R'){
                r.push(i);
            }else{
                d.push(i);
            }
        }
        while(!r.empty() && !d.empty()){
            int rindex = r.front();
            int dindex = d.front();
            if(rindex<dindex){
                r.pop();
                d.pop();
                r.push(rindex + n);
            }
            else{
                r.pop();
                d.pop();
                d.push(dindex + n);
            }
        }
        if(!r.empty()) return "Radiant";
        return "Dire";
    }
};