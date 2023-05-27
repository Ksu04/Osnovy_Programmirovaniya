#include <iostream>
#include "Header.h"
using namespace std;

unsigned integer::count_digits(unsigned int N)
{
    unsigned long int M;
    unsigned int kol;
    for (M = N, kol = 1; M / 10 > 0; kol++, M /= 10);
    return kol;
}
unsigned integer::reverse(unsigned int N)
{
    unsigned long int M, R, S;
    int size= count_digits(this->n);
    int i;
    R = 10 ^ size;
    for (S = 0, M = this->n,  i = 1; i <= size; S += (M % 10 * R), M /= 10, R /= 10, i++);
    return S;
}
unsigned long integer::reverse_digit(unsigned int N)   // ѕолучить новое число, 
{                                             // записав цифры числа N в обратном пор€дке
    int M, R, S;                // R = 10kol Ч старший разр€д заданного числа
    int j, i; //S - целое число, полученное из цифр числа N=17852, S = 2 Х 104 + 5 Х 103 + 8 Х 102 +7 Х 101 + 1 Х 100
    for (R = 1, j = 1; j < count_digits(N); R *= 10, j++);
    for (S = 0, M = N, i = 1; i <= count_digits(N); S += (M % 10 * R), M /= 10, R /= 10, i++);
    return S;
}
bool integer::polindrom()  // ѕроверить, €вл€етс€ ли заданное число N палиндромом
{
    unsigned long int M, S;  // «апишем цифры заданного числа N в обратном пор€дке, 
    S = reverse_digit(this->n);  // получитс€ новое число S.
    if (this->n == S)             // —равнить  число S с исходным N.
        return true;         //   ≈сли числа равны, то заданное число €вл€етс€ палиндромом.
    else return false;
}
unsigned integer::count_dels()
{
    unsigned int i, K; 
    K = 0; 
    for (i = 1; i <= this->n / 2; i++)
        if (this->n % i == 0) K++;
    
    return K;  
}
unsigned int integer::soversh()
{          
    unsigned int i, S;
    for (S = 0, i = 1; i <= this->n / 2; i++)
        if (this->n % i == 0) S += i;
    if (S == this->n) return 1;
    else return 0;
}
bool integer::is_prostoe() {
    unsigned i;
    bool Pr;
    Pr = true;
    for (i = 2; i <= this->n / 2; i++)
        if (this->n % i == 0)
        {
            Pr = false;   break;
        }
    return Pr;
}
unsigned massive_enter_power(unsigned N) {
    unsigned c = 0;
    int i = 0;
    while (c != 0) {
        cin >> c;

    }
    return c;

}

void MyVector::reserve(int size)
{
    this->length = size;
    this->pMem = new int[size]; // выдел€ет пам€ть и вызывает конструктор
    this->composity = size;

}
void MyVector::push_back(int x)
{
    if (pointer < length) { pMem[pointer] = x; }
    if (pointer >= length)
    {
        reserve();
        pointer++;
        pMem[pointer] = x;
    }
}
void MyVector::reserve() 
{
    this->length *= 2;
    int* p = new int[length];
    pMem = p;
    delete[] pMem; // [] удал€ет пам€ть всего массива
}

void MyVector::print()
{
    for (int i = 0; i < length; i++)
    {
        cout << pMem[i];
    }

}

int main() {
    
    MyVector a(5);
    MyVector b;

    for (int i = 0; i < 4; i++)
    {
        a.push_back(i);
        a.print();
    }
    
 void MyVector::at(int x) {
     return pMem[x];
  }

    
    
    /*
    unsigned int N, result;
    unsigned int arr[];
    cout << " N = ";  	cin >> N;
    integer a(N);
    massive_enter_power();
    
    
    bool flag = a.polindrom();
    unsigned power = a.count_digits(N);
    unsigned long rever = a.reverse_digit(N);
    cout << " count of difits = " << power << endl;
    cout << " reverse = " << rever << endl;
    switch (flag)
    {
    case 1: printf("\n is palindrom \n"); break;
    case 0: printf("\n is not palindrom \n"); break;
    }


    
    unsigned c = a.count_dels();
    unsigned sov = a.soversh();
    bool prostoe = a.is_prostoe();
    cout << "Numder of divisor = " << c << endl;
    cout << "Soverhennoe? " << sov << endl;
    cout << "Prostoe? " << prostoe << endl;
    */
    system("pause");
    return 0;
}
