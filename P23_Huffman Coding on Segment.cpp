#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class huffmanNode {
public:
	int data;
	huffmanNode* left;
	huffmanNode* right;
	int freq;

	//Constructor
	huffmanNode(int d, int f) {
		data = d;
		freq = f;
		left = right = nullptr;
	}
};

class Comp {
public:
	bool operator()(huffmanNode* a, huffmanNode* b) {
		return a->freq > b->freq;
	}
};

vector<pair<int, int>>cnt; // Vector to store bit counts for each character

void countingBits(huffmanNode* root, int lv) {

	if (root->left)
		countingBits(root->left, lv + 1);

	if (root->right)
		countingBits(root->right, lv + 1);

	if (root->left == nullptr && root->right == nullptr)
		cnt.push_back(make_pair(root->data, lv));
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(), cout.tie();
	int n, q, q1, q2;
	cin >> n;
	vector<int>vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	cin >> q;
	vector<int>res(q);

	for (int i = 0; i < q; i++) {

		cin >> q1 >> q2;

		//Creating map for frequency
		unordered_map<int, int>mp;
		for (int j = q1; j < q2; j++)
			mp[vec[j]]++;

		// Using Min-Heap which is a priority queue and compare on frequencies
		priority_queue<huffmanNode*, vector<huffmanNode*>, Comp>pq;

		for (auto it = mp.begin(); it != mp.end(); it++) {
			huffmanNode* node = new huffmanNode(it->first, it->second);
			pq.push(node);
		}

		while (pq.size() != 1) {
			huffmanNode* l = pq.top();
			pq.pop();
			huffmanNode* r = pq.top();
			pq.pop();
			huffmanNode* node = new huffmanNode(0, l->freq + r->freq);
			node->left = l;
			node->right = r;
			pq.push(node);
		}

		int lv = 0, r = 0;
		countingBits(pq.top(), lv);
		for (int i = 0; i < cnt.size(); i++)
			r += mp[cnt[i].first] * cnt[i].second;

		res[i] = r;
		cnt.clear();
	}

	for (int i = 0; i < q; i++)
		cout << res[i] << endl;

	return 0;
}