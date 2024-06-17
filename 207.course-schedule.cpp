// @leet start
class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> edges(numCourses, vector<int>());
    vector<int> indeg(numCourses);
    for (auto& pair : prerequisites) {
      edges[pair[1]].push_back(pair[0]);
      indeg[pair[0]]++;
    }

    queue<int> label;
    for (auto i = 0; i < indeg.size(); ++i) {
      if (indeg[i] == 0) {
        label.push(i);
      }
    }

    // cout << "lable size: " << label.size() << endl;
    int result = 0;
    while (!label.empty()) {
      result++;
      int cur = label.front();
      label.pop();
      for (auto val : edges[cur]) {
        indeg[val] = indeg[val] - 1;
        if (indeg[val] == 0) {
          label.push(val);
        }
      }
    }
    return result == numCourses;
  }
};
// @leet end
