#include <iostream>
using namespace std;



const int MAX_FILM = 100;

struct Film {
    string judul;
    string genre;
    float rating;
};

Film daftarFilm[MAX_FILM];
int jumlahFilm = 0;
void tambahFilm(string judul, string genre, float rating) {
    if (jumlahFilm < MAX_FILM) {
        daftarFilm[jumlahFilm].judul = judul;
        daftarFilm[jumlahFilm].genre = genre;
        daftarFilm[jumlahFilm].rating = rating;
        jumlahFilm++;
    } else {
        cout << "Daftar film sudah penuh!" << endl;
    }
}

void LihatDaftarFilm (){
    system("cls");
    cout << "===== Daftar Film =====" << endl;
    if (jumlahFilm == 0) {
    cout << "Belum ada film yang tersedia." << endl;
    } else {
    for (int i = 0; i < jumlahFilm; i++) {
    cout << i + 1 << ". " << daftarFilm[i].judul 
    << " | " << daftarFilm[i].genre 
    << " | " << daftarFilm[i].rating << " menit" << endl;
    }
    }
}

void cariFilm(string nama) {
    bool ditemukan = false;
    for (int i = 0; i < jumlahFilm; i++) {
        if (daftarFilm[i].judul == nama) {
            cout << "Film ditemukan:\n";
            cout << daftarFilm[i].judul << " | " << daftarFilm[i].genre << " | " << daftarFilm[i].rating << " menit" << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Film tidak ditemukan.\n";
    }
}

void urutkanFilmBerdasarkanRating() {
    for (int i = 0; i < jumlahFilm - 1; i++) {
        for (int j = 0; j < jumlahFilm - i - 1; j++) {
            if (daftarFilm[j].rating < daftarFilm[j + 1].rating) {
                swap(daftarFilm[j], daftarFilm[j + 1]);
            }
        }
    }
    cout << "Film berhasil diurutkan berdasarkan rating (tertinggi ke terendah).\n";
}

void tambahFilm (){
                            if (jumlahFilm >= MAX_FILM) {
                            cout << "Kapasitas film sudah penuh!" << endl;
                        } else {
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

void hapusFilm (){
                            if (jumlahFilm == 0) {
                        cout << "Tidak ada film untuk dihapus." << endl;
                        } else {
                        string hapus;
                        cin.ignore(); 
                        cout << "Masukkan nama film yang akan dihapus: ";
                        getline(cin, hapus);

                        int index = -1;
                        for (int i = 0; i < jumlahFilm; i++) {
                            if (daftarFilm[i].judul == hapus) {
                                index = i;
                                break;
                            }
                        }
                        if (index != -1) {
                            for (int i = index; i < jumlahFilm - 1; i++) {
                                daftarFilm[i] = daftarFilm[i + 1];
                            }
                            jumlahFilm--;
                            cout << "Film berhasil dihapus!" << endl;
                        } else {
                            cout << "Film tidak ditemukan!" << endl;
                        }
                        }
}

int main () {
    int menu, menu1, menu2, menu3;
    char ulang;
    do {
        system("cls");
        cout << "==========================" << endl;
        cout << "PROGRAM ADMIN BIOSKOP XXZ" << endl;
        cout << "==========================" << endl;
        cout << "1. Jadwal Tayang" << endl;
        cout << "2. Daftar Film" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: "; cin >> menu;
        cout << " " << endl;
        cout << "==========================" << endl;
        
        switch (menu) {
            case 1:
                system("cls");
                cout << "=================" << endl;
                cout << "Jadwal Tayang" << endl;
                cout << "=================" << endl;
                cout << "1. Lihat jadwal tayang" << endl;
                cout << "2. Tambah jadwal tayang" << endl;
                cout << "3. Hapus jadwal tayang" << endl;
                cout << "4. Kembali ke menu utama" << endl;
                cout << "Pilih menu: "; cin >> menu1;
                switch (menu1) {
                    case 1:
                        cout << "Lihat jadwal tayang" << endl;
                        break;
                    case 2:
                        cout << "Tambah jadwal tayang" << endl;
                        break;
                    case 3:
                        cout << "Hapus jadwal tayang" << endl;
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
                cout << "Pilih menu: "; cin >> menu2;
                switch (menu2) {
                    case 1:
                        LihatDaftarFilm();
                        break;
                    case 2: {
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
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                exit(0);
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        cout << "Apakah Anda ingin kembali ke menu utama? (y/n): "; cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');
    cout << "Terima kasih telah menggunakan program ini!" << endl;

    return 0;
}