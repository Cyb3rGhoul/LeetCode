class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int m = flowerbed.size();
    if (m == 1) {
        if (n == 1 && flowerbed[0] == 0) return true;
        return n == 0;
    }
    
    for (int i = 0; i < m && n > 0; i++) {
        if (flowerbed[i] == 0) {
            bool leftEmpty = (i == 0 || flowerbed[i - 1] == 0);
            bool rightEmpty = (i == m - 1 || flowerbed[i + 1] == 0);
            if (leftEmpty && rightEmpty) {
                flowerbed[i] = 1;
                n--;
            }
        }
    }
    
    return n == 0;
}

};