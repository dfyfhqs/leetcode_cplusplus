// @leet start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

#include <algorithm>
class Solution {
 public:
  int getImportance(vector<Employee*> employees, int id) {
    stack<int> label;
    int result = 0;
    std::unordered_map<int, int> id_map;
    int idx = 0;
    std::for_each(employees.begin(), employees.end(),
                  [&](auto& e) { id_map[e->id] = idx++; });
    auto find = id_map.find(id);
    if (find == id_map.end()) {
      return result;
    }
    label.push(find->second);
    while (!label.empty()) {
      int cur = label.top();
      label.pop();
      result += employees[cur]->importance;
      for (auto& val : employees[cur]->subordinates) {
        label.push(id_map[val]);
      }
    }
    return result;
  };
};  // class Solution
    // @leet end
