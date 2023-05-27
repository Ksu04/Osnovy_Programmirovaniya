#include<iostream>
#include"Header.h"
using namespace std;

int  main()
{
    Node* top = first(1);
    for(int  i = 2;  i < 6;   i++) push(&top, i);
    while(top)
        cout << pop(&top) << ' ';

    

    return   0;
}

/*
шаблон обеспечивает механизм слабой типизации (не указываем конретный тип в реализации).
Обладает большой гибкостью (подходит ко всем объектам)

template<class T> == formobj. Т заменяет объект. Компилятор не выделяет память немедленно.
В шаблоне у функции может быть только определение (в header'е)

template<class T>class x{} - можно использовать вместо класс

особенности шаблонов !!!
*/

