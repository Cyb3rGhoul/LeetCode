class Solution {
public:
    int dayOfYear(string date) {
    string y = date.substr(0, 4); // Extract "YYYY"
    string m = date.substr(5, 2); // Extract "MM"
    string d = date.substr(8, 2); // Extract "DD"
    
    int year = stoi(y);
    int month = stoi(m);
    int day = stoi(d);
    
    // Array to store days in each month
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Check if it's a leap year and update February
    bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (isLeapYear)
        daysInMonth[2] = 29;
    
    int dayCount = day;
    
    // Add days from previous months
    for (int i = 1; i < month; i++) {
        dayCount += daysInMonth[i];
    }
    
    return dayCount;
}
};