#include <iostream>
#include <fstream>
using namespace std;

const int MAX_FILM = 100;
struct Film
{
    string judul;
    string genre;
    float rating;
};

struct JadwalTayang {
    string judulFilm;
    string waktuTayang;
    JadwalTayang *next, *prev;
};

JadwalTayang* headJadwal = nullptr;


const int MAX_JADWAL = 100;
JadwalTayang daftarJadwal[MAX_JADWAL];
int jumlahJadwal = 0;

Film daftarFilm[MAX_FILM];
int jumlahFilm = 0;


void LihatDaftarFilm()
{
    cout << "===== Daftar Film =====" << endl;
    if (jumlahFilm == 0)
    {
        cout << "Belum ada film yang tersedia." << endl;
    }
    else
    {
        for (int i = 0; i < jumlahFilm; i++)
        {
            cout << i + 1 << ". " << daftarFilm[i].judul
                 << " | " << daftarFilm[i].genre
                 << " | " << daftarFilm[i].rating << endl;
        }
    }
}

void cariFilm(string nama)
{
    bool ditemukan = false;
    for (int i = 0; i < jumlahFilm; i++)
    {
        if (daftarFilm[i].judul == nama)
        {
            cout << "Film ditemukan:\n";
            cout << daftarFilm[i].judul << " | " << daftarFilm[i].genre << " | " << daftarFilm[i].rating << " rating" << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan)
    {
        cout << "Film tidak ditemukan.\n";
    }
}

void urutkanFilmBerdasarkanRating()
{
    for (int i = 0; i < jumlahFilm - 1; i++)
    {
        for (int j = 0; j < jumlahFilm - i - 1; j++)
        {
            if (daftarFilm[j].rating < daftarFilm[j + 1].rating)
            {
                swap(daftarFilm[j], daftarFilm[j + 1]);
            }
        }
    }
    cout << "Film berhasil diurutkan berdasarkan rating (tertinggi ke terendah).\n";
    cout << "Daftar film setelah diurutkan:\n";
    LihatDaftarFilm();
}

void tambahFilm()
{
    if (jumlahFilm >= MAX_FILM)
    {
        cout << "Kapasitas film sudah penuh!" << endl;
    }
    else
    {
        cout << "=== Tambah Film ===" << endl;
        cout << "Masukkan judul film: ";
        cin.ignore();
        getline(cin, daftarFilm[jumlahFilm].judul);
        cout << "Masukkan genre film: ";
        getline(cin, daftarFilm[jumlahFilm].genre);
        cout << "Masukkan rating film: ";
        cin >> daftarFilm[jumlahFilm].rating;
        jumlahFilm++;
        cout << "Film berhasil ditambahkan!" << endl;
    }
}

void hapusFilm()
{
    if (jumlahFilm == 0)
    {
        cout << "Tidak ada film untuk dihapus." << endl;
    }
    else
    {
        string hapus;
        cin.ignore();
        cout << "Masukkan nama film yang akan dihapus: ";
        getline(cin, hapus);

        int index = -1;
        for (int i = 0; i < jumlahFilm; i++)
        {
            if (daftarFilm[i].judul == hapus)
            {
                index = i;
                break;
            }
        }
        if (index != -1)
        {
            for (int i = index; i < jumlahFilm - 1; i++)
            {
                daftarFilm[i] = daftarFilm[i + 1];
            }
            jumlahFilm--;
            cout << "Film berhasil dihapus!" << endl;
        }
        else
        {
            cout << "Film tidak ditemukan!" << endl;
        }
    }
}

void lihatJadwalTayang() {
    cout << "===== Jadwal Tayang =====" << endl;
    if (headJadwal == nullptr) {
        cout << "Belum ada jadwal tayang." << endl;
    } else {
        int i = 1;
        JadwalTayang* tayang = headJadwal;
        while (tayang != nullptr) {
            cout << i++ << ". " << tayang->judulFilm << " | " << tayang->waktuTayang << endl;
            tayang = tayang->next;
        }
    }
}

void tambahJadwalTayang() {
    cin.ignore();
    string judul, waktu;
    cout << "Masukkan judul film: ";
    getline(cin, judul);

    bool ditemukan = false;
    for (int i = 0; i < jumlahFilm; i++) {
        if (daftarFilm[i].judul == judul) {
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Film tidak ditemukan dalam daftar!" << endl;
        return;
    }

    cout << "Masukkan waktu tayang (Contoh = 19:00) = ";
    getline(cin, waktu);

    JadwalTayang* baru = new JadwalTayang;
    baru->judulFilm = judul;
    baru->waktuTayang = waktu;
    baru->next = nullptr;

    if (headJadwal == nullptr) {
        headJadwal = baru;
        baru->prev = nullptr;
    } else {
        JadwalTayang* tampil = headJadwal;
        while (tampil->next != nullptr) {
            tampil = tampil->next;
        }
        tampil->next = baru;
        baru->prev = tampil;
    }

    cout << "Jadwal tayang berhasil ditambahkan!" << endl;
}

void hapusJadwalTayang() {
    cin.ignore();
    string judul;
    cout << "Masukkan judul film yang ingin dihapus dari jadwal: ";
    getline(cin, judul);

    JadwalTayang* tampil = headJadwal;
    JadwalTayang* prev = nullptr;
    bool ditemukan = false;

    while (tampil != nullptr) {
        if (tampil->judulFilm == judul) {
            ditemukan = true;
            if (prev == nullptr) {
                headJadwal = tampil->next;
            } else {
                prev->next = tampil->next;
            }
            delete tampil;
            cout << "Jadwal tayang berhasil dihapus!" << endl;
            break;
        }
        prev = tampil;
        tampil = tampil->next;
    }

    if (!ditemukan) {
        cout << "Jadwal tidak ditemukan!" << endl;
    }
}

void simpanDataFilm() {
    ofstream file("film.txt");
    for (int i = 0; i < jumlahFilm; i++) {
        file << daftarFilm[i].judul << "|" << daftarFilm[i].genre << "|" << daftarFilm[i].rating << "\n";
    }
    file.close();
}

void muatDataFilm() {
    ifstream file("film.txt");
    string judul, genre;
    float rating;
    jumlahFilm = 0;
    while (getline(file, judul, '|') && getline(file, genre, '|') && file >> rating) {
        file.ignore();
        daftarFilm[jumlahFilm++] = {judul, genre, rating};
    }
    file.close();
}

void simpanJadwalTayang() {
    ofstream file("jadwal.txt");
    JadwalTayang* sekarang = headJadwal;
    while (sekarang != nullptr) {
        file << sekarang->judulFilm << "|" << sekarang->waktuTayang << "\n";
        sekarang = sekarang->next;
    }
    file.close();
}

void muatJadwalTayang() {
    ifstream file("jadwal.txt");
    string judul, waktu;
    headJadwal = nullptr;

    while (getline(file, judul, '|') && getline(file, waktu)) {
        JadwalTayang* baru = new JadwalTayang{judul, waktu, nullptr};
        if (headJadwal == nullptr) {
            headJadwal = baru;
            baru->prev = nullptr;
        } else {
            JadwalTayang* tampil = headJadwal;
            while (tampil->next != nullptr)
                tampil = tampil->next;
            tampil->next = baru;
            baru->prev = tampil;
        }
    }
    file.close();
}



int main()
{
    muatDataFilm();
    muatJadwalTayang();
    JadwalTayang* tayang = headJadwal;
    int menu, menu1, menu2, menu3;
    char ulang;
    do
    {
        system("cls");
        cout << "==========================" << endl;
        cout << "PROGRAM ADMIN BIOSKOP XXZ" << endl;
        cout << "==========================" << endl;
        cout << "Film yang sedang tayang            : ";
        if (headJadwal == nullptr) {
            cout << "Belum ada jadwal tayang." << endl;
        } else {
            cout << headJadwal->judulFilm << " | " << headJadwal->waktuTayang << endl;

            cout << "Film yang akan tayang selanjutnya  : ";
            if (headJadwal->next != nullptr)
                cout << headJadwal->next->judulFilm << " | " << headJadwal->next->waktuTayang << endl;
            else
                cout << "Tidak ada film selanjutnya." << endl;

            cout << "Film yang telah tayang terakhir    : ";
            if (headJadwal->prev != nullptr)
                cout << headJadwal->prev->judulFilm << " | " << headJadwal->prev->waktuTayang << endl;
            else
                cout << "Tidak ada film sebelumnya." << endl;
        }
        cout << "==========================" << endl;
        cout << "1. Jadwal Tayang" << endl;
        cout << "2. Daftar Film" << endl;
        cout << "3. Tayangkan film selanjutnya" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> menu;
        cout << " " << endl;
        cout << "==========================" << endl;

        switch (menu)
        {
        case 1:
            system("cls");
            cout << "=================" << endl;
            cout << "Jadwal Tayang" << endl;
            cout << "=================" << endl;
            cout << "1. Lihat jadwal tayang" << endl;
            cout << "2. Tambah jadwal tayang" << endl;
            cout << "3. Hapus jadwal tayang" << endl;
            cout << "4. Kembali ke menu utama" << endl;
            cout << "Pilih menu: ";
            cin >> menu1;
            switch (menu1)
            {
                case 1:
                    lihatJadwalTayang();
                    break;
                case 2:
                    tambahJadwalTayang();
                    break;
                case 3:
                    hapusJadwalTayang();
                    break;
                case 4:
                    cout << "Kembali ke menu utama..." << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid!" << endl;
            }
            break;
        case 2:
            system("cls");
            cout << "=================" << endl;
            cout << "Daftar Film" << endl;
            cout << "=================" << endl;
            cout << "1. Lihat daftar film" << endl;
            cout << "2. Cari film" << endl;
            cout << "3. Urutkan film" << endl;
            cout << "4. Tambah film" << endl;
            cout << "5. Hapus film" << endl;
            cout << "6. Kembali ke menu utama" << endl;
            cout << "Pilih menu: ";
            cin >> menu2;
            switch (menu2)
            {
            case 1:
                LihatDaftarFilm();
                break;
            case 2:
            {
                cin.ignore();
                string namaFilm;
                cout << "Masukkan nama film yang ingin dicari: ";
                getline(cin, namaFilm);
                cariFilm(namaFilm);
                break;
            }
            case 3:
                urutkanFilmBerdasarkanRating();
                break;

            case 4:
                tambahFilm();
                break;
            case 5:
                hapusFilm();
                break;
            case 6:
                cout << "Kembali ke menu utama..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
            }
            break;
        case 3:
            if (headJadwal != nullptr && headJadwal->next != nullptr) {
                headJadwal = headJadwal->next;
                cout << "Film telah diganti ke jadwal berikutnya.\n";
            } else if (headJadwal != nullptr && headJadwal->next == nullptr) {
                cout << "Tidak ada film selanjutnya.\n";
            } else {
                cout << "Belum ada film tayang.\n";
            }
            break;
        case 4:
            cout << "Terima kasih telah menggunakan program ini!" << endl;
            simpanDataFilm();
            simpanJadwalTayang();
            exit(0);
            break; 
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
        cout << "Apakah Anda ingin kembali ke menu utama? (y/n): ";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');
    cout << "Terima kasih telah menggunakan program ini!" << endl;

    simpanDataFilm();
    simpanJadwalTayang();

    return 0;
}