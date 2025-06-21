class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);

        int n = word.length();

        // frequency store kar li humne
        for(int i = 0; i<n; i++){
            freq[word[i]-'a']++;
        }

        int res = word.length();

        //iterate kiya pure freq par
        //humne maan liya ki humara jo best freq hai wo freq[i] ki hai
        //fir agar wo best hai to fir humne baki elements par check kiya

        //agar freq of humara element bada hai to chota element pura hata do

        //agar freq of humara ele - freq of loop mai aaya wala ele agar wo bada hai k se
        //matalb ki humko jitana bada hai wo hatana padega
        //to humne del += (abs(freq[j]-freq[i])-k) ye  kar diya

        //res mai fir minimum of del ya res ko store kar liya

        
        for(int i = 0; i<26; i++){
            int del = 0;
            for(int j = 0; j<26; j++){
                if(i==j) continue;

                if(freq[j]<freq[i]){
                    del += freq[j];
                }
                else if(abs(freq[j]-freq[i])>k){
                    del += (abs(freq[j]-freq[i])-k);
                }
            }
            res = min(res,del);
        }
        return res;


    }
};