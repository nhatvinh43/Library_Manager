#include "Library.h"
#include <iostream>
using namespace std;
int Library::countLines(string filename)
{
	fstream fp(filename, ios::in);
	string tempstring;
	int count = 0;
	while (fp.eof() == 0)
	{
		getline(fp, tempstring);
		count++;
	}
	fp.close();
	if (count == 0) return 0;
	return count-1;
}
int Library::countTabs(string filename)
{
	fstream fp(filename, ios::in);
	int count = 0;
	while (fp.eof() == 0)
	{
		char temp = fp.get();
		if (temp == '\n')
		{
			fp.close();
			return count;
		}
		if (temp == '\t')
		{
			count++;
		}
	}
	fp.close();
	return count;
}

void Library::Reader_AddtoFile(Reader& temp)
{
	fstream fp("Reader_Info.txt", ios::app);
	if (fp.is_open() == 0)
	{
		cout << "Khong the mo file!\n";
		system("pause");
		return;
	}
	temp.xuat(fp);
	fp.close();
}
void Library::VBook_AddtoFile(VBook& temp)
{
	fstream fp("VBook_Info.txt", ios::app);
	if (fp.is_open() == 0)
	{
		cout << "Khong the mo file!\n";
		system("pause");
		return;
	}
	temp.xuat(fp);
	
	fp.close();
}
void Library::EBook_AddtoFile(EBook& temp)
{
	fstream fp("EBook_Info.txt", ios::app);
	if (fp.is_open() == 0)
	{
		cout << "Khong the mo file!\n";
		system("pause");
		return;
	}
	temp.xuat(fp);
	fp.close();
}
void Library:: BookTicket_AddtoFile(BookTicket& temp)
{
	fstream fp("BookTicket_Info.txt", ios::app);
	if (fp.is_open() == 0)
	{
		cout << "Khong the mo file!\n";
		system("pause");
		return;
	}
	temp.xuat(fp);
	fp.close();
}

int Library::checkFileReader(const string filename, const string keyword)
{
	list<Reader>dstemp = this->getListReader(filename);
	list<Reader>::iterator it;
	for (it = dstemp.begin(); it != dstemp.end(); it++)
	{
		;
		if ((*it).maDocGia == keyword)
		{
			return 1;
		}
	}
	return 0;
}
int Library::checkFileVBook(const string filename, const string keyword)
{
	list<VBook>dstemp = this->getListVBook(filename);
	list<VBook>::iterator it;
	for (it = dstemp.begin(); it != dstemp.end(); it++)
	{
		;
		if ((*it).maSach == keyword)
		{
			return 1;
		}
	}
	return 0;
}
int Library::checkFileEBook(const string filename, const string keyword)
{
	list<EBook>dstemp = this->getListEBook(filename);
	list<EBook>::iterator it;
	for (it = dstemp.begin(); it != dstemp.end(); it++)
	{
		;
		if ((*it).maSach == keyword)
		{
			return 1;
		}
	}
	return 0;
}

