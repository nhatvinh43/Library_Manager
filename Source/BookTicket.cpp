#include "BookTicket.h"
#include "Date.h"
#include <ctime>
#include <iostream>
using namespace std;

int rdn( Date ngay)
{
	if (ngay.month < 3)
		ngay.year--, ngay.month += 12;
	return 365 * ngay.year + ngay.year / 4 - ngay.year / 100 + ngay.year / 400 + (153 * ngay.month - 457) / 5 + ngay.day - 306;
}
int BookTicket::tinhSoNgayLo()
{
	Date currentDate;
	time_t t = time(0);
	tm* now = localtime(&t);
	currentDate.year = now->tm_year + 1900;
	currentDate.month = now->tm_mon + 1;
	currentDate.day = now->tm_mday;
	if (this->trangThai == 0 || rdn(currentDate) - rdn(ngayTra)>0)
	{
		this->soNgayLo = rdn(currentDate) - rdn(ngayTra);
		if (this->soNgayLo <= 0)
		{
			this->soNgayLo = 0;
		}
	}
	else soNgayLo = 0;
	return soNgayLo;
}
void BookTicket:: xuat(ostream& os)
{
	os <<maDocGia<<"\t"<< tenSach << "\t" <<loaiSach<<"\t"<< ngayMuon.day << "/" << ngayMuon.month << "/" << ngayTra.year << "\t" << ngayTra.day << "/" << ngayTra.month << "/" << ngayTra.year << "\t";
	if (trangThai == 0)
	{
		os << "Chua tra" << "\t";
	}
	else
	{
		os << "Da tra" << "\t";
	}
	os << soNgayLo << endl;
}
int BookTicket::tinhSoTienPhat()
{
	if (this->loaiSach == "Tieng Viet" || this->loaiSach == "tieng viet" || this->loaiSach == "Tieng viet" || this->loaiSach == "TIENG VIET")
	{
		this->soTienPhat = soNgayLo*VFine;
		return this->soTienPhat;
	}
	else
	{
		this->soTienPhat = soNgayLo*EFine;
		return this->soTienPhat;
	}
}