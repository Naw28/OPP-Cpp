#include <iostream>
#include <vector>
#include <ctime>
#include <cctype>
#include <fstream>

using namespace std;

class LoiLogin : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Tai khoan hoac mat khau khong chinh xac!!!";
    }
};
class LoiTaoTaiKhoan : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Tai khoan da ton tai!!!";
    }
};
class LoiQuaGioiHanMuon : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Ban da muon qua gioi han cho phep!!!";
    }
};
class LoiKhongTonTaiSach : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Khong ton tai sach!!!";
    }
};
class LoiKhongDuSach : public exception
{
public:
    const char *what() const noexcept override
    {
        return "So luong sach khong du!!!";
    }
};
class LoiFile : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Loi khong mo duoc file!!!";
    }
};
class Thoat : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Ket thuc chuong trinh!!!";
    }
};

class Sach
{
private:
    string m_maSach;
    string m_tenSach;
    string m_tacGia;
    string m_theLoai;
    int m_soLuong;

public:
    Sach(const string &ma, const string &tensach, const string &tacgia, const string &theloai, int soluong)
        : m_maSach(ma), m_tenSach(tensach), m_tacGia(tacgia), m_theLoai(theloai), m_soLuong(soluong) {}

    void setMaSach(const string &ma) { m_maSach = ma; }
    void setTenSach(const string &ten) { m_tenSach = ten; }
    void setTacGia(const string &tacgia) { m_tacGia = tacgia; }
    void setTheLoai(const string &theloai) { m_theLoai = theloai; }
    void setSoLuong(int soluong) { m_soLuong = soluong; }

    string getMaSach() const { return m_maSach; }
    string getTenSach() const { return m_tenSach; }
    string getTacGia() const { return m_tacGia; }
    string getTheLoai() const { return m_theLoai; }
    int getSoLuong() const { return m_soLuong; }

    bool KiemTraTrungLap(const string &ktra) const
    {
        if (m_maSach == ktra || m_tenSach == ktra)
        {
            return true;
        }
        return false;
    }

    void InThongTin() const
    {
        cout << "Ma sach: " << m_maSach << endl;
        cout << "Ten sach: " << m_tenSach << endl;
        cout << "Tac gia: " << m_tacGia << endl;
        cout << "The loai: " << m_theLoai << endl;
        cout << "So luong: " << m_soLuong << endl;
    }
};
class NguoiMuon
{
private:
    static int m_id;
    string m_maNguoiMuon;
    string m_tenNguoiMuon;
    string m_ngayMuon;
    string m_sachDaMuon;
    int m_gioiHanMuon = 3;
    string m_taikhoan;

public:
    NguoiMuon(const string &tenNguoiMuon, const string &taikhoan) : m_maNguoiMuon("A" + to_string(m_id++)), m_tenNguoiMuon(tenNguoiMuon), m_taikhoan(taikhoan) {}
    NguoiMuon(const string &tenNguoiMuon, const string &ngayMuon, const string &sachDaMuon, const string &taikhoan)
        : m_maNguoiMuon("A" + to_string(m_id++)), m_tenNguoiMuon(tenNguoiMuon), m_ngayMuon(ngayMuon), m_sachDaMuon(sachDaMuon), m_taikhoan(taikhoan) {}
    NguoiMuon(const NguoiMuon &other)
        : m_maNguoiMuon("A" + to_string(m_id++)), m_tenNguoiMuon(other.getTenNguoiMuon()), m_ngayMuon(other.getNgayMuon()), m_sachDaMuon(other.getSachDaMuon()) {}

    void setTenNguoiMuon(const string &tenNguoiMuon) { m_tenNguoiMuon = tenNguoiMuon; }
    void setNgayMuon(const string &ngayMuon) { m_ngayMuon = ngayMuon; }
    void setSachDaMuon(const string &sachDaMuon) { m_sachDaMuon = sachDaMuon; }
    void setTaiKhoan(const string &taikhoan) { m_taikhoan = taikhoan; }
    void setGioiHanMuon(int gh) { m_gioiHanMuon = gh; }

    string getMaNguoiMuon() const { return m_maNguoiMuon; }
    string getTenNguoiMuon() const { return m_tenNguoiMuon; }
    string getNgayMuon() const { return m_ngayMuon; }
    string getSachDaMuon() const { return m_sachDaMuon; }
    int getGioHanMuon() { return m_gioiHanMuon; }
    string getTaiKhoan() { return m_taikhoan; }

    bool KiemTraTrungLap(const string &ktra) const
    {
        if (m_maNguoiMuon == ktra || m_tenNguoiMuon == ktra)
        {
            return true;
        }
        return false;
    }

