#pragma once
#include <iostream>
#include "Book.h"
#define READ   "r"
#define WRITE  "w"
#define APPEND "a"

using namespace std;

class FileBook
{
	FILE* file;
	char* path;
	friend class Book;
public:
	FileBook(const char* p) : path{ new char[100] } {
		strcpy_s(path, 100, p);
		/*strcat_s(path, 100, n);*/
	}
	~FileBook() {
		delete[] path;
		fclose(file);
	}

	void SaveBookFile(Book* books, int size = 1);
	Book* LoadBookFile();
};