list<Reader> Library::getListReader(string filename)
{
	list <Reader> dstemp;
	fstream fp(filename, ios::in);
	if (fp.is_open() == 0) return dstemp;
	int n = this->countLines(filename);
	fp.seekp(0);
	for (int i = 1; i <= n; i++)
	{
		Reader tempRD;
		char tempchar;
		getline(fp, tempRD.maDocGia, '\t');
		getline(fp, tempRD.hoVaTen, '\t');
		fp >> tempRD.ngaySinh.day;
		fp >> tempchar;
		fp >> tempRD.ngaySinh.month;
		fp >> tempchar;
		fp >> tempRD.ngaySinh.year;
		string tempstring;
		getline(fp, tempstring, '\t');
		getline(fp, tempRD.ngheNghiep, '\t');
		getline(fp, tempRD.diaChi, '\t');
		getline(fp, tempRD.CMND, '\t');
		getline(fp, tempRD.SDT);
		dstemp.push_back(tempRD);
	}
	fp.close();
	return dstemp;
}
list<VBook> Library::getListVBook(string filename)
{
	list <VBook> dstemp;
	fstream fp(filename, ios::in);
	if (fp.is_open() == 0) return dstemp;
	int n = this->countLines(filename);
	fp.seekp(0);
	for (int i = 1; i <= n; i++)
	{
		VBook tempB;
		getline(fp, tempB.maSach, '\t');
		getline(fp, tempB.tenSach, '\t');
		getline(fp, tempB.tacGia, '\t');
		getline(fp, tempB.nhaXuatBan, '\t');
		getline(fp, tempB.giaSach);
		dstemp.push_back(tempB);
	}
	fp.close();
	return dstemp;
}
list<EBook> Library::getListEBook(string filename)
{
	list <EBook> dstemp;
	fstream fp(filename, ios::in);
	if (fp.is_open() == 0) return dstemp;
	int n = this->countLines(filename);
	fp.seekp(0);
	for (int i = 1; i <= n; i++)
	{
		EBook tempB;
		getline(fp, tempB.maSach, '\t');
		getline(fp, tempB.tenSach, '\t');
		getline(fp, tempB.tacGia, '\t');
		getline(fp, tempB.nhaXuatBan, '\t');
		getline(fp, tempB.giaSach,'\t');
		getline(fp, tempB.ISBN);
		dstemp.push_back(tempB);
	}
	fp.close();
	return dstemp;
}
list<BookTicket> Library:: getListBookTicket(string filename)
{
	list <BookTicket> dstemp;
	fstream fp(filename, ios::in);
	if (fp.is_open() == 0) return dstemp;
	int n = this->countLines(filename);
	fp.seekp(0);
	for (int i = 1; i <= n; i++)
	{
		BookTicket bt;
		char tempchar;
		getline(fp, bt.maDocGia, '\t');
		getline(fp, bt.tenSach, '\t');
		getline(fp, bt.loaiSach, '\t');
		fp >> bt.ngayMuon.day;
		fp >> tempchar;
		fp >> bt.ngayMuon.month;
		fp >> tempchar;
		fp >> bt.ngayMuon.year;
		string tempstring;
		getline(fp, tempstring, '\t');
		fp >> bt.ngayTra.day;
		fp >> tempchar;
		fp >> bt.ngayTra.month;
		fp >> tempchar;
		fp >> bt.ngayTra.year;
		getline(fp, tempstring, '\t');
		getline(fp, tempstring, '\t');
		if (tempstring == "Chua tra")
		{
			bt.trangThai = 0;
		}
		else bt.trangThai = 1;
		fp >> bt.soNgayLo;
		getline(fp, tempstring);
		dstemp.push_back(bt);
	}
	fp.close();
	return dstemp;
}

void Library::sortReaderList()
{
	list<Reader> dstemp = this->getListReader("Reader_Info.txt");
	dstemp.sort();
	remove("Reader_Info.txt");
	list<Reader>::iterator it;
	for (it = dstemp.begin(); it != dstemp.end(); it++)
	{
		this->Reader_AddtoFile(*it);
	}
}
void Library::sortVBookList()
{
	list<VBook> dstemp = this->getListVBook("VBook_Info.txt");
	list<VBook>::iterator tempit;
	dstemp.sort();
	remove("VBook_Info.txt");
	list<VBook>::iterator it;
	for (it = dstemp.begin(); it != dstemp.end(); it++)
	{
		this->VBook_AddtoFile(*it);
	}
}
void Library::sortEBookList()
{
	list<EBook> dstemp = this->getListEBook("EBook_Info.txt");
	dstemp.sort();
	remove("EBook_Info.txt");
	list<EBook>::iterator it;
	for (it = dstemp.begin(); it != dstemp.end(); it++)
	{
		this->EBook_AddtoFile(*it);
	}
}
void Library::sortBookTicketList()
{
	list<BookTicket> dstemp = this->getListBookTicket("BookTicket_Info.txt");
	dstemp.sort();
	remove("BookTicket_Info.txt");
	list<BookTicket>::iterator it;
	for (it = dstemp.begin(); it != dstemp.end(); it++)
	{
		this->BookTicket_AddtoFile(*it);
	}
}

