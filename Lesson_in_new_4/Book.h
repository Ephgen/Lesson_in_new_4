#pragma once
#include <iostream>

using namespace std;

/*
�������� ����� Book
���������� ������� ������: �����, ��������, ������������,
���, ���������� �������.
������� ������ ��������. �������:
1. ������ ���� ��������� ������;
2. ������ ����, ���������� �������� �������������;
3. ������ ����, ���������� ����� ��������� ����.
4. �������������� �����.
5. ���������� � ����.
6. �������� �� �����.
����������� explicit ����������� � ����������� �������-�����
(��������, ��� ����������� ������ � ����� � �.�.)
*/

class Book
{
	char _author[25];
	char _nameBook[25];
	char* _publisher;
	int _year;
	int _pages;



public:               // ����������� ����������� ���������
	Book(const char* a, const char* n, char* p, int y, int page) :
		_publisher{(p) ? new char[strlen(p) + 1] : new char[25]}, 
		_year{y}, _pages{page}
	{
		strcpy_s(_author, a);
		strcpy_s(_nameBook, n);
		if (p)strcpy_s(_publisher, strlen(p) + 1,p);
	}

	Book() : Book("\0", "\0", nullptr,0,0) {	}
	
	ostream& ShowAutorBook(ostream& in, const char* author, int size) {
		for (int i = 0; i < size; i++) {
			if (!strcmp(this[i]._author, author))
			in << "��� ������: " << this[i]._author << " �����: " << this[i]._nameBook << endl;
		}
		return in;
	}
	
	ostream& ShowPublisherBook(ostream& in, const char* publisher, int size) {
		for (int i = 0; i < size; i++) {
			if (!strcmp(this[i]._publisher, publisher))
				in << "��� ������: " << this[i]._author << " �����: " << this[i]._nameBook << endl;
		}
		return in;
	}

	ostream& ShowYearBook(ostream& in, int y, int size) {
		for (int i = 0; i < size; i++) {
			if (this[i]._year >= y)
				in << "��� ������: " << this[i]._author << " �����: " << this[i]._nameBook << endl;
		}
		return in;
	}
};

