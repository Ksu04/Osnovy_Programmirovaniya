#pragma once
#include<vector>
#include<list>
#include<map>
#include<string>
#include<iostream>
using namespace std;
class Node
{
public:
	int count;
	char symbol;
	Node* left;
	Node* right;
	Node() {};
	Node(char _symbol, int _count)
	{
		symbol = _symbol; // передает в 12 строку полученное значение
		count = _count;
	}
	Node(Node* l, Node* r) 
	{
		symbol = 0;
		left = l;
		right = r;
		count = l->count + r->count;
	}
	static void BuildTable(Node* root, vector<bool>& code, map<char, vector<bool>>& table) {
		if (root->left) // непустая, что-то есть
		{
			code.push_back(0);
			BuildTable(root->left, code, table);
		}
		if (root->right)
		{
			code.push_back(1);
			BuildTable(root->right, code, table);
		}
		if (root->symbol) table[root->symbol] = code;
		if (code.size()) code.pop_back(); // удаляет последний элемент
	}
	bool SortNode(const Node* a, const Node* b)
	{
		return a->count < b->count;
	}
	static string Decode(string& str, map <vector<bool>, char>& table)
	{
		string out = " ";
		vector<bool> code;
		for (int i = 0; i < str.length(); i++)
		{
			code.push_back(str[i] != '0');
			if (table[code])
			{
				out += table[code];
				code.clear(); // почистит, erase удалит всю мапу 
			}
		}
		return out;
	}
	static void Print(Node* root, int depth = 0)
	{
		if (!root) return;
		if (root->symbol)
		{
			for (int i = 0; i < depth; i++)
			{
				cout << ".";
				cout << root->symbol << endl;
			}
		}
		else depth++;
		Print(root->left, depth);
		Print(root->right, depth);
	}
};

