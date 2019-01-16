#ifndef _READER_H_
#define _READER_H_
#include <iostream>
#include <fstream>
#include "BookTicket.h"
#include <list>
#include "Date.h"
using namespace std;
class Reader
{
private:
	string maDocGia;
	string hoVaTen;
	Date ngaySinh;
	string ngheNghiep;
	string diaChi;
	string CMND;
	string SDT;
	list<BookTicket> danhSachMuonLo;
	friend class Library;
public:
	Reader()
	{
		maDocGia = hoVaTen = ngheNghiep = diaChi = CMND = SDT = string::npos;
		
	}
	Reader(string, string, Date, string, string, string, string);
	Reader operator = (Reader& temp);
	void xuat(ostream& os);
	int tinhTienLo(ostream& os);
	bool operator ==(const Reader& temp)
	{
		return maDocGia == temp.maDocGia;
	}
	bool operator !=(const Reader& temp)
	{
		return !operator==(temp);
	}
	bool operator < (const Reader& temp)
	{
		return this->maDocGia < temp.maDocGia;
	}
};
#endif