#include <iostream>
#include <ctime>
#include "Library.h"
#include <string>
using namespace std;
void menu()
{
	while (1)
	{
		system("cls");
		Library thuVien;
		int n = 0;
		cout << "-------------QUAN LY THU VIEN------------------\n";
		cout << "1./ Nhap sach tieng Viet vao thu vien.\n";
		cout << "2./ Nhap sach ngoai van vao thu vien.\n";
		cout << "3./ Xoa sach tieng Viet khoi thu vien.\n";
		cout << "4./ Xoa sach ngoai van khoi thu vien.\n";
		cout << "5./ Cap nhat thong tin sach tieng Viet.\n";
		cout << "6./ Cap nhat thong tin sach ngoai van.\n";
		cout << "7./ Tim kiem thong tin sach tieng Viet.\n";
		cout << "8./ Tim kiem thong tin sach ngoai van.\n";
		cout << "9./ Nhap thong tin doc gia.\n";
		cout << "10./ Xoa thong tin doc gia.\n";
		cout << "11./ Cap nhat thong tin doc gia.\n";
		cout << "12./ Tim kiem thong tin doc gia.\n";
		cout << "13./ Muon sach (tao phieu muon sach).\n";
		cout << "14./ Tra sach (xoa phieu muon sach).\n";
		cout << "15./ Liet ke danh sach muon qua han.\n";
		cout << "16./ Cap nhat doc gia da dong phat.\n";
		cout << "17./ Thoat chuong trinh.\n";
		cout << "--------------------------------------------\n";
		do
		{
			cout << "Vui long nhap tuy chon: ";
			cin >> n;
			fflush(stdin);
		} while (n < 0 || n > 17);
		switch (n)
		{
		case 1:
		{
				  cout << "--------Nhap sach tieng Viet----------\n";
				  thuVien.VBook_Add();
				  thuVien.Book_MergeFile();
				  continue;
		}
		case 2:
		{
				  cout << "--------Nhap sach ngoai van----------\n";
				  thuVien.EBook_Add();
				  thuVien.Book_MergeFile();
				  continue;
		}
		case 3:
		{
				  cout << "--------Xoa sach tieng Viet----------\n";
				  thuVien.VBook_Delete();
				  thuVien.Book_MergeFile();
				  continue;
		}
		case 4:
		{
				  cout << "--------Xoa sach ngoai van----------\n";
				  thuVien.EBook_Delete();
				  thuVien.Book_MergeFile();
				  continue;
		}
		case 5:
		{
				  cout << "--------Cap nhat sach tieng Viet----------\n";
				  thuVien.VBook_Update();
				  thuVien.Book_MergeFile();
				  continue;
		}
		case 6:
		{
				  cout << "--------Cap nhat sach ngoai van----------\n";
				  thuVien.EBook_Update();
				  thuVien.Book_MergeFile();
				  continue;
		}
		case 7:
		{
				  cout << "--------Tim kiem sach tieng Viet----------\n";
				  thuVien.VBook_Search();
				  continue;
		}
		case 8:
		{
				  cout << "--------Tim kiem sach ngoai van----------\n";
				  thuVien.EBook_Search();
				  continue;
		}
		case 9:
		{
				  cout << "--------Nhap thong tin doc gia----------\n";
				  thuVien.Reader_Add();
				  continue;
		}
		case 10:
		{
				   cout << "--------Xoa thong tin doc gia----------\n";
				   thuVien.Reader_Delete();
				   continue;
		}
		case 11:
		{
				   cout << "--------Cap nhat thong tin doc gia----------\n";
				   thuVien.Reader_Update();
				   continue;
		}
		case 12:
		{
				   cout << "--------Tim thong tin doc gia----------\n";
				   thuVien.Reader_Search();
				   continue;
		}
		case 13:
		{
				   cout << "--------Muon sach( lap the muon sach----------\n";
				   thuVien.BookTicket_Add();
				   continue;
		}
		case 14:
		{
				   cout << "--------Tra sach( xoa the muon sach----------\n";
				   thuVien.BookTicket_Delete();
				   continue;
		}
		case 15:
		{
				   cout << "--------Lap danh sach muon qua han----------\n";
				   thuVien.BookTicket_FineList();
				   continue;
		}
		case 16:
		{
				   cout << "--------Cap nhat doc gia da dong phat----------\n";
				   thuVien.BookTicket_FineUpdate();
				   continue;
		}
		case 17: return;
		}
	}
}
void main()
{
	menu();	
}