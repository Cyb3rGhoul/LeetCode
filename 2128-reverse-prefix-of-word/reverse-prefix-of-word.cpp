class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.length();
        int k = 0;
        for(int i = 0; i<n; i++){
            if(word[i]==ch){
                k  = i;
                break;
            }
        }
        reverse(word.begin(),word.begin()+k+1);
        return word;
    }
};