#include<iostream>
#include<string>
#include<vector>
/*
Есть графические примитивы - фигуры с различными свойствами, но над каждой фигурой можно производить одинаковые действия.
Примитивы должны уметь отдавать информацию о себе в определенном формате, которую некая функция будет выводить в какой нибудь вывод. 
Для простоты примера - stdout
При этом некоторые примитивы могут быть вариациями других. формат вывода информации на примере прямоугольника и 
круга должен быть таким.
Paint Rectangle:
Rect { left = 10, top = 20, right = 600, bottom = 400 }

Paint Circle:
Circ {radius = 150, centre = (50, 300)}

Примитивы нужно объединить в однородный список

пример:
*/
class Primitive {
public:
	virtual void paint() const = 0;
	virtual std::string getinfo() const = 0;
	virtual ~Primitive();
};

class Rect : public Primitive // чтобы в шаблоне создть новый класс
{
public:
	Rect(int left, int top, int right, int bottom) : // пишем список инициализации
		m_left(left),
		m_top(top),
		m_right(right),
		m_bottom(bottom) {};

	virtual void paint() const
	{
		std::cout << "paint ractangle " << getinfo() << std::endl;
	}
	virtual std::string getinfo() const
	{
		return "Rect { left = " + std::to_string(m_left) + ", top = "
			+ std::to_string(m_top) + ", right = " + std::to_string(m_right) + ", bottom = " 
			+ std::to_string(m_bottom) + "}";
	}
private:
	int m_left, m_top, m_right, m_bottom;
};

class Circle : public Primitive {
private:
	int m_x, m_y, m_radius;
public:
	Circle(int x, int y, int radius) :
		m_x(x), m_y(y), m_radius(radius) {};
	virtual void paint() const 
	{
		std::cout << "paint circle " << getinfo() << std::endl;
	}
	virtual std::string getinfo()const {
		return "Cirlce: radius = " + std::to_string(m_radius) +
			"and centre = " + std::to_string(m_x) + ", " + std::to_string(m_y) + ")";
	}
};

// функция для вывода информации для вывода информации о всех примитивах в списке

void print_primitives(const std::vector<std::shared_ptr<Primitive>>& primitives)
{
	for (const auto& primitive : primitives)
	{
		primitive->paint();
	}
}
int main()
{
	// создаем список примитивов
	std::vector<std::shared_ptr<Primitive>> primitives;
	primitives.push_back(std::make_shared<Circle>(50, 300, 150));
	primitives.push_back(std::make_shared<Rect>(10, 20, 600, 400));
	// выводим информацию о примитивах
	print_primitives(primitives);
	return 0;
}

/*
unique_ptr<тип> (new тип) - уникальный указатель. обеспеч безопасности исключений.
элементы в типах контейнера



*/