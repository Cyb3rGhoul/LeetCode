class Solution {
public:
    void solve(int n, string& curr, int &ctn, int &k, string& res){
        if(curr.length()==n){
            ctn++;
            if(ctn==k) res = curr;
            return;
        }
        for(char ch = 'a'; ch<='c'; ch++){
            if(!curr.empty() && ch==curr.back()) continue;
            curr.push_back(ch);
            solve(n,curr,ctn,k,res);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";
        string res = "";
        int ctn = 0;
        solve(n, curr, ctn, k, res);
        return res;
    }
};