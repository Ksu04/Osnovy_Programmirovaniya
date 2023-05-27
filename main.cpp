#include <map>
#include <string>
#include <iostream>

int main()
{
	std::map<std::string, std::string> m;
	m["Masha"] = "23456";
	std::cout << m["Masha"] << std::endl;

	std::map<std::string, std::string> m2;
	m2["masha"] = "23456";
	m2["Misha"] = "98765";
	for (auto& it : m2)
		//for (auto it = m2.begin(); it != m2.end(); ++i) // для старообрядцев
	{
		std::cout << it.first << " <-> " << it.second << std::endl;
	}

	return 0;
}