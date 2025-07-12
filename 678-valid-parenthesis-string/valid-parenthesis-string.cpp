class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int leftMin = 0, leftMax = 0;
        for(int i = 0; i<n; i++){
            if(s[i]=='('){
                leftMin++;
                leftMax++;
            }
            else if(s[i]==')'){
                leftMin--;
                leftMax--;
            }else{
                leftMin--;
                leftMax++;
            }

            if(leftMax<0) return false;
            if(leftMin<0) leftMin = 0;
        }

        return leftMin==0;
    }
};