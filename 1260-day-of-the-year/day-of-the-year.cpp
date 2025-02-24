class Solution {
public:
    int dayOfYear(string date) {
        string y = date.substr(0, 4);  // Extract "YYYY"
        string m = date.substr(5, 2);  // Extract "MM"
        string d = date.substr(8, 2);  // Extract "DD"

        int year = stoi(y);
        int month = stoi(m);
        int day = stoi(d);
    
        int res = 0;

        if(month==1) return day;
        res += 31;

        for(int i = 2; i<month; i++){
            if(i == 3 || i == 5 || i==7 || i==8 || i == 10 || i == 12){
                res += 31;
            }
            else if(i==2 && (year%4==0 || year%100==0) && year != 1900){
                res += 29;
            }else if(i==2 && (year%4!=0 || year==1900)){
                res+=28;
            }else{
                res+=30;
            }
        }
        return res + day;

    }
};