void Library::Reader_Add()
{
	system("cls");
	cout << "Nhap so doc gia can them vao thu vien: ";
	int n;
	cin >> n;
	fflush(stdin);
	for (int i = 0; i < n; i++)
	{
		list<Reader> dstemp = this->getListReader("Reader_Info.txt");
		system("cls");
		Reader DocGia;
		cout << "CMND: ";
		getline(cin, DocGia.CMND);
		cout << "Ma doc gia: ";
		getline(cin, DocGia.maDocGia);
		int duplicate = 0;
		list<Reader>::iterator it;
		for (it = dstemp.begin(); it != dstemp.end(); it++)
		{
			if ((*it).CMND == DocGia.CMND || (*it).maDocGia == DocGia.maDocGia)
			{
				duplicate = 1;
			}
		}
		if (duplicate == 1)
		{
			cout << "Doc gia da ton tai!\n";
			i--;
			system("pause");
			continue;
		}
		cout << "Ten doc gia: ";
		getline(cin, DocGia.hoVaTen);
		fflush(stdin);
		cout << "Ngay sinh: ";
		cin >> DocGia.ngaySinh.day;
		cin >> DocGia.ngaySinh.month;
		cin >> DocGia.ngaySinh.year;
		fflush(stdin);
		cout << "Nghe nghiep: ";
		getline(cin, DocGia.ngheNghiep);
		cout << "Dia chi: ";
		getline(cin, DocGia.diaChi);
		cout << "SDT: ";
		getline(cin, DocGia.SDT);
	
		this->Reader_AddtoFile(DocGia);
		this->sortReaderList();
	}
}
void Library::Reader_Delete()
{
	system("cls");
	cout << "Nhap ma doc gia can xoa: ";
	string mdg;
	cin >> mdg;
	int res = this->checkFileReader("Reader_Info.txt", mdg);
	if (res == 0)
	{
		cout << "Khong tim thay doc gia trong thu vien!\n";
		system("pause");
		return;
	}
	else
	{
		list<Reader>dstemp = this->getListReader("Reader_Info.txt");
		list<Reader>::iterator it;
		for (it = dstemp.begin(); it != dstemp.end(); it++)
		{
			if (it->maDocGia == mdg)
			{
				it=dstemp.erase(it);
				if (it == dstemp.end())
				{
					break;
				}
			}
		}
		remove("Reader_Info.txt");
		dstemp.sort();
		for (it = dstemp.begin(); it != dstemp.end(); it++)
		{
			this->Reader_AddtoFile(*it);
		}
	}
	cout << "Xoa thanh cong!\n";
	system("pause");
}
void Library::Reader_Update()
{
	system("cls");
	cout << "Nhap ma doc gia can cap nhat: ";
	string mdg;
	cin >> mdg;
	fflush(stdin);
	list<Reader>::iterator it;
	list<Reader>dstemp = this->getListReader("Reader_Info.txt");
	for (it = dstemp.begin(); it != dstemp.end(); it++)
	{
		if ((*it).maDocGia == mdg)
		{
			dstemp.remove(*it);
			int duplicate = 0;
			system("cls");
			Reader DocGia;
			cout << "CMND: ";
			getline(cin, DocGia.CMND);
			list<Reader>::iterator it;
			for (it = dstemp.begin(); it != dstemp.end(); it++)
			{
				if ((*it).CMND == DocGia.CMND)
				{
					duplicate = 1;
					break;
				}
			}
			if (duplicate == 1)
			{
				cout << "Doc gia da ton tai, cap nhat that bai!\n";
				system("pause");
				return;
			}
			cout << "Ma doc gia: ";
			getline(cin, DocGia.maDocGia);
			for (it = dstemp.begin(); it != dstemp.end(); it++)
			{
				if ((*it).maDocGia == DocGia.maDocGia)
				{
					duplicate = 1;
					break;
				}
			}
			if (duplicate == 1)
			{
				cout << "Doc gia da ton tai, cap nhat that bai!\n";
				system("pause");
				return;
			}
			cout << "Ten doc gia: ";
			getline(cin, DocGia.hoVaTen);
			fflush(stdin);
			cout << "Ngay sinh: ";
			cin >> DocGia.ngaySinh.day;
			cin >> DocGia.ngaySinh.month;
			cin >> DocGia.ngaySinh.year;
			fflush(stdin);
			cout << "Nghe nghiep: ";
			getline(cin, DocGia.ngheNghiep);
			cout << "Dia chi: ";
			getline(cin, DocGia.diaChi);
			cout << "SDT: ";
			getline(cin, DocGia.SDT);
			cout << "Cap nhat thanh cong!\n";
			remove("Reader_Info.txt");
			dstemp.push_back(DocGia);
			dstemp.sort();
			for (it = dstemp.begin(); it != dstemp.end(); it++)
			{
				this->Reader_AddtoFile(*it);
			}
			system("pause");
			return;
		}
	}
	cout << "Khong tim thay doc gia trong thu vien!\n";
	system("pause");
}
void Library:: Reader_Search()
{
	system("cls");
	cout << "Nhap ma doc gia can tim kiem: ";
	string mdg;
	cin >> mdg;
	list<Reader>::iterator it;
	list <Reader> dstemp = this->getListReader("Reader_Info.txt");
	for (it = dstemp.begin(); it != dstemp.end(); it++)
	{
		if (mdg == (*it).maDocGia)
		{
			cout << "MDG\tTen DG\tNgay sinh\tNghe nghiep\tDia chi\tCMND\tSDT\n";
			(*it).xuat(cout);
			system("pause");
			return;
		}
	}
	cout << "Khong tim thay doc gia!\n";
	system("pause");
}

