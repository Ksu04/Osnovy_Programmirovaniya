#include"Header.h"

int main()
{
	Array<std::string> array;
	array.push_back("HelloWorld");
	for (size_t i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << " ";
	}
	

}