class Solution {
    using uss = unordered_set<string>;
    int k = 0;
    string exp;

    uss add(uss& a, uss& b){
        uss res = a;
        for(auto& s: b){
            if(s.size()) res.insert(s);
        }
        return res;
    }

    uss mul(uss& a, uss& b){
        uss res;
        for(auto& s1: a){
            for(auto& s2: b){
                if((s1+s2).size()>0) res.insert(s1+s2);
            }
        }
        return res;
    }

    uss dfs(){
        uss a,b;
        b.insert("");

        while(k<exp.size() && exp[k]!= '}'){
            if(exp[k]==','){
                k++;
                continue;
            }
            else if(exp[k]=='{'){
                bool is_add = false;
                if(k==0 || exp[k-1]==',') is_add=true;
                k++;
                uss c = dfs();
                k++;
                if(is_add){
                    a = add(a,b);
                    b = c;
                }
                else{
                    b = mul(b,c);
                }
            }else{
                bool is_add = false;
                if(k==0 || exp[k-1]==',') is_add=true;
                string s;
                while(k<exp.size() && islower(exp[k])) s += exp[k++];
                uss c;
                c.insert(s);
                if(is_add){
                    a = add(a,b);
                    b = c;
                }
                else{
                    b = mul(b,c);
                }
            }
        }
        return add(a,b);
    }


public:
    vector<string> braceExpansionII(string expression) {
         k = 0;
         exp = expression;


         auto uss = dfs();
         auto res = vector<string>(uss.begin(),uss.end());
         sort(res.begin(),res.end());
         return res;
    }
};