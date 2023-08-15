#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;

map<char, string> codes;
map<char, int> freq;
//MinHeap structure
struct MinHeapNode
{
	char data;
	int freq;
	MinHeapNode *left, *right;
	MinHeapNode(char data, int freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

struct compare
{
	bool operator()(MinHeapNode* l, MinHeapNode* r)
	{
		return (l->freq > r->freq);
	}
};

void printCodes(struct MinHeapNode* root, string str)
{
	if (!root)
		return;
	if (root->data != '$')
		cout << root->data << ": " << str << "\n";
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

void storeCodes(struct MinHeapNode* root, string str)
{
	if (root == NULL)
		return;
	if (root->data != '$')
		codes[root->data] = str;
	storeCodes(root->left, str + "0");
	storeCodes(root->right, str + "1");
}

priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

//huffman Code function
void HuffmanCodes(int size)
{
	struct MinHeapNode *left, *right, *top;
	for (map<char, int>::iterator v = freq.begin(); v != freq.end(); v++)
		minHeap.push(new MinHeapNode(v->first, v->second));
	while (minHeap.size() != 1)
	{
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		top = new MinHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}
	storeCodes(minHeap.top(), "");
}

void calcFreq(string str, int n)
{
	for (int i = 0; i < str.size(); i++)
		freq[str[i]]++;
}

// complete this function
string decodeHuffmanData(struct MinHeapNode* root, string binaryString);
int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		//taking string
		cin >> str;
		string encodedString, decodedString;
		//function calls
		calcFreq(str, str.length());
		HuffmanCodes(str.length());

		//adding encoded string
		for (auto i : str)encodedString += codes[i];
		//cout<<encodedString<<endl;

		//decoding encoded string
		decodedString = decodeHuffmanData(minHeap.top(), encodedString);
		cout << decodedString << endl;
	}
	return 0;
}
void code(string str, unordered_map<string, char> &mp, MinHeapNode *root)
{
	if (root == NULL) return;
	if (root->data != '$')
	{
		mp[str] = root->data;
		return;
	};
	code(str + "0", mp, root->left);
	code(str + "1", mp, root->right);
}

string decodeHuffmanData(struct MinHeapNode* root, string binaryString)
{
	// Code here
	unordered_map<string, char> mp;
	code("", mp, root);
	int n = binaryString.size();
	int i = 0;
	string temp = "", res = "";

	while (i < n)
	{
		temp.push_back(binaryString[i]);
		if (mp.find(temp) != mp.end())
		{
			res.push_back(mp[temp]);
			temp = "";
		}
		i++;
	}
	return res;
}