void Library::VBook_Add()
{

	system("cls");
	cout << "Nhap so sach tieng viet can them vao thu vien: ";
	int n;
	cin >> n;
	fflush(stdin);
	for (int i = 0; i < n; i++)
	{
		list<VBook> dstemp = this->getListVBook("VBook_Info.txt");
		system("cls");
		VBook sachViet;
		cout << "Ma sach: ";
		getline(cin, sachViet.maSach);

		int duplicate = 0;
		list<VBook>::iterator it;
		for (it = dstemp.begin(); it != dstemp.end(); it++)
		{
			if ((*it).maSach == sachViet.maSach)
			{
				duplicate = 1;
			}
		}
		if (duplicate == 1)
		{
			cout << "Sach da ton tai!\n";
			i--;
			system("pause");
			continue;
		}
		cout << "Ten sach: ";
		getline(cin, sachViet.tenSach);
		cout << "Tac gia: ";
		getline(cin, sachViet.tacGia);
		cout << "Nha xuat ban: ";
		getline(cin, sachViet.nhaXuatBan);
		cout << "Gia sach: ";
		getline(cin, sachViet.giaSach);
		dstemp.push_back(sachViet);
		this->VBook_AddtoFile(sachViet);
		this->sortVBookList();
	}
}
void Library::VBook_Delete()
{
	system("cls");
	cout << "Nhap ma sach can xoa: ";
	string ms;
	cin >> ms;
	int res = this->checkFileVBook("VBook_Info.txt", ms);
	if (res == 0)
	{
		cout << "Khong tim thay sach trong thu vien!\n";
		system("pause");
		return;
	}
	else
	{
		list<VBook>dstemp = this->getListVBook("VBook_Info.txt");
		list<VBook>::iterator it;
		for (it = dstemp.begin(); it != dstemp.end(); it++)
		{
			if (it->maSach == ms)
			{
				it = dstemp.erase(it);
				if (it == dstemp.end())
				{
					break;
				}
			}
		}
		remove("VBook_Info.txt");
		dstemp.sort();
		for (it = dstemp.begin(); it != dstemp.end(); it++)
		{
			this->VBook_AddtoFile(*it);
		}
	}
	cout << "Xoa thanh cong!\n";
	system("pause");
}
void Library::VBook_Update()
{
	system("cls");
	cout << "Nhap ma sach can cap nhat: ";
	string ms;
	cin >> ms;
	fflush(stdin);
	list<VBook>::iterator it;
	list<VBook>dstemp = this->getListVBook("VBook_Info.txt");
	for (it = dstemp.begin(); it != dstemp.end(); it++)
	{
		if ((*it).maSach == ms)
		{
			dstemp.remove(*it);
			int duplicate = 0;
			system("cls");
			VBook sachViet;
			cout << "Ma sach: ";
			getline(cin, sachViet.maSach);
			list<VBook>::iterator it;
			for (it = dstemp.begin(); it != dstemp.end(); it++)
			{
				if ((*it).maSach == sachViet.maSach)
				{
					duplicate = 1;
					break;
				}
			}
			if (duplicate == 1)
			{
				cout << "Sach da ton tai, cap nhat that bai!\n";
				system("pause");
				return;
			}
			cout << "Ten sach: ";
			getline(cin, sachViet.tenSach);
			fflush(stdin);
			cout << "Tac gia: ";
			getline(cin, sachViet.tacGia);
			cout << "Nha xuat ban: ";
			getline(cin, sachViet.nhaXuatBan);
			cout << "Gia sach: ";
			getline(cin, sachViet.giaSach);
			cout << "Cap nhat thanh cong!\n";
			remove("VBook_Info.txt");
			dstemp.push_back(sachViet);
			dstemp.sort();
			for (it = dstemp.begin(); it != dstemp.end(); it++)
			{
				this->VBook_AddtoFile(*it);
			}
			system("pause");
			return;
		}
	}
	cout << "Khong tim thay doc gia trong thu vien!\n";
	system("pause");
}
void Library::VBook_Search()
{
	system("cls");
	cout << "Nhap ma sach can tim kiem: ";
	string ms;
	cin >> ms;
	list<VBook>::iterator it;
	list <VBook> dstemp = this->getListVBook("VBook_Info.txt");
	for (it = dstemp.begin(); it != dstemp.end(); it++)
	{
		if (ms == (*it).maSach)
		{
			cout << "MS\tTen sach\tTac gia\tNXB\tGia\n";
			(*it).xuat(cout);
			system("pause");
			return;
		}
	}
	cout << "Khong tim thay sach!\n";
	system("pause");
}