    void InThongTin() const
    {
        cout << "Ma nguoi muon: " << m_maNguoiMuon << endl;
        cout << "Ten nguoi muon: " << m_tenNguoiMuon << endl;
        cout << "Ngay muon: " << m_ngayMuon << endl;
        cout << "Sach da muon: " << m_sachDaMuon << endl;
    }
};
class QuanLyMuonTra
{
private:
    string m_maNguoiMuon;
    string m_maSach;
    int m_soLuong;
    int m_thoiHan;
    string m_thoiDiemMuon;
    string m_thoiDiemTra;
    string m_trangThai;

public:
    QuanLyMuonTra(const string &manguoi, const string &masach, int soluong)
        : m_maNguoiMuon(manguoi), m_maSach(masach), m_soLuong(soluong)
    {
        time_t now = time(NULL);
        tm *local = localtime(&now);
        char time[20];
        strftime(time, 20, "%D-%X", local);
        m_thoiHan = 15;
        m_thoiDiemMuon = time;
        m_thoiDiemTra = "Chua tra";
        m_trangThai = "Da muon";
    }

    void traSach()
    {
        time_t now = time(NULL);
        tm *local = localtime(&now);
        char time[20];
        strftime(time, 20, "%D-%X", local);
        m_thoiHan = 0;
        m_thoiDiemTra = time;
        m_trangThai = "Da tra";
    }
    string getMaNguoiMuon() { return m_maNguoiMuon; }
    string getMaSach() { return m_maSach; }
    int getSoluong() { return m_soLuong; }
    int getThoiHan() { return m_thoiHan; }
    string getThoiDiemMuon() { return m_thoiDiemMuon; }
    string getThoiDiemTra() { return m_thoiDiemTra; }
    string getTrangThai() { return m_trangThai; }
};
class TaiKhoan
{
private:
    string m_username;
    string m_password;

public:
    TaiKhoan(const string &user, const string &pass)
        : m_username(user), m_password(pass) {}

    string getUsername() const { return m_username; }
    string getPassword() const { return m_password; }

    bool KiemTraTrungLap(const string &user) const
    {
        if (m_username == user)
        {
            return true;
        }
        return false;
    }
};

template <typename T>
class QuanLyCapNhat
{
private:
    vector<T> items;

public:
    void Them(const T &item)
    {
        items.push_back(item);
    }

    void Xoa(int index)
    {
        if (index < 0 || index >= items.size())
        {
            throw out_of_range("Chi so khong hop le!");
        }

        items.erase(items.begin() + index);
    }

    vector<T> TimKiem(const string &tim)
    {
        vector<T> result;
        for (const auto &item : items)
        {
            if (item->KiemTraTrungLap(tim))
            {
                result.push_back(item);
            }
        }
        return result;
    }

    vector<T> getALL() const
    {
        return items;
    }
};

QuanLyCapNhat<TaiKhoan *> taikhoan;
QuanLyCapNhat<Sach *> sach;
QuanLyCapNhat<NguoiMuon *> nguoimuon;
QuanLyCapNhat<QuanLyMuonTra *> muontra;

void DangKy(QuanLyCapNhat<TaiKhoan *> &taikhoan);
void DangNhap(QuanLyCapNhat<TaiKhoan *> &taikhoan);
void DangXuat(QuanLyCapNhat<TaiKhoan *> &taikhoan);
void MainMenu();
void MenuThuThu();
void MenuNguoiDung(const string &username);
void ThemSach();
void XoaSach();
void TimSach();
void CapNhatSach();
void HienTatCaSach();
void TongSoSach();

void MuonSach(const string &username);

int NguoiMuon::m_id = 0;

void MainMenu()
{
    int choice;
    cout << "\n----- THU VIEN -----\n";
    cout << "1. Dang nhap\n";
    cout << "2. Dang ky\n";
    cout << "0. Thoat\n";
    cout << "Nhap lua chon: ";
    cin >> choice;
    cin.ignore();

    while (true)
    {
        switch (choice)
        {
        case 1:
            DangNhap(taikhoan);
            return;
        case 2:
            DangKy(taikhoan);
            return;
        case 0:
            throw Thoat();

        default:
            throw invalid_argument("Lua chon khong hop le!!!");
        }
    }
}

void DangKy(QuanLyCapNhat<TaiKhoan *> &taikhoan)
{
    cout << "\n------- Tao tai khoan -------\n";
    string hoten;
    string username, password;
    cout << "Nhap ho ten cua ban: ";
    getline(cin, hoten);
    cout << "Nhap username: ";
    cin >> username;
    cout << "Nhap password: ";
    cin >> password;

    for (const auto &acc : taikhoan.getALL())
    {
        if (acc->KiemTraTrungLap(username))
        {
            throw LoiTaoTaiKhoan();
        }
    }

    taikhoan.Them(new TaiKhoan(username, password));
    nguoimuon.Them(new NguoiMuon(hoten, username));
    cout << "\nDang ky thanh cong\n";
    MainMenu();
}

