class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        int n = d.size();
        double maxi = -1;
        // int idx = 0;
        int area = 0;
        for(int i = 0; i<n; i++){
            double a = sqrt((d[i][0]*d[i][0]) + (d[i][1]*d[i][1]));
            // cout<<a<<" "<<maxi<<endl;
            if(maxi <= a){
                if(maxi==a) area = max(area,d[i][0]*d[i][1]);
                else area = d[i][0]*d[i][1];
                maxi = a;
                // idx = i;
            }
        }

        return area;
    }
};