void Library::EBook_Add()
{
	system("cls");
	cout << "Nhap so sach ngoai van can them vao thu vien: ";
	int n;
	cin >> n;
	fflush(stdin);
	for (int i = 0; i < n; i++)
	{
		list<EBook> dstemp = this->getListEBook("EBook_Info.txt");
		system("cls");
		EBook sachNgoai;
		cout << "Ma sach: ";
		getline(cin, sachNgoai.maSach);

		int duplicate = 0;
		list<EBook>::iterator it;
		for (it = dstemp.begin(); it != dstemp.end(); it++)
		{
			if ((*it).maSach == sachNgoai.maSach)
			{
				duplicate = 1;
			}
		}
		if (duplicate == 1)
		{
			cout << "Sach da ton tai!\n";
			i--;
			system("pause");
			continue;
		}

		cout << "Ten sach: ";
		getline(cin, sachNgoai.tenSach);
		cout << "Tac gia: ";
		getline(cin, sachNgoai.tacGia);
		cout << "Nha xuat ban: ";
		getline(cin, sachNgoai.nhaXuatBan);
		cout << "Gia sach: ";
		getline(cin, sachNgoai.giaSach);
		cout << "ISBN: ";
		getline(cin, sachNgoai.ISBN);

		dstemp.push_back(sachNgoai);
		this->EBook_AddtoFile(sachNgoai);
		this->sortEBookList();
	}
}
void Library::EBook_Delete()
{
	system("cls");
	cout << "Nhap ma sach can xoa: ";
	string ms;
	cin >> ms;
	int res = this->checkFileEBook("EBook_Info.txt", ms);
	if (res == 0)
	{
		cout << "Khong tim thay sach trong thu vien!\n";
		system("pause");
		return;
	}
	else
	{
		list<EBook>dstemp = this->getListEBook("EBook_Info.txt");
		list<EBook>::iterator it;
		for (it = dstemp.begin(); it != dstemp.end(); it++)
		{
			if (it->maSach == ms)
			{
				it = dstemp.erase(it);
				if (it == dstemp.end())
				{
					break;
				}
			}
		}
		remove("EBook_Info.txt");
		dstemp.sort();
		for (it = dstemp.begin(); it != dstemp.end(); it++)
		{
			this->EBook_AddtoFile(*it);
		}
	}
	cout << "Xoa thanh cong!\n";
	system("pause");
}
void Library::EBook_Update()
{
	system("cls");
	cout << "Nhap ma sach can cap nhat: ";
	string ms;
	cin >> ms;
	fflush(stdin);
	list<EBook>::iterator it;
	list<EBook>dstemp = this->getListEBook("EBook_Info.txt");
	for (it = dstemp.begin(); it != dstemp.end(); it++)
	{
		if ((*it).maSach == ms)
		{
			dstemp.remove(*it);
			int duplicate = 0;
			system("cls");
			EBook sachNgoai;
			cout << "Ma sach: ";
			getline(cin, sachNgoai.maSach);
			list<EBook>::iterator it;
			for (it = dstemp.begin(); it != dstemp.end(); it++)
			{
				if ((*it).maSach == sachNgoai.maSach)
				{
					duplicate = 1;
					break;
				}
			}
			if (duplicate == 1)
			{
				cout << "Sach da ton tai, cap nhat that bai!\n";
				system("pause");
				return;
			}
			cout << "Ten sach: ";
			getline(cin, sachNgoai.tenSach);
			fflush(stdin);
			cout << "Tac gia: ";
			getline(cin, sachNgoai.tacGia);
			cout << "Nha xuat ban: ";
			getline(cin, sachNgoai.nhaXuatBan);
			cout << "Gia sach: ";
			getline(cin, sachNgoai.giaSach);
			cout << "ISBN: ";
			getline(cin, sachNgoai.ISBN);
			cout << "Cap nhat thanh cong!\n";
			remove("EBook_Info.txt");
			dstemp.push_back(sachNgoai);
			dstemp.sort();
			for (it = dstemp.begin(); it != dstemp.end(); it++)
			{
				this->EBook_AddtoFile(*it);
			}
			system("pause");
			return;
		}
	}
	cout << "Khong tim thay doc gia trong thu vien!\n";
	system("pause");
}
void Library::EBook_Search()
{
	system("cls");
	cout << "Nhap ma sach can tim kiem: ";
	string ms;
	cin >> ms;
	list<EBook>::iterator it;
	list <EBook> dstemp = this->getListEBook("EBook_Info.txt");
	for (it = dstemp.begin(); it != dstemp.end(); it++)
	{
		if (ms == (*it).maSach)
		{
			cout << "MS\tTen sach\tTac gia\tNXB\tGia\tISBN\n";
			(*it).xuat(cout);
			system("pause");
			return;
		}
	}
	cout << "Khong tim thay sach!\n";
	system("pause");
}

