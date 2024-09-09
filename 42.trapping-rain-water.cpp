// @leet start
class Solution {
 public:
  int trap(vector<int>& height) {
    // 单调栈
    // return trapStack(height);
    return trapPoint(height);
  }

  // 单调栈
  int trapStack(vector<int>& height) {
    stack<int> label;
    int result = 0;
    for (auto i = 0; i < height.size(); ++i) {
      if (label.empty()) {
        label.push(i);
        continue;
      }
      int cur = height[i];
      while (!label.empty() && cur > height[label.top()]) {
        // cout << " i: " << i << " top: " << label.top();
        int top_idx = label.top();
        int top = height[label.top()];
        label.pop();
        if (label.empty()) {
          // cout << " break " << endl;
          break;
        }
        int temp =
            (min(cur, height[label.top()]) - top) * (i - label.top() - 1);
        result += temp;
        // cout << " curresult: " << temp << " final: " << result << endl;
      }
      label.push(i);
    }
    return result;
  }

  int trapPoint(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int result = 0;
    int cur = 0;
    int pre_cur = 0;
    while (left <= right) {
      int nextleft = left, nextright = right;
      if (height[left] <= height[right]) {
        cur = height[left];
        nextleft++;
        // cout << "nextleft: " << nextleft << " cur: " << cur << endl;
        while (nextleft <= nextright && height[nextleft] <= cur) {
          ++nextleft;
        }
      } else {
        cur = height[right];
        --nextright;
        // cout << "nextright: " << nextright << " cur: " << cur << endl;
        while (nextleft <= nextright && height[nextright] <= cur) {
          --nextright;
        }
      }

      if (cur == 0) {
        left = nextleft;
        right = nextright;
        pre_cur = cur;
        continue;
      }

      // cout << "left: " << left << " right: " << right
      //      << " nextleft: " << nextleft << " nextright: " << nextright
      //      << " cur: " << cur << " pre: " << pre_cur << endl;
      for (auto i = left; i <= right; ++i) {
        result += max(0, cur - max(height[i], pre_cur));
        // cout << "   i: " << i
        //      << " height: " << max(0, cur - max(height[i], pre_cur)) << endl;
      }
      // cout << "   final: " << result << endl;
      left = nextleft;
      right = nextright;
      pre_cur = cur;
    }
    return result;
  }
};
// @leet end
