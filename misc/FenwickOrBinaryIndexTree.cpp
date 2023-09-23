#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    vector<int> fenwick;
	void printFenwick() {
        for (int i = 0; i < fenwick.size(); i++) {
            cout << fenwick[i] << "\t";
        }
        cout << "\n";
    }
    int getSum(int i) {
        i++;
        int sum = 0;
        for (; i > 0; i -= (i & -i)) {
            sum += fenwick[i];
        }
        return sum;
    }
    void update(int i, int x) {
        i++;
        for (; i < fenwick.size(); i += (i & -i)) {
            fenwick[i] += x;
        }
    }
    void buildFenwick(vector<int> &nums) {
        fenwick = vector<int>(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            update(i, nums[i]);
        }
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution solution;
    solution.buildFenwick(nums);
    solution.printFenwick();
    int type;
    cout << "Enter type (0 to exit): ";
    cin >> type;
    while (type != 0)
	{
		if (type> 0)
		{
            int idx;
            cout << "Enter idx : ";
            cin >> idx;
            cout << solution.getSum(idx) << "\n";
        }
		else{
            int idx, val;
            cout << "Enter idx & val : ";
            cin >> idx >> val;
            solution.update(idx, val);
            solution.printFenwick();
        }
        cout << "Enter type (0 to exit): ";
        cin >> type;
    }
    return 0;
}