void DangNhap(QuanLyCapNhat<TaiKhoan *> &taikhoan)
{
    cout << "------- Dang nhap -------\n";
    string username, password;
    cout << "Nhap username: ";
    cin >> username;
    cout << "Nhap password: ";
    cin >> password;

    for (const auto &acc : taikhoan.getALL())
    {
        if (acc->getUsername() == username && acc->getPassword() == password)
        {
            if (username == "admin" && password == "admin")
            {
                MenuThuThu();
                return;
            }
            else
            {
                MenuNguoiDung(username);
                return;
            }
        }
    }
    throw LoiLogin();
}

void DangXuat(QuanLyCapNhat<TaiKhoan *> &taikhoan)
{
    bool dangxuat;
    cout << "Ban co muon dang xuat?(1/0): ";
    cin >> dangxuat;
    if (dangxuat)
    {
        MainMenu();
    }
    else
    {
        throw invalid_argument("Lua chon khong hop le!!!");
    }
}

void MenuThuThu()
{
    int choice;
    while (true)
    {
        cout << "\n----- QUAN LY THU VIEN -----\n";
        cout << "1. Them sach moi" << endl;
        cout << "2. Xoa sach" << endl;
        cout << "3. Tim kiem sach" << endl;
        cout << "4. Cap nhat thong tin sach" << endl;
        cout << "5. Hien tat ca sach" << endl;
        cout << "6. Tong so sach hien tai" << endl;
        cout << "7. Tra cuu lich su muon sach" << endl;
        cout << "8. Tra cuu lich nguoi muon" << endl;
        cout << "9. Dang xuat" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            ThemSach();
            break;
        case 2:
            XoaSach();
            break;
        case 3:
            TimSach();
            break;
        case 4:
            CapNhatSach();
            break;
        case 5:
            HienTatCaSach();
            break;
        case 6:
            TongSoSach();
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            DangXuat(taikhoan);
            break;
        case 0:
            throw Thoat();
        default:
            cout << "Lua chon khong hop le!!!\n";
            break;
        }
        bool tmp;
        cout << "Ban muon tiep tuc chuong trinh?(1/0): ";
        cin >> tmp;
        cin.ignore();
        if (!tmp)
        {
            throw Thoat();
        }
    }
}

void MenuNguoiDung(const string &username)
{
    int choice;
    while (true)
    {
        cout << "\n----- MENU NGUOI DUNG -----" << endl;
        cout << "1. Muon sach" << endl;
        cout << "2. Tra sach" << endl;
        cout << "3. Tim kiem sach" << endl;
        cout << "4. Hien thi tat ca sach" << endl;
        cout << "5. Dang xuat" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            MuonSach(username);
            break;

        case 2:

            break;
        case 3:
            TimSach();
            break;
        case 4:
            HienTatCaSach();
            break;
        case 5:
            DangXuat(taikhoan);
            break;
        case 0:
            throw invalid_argument("Ket thuc chuong trinh");
        default:
            cout << "Lua chon khong hop le!!!\n";
            break;
        }
        bool tmp;
        cout << "Ban muon tiep tuc chuong trinh?(1/0): ";
        cin >> tmp;
        cin.ignore();
        if (!tmp)
        {
            throw Thoat();
        }
    }
}

