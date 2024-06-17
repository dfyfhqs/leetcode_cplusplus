// @leet start
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    std::string result;
    help(0, 0, "", n);
    return result_vec_;
  }

  void help(int leftcount, int rightcount, const string& result, int n) {
    // std::cout << "leftcount: " << leftcount << " rightcount: " << rightcount
    //           << " result: " << result << endl;
    if (leftcount == rightcount && rightcount == n) {
      result_vec_.push_back(std::move(result));
      return;
    }
    if (leftcount == rightcount) {
      help(leftcount + 1, rightcount, result + "(", n);
      return;
    }

    if (leftcount == n) {
      help(leftcount, rightcount + 1, result + ")", n);
      return;
    }

    help(leftcount + 1, rightcount, result + "(", n);
    help(leftcount, rightcount + 1, result + ")", n);
  }

  vector<string> result_vec_;
};
// @leet end
