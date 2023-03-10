#include "FileBook.h"
#include "Book.h"

void FileBook::SaveBookFile(Book* books, int size) {
	if (!fopen_s(&file, path, APPEND)) {
		for (int i = 0; i < size; i++) {
			fprintf_s(file, "%s ", books[i]._nameBook, strlen(books[i]._nameBook)*sizeof(char));
			fprintf_s(file, "%s ", books[i]._author, strlen(books[i]._author) * sizeof(char));
			fprintf_s(file, "%s ", books[i]._publisher, strlen(books[i]._publisher) * sizeof(char));
			fprintf_s(file, "%d ", books[i]._pages, sizeof(int));
			fprintf_s(file, "%d \n", books[i]._year, sizeof(int));
		}
	}
	fclose(file);
}
Book* FileBook::LoadBookFile() {
	int count = 0;
	char* s = new char[100];
	if (!fopen_s(&file, path, READ)) {
		while (!feof(file)) {
			fgets(s, 100, file);
			count++;
		}
	}
	fclose(file);

	Book* books = new Book[count];
	int i = 0;
	char publish[25];
	if (!fopen_s(&file, path, READ)) {
		while (!feof(file))
		{
			fscanf_s(file, "%s", books[i]._nameBook, sizeof(books[i]._nameBook));
			fscanf_s(file, "%s", books[i]._author, sizeof(books[i]._author));
			fscanf_s(file, "%s", publish, sizeof(publish));
			strcpy_s(books[i]._publisher, 25, publish);
			fscanf_s(file, "%d", &books[i]._pages, sizeof(books[i]._pages));
			fscanf_s(file, "%d", &books[i]._year, sizeof(books[i]._year));
			if (i >= 5) break;
			i++;
		}
	}
	fclose(file);
	return books;

}