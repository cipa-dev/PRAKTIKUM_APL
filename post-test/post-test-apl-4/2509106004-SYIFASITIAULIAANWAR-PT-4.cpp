#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct User{
    string username;
    string password;
};

struct Produk{
    string nama;
    string warna;
    int harga;
    int stok;
};

// fungsi
bool inputAngka(int &var){
    if(!(cin >> var)){
        cin.clear();
        cin.ignore(1000,'\n');
        return false;
    }
    return true;
}

void tampilProduk(Produk *produk, int jumlahProduk);
void tambahProduk(Produk *produk, int *jumlahProduk);
void ubahProduk(Produk *produk, int jumlahProduk);
void hapusProduk(Produk *produk, int *jumlahProduk);
bool login(User *user, int jumlahUser);
void registrasi(User *user, int *jumlahUser);
int totalStok(Produk *produk, int n);

int main(){
    User user[100];
    Produk produk[100];

    int jumlahUser = 0;
    int jumlahProduk = 0;
    int menuUtama;

    do{
        system("cls");
        cout<<"MENU UTAMA\n";
        cout<<"1. Login\n2. Registrasi\n3. Keluar\n";
        cout<<"Pilih: ";

        if(!inputAngka(menuUtama)){
            cout<<"Input harus angka!\n";
            system("pause");
            continue;
        }

        if(menuUtama==1){
            if(login(user,jumlahUser)){
                int menuAdmin;
                do{
                    system("cls");
                    cout<<"MENU ADMIN\n";
                    cout<<"1. Tampil\n2. Tambah\n3. Ubah\n4. Hapus\n5. Keluar\n";
                    cout<<"Pilih: ";

                    if(!inputAngka(menuAdmin)){
                        cout<<"Input harus angka!\n";
                        system("pause");
                        continue;
                    }

                    if(menuAdmin==1){
                        tampilProduk(produk,jumlahProduk);
                        cout<<"Total stok: "<<totalStok(produk,jumlahProduk)<<endl;
                        system("pause");
                    }
                    else if(menuAdmin==2){
                        tambahProduk(produk,&jumlahProduk);
                    }
                    else if(menuAdmin==3){
                        ubahProduk(produk,jumlahProduk);
                    }
                    else if(menuAdmin==4){
                        hapusProduk(produk,&jumlahProduk);
                    }

                }while(menuAdmin!=5);
            }
        }
        else if(menuUtama==2){
            registrasi(user,&jumlahUser);
        }

    }while(menuUtama!=3);

    cout<<"Terima kasih\n";
}

// LOGIN
bool login(User *user, int jumlahUser){
    string username,password;

    cout<<"Username: "; cin>>username;
    cout<<"Password: "; cin>>password;

    if(username=="admincipa" && password=="004")
        return true;

    for(int i=0;i<jumlahUser;i++){
        if(username==user[i].username && password==user[i].password)
            return true;
    }

    cout<<"Login gagal!\n";
    system("pause");
    return false;
}

// REGISTRASI
void registrasi(User *user, int *jumlahUser){
    system("cls");

    cout<<"Username: ";
    cin>>user[*jumlahUser].username;

    cout<<"Password: ";
    cin>>user[*jumlahUser].password;

    (*jumlahUser)++;

    cout<<"Registrasi berhasil\n";
    system("pause");
}

// TAMPIL
void tampilProduk(Produk *produk, int jumlahProduk){
    system("cls");

    if(jumlahProduk==0){
        cout<<"Belum ada produk\n";
        return;
    }

    cout<<left<<setw(5)<<"No"
        <<setw(20)<<"Nama"
        <<setw(10)<<"Harga"
        <<setw(5)<<"Stok"<<endl;

    for(int i=0;i<jumlahProduk;i++){
        cout<<setw(5)<<i+1
            <<setw(20)<<produk[i].nama
            <<setw(10)<<produk[i].harga
            <<setw(5)<<produk[i].stok<<endl;
    }
}

// TAMBAH
void tambahProduk(Produk *produk, int *jumlahProduk){
    system("cls");

    cin.ignore();
    cout<<"Nama: ";
    getline(cin,produk[*jumlahProduk].nama);

    cout<<"Harga: ";
    while(!inputAngka(produk[*jumlahProduk].harga)){
        cout<<"Harus angka! ";
    }

    cout<<"Stok: ";
    while(!inputAngka(produk[*jumlahProduk].stok)){
        cout<<"Harus angka! ";
    }

    (*jumlahProduk)++;

    cout<<"Berhasil tambah\n";
    system("pause");
}

// UBAH
void ubahProduk(Produk *produk, int jumlahProduk){
    tampilProduk(produk,jumlahProduk);

    int pilih;
    cout<<"Pilih: ";

    if(!inputAngka(pilih)){
        cout<<"Harus angka!\n";
        system("pause");
        return;
    }

    if(pilih>=1 && pilih<=jumlahProduk){
        cin.ignore();

        cout<<"Nama baru: ";
        getline(cin,produk[pilih-1].nama);

        cout<<"Harga: ";
        inputAngka(produk[pilih-1].harga);

        cout<<"Stok: ";
        inputAngka(produk[pilih-1].stok);

        cout<<"Berhasil ubah\n";
    }
    else{
        cout<<"Tidak valid\n";
    }

    system("pause");
}

// HAPUS
void hapusProduk(Produk *produk, int *jumlahProduk){
    tampilProduk(produk,*jumlahProduk);

    int hapus;
    cout<<"Pilih: ";

    if(!inputAngka(hapus)){
        cout<<"Harus angka!\n";
        system("pause");
        return;
    }

    if(hapus>=1 && hapus<=*jumlahProduk){
        for(int i=hapus-1;i<(*jumlahProduk)-1;i++){
            produk[i]=produk[i+1];
        }
        (*jumlahProduk)--;

        cout<<"Berhasil hapus\n";
    }
    else{
        cout<<"Tidak valid\n";
    }

    system("pause");
}

// REKURSIF
int totalStok(Produk *produk, int n){
    if(n==0) return 0;
    return produk[n-1].stok + totalStok(produk,n-1);
}