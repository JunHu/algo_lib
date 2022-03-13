// nlogn求最长不降子序列
// 使用lower_bound可以求最长上升子序列

int lis(vector<int>& arr) {
	vector<int> lis_ret;
	for (int i = 0; i < arr.size(); ++i) {
		auto it = upper_bound(lis_ret.begin(), lis_ret.end(), arr[i]);
		if (it == lis_ret.end()) lis_ret.push_back(arr[i]);
		else *it = arr[i];
	}
	return lis_ret.size();
}
