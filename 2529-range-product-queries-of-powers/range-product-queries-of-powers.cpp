class Solution {
public:
    int MOD = 1e9+7;
    string solve(int n){
        string bit = "";
        while(n!=0){
            int num = n%2;
            string c = to_string(num);
            bit += c;
            n/=2;
        }
        // reverse(bit.begin(),bit.end());
        // cout<<bit;
        return bit;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        string res = solve(n);
        vector<int> temp;
        vector<int> power;
        for(int i = 0; i<res.length(); i++){
            if(res[i]=='1'){
                power.push_back(pow(2,i));
            }
        }

        for(auto q : queries){
            long long ans = 1;
            for(int i = q[0]; i<=q[1]; i++){
                ans = (ans*power[i])%MOD;
            }
            temp.push_back((int)ans%MOD);
        }
        return temp;
    }
};