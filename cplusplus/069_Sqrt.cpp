/*
The sequence 1, 2, ... , n has no duplication.
Near the very end, closest step, before while loop, left = mid = right.
In while, If mid < sqrt(x), left = mid + 1 executed, right pointer is not moving, and right is the answer.
If while, If mid > sqrt(x), right = mid - 1 executed, right pointer shifts left 1, closest to sqrt(x), right is also the answer.
*/
class Solution {
public:
  int mySqrt(int x) {
    int left = 1, right = x/2+1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (mid == x / mid) {
        return mid;
      } else if (mid < x / mid) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return right;
  }
};
