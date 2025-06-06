class Solution {
public:

    void solve(int o, int c, string op, vector<string> &v){
        if(o==0 && c==0){
            v.push_back(op);
            return;
        }

        if(o==c){

            string op1 = op;
            op1.push_back('(');
            solve(o-1,c,op1,v);
            
        }
        else if(o<c){
            if (o > 0) {
                string op1 = op;
                op1.push_back('(');
                solve(o - 1, c, op1, v);
            }
            string op2 = op;
            op2.push_back(')');
            solve(o,c-1,op2,v);
            
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        int o = n;
        int c = n;
        solve(o,c,"",v);
        return v;
    }
};