class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a1 = (abs(ax2-ax1) * abs(ay2-ay1));
        int a2 = (abs(bx2-bx1) * abs(by2-by1));
        int it1 = max(ay1,by1) - min(ay2,by2);
        int it2 = max(ax1,bx1) - min(ax2,bx2);
        int it = 0;
        if(it1<=0 && it2<=0) it = (it1 * it2);

        cout<<a1<<" "<<a2<<" "<<it1<<" "<<it2;

        return a1 + a2 - it;
    }
};