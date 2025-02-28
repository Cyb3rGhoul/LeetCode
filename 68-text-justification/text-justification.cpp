class Solution {
public:
    int MAX_W;
    string findLine(int i, int j, int eachS, int extraS, vector<string>& words){
        string line;
        for(int k = i; k<j; k++){
            line += words[k];

            if(k==j-1){ // lastword of my line;
                // no space after last word of my line
                continue;
            }

            for(int z = 1; z<= eachS; z++){
                line += " ";
            }
            if(extraS){
                line += " ";
                extraS--;
            }
        }

        while(line.length()<MAX_W){
            line += " ";
        }
        return line;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int i = 0;
        MAX_W = maxWidth;
        while(i<n){
            int lC = words[i].length();
            int j = i+1;
            int s = 0;
            while(j<n && words[j].length() + 1 + s + lC <= maxWidth){
                lC += words[j].length();
                s++;
                j++;
            }
            int rem = maxWidth - lC;
            int eachS = s == 0 ? 0 : rem/s;
            int extraS = s == 0 ? 0 : rem%s;

            if(j==n){
                eachS = 1;
                extraS = 0;
            }
            res.push_back(findLine(i,j,eachS, extraS, words));
            i = j;
        }
        return res;

    }
};