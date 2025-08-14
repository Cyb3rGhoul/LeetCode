class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string res = "";
        for(int i = 0; i<n-2; i++){
            if(num[i]==num[i+1] && num[i]==num[i+2]){
                int a = stoi(num.substr(i,3));
                if(res.length()==0 || stoi(res)<a){
                    res = num.substr(i,3);
                }
            }
        }
        return res;
    }
};