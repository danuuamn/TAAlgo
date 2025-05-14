#include <iostream>
using namespace std;

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
                        cout << "Lihat daftar film" << endl;
                        break;
                    case 2:
                        cout << "Cari film" << endl;
                        break;
                    case 3:
                        cout << "Urutkan film" << endl;
                        break;
                    case 4:
                        cout << "Tambah film" << endl;
                        break;
                    case 5:
                        cout << "Hapus film" << endl;
                        break;
                    case 6:
                        cout << "Kembali ke menu utama..." << endl;
                        break;
                    default:
                        cout << "Pilihan tidak valid!" << endl;
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