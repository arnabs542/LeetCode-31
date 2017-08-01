Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.


 # Solution

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        std::size_t pos(digits.size()); // we know its non-empty array
        
        // Find the first non-9 digit backward
        while (pos > 0) { // notice that pos-- > 0 is wrong!
            -- pos;
            if (digits[pos] != 9) {
                ++ digits[pos];
                return digits;
            } else {
                digits[pos] = 0;
            }
        }
        
        // it was 99....
        digits[pos] = 1;
        digits.push_back(0);
        
        return digits;
    }
};
```
