#include "Reader.h"
#include <iostream>
#include <iomanip>
using namespace std;
Reader::Reader(string mdg, string ht, Date ns, string nn, string dc, string cmnd, string sdt)
{
	maDocGia = mdg;
	hoVaTen = ht;
	ngaySinh = ns;
	ngheNghiep = nn;
	diaChi = dc;
	CMND = cmnd;
	SDT = sdt;
}
void Reader::xuat(ostream& os)
{
	os << maDocGia << "\t" << hoVaTen << "\t" << ngaySinh.day << "/" << ngaySinh.month << "/" << ngaySinh.year << "\t" << ngheNghiep << "\t" << diaChi << "\t" << CMND << "\t" << SDT << endl;
}
Reader Reader::operator =(Reader& temp)
{
	maDocGia = temp.maDocGia;
	hoVaTen = temp.hoVaTen;
	ngaySinh = temp.ngaySinh;
	ngheNghiep = temp.ngheNghiep;
	diaChi = temp.diaChi;
	CMND = temp.CMND;
	SDT = temp.SDT;
	return *this;
}
int Reader::tinhTienLo(ostream& os)
{
	int sum=0;
	list<BookTicket>::iterator it;
	for (it = danhSachMuonLo.begin(); it != danhSachMuonLo.end(); it++)
	{
		(*it).xuat(os);
		sum += (*it).soTienPhat;
	}
	os << "Tong so tien bi phat cua doc gia " << hoVaTen << " la: " << sum << endl << endl;
	return sum;
}