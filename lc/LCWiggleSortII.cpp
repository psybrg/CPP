#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    void swap(vector<int>& nums, int i, int j) {
        // printf("[%d]:%d\t[%d]:%d\n", i, nums[i], j, nums[j]);
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
    void print(vector<int> nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << "\t";
        }
        cout << "\n";
    }
    int kthSmallestNumber(vector<int>& nums, int k) {
        srand(time(0));
        for (int i = nums.size() - 1; i >= 0; i--) {
            swap(nums, i, rand() % (i + 1));
        }
        int l = 0, r = nums.size() - 1;
        k--;

        while (l < r) {
            int m = getmediandle(nums, l, r);

            if (m < k) {
                l = m + 1;
            } else if (m > k) {
                r = m - 1;
            } else {
                break;
            }
        }
        return nums[k];
    }
    int getmediandle(vector<int>& nums, int l, int r) {
        int i = l;

        for (int j = l + 1; j <= r; j++) {
            if (nums[j] < nums[l]) swap(nums, ++i, j);
        }

        swap(nums, l, i);
        return i;
    }
    int partition(vector<int>& arr, int l, int r) {
        int x = arr[r], i = l;
        for (int j = l; j <= r - 1; j++) {
            if (arr[j] <= x) {
                swap(arr, i, j);
                i++;
            }
        }
        swap(arr, i, r);
        return i;
    }
    int kthSmallest(vector<int>& arr, int l, int r, int k) {
        if (k > 0 && k <= r - l + 1) {
            int index = partition(arr, l, r);
            if (index - l == k - 1) return arr[index];
            if (index - l > k - 1) return kthSmallest(arr, l, index - 1, k);
            return kthSmallest(arr, index + 1, r, k - index + l - 1);
        }
        return INT_MAX;
    }
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return;
        sort(nums.begin(), nums.end());
        int median = nums[nums.size()/2];
        // int median = kthSmallestNumber(nums, (n - 1) / 2);
        // int median = kthSmallest(nums, 0, n - 1, n>>1);
        for (int i = 0; i < n; i++) cout << nums[i] << "\t";
        cout << "\n";
        cout << median << "\n";
        int oddPosition = 1;
        int evenPosition = n % 2 == 0 ? n - 2 : n - 1;
        int i = 0;
        while (i < n) {
            if (nums[i] < median && (i < evenPosition || (i >= evenPosition && i % 2 != 0))) {
                printf("[%d]:%d\t[%d]:%d\n", i, nums[i], evenPosition, nums[evenPosition]);
                swap(nums, i, evenPosition);
                evenPosition -= 2;
            } else if (nums[i] > median && oddPosition < n && (oddPosition < i || (oddPosition >= i && i % 2 == 0))) {
                printf("[%d]:%d\t[%d]:%d\n", i, nums[i], oddPosition, nums[oddPosition]);
                swap(nums, i, oddPosition);
                oddPosition += 2;
            } else {
                i++;
            }
            // cout << evenPosition << "\t" << i << "\t" << oddPosition << "\n";
        }
    };
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution solution;
    solution.wiggleSort(nums);
    for (int i = 0; i < n; i++) cout << nums[i] << "\t";
    cout << "\n";
    return 0;
}