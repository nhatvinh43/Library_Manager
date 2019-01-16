#ifndef _BOOK_TICKET_H_
#define _BOOK_TICKET_H_
#include "Date.h"
#include <string>
using namespace std;

class BookTicket
{
private:
	string maDocGia;
	string tenSach;
	string loaiSach;
	Date ngayMuon;
	Date ngayTra;
	int trangThai;
	int soNgayLo;
	int soTienPhat;
	const static int VFine = 10000;
	const static int EFine = 20000;
	const static int BorrowLimit = 7;
	friend class Library;
	friend class Reader;
public:
	int tinhSoNgayLo();
	int tinhSoTienPhat();
	friend int rdn(Date);
	void xuat(ostream&);
	bool operator ==(const BookTicket& temp)
	{
		return tenSach == temp.tenSach;
	}
	bool operator !=(const BookTicket& temp)
	{
		return !operator==(temp);
	}
	bool operator < (const BookTicket& temp)
	{
		return rdn((*this).ngayMuon) > rdn((temp).ngayMuon);
	}
	bool is_leap_year(int year)
	{
		return (!(year & 3) && ((year % 25) || !(year & 15)));
	}
};
#endif
