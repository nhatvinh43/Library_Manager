#ifndef _LIBRARY_H_
#define _LIBRARY_H_
#include "Book.h"
#include "BookTicket.h"
#include "Reader.h"
#include <ctime>
#include <list>
#include <fstream>
#include <iostream>
using namespace std;
class Library
{
private:
	list<Reader> danhSachDocGia;
	list<VBook> danhSachVBook;
	list<EBook> danhSachEBook;
	list<BookTicket> danhSachTheMuon;
	list<Reader> danhSachPhat;
	const static int Vbook_fine = 10000;
	const static int Ebook_fine = 20000;
public:
	int countLines(string filename);
	int countTabs(string filename);

	void Reader_AddtoFile(Reader&);
	void VBook_AddtoFile(VBook&);
	void EBook_AddtoFile(EBook&);
	void BookTicket_AddtoFile(BookTicket&);

	int checkFileReader(const string, const string);
	int checkFileVBook(const string, const string);
	int checkFileEBook(const string, const string);

	void sortReaderList();
	void sortVBookList();
	void sortEBookList();
	void sortBookTicketList();

	list<Reader> getListReader(string filename);
	list<VBook> getListVBook(string filename);
	list<EBook> getListEBook(string filename);
	list<BookTicket> getListBookTicket(string filename);

	void Reader_Add();
	void Reader_Delete();
	void Reader_Update();
	void Reader_Search();

	void VBook_Add();
	void VBook_Delete();
	void VBook_Update();
	void VBook_Search();

	void EBook_Add();
	void EBook_Delete();
	void EBook_Update();
	void EBook_Search();

	void BookTicket_Add();
	void BookTicket_Delete();
	void BookTicket_FineList();
	void BookTicket_AutoUpdate();
	void BookTicket_FineUpdate();

	void Book_MergeFile();

};
#endif