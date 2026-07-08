class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are never palindromes.
        // Numbers ending in 0 (except 0 itself) can't be palindromes,
        // since a palindrome can't start with 0.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reverted = 0;
        while (x > reverted) {
            reverted = reverted * 10 + x % 10;
            x /= 10;
        }

        // For even digit count, x == reverted.
        // For odd digit count, the middle digit is in reverted's ones place,
        // so we discard it with reverted / 10.
        return x == reverted || x == reverted / 10;
    }
};