/*
 * @lc app=leetcode.cn id=793 lang=cpp
 *
 * [793] 阶乘函数后 K 个零
 *
 * https://leetcode.cn/problems/preimage-size-of-factorial-zeroes-function/description/
 *
 * algorithms
 * Hard (48.69%)
 * Likes:    208
 * Dislikes: 0
 * Total Accepted:    27.8K
 * Total Submissions: 57.1K
 * Testcase Example:  '0'
 *
 *  f(x) 是 x! 末尾是 0 的数量。回想一下 x! = 1 * 2 * 3 * ... * x，且 0! = 1 。
 * 
 * 
 * 例如， f(3) = 0 ，因为 3! = 6 的末尾没有 0 ；而 f(11) = 2 ，因为 11!= 39916800 末端有 2 个 0 。
 * 
 * 
 * 给定 k，找出返回能满足 f(x) = k 的非负整数 x 的数量。
 * 
 * 
 * 
 * 示例 1： 
 * 
 * 
 * 输入：k = 0
 * 输出：5
 * 解释：0!, 1!, 2!, 3!, 和 4! 均符合 k = 0 的条件。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：k = 5
 * 输出：0
 * 解释：没有匹配到这样的 x!，符合 k = 5 的条件。
 * 
 * 示例 3:
 * 
 * 
 * 输入: k = 3
 * 输出: 5
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 0 <= k <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int preimageSizeFZF(int k) {
      long right = rightBundle(k);
      long left = leftBundle(k);
      std::cout << k << ", " << left << ", " << right << std::endl;
      return right - left + 1;
    }

    long findValue(long k) {
      long result = 0;
      while (k >= 5) {
        result += k / 5;
        k = k / 5;
      }
      return result;
    }

    long leftBundle(long k) {
      long left = 0, right = LONG_MAX-1;
      while (left <= right) {
        long mid = left + (right - left)/2;
        long midResult = findValue(mid);
        //std::cout << left << ", " << right << ", " << mid << ", " << midResult << ", "  << k << std::endl;
        if (midResult < k) {
          left = mid + 1;
        } else {
          right = mid-1;
        }
      }
      std::cout << "left: " << left << ", " << findValue(left)  << std::endl;
      return left;
    }

    long rightBundle(long k) {
      long left = 0, right = LONG_MAX-1;
      while (left <= right) {
        long mid = left + (right - left)/2;
        long midResult = findValue(mid);
        if (midResult > k) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
      std::cout << "right: " << right << ", " << findValue(right)  << std::endl;
      return right;
    }
};
// @lc code=end

