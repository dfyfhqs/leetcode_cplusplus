// @leet start
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return resultvec;
    }
    digit2string_ = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };

    string result = digits;
    help(digits, result, 0);
    return resultvec;
  };

  void help(const string& digits, string& curstr, int start) {
    if (start == digits.size()) {
      resultvec.push_back(curstr);
      return;
    }
    char ch = digits[start];
    for (auto val : digit2string_[ch]) {
      curstr[start] = val;
      help(digits, curstr, start + 1);
    }
  }
  vector<string> resultvec;
  unordered_map<char, std::string> digit2string_;
};
// @leet end
