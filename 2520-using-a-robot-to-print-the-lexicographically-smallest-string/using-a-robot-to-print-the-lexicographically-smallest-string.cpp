// isme patter to pata nahi kya hai par bas approach mai itan samjh aa raha hai ki compariosin ho ra hai from the extreme elements like back or front

//usko dekh kar stack ka implementation aa sakta hai par string ka bhi kafi sare stl hai esse to humne ussi se kaam chala liya



class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();

        vector<char> ch(n);
        ch[n-1] = s[n-1];

        //minimum charecter ka array bana liya
        for(int i = n-2; i>=0; i--){
            ch[i] = min(s[i],ch[i+1]);
        }

        string t = "";
        string paper = "";
        
        int i = 0;
        while(i<n){ //iterate karo tum aab s par;
            t.push_back(s[i]); // t mai to dalna hai no matter what
            char minCh = (i+1<n) ? ch[i+1] : s[i]; //minchar dekho  

            while(!t.empty() && t.back() <= minCh){ // t ko pop back karo jab tak uska piche wala is smaller than minChar
                paper+=t.back();
                t.pop_back();
            }
            i++;
        }

        //t mai agar kuch baccha jaye to usko bhi add kardo

        while(!t.empty()){
            paper.push_back(t.back());
            t.pop_back();
        }
        

        return paper;
    }
};