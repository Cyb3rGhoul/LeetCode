class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        if(k>n){
            cout<<"loop 1"<<endl;
            for(int i = n; i<=k; i++){
                s+=fill;
            }
        }
        else if(k<n && k%n!=0){
            cout<<"loop 2"<<endl;
            int t = k - n%k;
            cout<<t<<endl;
            for(int i = 0; i<=t; i++){
                s+=fill;
            }
        }
        vector<string> res;
        for(int i = 0; i<n; i+=k){
            res.push_back(s.substr(i,k));
        }

        return res;
    }
};