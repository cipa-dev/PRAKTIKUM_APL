#include <iostream>
#include <string> //untuk mnggunakan string
#include <cstdlib> //untuk system("cls") dan system("pause")
#include <iomanip> //untuk membuat tampilan rapi pd tabel
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
        cin>>menuUtama;
        if(menuUtama==1){
            int kesempatan = 3;
            bool login = false;
            string username, password;
            while(kesempatan>0){
                system("cls");
                cout<<"-------------------------------"<<endl;
                cout<<"             LOGIN             "<<endl;
                cout<<"-------------------------------"<<endl;
                cout<<"username : ";
                cin>>username;
                cout<<"password : ";
                cin>>password;
                if(username=="admincipa" && password=="004"){
                    login = true;
                    break;
                }
                for(int i=0;i<jumlahUser;i++){
                    if(username==user[i].username && password==user[i].password){
                        login = true;
                        break;
                    }
                }
                if(login) break;
                kesempatan--;
                cout<<"LOGIN GAGAL! SISA KESEMPATAN : "<<kesempatan<<endl;
                system("pause");
            }
            if(!login){
                cout<<"KESEMPATAN HABIS! ANDA GAGAL LOGIN"<<endl;
                return 0;
            }
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
                cin>>menuAdmin;
                if(menuAdmin==1){
                    system("cls");
                    cout<<"------------------- DAFTAR PRODUK -------------------"<<endl;
                    if(jumlahProduk==0){
                        cout<<"BELUM ADA PRODUK"<<endl;
                    }else{
                        cout<<"---------------------------------------------------------------"<<endl;
                        cout<<left<<setw(5)<<"No"
                            <<setw(20)<<"nama produk"
                            <<setw(15)<<"warna"
                            <<setw(10)<<"harga"
                            <<setw(5)<<"stok"<<endl;
                        cout<<"---------------------------------------------------------------"<<endl;
                        for(int i=0;i<jumlahProduk;i++){
                            cout<<left<<setw(5)<<i+1
                                <<setw(20)<<produk[i].nama
                                <<setw(15)<<produk[i].warna
                                <<setw(10)<<produk[i].harga
                                <<setw(5)<<produk[i].stok<<endl;
                        }
                        cout<<"---------------------------------------------------------------"<<endl;
                    }
                    system("pause");
                }
                else if(menuAdmin==2){
                    system("cls");
                    cout<<"------------- TAMBAH PRODUK -------------"<<endl;
                    cin.ignore();
                    cout<<"nama produk : ";
                    getline(cin, produk[jumlahProduk].nama);
                    cout<<"warna : ";
                    getline(cin, produk[jumlahProduk].warna);
                    cout<<"harga : ";
                    cin>>produk[jumlahProduk].harga;
                    cout<<"stok : ";
                    cin>>produk[jumlahProduk].stok;
                    jumlahProduk++;
                    cout<<"produk berhasil ditambahkan"<<endl;
                    system("pause");
                }
                else if(menuAdmin==3){
                    system("cls");
                    cout<<"------------- UBAH PRODUK -------------"<<endl;
                    cout<<"---------------------------------------------------------------"<<endl;
                    cout<<left<<setw(5)<<"No"
                        <<setw(20)<<"nama produk"
                        <<setw(15)<<"warna"
                        <<setw(10)<<"harga"
                        <<setw(5)<<"stok"<<endl;
                    cout<<"---------------------------------------------------------------"<<endl;
                    for(int i=0;i<jumlahProduk;i++){
                        cout<<left<<setw(5)<<i+1
                            <<setw(20)<<produk[i].nama
                            <<setw(15)<<produk[i].warna
                            <<setw(10)<<produk[i].harga
                            <<setw(5)<<produk[i].stok<<endl;
                    }
                    cout<<"---------------------------------------------------------------"<<endl;
                    int pilih;
                    cout<<"pilih nomor produk : ";
                    cin>>pilih;
                    if(pilih>=1 && pilih<=jumlahProduk){
                        cin.ignore();
                        cout<<"nama baru : ";
                        getline(cin, produk[pilih-1].nama);
                        cout<<"warna baru : ";
                        getline(cin, produk[pilih-1].warna);
                        cout<<"harga baru : ";
                        cin>>produk[pilih-1].harga;
                        cout<<"stok baru : ";
                        cin>>produk[pilih-1].stok;
                        cout<<"produk berhasil diubah"<<endl;
                    }else{
                        cout<<"NOMOR TIDAK VALID!"<<endl;
                    }
                    system("pause");
                }
                else if(menuAdmin==4){
                    system("cls");
                    cout<<"------------- HAPUS PRODUK -------------"<<endl;
                    cout<<"---------------------------------------------------------------"<<endl;
                    cout<<left<<setw(5)<<"No"
                        <<setw(20)<<"nama produk"
                        <<setw(15)<<"warna"
                        <<setw(10)<<"harga"
                        <<setw(5)<<"stok"<<endl;
                    cout<<"---------------------------------------------------------------"<<endl;
                    for(int i=0;i<jumlahProduk;i++){
                        cout<<left<<setw(5)<<i+1
                            <<setw(20)<<produk[i].nama
                            <<setw(15)<<produk[i].warna
                            <<setw(10)<<produk[i].harga
                            <<setw(5)<<produk[i].stok<<endl;
                    }
                    cout<<"---------------------------------------------------------------"<<endl;
                    int hapus;
                    cout<<"pilih nomor produk : ";
                    cin>>hapus;
                    if(hapus>=1 && hapus<=jumlahProduk){
                        for(int i=hapus-1;i<jumlahProduk-1;i++){
                            produk[i]=produk[i+1];
                        }
                        jumlahProduk--;
                        cout<<"produk berhasil dihapus"<<endl;
                    }else{
                        cout<<"NOMOR TIDAK VALID!"<<endl;
                    }
                    system("pause");
                }
                else if(menuAdmin==5){
                    break;
                }
                else{
                    cout<<"MASUKKAN ANGKA PILIHAN YANG TERSEDIA!"<<endl;
                    system("pause");
                }
            }while(menuAdmin!=5);
        }
        else if(menuUtama==2){
            system("cls");
            cout<<"-------------------------------"<<endl;
            cout<<"          REGISTRASI           "<<endl;
            cout<<"-------------------------------"<<endl;
            cout<<"username : ";
            cin>>user[jumlahUser].username;
            cout<<"password : ";
            cin>>user[jumlahUser].password;
            jumlahUser++;
            cout<<"REGISTER BERHASIL!"<<endl;
            system("pause");
        }
        else if(menuUtama==3){
            break;
        }
        else{
            cout<<"MASUKKAN ANGKA YANG TERSEDIA!"<<endl;
            system("pause");
        }
    }while(menuUtama!=3);
    cout<<"TERIMA KASIH!"<<endl;
}