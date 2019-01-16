#include "Book.h"
#include <iostream>
#include <iomanip>
using namespace std;
Book::Book()
{
	maSach = tenSach = tacGia = nhaXuatBan = giaSach = string::npos;
}
Book::Book(Book& temp)
{
	this->maSach = temp.maSach;
	this->tenSach = temp.tenSach;
	this->tacGia = temp.nhaXuatBan;
	this->nhaXuatBan = temp.nhaXuatBan;
	this->giaSach = temp.giaSach;
}
Book::Book(string ms, string ts, string tg, string nxb, string gs)
{
	this->maSach = ms;
	this->tenSach = ts;
	this->nhaXuatBan = nxb;
	this->tacGia = tg;
	this->giaSach = gs;
}
void VBook::xuat(ostream& os)
{
	os << maSach << "\t" << tenSach << "\t" << tacGia << "\t" << nhaXuatBan << "\t" << giaSach << endl;
}
VBook::VBook() :Book()
{
}
VBook::VBook(const VBook& temp)
{
	this->maSach = temp.maSach;
	this->tenSach = temp.tenSach;
	this->tacGia = temp.tacGia;
	this->nhaXuatBan = temp.nhaXuatBan;
	this->giaSach = temp.giaSach;
}
VBook::VBook(string ms, string ts, string tg, string nxb, string gs)
{
	this->maSach = ms;
	this->tenSach = ts;
	this->nhaXuatBan = nxb;
	this->tacGia = tg;
	this->giaSach = gs;
}
EBook::EBook()
{
	this->maSach = string::npos;
	this->tenSach = string::npos;
	this->nhaXuatBan = string::npos;
	this->tacGia = string::npos;
	this->giaSach = string::npos;
	this->ISBN = string::npos;
}
EBook::EBook(const EBook& temp)
{
	this->maSach = temp.maSach;
	this->tenSach = temp.tenSach;
	this->tacGia = temp.tacGia;
	this->nhaXuatBan = temp.nhaXuatBan;
	this->giaSach = temp.giaSach;
	this->ISBN = temp.ISBN;
}
EBook::EBook(string ms, string ts, string tg, string nxb, string gs, string isbn)
{
	this->maSach = ms;
	this->tenSach = ts;
	this->nhaXuatBan = nxb;
	this->tacGia = tg;
	this->giaSach = gs;
	this->ISBN = isbn;
}
void EBook::xuat(ostream& os)
{
	os << maSach << "\t" << tenSach << "\t" << nhaXuatBan << "\t" << tacGia << "\t" << giaSach <<"\t"<<ISBN<< endl;
}