void ThemSach()
{
    string ma, ten, tacgia, theloai;
    int soluong;

    cout << "Nhap ma sach: ";
    getline(cin, ma);
    cout << "Nhap ten sach: ";
    getline(cin, ten);
    cout << "Nhap ten tac gia: ";
    getline(cin, tacgia);
    cout << "Nhap the loai: ";
    getline(cin, theloai);
    cout << "Nhap so luong: ";
    cin >> soluong;
    if (isdigit(soluong) || soluong <= 0)
    {
        throw invalid_argument("So luong khong hop le!!!");
    }

    sach.Them(new Sach(ma, ten, tacgia, theloai, soluong));
    cout << "\nThem sach thanh cong!!!\n";
}
void XoaSach()
{
    string id;
    int index = 0;
    cout << "Nhap id sach muon xoa: ";
    getline(cin, id);

    for (auto &s : sach.getALL())
    {
        if (s->getMaSach() == id)
        {
            sach.Xoa(index);
            cout << "\nXoa sach thanh cong!!!\n";
            return;
        }
        index++;
    }
    throw LoiKhongTonTaiSach();
}
void TimSach()
{
    string id;
    cout << "Nhap id sach muon tim: ";
    cin >> id;
    if (sach.TimKiem(id).empty())
    {
        cout << "Khong ton tai sach!!!\n";
        return;
    }
    else
    {
        for (auto &s : sach.TimKiem(id))
        {
            cout << "\n----- THONG TIN SACH -----\n";
            cout << "Ma sach: " << s->getMaSach() << endl;
            cout << "Ten sach: " << s->getTenSach() << endl;
            cout << "Tac gia: " << s->getTacGia() << endl;
            cout << "The loai: " << s->getTheLoai() << endl;
            cout << "So luong: " << s->getSoLuong() << endl;
        }
    }
}
void CapNhatSach()
{
    string id;
    string ten, tacgia, theloai;
    int soluong;
    cout << "Nhap id sach: ";
    getline(cin, id);
    for (auto &s : sach.getALL())
    {
        if (s->getMaSach() == id)
        {
            cout << "\n----- CAP NHAT SACH -----\n";
            cout << "Nhap ten sach: ";
            getline(cin, ten);
            s->setTenSach(ten);
            cout << "Nhap ten tac gia: ";
            getline(cin, tacgia);
            s->setTacGia(tacgia);
            cout << "Nhap the loai: ";
            getline(cin, theloai);
            s->setTheLoai(theloai);
            cout << "Nhap so luong: ";
            cin >> soluong;
            if (isdigit(soluong) || soluong <= 0)
            {
                throw invalid_argument("So luong khong hop le!!!");
            }
            s->setSoLuong(soluong);
            cout << "\nCap nhat sach thanh cong!!!\n";
            return;
        }
    }
    cout << "Khong tim thay sach\n";
}
void HienTatCaSach()
{
    cout << "\n----- THU VIEN SACH -----\n";
    for (auto &s : sach.getALL())
    {
        cout << "Ma sach: " << s->getMaSach() << endl;
        cout << "Ten sach: " << s->getTenSach() << endl;
        cout << "Tac gia: " << s->getTacGia() << endl;
        cout << "The loai: " << s->getTheLoai() << endl;
        cout << "So luong: " << s->getSoLuong() << endl;
        cout << "-------------------------\n";
    }
}
void TongSoSach()
{
    int sum;
    for (auto &s : sach.getALL())
    {
        sum += s->getSoLuong();
    }
    cout << "Tong so sach hien tai: " << sum << endl;
}
void MuonSach(const string &username)
{
    string id;
    string idNguoiMuon;
    int soluong;
    ofstream file("lichsumuontra.txt", ios::app);
    if (!file.is_open())
    {
        throw LoiFile();
    }
    cout << "Nhap id sach: ";
    getline(cin, id);
    cout << "Nhap so luong: ";
    cin >> soluong;
    if (isdigit(soluong) || soluong <= 0)
    {
        throw invalid_argument("So luong khong hop le!!!");
    }

    for (auto &n : nguoimuon.getALL())
    {
        if (n->getTaiKhoan() == username)
        {
            idNguoiMuon = n->getMaNguoiMuon();
            if (n->getGioHanMuon() <= 0)
            {
                throw LoiQuaGioiHanMuon();
            }
            else
            {
                n->setGioiHanMuon(n->getGioHanMuon() - soluong);
            }
        }
    }

    for (auto &s : sach.getALL())
    {
        if (s->KiemTraTrungLap(id))
        {
            if (s->getSoLuong() <= 0)
            {
                throw LoiKhongDuSach();
            }
            else if (s->getSoLuong() < soluong)
            {
                throw LoiKhongDuSach();
            }
            else
            {
                s->setSoLuong(s->getSoLuong() - soluong);
                muontra.Them(new QuanLyMuonTra(idNguoiMuon, id, soluong));
                QuanLyMuonTra *a = new QuanLyMuonTra(idNguoiMuon, id, soluong);
                file << a->getMaNguoiMuon() << "," << a->getMaSach() << "," << a->getSoluong() << "," << a->getThoiHan() << ","
                     << a->getThoiDiemMuon() << "," << a->getThoiDiemTra() << "," << a->getTrangThai() << endl;
                cout << "Muon sach thanh cong!!!\n";
                delete a;
                file.close();
                return;
            }
        }
    }
}
int main()
{
    try
    {
        sach.Them(new Sach("A01", "C++ Programing", "Brian", "Programming", 5));
        sach.Them(new Sach("A02", "My life", "Chris", "lifestyle", 2));
        taikhoan.Them(new TaiKhoan("admin", "admin"));
        MainMenu();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
