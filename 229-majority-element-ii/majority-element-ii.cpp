class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        vector<int> res;
        int ele1=INT_MAX;
        int ele2=INT_MAX;
        int ctn1 = 0;
        int ctn2 = 0;
        int n = a.size();
        for(int i = 0; i<n; i++){
            if(a[i]==ele1){
                ctn1++;
            }
            else if(a[i]==ele2){
                ctn2++;
            }
            else if(ctn1==0){
                ele1 = a[i];
                ctn1++;
            }
            else if(ctn2==0){
                ele2 = a[i];
                ctn2++;
            }

            else{
                ctn1--;
                ctn2--;
            }
        }
        ctn1=0;
        ctn2=0;
        for(int i = 0; i<n; i++){
            if(a[i]==ele1)ctn1++;
            else if(a[i]==ele2)ctn2++;
        }

        if(ctn1>n/3) res.push_back(ele1);
        if(ctn2>n/3) res.push_back(ele2);

        return res;
    }
};