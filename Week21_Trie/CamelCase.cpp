#include <bits/stdc++.h>
using namespace std;

// Alphabet size (# of upper-Case characters)
#define ALPHABET_SIZE 26


struct trienode {
	vector<string>word;
	trienode *child[26];
	bool isend;
	trienode() {
		for (int i = 0; i < 26; ++i) child[i] = NULL;
		isend = false;
	}
};
// inserting whole word with reference to the captial letter of the last word.
void insert(string s, trienode *root) {
	trienode * curr = root;
	for (int i = 0; i < s.length(); ++i) {
		if (islower(s[i])) continue;
		int index = s[i] - 'A';
		if (!curr->child[index])
			curr->child[index] = new trienode();
		curr =  curr->child[index];
	}
	curr->isend = true;
	curr->word.push_back(s);
	sort(curr->word.begin(), curr->word.end());
}
// Similarly searching and then printing with the last capital letter of the pattern.
void print(trienode *curr) {
	if (curr->isend)
		for (auto i : curr->word) cout << i << " ";
	for (int i = 0; i < 26; ++i) {
		trienode *temp = curr->child[i];
		if (temp) print(temp);
	}
}
bool search(trienode *root, string pattern) {
	trienode* curr = root;
	for (int i = 0; i < pattern.length(); ++i) {
		int index = pattern[i] - 'A';
		if (!curr->child[index]) return false;
		curr = curr->child[index];
	}
	print(curr);
	return true;
}
// finally printing with 2 cases:
//1. for e.g. pattern = "HW" & inserted short word 		      is also "HW".
//2. for e.g. pattern = "HW" & inserted short word is "HWBGG","HWCY",etc.

class Solution
{
public:
	//Function to print all words in the CamelCase dictionary
	//that matches with a given pattern.
	void findAllWords(vector<string> dict, string pattern)
	{
		//code here
		trienode *root = new trienode();
		for (auto i : dict) insert(i, root);
		if (!search(root, pattern))
			cout << "No match found";
	}
};


//{ Driver Code Starts.

int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int now;
		cin >> now;
		vector<string> dict(now) ;
		for (int i = 0; i < now; i++)
			cin >> dict[i];

		string pattern;
		cin >> pattern;
		Solution obj;
		obj.findAllWords(dict, pattern);
		cout << endl;
	}
	return 0;
}