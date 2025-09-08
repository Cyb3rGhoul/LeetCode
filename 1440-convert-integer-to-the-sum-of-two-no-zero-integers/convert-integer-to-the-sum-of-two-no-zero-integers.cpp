class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = 1;
        int b = n-1;
        while(true){
            string s1 = to_string(a);
            string s2 = to_string(b);
            bool aCheck = false;
            for(int i = 0; i<s1.size(); i++){
                if(s1[i]=='0'){ 
                    aCheck = true;
                    a++;
                    b--;
                    break;
                }
            }
            bool bCheck = false;
            for(int i = 0; i<s2.size(); i++){
                if(s2[i]=='0'){ 
                    bCheck = true;
                    a++;
                    b--;
                    break;
                }
            }
            if(!aCheck && !bCheck) break;
        } 

         return {a,b};
    }
};