void Library::BookTicket_Add()
{
	system("cls");
	int n;
	cout << "Nhap so phieu can nhap: ";
	cin >> n;
	fflush(stdin);
	for (int i = 0; i < n; i++)
	{
		system("cls");
		cout << "Nhap ma so doc gia: ";
		BookTicket bt;
		cin >> bt.maDocGia;
		fflush(stdin);
		int check = this->checkFileReader("Reader_Info.txt", bt.maDocGia);
		if (check == 0)
		{
			cout << "Doc gia khong ton tai trong thu vien, voi long nhap doc gia truoc!\n";
			system("pause");
			return;
		}
		cout << "Nhap ten sach muon: ";
		getline(cin, bt.tenSach);
		cout << "Nhap loai sach muon: ";
		getline(cin, bt.loaiSach);
		fflush(stdin);
		cout << "Nhap ngay muon: ";
		cin >> bt.ngayMuon.day;
		cin >> bt.ngayMuon.month;
		cin >> bt.ngayMuon.year;

		tm t1;
		fill((char*)&t1, (char*)&t1 + sizeof(t1), 0);
		t1.tm_year = bt.ngayMuon.year - 1900;
		t1.tm_mon = bt.ngayMuon.month - 1;
		t1.tm_mday = bt.ngayMuon.day;
		time_t delta = mktime(&t1) + (60 * 60 * 24 * bt.BorrowLimit);
		tm t2 = *localtime(&delta);
		bt.ngayTra.day = t2.tm_mday;
		bt.ngayTra.month = t2.tm_mon+1;
		bt.ngayTra.year = t2.tm_year+1900;

		bt.trangThai = 0;
		bt.soNgayLo = 0;
		this->BookTicket_AddtoFile(bt);
		this->sortBookTicketList();
	}
}
void Library::BookTicket_Delete()
{
	system("cls");
	cout << "Nhap ma doc gia tra sach: ";
	string mdg;
	getline(cin, mdg);
	string tensach;
	cout << "Nhap ten sach muon: ";
	getline(cin, tensach);
	list<BookTicket>dstemp = this->getListBookTicket("BookTicket_Info.txt");
	list<BookTicket>::iterator it;
	int check = 0;
	for (it = dstemp.begin(); it != dstemp.end(); it++)
	{
		if ((*it).maDocGia == mdg && (*it).tenSach == tensach)
		{
			check = 1;
			it->trangThai = 1;
			it->tinhSoNgayLo();	
		}
	}
	if (check == 0)
	{
		cout << "Khong ton tai the muon theo thong tin da nhap!\n";
		system("pause");
		return;
	}
	remove("BookTicket_Info.txt");
	for (it = dstemp.begin(); it!= dstemp.end(); it++)
	{
		this->BookTicket_AddtoFile(*it);
	}
	cout << "Tra sach thanh cong!\n";
	system("pause");
}
void Library::BookTicket_AutoUpdate()
{
	list<BookTicket> dstemp = this->getListBookTicket("BookTicket_Info.txt");
	remove("BookTicket_Info.txt");
	list<BookTicket>::iterator it;
	for (it = dstemp.begin(); it != dstemp.end(); it++)
	{
		(*it).tinhSoNgayLo();
		(*it).tinhSoTienPhat();
		this->BookTicket_AddtoFile(*it);
	}
}
void Library:: BookTicket_FineList()
{
	system("cls");
	//Cap nhat so ngay muon lo tinh den ngay hom nay
	this->BookTicket_AutoUpdate();

	//Rut ra danh sach nhung phieu muon sach bi phat tien
	list<BookTicket> dstemp = this->getListBookTicket("BookTicket_Info.txt");
	list<BookTicket>::iterator it;

	list<BookTicket> dsFine;
	for (it = dstemp.begin(); it != dstemp.end(); it++)
	{
		(*it).tinhSoTienPhat();
		if ((*it).soTienPhat > 0)
		{
			dsFine.push_back(*it);
		}
	}

	//Rut ra danh sach nhung doc gia co ten trong danh sach phieu muon bi phat tien
	list<Reader> dsreader = this->getListReader("Reader_Info.txt");
	list<Reader> dsreader_fine;
	list<Reader>::iterator it2;
	for (it = dsFine.begin(); it != dsFine.end(); it++)
	{
		for (it2 = dsreader.begin(); it2 != dsreader.end(); it2++)
		{
			if ((*it).maDocGia == (*it2).maDocGia)
			{
				dsreader_fine.push_back(*it2);
			}
		}
	}
	dsreader_fine.sort();
	dsreader_fine.unique();
	
	//Phan chia phieu muon sach bi phat tien theo dung doc gia, moi doc gia co 1 danh sach nhung the bi phat tien
	for (it = dsFine.begin(); it != dsFine.end(); it++)
	{
		for (it2 = dsreader_fine.begin(); it2 != dsreader_fine.end(); it2++)
		{
			if ((*it).maDocGia == (*it2).maDocGia)
			{
				(*it2).danhSachMuonLo.push_back(*it);
			}
		}
	}
	

	//Xuat cac the muon sach bi phat theo ten doc gia, kem theo so ngay muon lo va so tien phat.
	fstream fp("FineList.txt", ios::out);
	for (it2 = dsreader_fine.begin(); it2 != dsreader_fine.end(); it2++)
	{
		int n = (*it2).tinhTienLo(fp);
	}
	fp.close();
	cout << "Da xuat danh sach!\n";
	system("pause");
}
void Library::BookTicket_FineUpdate()
{
	system("cls");
	cout << "Nhap ma doc gia tra sach: ";
	string mdg;
	getline(cin, mdg);
	string tensach;
	cout << "Nhap ten sach muon: ";
	getline(cin, tensach);
	list<BookTicket>dstemp = this->getListBookTicket("BookTicket_Info.txt");
	list<BookTicket>::iterator it;
	int check = 0;
	for (it = dstemp.begin(); it != dstemp.end(); it++)
	{
		if ((*it).maDocGia == mdg && (*it).tenSach == tensach)
		{
			check = 1;
			it->trangThai = 1;
			it->soNgayLo=0;
		}
	}
	if (check == 0)
	{
		cout << "Khong ton tai the muon theo thong tin da nhap!\n";
		system("pause");
		return;
	}
	remove("BookTicket_Info.txt");
	for (it = dstemp.begin(); it != dstemp.end(); it++)
	{
		this->BookTicket_AddtoFile(*it);
	}
	cout << "Cap nhat dong phat thanh cong!\n";
	system("pause");
	
}
void Library::Book_MergeFile()
{
	fstream fp("Book_Info.txt", ios::out);
	list<Book*> dstemp;
	list<VBook> dsVBook = this->getListVBook("VBook_Info.txt");
	list<EBook> dsEBook = this->getListEBook("EBook_Info.txt");
	list<VBook>::iterator VBook_IT;
	list<EBook>::iterator EBook_IT;
	for (VBook_IT = dsVBook.begin(); VBook_IT != dsVBook.end(); VBook_IT++)
	{
		EBook temp = (*VBook_IT).toEBook();
		temp.xuat(fp);
	}
	for (EBook_IT = dsEBook.begin(); EBook_IT != dsEBook.end(); EBook_IT++)
	{
		(*EBook_IT).xuat(fp);
	}
	fp.close();
	int n = this->countLines("Book_Info.txt");
	int check = 0;
	dsEBook = this->getListEBook("Book_Info.txt");
	remove("Book_Info.txt");
	fp.open("Book_Info.txt", ios::app);
	dsEBook.sort();
	for (EBook_IT = dsEBook.begin(); EBook_IT != dsEBook.end(); EBook_IT++)
	{
		(*EBook_IT).xuat(fp);
	}
}