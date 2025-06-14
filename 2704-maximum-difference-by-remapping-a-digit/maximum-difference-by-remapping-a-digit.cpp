class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int n = s.length();
        int mini = INT_MAX;
        for(char ch: s){
            int res = ch-'0';
            mini = min(mini,res);
        }
        int i = 0;
        int maxi = s[0]-'0';
        while(i<n && s[i] == '9'){
            i++;
        }
        int miniN = s[i]-'0';
        cout<<miniN<<" "<<maxi<<endl;
        cout<<endl;

        string m = s;
        for(int i = 0; i<n; i++){
            int a = m[i]-'0';
            if(a == miniN) m[i] = '9';
           
        }
        int maxNum = stoi(m);

        string l = s;
        for(int i =0;i <n; i++){
            int a = l[i]-'0';
            if(a == maxi) l[i] = '0';
        }
        
        int minNum = stoi(l);
        cout<<minNum<<endl;
        cout<<maxNum<<endl;

        return maxNum-minNum;
    }
};