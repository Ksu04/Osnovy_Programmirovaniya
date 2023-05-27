/*
Алгоритм Хаффмана
Через деревья: заопминается класс, элемент с двумя указателями
Нужно запоминать сколько и где встречается символ

сделать вывод на экран, применить Принт
*/
#include"Header.h"
// using namespace Node;
int main() {
	int a = 0, c;
	cout << "Enter the text: " << endl;
	string raw;
	getline(cin, raw);
	map<char, int> symbols;
	for (int i = 0; i < raw.length(); i++) symbols[raw[i]]++;
	list<Node*> trees;
	map<char, int>::iterator itr; // показываем, что будем работать с мапом
	for (itr = symbols.begin(); itr != symbols.end(); itr++)
	{
		Node* p = new Node(itr->first, itr->second);
		trees.push_back(p);
	}
	if (trees.size() == 0)
	{
		cout << "string is empty" << endl;
		system("pause");
		return 0;
	}
	else
	{
		if (trees.size() == 1)
		{
			Node* root = trees.front(); 
			root->Print(root);
			cout << " - " << a << endl;
			system("pause");
		}
		else 
		{
			while (trees.size() != 1)
			{
				Node* l = trees.front();
				trees.pop_front();
				Node* r = trees.front();
				trees.pop_front();
				Node* parent = new Node(l, r);
				trees.push_back(parent);

			}
			Node* root = trees.front();
			root->Print(root);
			vector<bool> code;
			map<char, vector<bool>> table;
			Node::BuildTable(root, code, table);
			for (itr = symbols.begin(); itr != symbols.end(); itr++)
			{
				cout << itr->first << "-";
				for (int j = 0; j < table[itr->first].size(); j++)cout << table[itr->first][j] << endl;
			}
			string out = " ";
			for (int i = 0; i < raw.length(); i++)
			{
				for (int j = 0; j < table[raw[i]].size(); j++)
				{
					out += table[raw[i]][j] + '0';
					cout << table[raw[i]][j];
					cout << endl;
					// cout << out.c_str() << endl; c_str преобразовывает в си строку(массив чаров) (здесь не нужно)
					cout << out << endl;
					map<vector<bool>, char> ftable;
					for (auto i = table.begin(); i != table.end(); i++) ftable[i->second] = i->first;
					cout << Node::Decode(out, ftable) << endl;
					system("pause");
				}
			}
		}
	}
}