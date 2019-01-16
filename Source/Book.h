#ifndef _BOOK_H_
#define _BOOK_H_
#include <string>
using namespace std;
class Book
{
protected:
	string maSach;
	string tenSach;
	string tacGia;
	string nhaXuatBan;
	string giaSach;
public:
	Book();
	Book(Book&);
	Book(string, string, string, string, string);
	friend class Library;
	string getmaSach()
	{
		return this->maSach;
	}
	bool operator ==(const Book& temp)
	{
		return maSach == temp.maSach;
	}
	bool operator !=(const Book& temp)
	{
		return !operator==(temp);
	}
	bool operator < (const Book& temp)
	{
		return this->maSach < temp.maSach;
	}
};
class EBook :public Book
{
private:
	string ISBN;
public:
	friend class Library;
	friend class VBook;
	EBook();
	EBook(const EBook&);
	EBook(string, string, string, string, string, string);
	bool operator ==(const EBook& temp)
	{
		return maSach == temp.maSach;
	}
	bool operator !=(const EBook& temp)
	{
		return !operator==(temp);
	}
	bool operator < (const EBook& temp)
	{
		return this->maSach < temp.maSach;
	}
	void xuat(ostream& os);
};
class VBook :public Book
{
public:
	VBook();
	VBook(const VBook&);
	VBook(string, string, string, string, string);
	void xuat(ostream&);
	bool operator ==(const VBook& temp)
	{
		return maSach == temp.maSach;
	}
	bool operator !=(const VBook& temp)
	{
		return !operator==(temp);
	}
	bool operator < (const VBook& temp)
	{
		return this->maSach < temp.maSach;
	}
	EBook toEBook() const
	{
		EBook temp;
		temp.maSach = this->maSach;
		temp.tenSach = this->tenSach;
		temp.tacGia = this->tacGia;
		temp.nhaXuatBan = this->nhaXuatBan;
		temp.giaSach = this->giaSach;
		temp.ISBN = "Khong co";
		return temp;
	}
	friend class Library;
};
#endif
