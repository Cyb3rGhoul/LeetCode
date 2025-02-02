class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length(), m = b.length();
        if (m > n) return addBinary(b, a);  // Ensure `a` is longer or equal

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int carry = 0;
        string ans = "";
        int i = 0;

        // Add common length part
        while (i < m) {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            carry = sum / 2;
            ans += (sum % 2 + '0');
            i++;
        }

        // Add remaining part of `a`
        while (i < n) {
            int sum = (a[i] - '0') + carry;
            carry = sum / 2;
            ans += (sum % 2 + '0');
            i++;
        }

        // If there's a leftover carry, add it
        if (carry) {
            ans += '1';
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

