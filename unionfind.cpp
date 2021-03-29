#include <vector>


class UnionFind {
public:
  UnionFind(int n) {
    parent_.resize(n);
    size_.resive(n);
    for(auto i = 0; i < n; ++i) {
      parent[i] = i;
    }
    count_ = n;
  }

  /* 将 p 和 q 连通 */
  void union(int p, int q) {
    auto pRoot = find(p);
    auto qRoot = find(q);
    if (pRoot == qRoot) {
      return;
    }

    // 平衡
    if (size[pRoot] >= size[qRoot]) {
      parent_[qRoot] = pRoot;
      size[qRoot] += size[pRoot];
    } else {
      parent_[pRoot] = qRoot;
      size[pRoot] += size[qRoot];
    }
  }

  /* 判断 p 和 q 是否互相连通 */
  bool isConnected(int p, int q) {
    auto pRoot = find(p);
    auto qRoot = find(q);
    return pRoot == qRoot;
  }

private:
  /* 返回节点 x 的根节点 */
  int find(int x) {
    //// 不压缩时，不断查找父节点
    //while(parent_[x] ！= x) {
    //  x = parent_[x];
    //}
    // 压缩路径长度
    while(parent_[x] != x) {
      parent_[x] = parent_[parent_[x]];
      x = parent_[x];
    }
    return x;
  }


private:
  std::vector<int> parent_;
  std::vector<int> size_;
  int count_;
};


int main() {
  UnionFind uf;

}