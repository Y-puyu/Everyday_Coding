class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		vector<vector<int> > res;
		sort(S.begin(), S.end());
		int max = 1 << S.size();
		for (int k = 0; k < max; ++k) {
			vector<int> out = convertIntToSet(S, k);
			res.push_back(out);
		}
		return res;
	}
	vector<int> convertIntToSet(vector<int> &S, int k) {
		vector<int> sub;
		int idx = 0;
		for (int i = k; i > 0; i >>= 1) {
			if ((i & 1) == 1) {
				sub.push_back(S[idx]);
			}
			++idx;
		}
		return sub;
	}
};


class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ret;
		ret.push_back({});
		int size = nums.size();
		int subsize = pow(2, size);
		int hash = 1;
		while (hash < subsize) {
			vector<int> temp;
			for (int k = 0; k < size; ++k) {
				int a = 1 << k;
				if (a & hash) {
					temp.push_back(nums[k]);
				}
			}
			ret.push_back(temp);
			++hash;
		}
		return ret;
	}
};


class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int S = nums.size();
		int N = 1 << S;
		vector<vector<int> > res;
		for (int i = 0; i < N; ++i) {
			vector<int> v;
			for (int j = 0; j < S; ++j)
				if (i & (1 << j))
					v.push_back(nums[j]);
			res.push_back(v);
		}
		return res;
	}
};


class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		vector<vector<int> > res(1);
		for (int i = 0; i < S.size(); ++i) {
			int size = res.size();
			for (int j = 0; j < size; ++j) {
				res.push_back(res[j]);
				res.back().push_back(S[i]);
			}
		}
		return res;
	}
};

class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		vector<vector<int> > res;
		vector<int> out;
		getSubsets(S, 0, out, res);
		return res;
	}
	void getSubsets(vector<int> &S, int pos, vector<int> &out, vector<vector<int> > &res) {
		res.push_back(out);
		for (int i = pos; i < S.size(); ++i) {
			out.push_back(S[i]);
			getSubsets(S, i + 1, out, res);
			out.pop_back();
		}
	}
};


class Solution {
private:
	vector<vector<int> >res;
public:
	vector<vector<int> > subsets(vector<int> &S) {
		res.clear();
		vector<int>tmpres;
		dfs(S, 0, tmpres);
		return res;
	}
	void dfs(vector<int> &S, int iend, vector<int> &tmpres)
	{
		if (iend == S.size())
		{
			res.push_back(tmpres); return;
		}
		//—°‘ÒS[iend]
		tmpres.push_back(S[iend]);
		dfs(S, iend + 1, tmpres);
		tmpres.pop_back();
		//≤ª—°‘ÒS[iend]
		dfs(S, iend + 1, tmpres);
	}
};

