class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        int l = n-1;
        while(l>=1){
            if(s[l]>='0' && s[l]<='9'){
                s.erase(s.begin()+l);
                int r = l-1;
                while(r>=0){
                    if(s[r]>='0' && s[r]<='9'){
                        r--;
                    }else{
                        s.erase(s.begin()+r);
                        break;
                    }
                }
            }
            l--;
        }
        return s;

    }
};