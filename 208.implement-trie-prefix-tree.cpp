// @leet start
class Trie {
 public:
  Trie() : child_(26) {}

  void insert(string word) {
    Trie* cur = this;
    for (auto ch : word) {
      int idx = ch - 'a';
      if (cur->child_[idx] == nullptr) {
        cur->child_[idx] = new Trie();
      }
      cur = cur->child_[idx];
    }
    cur->is_end_ = true;
  }

  bool search(string word) {
    // cout << "search word: " << word << endl;
    Trie* cur = this;
    for (auto ch : word) {
      // cout << "ch: " << ch << endl;
      int idx = ch - 'a';
      if (cur->child_[idx] == nullptr) {
        return false;
      }
      cur = cur->child_[idx];
    }
    // cout << "search word: " << word << " result: " << cur->is_end_ << endl;
    return cur->is_end_ == true;
  }

  bool startsWith(string prefix) {
    Trie* cur = this;
    for (auto ch : prefix) {
      int idx = ch - 'a';
      if (cur->child_[idx] == nullptr) {
        return false;
      }
      cur = cur->child_[idx];
    }
    // cout << "startwith: " << cur->is_end_ << endl;
    return true;
    // return (cur->is_end_ == false);
  }
  vector<Trie*> child_;
  bool is_end_ = false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @leet end
