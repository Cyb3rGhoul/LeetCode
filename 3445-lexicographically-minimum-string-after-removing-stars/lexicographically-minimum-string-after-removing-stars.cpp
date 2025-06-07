typedef pair<char,int> p;
class Solution {
public:
    struct comp{
        bool operator()(p &p1, p &p2){
            if(p1.first==p2.first){
                return p1.second<p2.second;
            }
            return p1.first>p2.first;
        }
    };
    string clearStars(string s) {
        priority_queue<p,vector<p>,comp> pq;
        vector<bool> isFalse(s.size(),false);

        for(int i = 0; i<s.length(); i++){
            if(s[i]=='*'){
                if(!pq.empty()){
                    auto [c,idx] = pq.top();
                    pq.pop();
                    isFalse[idx] = true;
                }
                isFalse[i]=true;
            }
            else{
                pq.push({s[i],i});
            }
        }


        string res = "";

        for(int i = 0; i<s.length(); i++){
            if(!isFalse[i]) res += s[i];
        }

        return res;
    }
};