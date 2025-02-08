class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int can = n;
        int i = 1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                i++;
                continue;
            }
            int peak = 0;
            while(ratings[i]>ratings[i-1]){
                peak++;
                can += peak;
                i++;
                if(i==n){
                    return can;
                }
            }
            int dip = 0;
            while(i<n && ratings[i]<ratings[i-1]){
                dip++;
                can+=dip;
                i++;
            }

            can -= min(peak,dip);
        }

        return can;
    }
};