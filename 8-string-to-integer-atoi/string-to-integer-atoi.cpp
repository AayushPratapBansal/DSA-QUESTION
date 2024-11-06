class Solution {
public:
    int myAtoi(string s) {
 int i = 0;
    int n = s.length();
    long result = 0;
    int sign = 1;

    // Step 1: Ignore leading whitespace
    while (i < n && s[i] == ' ') {
        i++;
    }

    // Step 2: Check the sign
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Step 3: Convert digits to integer
    while (i < n && isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');
        
        
        if (sign * result > INT_MAX) return INT_MAX;
        if (sign * result < INT_MIN) return INT_MIN;
        
        i++;
    }


    return sign * result;
    }
};