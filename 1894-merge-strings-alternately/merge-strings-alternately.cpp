class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int i = 0, j= 0;
        string word = "";

        while(i<n && j<m){
            if(i==j){
                word += word1[i];
                i++;
            }
            else if(i>j){
                word += word2[j];
                j++;
            }
        }
        while(i<n){
            word += word1[i];
            i++;
        }
        while(j<m){
            word += word2[j];
            j++;
        }
        return word;
    }
};