// @leet start
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int total = nums1.size() + nums2.size();
    cout << "total:  " << total << endl;
    if (total % 2 == 0) {
      int start = total / 2;
      cout << "start:  " << start << endl;
      int n1 = findn(nums1, nums2, 0, 0, start);
      cout << "n1: " << n1 << endl;
      cout << "start + 1:  " << start + 1 << endl;
      int n2 = findn(nums1, nums2, 0, 0, start + 1);
      cout << "n2: " << n2 << endl;
      return (n1 + n2) * 1.0 / 2;
    }
    cout << "find n3 " << endl;
    int n3 = findn(nums1, nums2, 0, 0, total / 2 + 1);
    cout << "n3: " << n3 << endl;
    return n3;
  }

  int findn(const vector<int>& nums1, const vector<int>& nums2, int start1,
            int start2, int n) {
    cout << "start1: " << start1 << " start2: " << start2 << " n: " << n
         << endl;
    if (start1 >= nums1.size()) {
      // cout << "nums2: ";
      return nums2[start2 + n - 1];
    }
    if (start2 >= nums2.size()) {
      // cout << "nums1: ";
      return nums1[start1 + n - 1];
    }
    if (n == 1) {
      return min(nums1[start1], nums2[start2]);
    }
    // if (n == 2) {
    //   return max(nums1[start1], nums2[start2]);
    // }
    int mid1 = min(start1 + (n - 1) / 2, (int)nums1.size() - 1),
        mid2 = min(start2 + (n - 1) / 2, (int)nums2.size() - 1);
    cout << "mid1: " << mid1 << " mid1 val: " << nums1[mid1]
         << " mid2: " << mid2 << " mid2 val: " << nums2[mid2] << endl;
    if (nums1[mid1] == nums2[mid2]) {
      return nums1[mid1];
    } else if (nums1[mid1] < nums2[mid2]) {
      cout << " < " << endl;
      return findn(nums1, nums2, mid1 + 1, start2, n - (mid1 + 1 - start1));
    } else {
      cout << " > " << endl;
      return findn(nums1, nums2, start1, mid2 + 1, n - (mid2 + 1 - start2));
    }
  }
};
// @leet end

