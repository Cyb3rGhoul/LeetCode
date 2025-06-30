class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();

        int l = 0;
        int r = n -1;
        char c = letters[0];
        while(l<=r){
            int mid = l + (r-l) /2;

            //bada element store kar leta fir dekhta hu chota possible hai ki nahi
            if(letters[mid]>target){
                r = mid-1;
            }
            else if(letters[mid]<=target) l = mid + 1;

            if(letters[mid]>target) c = letters[mid]; 

        }
        if(c<target) return letters[0];

        return c;

        
    }
};