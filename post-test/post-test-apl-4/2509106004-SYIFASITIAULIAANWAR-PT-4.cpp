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
bool inputAngka(int &x){
    cin >> x;
    if(cin.fail()){
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
void garis(); 
void garis(int n);
int main(){
    User user[100];
    Produk produk[100];
    int jumlahUser = 0;
    int jumlahProduk = 0;
    int menuUtama;
    do{
        system("cls");
        cout<<"-------------------------------"<<endl;
        cout<<"         MENU UTAMA            "<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1. login"<<endl;
        cout<<"2. registrasi"<<endl;
        cout<<"3. keluar"<<endl;
        cout<<"pilih menu : ";
        if(!inputAngka(menuUtama)){
            cout<<"input harus angka"<<endl;
            system("pause");
            continue;
        }
        if(menuUtama==1){
            if(login(user,jumlahUser)){
                int menuAdmin;
                do{
                    system("cls");
                    cout<<"--------------------------------------"<<endl;
                    cout<<"        MENU ADMIN SYIFA HIJAB        "<<endl;
                    cout<<"--------------------------------------"<<endl;
                    cout<<"1. tampilkan produk"<<endl;
                    cout<<"2. tambah produk"<<endl;
                    cout<<"3. ubah produk"<<endl;
                    cout<<"4. hapus produk"<<endl;
                    cout<<"5. keluar"<<endl;
                    cout<<"pilih menu : ";
                    if(!inputAngka(menuAdmin)){
                        cout<<"input harus angka"<<endl;
                        system("pause");
                        continue;
                    }
                    if(menuAdmin==1){
                        tampilProduk(produk,jumlahProduk);
                        int total = totalStok(produk,jumlahProduk);
                        cout<<"total stok semua produk : "<<total<<endl;
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
    cout<<"terima kasih"<<endl;
}
bool login(User *user, int jumlahUser){
    string username,password;
    int kesempatan = 3;
    while(kesempatan>0){
        system("cls");
        cout<<"----------- LOGIN -----------"<<endl;
        cout<<"username : ";
        cin>>username;
        cout<<"password : ";
        cin>>password;
        if(username=="admincipa" && password=="004"){
            return true;
        }
        for(int i=0;i<jumlahUser;i++){
            if(username==user[i].username && password==user[i].password){
                return true;
            }
        }
        kesempatan--;
        cout<<"login gagal, sisa kesempatan : "<<kesempatan<<endl;
        system("pause");
    }
    return false;
}
void registrasi(User *user, int *jumlahUser){
    system("cls");
    cout<<"----------- REGISTRASI -----------"<<endl;
    cout<<"username : ";
    cin>>user[*jumlahUser].username;
    cout<<"password : ";
    cin>>user[*jumlahUser].password;
    (*jumlahUser)++;
    cout<<"registrasi berhasil"<<endl;
    system("pause");
}
void tampilProduk(Produk *produk, int jumlahProduk){
    system("cls");
    cout<<"----------------- DAFTAR PRODUK -----------------"<<endl;
    if(jumlahProduk==0){
        cout<<"belum ada produk"<<endl;
        return;
    }
    garis(55);
    cout<<left<<setw(5)<<"No"
        <<setw(20)<<"Nama"
        <<setw(15)<<"Warna"
        <<setw(10)<<"Harga"
        <<setw(5)<<"Stok"<<endl;
    garis(55);
    for(int i=0;i<jumlahProduk;i++){
        cout<<left<<setw(5)<<i+1
            <<setw(20)<<produk[i].nama
            <<setw(15)<<produk[i].warna
            <<setw(10)<<produk[i].harga
            <<setw(5)<<produk[i].stok<<endl;
    }
    garis(55);
}
void tambahProduk(Produk *produk, int *jumlahProduk){
    system("cls");
    cout<<"------ tambah produk ------"<<endl;
    cin.ignore();
    cout<<"nama produk : ";
    getline(cin,produk[*jumlahProduk].nama);
    cout<<"warna : ";
    getline(cin,produk[*jumlahProduk].warna);
    cout<<"harga : ";
    while(!inputAngka(produk[*jumlahProduk].harga)){
        cout<<"harus angka : ";
    }
    cout<<"stok : ";
    while(!inputAngka(produk[*jumlahProduk].stok)){
        cout<<"harus angka : ";
    }
    (*jumlahProduk)++;
    cout<<"produk berhasil ditambahkan"<<endl;
    system("pause");
}
void ubahProduk(Produk *produk, int jumlahProduk){
    tampilProduk(produk,jumlahProduk);
    int pilih;
    cout<<"pilih nomor produk : ";
    if(!inputAngka(pilih)){
        cout<<"input harus angka"<<endl;
        system("pause");
        return;
    }
    if(pilih>=1 && pilih<=jumlahProduk){
        cin.ignore();
        cout<<"nama baru : ";
        getline(cin,produk[pilih-1].nama);
        cout<<"warna baru : ";
        getline(cin,produk[pilih-1].warna);
        cout<<"harga baru : ";
        inputAngka(produk[pilih-1].harga);
        cout<<"stok baru : ";
        inputAngka(produk[pilih-1].stok);
        cout<<"produk berhasil diubah"<<endl;
    }
    else{
        cout<<"nomor tidak valid"<<endl;
    }
    system("pause");
}
void hapusProduk(Produk *produk, int *jumlahProduk){
    tampilProduk(produk,*jumlahProduk);
    int hapus;
    cout<<"pilih nomor produk : ";
    if(!inputAngka(hapus)){
        cout<<"input harus angka"<<endl;
        system("pause");
        return;
    }
    if(hapus>=1 && hapus<=*jumlahProduk){
        for(int i=hapus-1;i<(*jumlahProduk)-1;i++){
            produk[i]=produk[i+1];
        }
        (*jumlahProduk)--;
        cout<<"produk berhasil dihapus"<<endl;
    }
    else{
        cout<<"nomor tidak valid"<<endl;
    }
    system("pause");
}
int totalStok(Produk *produk, int n){
    if(n==0){
        return 0;
    }
    return produk[n-1].stok + totalStok(produk,n-1);
}
void garis(){
    cout<<"-----------------------------"<<endl;
}
void garis(int n){
    for(int i=0;i<n;i++){
        cout<<"-";
    }
    cout<<endl;
}