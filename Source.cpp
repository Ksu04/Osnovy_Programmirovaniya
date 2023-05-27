#include<iostream>
#include<string>
#include<vector>
/*
���� ����������� ��������� - ������ � ���������� ����������, �� ��� ������ ������� ����� ����������� ���������� ��������.
��������� ������ ����� �������� ���������� � ���� � ������������ �������, ������� ����� ������� ����� �������� � ����� ������ �����. 
��� �������� ������� - stdout
��� ���� ��������� ��������� ����� ���� ���������� ������. ������ ������ ���������� �� ������� �������������� � 
����� ������ ���� �����.
Paint Rectangle:
Rect { left = 10, top = 20, right = 600, bottom = 400 }

Paint Circle:
Circ {radius = 150, centre = (50, 300)}

��������� ����� ���������� � ���������� ������

������:
*/
class Primitive {
public:
	virtual void paint() const = 0;
	virtual std::string getinfo() const = 0;
	virtual ~Primitive();
};

class Rect : public Primitive // ����� � ������� ������ ����� �����
{
public:
	Rect(int left, int top, int right, int bottom) : // ����� ������ �������������
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

// ������� ��� ������ ���������� ��� ������ ���������� � ���� ���������� � ������

void print_primitives(const std::vector<std::shared_ptr<Primitive>>& primitives)
{
	for (const auto& primitive : primitives)
	{
		primitive->paint();
	}
}
int main()
{
	// ������� ������ ����������
	std::vector<std::shared_ptr<Primitive>> primitives;
	primitives.push_back(std::make_shared<Circle>(50, 300, 150));
	primitives.push_back(std::make_shared<Rect>(10, 20, 600, 400));
	// ������� ���������� � ����������
	print_primitives(primitives);
	return 0;
}

/*
unique_ptr<���> (new ���) - ���������� ���������. ������� ������������ ����������.
�������� � ����� ����������



*/