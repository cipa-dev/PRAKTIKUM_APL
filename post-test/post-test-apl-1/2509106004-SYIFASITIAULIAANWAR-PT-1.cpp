//KONVERSI JAM, MENIT, DETIK
#include <iostream>
using namespace std;
int main() {
    string nama, password;
    int kesempatan = 3;
    bool login = false;
    while (kesempatan > 0) {
        cout << "----- LOGIN -----" << endl;
        cout << "Nama     : ";
        cin >> nama;
        cout << "Password : ";
        cin >> password;
        if (nama == "syifa" && password == "004") {
            login = true;
            break;
        } else {
            kesempatan--;
            cout << "LOGIN SALAH! SISA LOGIN ANDA: " << kesempatan << endl;
            cout << endl;
        }
    }
    if (!login) {
        cout << "LOGIN GAGAL!" << endl;
        return 0;
    }
    int pilihan;
    do {
        cout << endl;
        cout << "----- MENU UTAMA -----" << endl;
        cout << "1. konversi jam ke menit dan detik" << endl;
        cout << "2. konversi menit ke jam dan detik" << endl;
        cout << "3. konversi detik ke jam dan menit" << endl;
        cout << "4. keluar" << endl;
        cout << "pilih menu (1-4): ";
        cin >> pilihan;
        if (pilihan == 1) {
            int jam;
            cout << "masukkan jumlah jam: ";
            cin >> jam;
            cout << "hasil: " << jam * 60 << " menit dan "
                 << jam * 3600 << " detik" << endl;
        }
        else if (pilihan == 2) {
        int menit;
        cout << "masukkan jumlah menit: ";
        cin >> menit;
        int jam = menit / 60;
        int sisaMenit = menit % 60;
        cout << "hasil: " << jam << " jam "
            << sisaMenit << " menit" << endl;
        }
        else if (pilihan == 3) {
            int detik;
            cout << "masukkan jumlah detik: ";
            cin >> detik;
            int jam = detik / 3600;
            int menit = (detik % 3600) / 60;
            cout << "hasil: " << jam << " jam dan "
                << menit << " menit" << endl;
        }
        else if (pilihan == 4) {
            cout << "TERIMA KASIH!" << endl;
        }
        else {
            cout << "PILIHAN TIDAK VALID!" << endl;
        }
    } while (pilihan != 4);
    return 0;
}