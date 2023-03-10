#include <iostream>
#include <windows.h>
#include "Book.h"
#include "FileBook.h"

using namespace std;


/*
Создайте класс Book
Необходимо хранить данные: Автор, Название, Издательство,
Год, Количество, страниц.
Создать массив объектов. Вывести:
1. список книг заданного автора;
2. список книг, выпущенных заданным издательством;
3. список книг, выпущенных после заданного года.
4. Редактирование книги.
5. сохранение в файл.
6. Загрузка из файла.
Используйте explicit конструктор и константные функции-члены
(например, для отображения данных о книге и т.д.)
*/

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Book b { "автор 1", "книга 1", (char*)"издатель 1", 2000, 498 };
	Book b1 { "автор 2", "книга 2", (char*)"издатель 2", 2007, 678 };
	Book b2{ "автор 3", "книга 3", (char*)"издатель 3", 2003, 678 };
	Book b3{ "автор 4", "книга 2", (char*)"издатель 2", 2004, 678 };
	Book b4{ "автор 1", "книга 3", (char*)"издатель 3", 2005, 678 };

	Book* books = new Book[5]{b, b1,b2, b3, b4};

	int size = 5;
	/*books->ShowAutorBook(cout,"автор 1", size);

	books->ShowPublisherBook(cout, "издатель 2", size);

	books->ShowYearBook(cout,2007, size);*/
	FileBook fb{(char*)"text.txt"};

	//fb.SaveBookFile(books,5);
	Book* books2 = fb.LoadBookFile();
	books2->ShowYearBook(cout, 2000, size);
}
