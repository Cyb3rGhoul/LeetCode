class Solution {
public:
    string countAndSay(int n) {
       if(n==1) return "1";
       string say = countAndSay(n-1);

       string res = "";
       for(int i = 0; i<say.length(); i++){
            char ch = say[i];
            int ctn = 1;
            while(i<say.length()-1 && say[i]==say[i+1]){
                ctn++;
                i++;
            }
            res+=(to_string(ctn)+string(1,ch));
       }
       return res;
    }
};