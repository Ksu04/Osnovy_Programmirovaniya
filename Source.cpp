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
������ ������������ �������� ������ ��������� (�� ��������� ��������� ��� � ����������).
�������� ������� ��������� (�������� �� ���� ��������)

template<class T> == formobj. � �������� ������. ���������� �� �������� ������ ����������.
� ������� � ������� ����� ���� ������ ����������� (� header'�)

template<class T>class x{} - ����� ������������ ������ �����

����������� �������� !!!
*/

