//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//deklarasi variable global

int ayam=0,tahu=0, tempe=0,nasi=0,dadak=0;
int dadas=0,pahaak=0,pahaas=0,pahabs=0,pahabk=0;
int sayapk=0,sayaps=0;
int tdadak=0,tdadas=0,tpahaak=0,tpahaas=0;
int tpahabk=0,tpahabs=0,tsayapk=0,tsayaps=0;
int ttahu=0,ttempe=0, tnasi=0;
String nama,pembeli[100];
int harga[7]={13000,12500,12000,11000,3000,2500,4000};
int kbd=0,kbp=0,kbs=0,ksp=0,sbd=0,sbp=0,sbs=0,ssp=0,th=0,tp=0,ns=0;
int tkbd=0,tkbp=0,tkbs=0,tksp=0,tsbd=0,tsbp=0,tsbs=0,tssp=0,tth=0;
int ttp=0,tns=0, pendapatan;
int jl_kbd[100],jl_kbp[100],jl_kbs[100],jl_ksp[100],jl_sbd[100];
int jl_sbp[100],jl_sbs[100],jl_ssp[100],jl_th[100],jl_tp[100],jl_ns[100];
String rasa_ayam,bagian_ayam,jml_ayam;
int x=0,y=0,z=0, i,a=0;
int bayar, kembalian;
int total_harga [100],t_harga;
String stok[11]={"Dada Krispi","Dada Spicy","Paha Atas Krispi",
                "Paha Atas Spicy","Paha Bawah Krispi",
                "Paha Bawah Spicy","Sayap Krispi","Sayap Spicy",
                "Tempe","Tahu","Nasi"};
int ayamTerjual=0,tempeTerjual=0,tahuTerjual=0,nasiTerjual=0;
int totalSemua,untungTotal=0, modalTotal,modalAyam,modalTempe;
int modalTahu,modalBeras;
int untungDada=0,untungPahaB=0,untungPahaA=0,untungSayap=0;
int untungTahu=0,untungTempe=0,untungBeras=0;
int kandang = 0,kulkas=0 , stock=0 , wadah[10],stokAyam;

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
//sebelum toko dibuka tidak ada aktivitas dalam program dengan mengunci tiap GroupBox
GroupBox5->Enabled=false;     //groupbox 5 terkunci
GroupBox11->Enabled=false;    //groupbox 11 terkunci
GroupBox8->Enabled=false;     //groupbox 8 terkunci
Button2->Enabled=false;       // button 2 terkunci
Button15->Enabled=false;      // button 15 terkunci
Button13->Enabled=false;      // button 13 terkunci
Button4->Enabled=false;       // button 4 terkunci
Button9->Enabled=false;       // button 9 terkunci
Button16->Enabled=false;      // button 16 terkunci
Button18->Enabled=false;      // button 18 terkunci
Button19->Enabled=false;      // button 19 terkunci
Button7->Enabled=false;       // button 7 terkunci
Button3->Enabled=false;       // button 3 terkunci
Button8->Enabled=false;       // button 8 terkunci
Button11->Enabled=false;      // button 11 terkunci
Button14->Enabled=false;      // button 14 terkunci
Button12->Enabled=false;      // button 12 terkunci


}
//---------------------------------------------------------------------------





void __fastcall TForm1::Button1Click(TObject *Sender)  //button open aplikasi kasir
{
 GroupBox5->Enabled=true;         // ketika tombol open ditekan maka groupbox5 akan dibuka untuk memasukan stok barang
 Button8->Enabled=true;           // button 8 diaktifkan
  Button14->Enabled=true;
   Button12->Enabled=true;
 Edit11->SetFocus();               // setelah tombol open ditekan maka program otomatis mengarahkan kursor ke edit1
 Edit1->Text="0";                 // didalam edit 1 akan ditampilkan "0"
 Edit2->Text="0";                 // didalam edit 2 akan ditampilkan "0"
 Edit3->Text="0";                 // didalam edit 3 akan ditampilkan "0"
 Edit5->Text="0";                 // didalam edit 5 akan ditampilkan "0"
 Edit6->Text="0";                 // didalam edit 6 akan ditampilkan "0"
 Edit7->Text="0";                 // didalam edit 7 akan ditampilkan "0"
 Edit8->Text="0";                 // didalam edit 8 akan ditampilkan "0"
 Edit12->Text="0";                // didalam edit 12 akan ditampilkan "0"


}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender) // button input bahan
{
//input stok menu
    int inAyam = StrToInt(Edit1->Text);       // inAyam adalah variable tempat menyimpan inputan user di  Edit1->Text
    int inTempe = StrToInt(Edit2->Text);      // inTempe adalah variable tempat menyimpan inputan user di  Edit2->Text
    int inTahu = StrToInt(Edit3->Text);       // inTahu adalah variable tempat menyimpan inputan user di  Edit3->Text
    int inNasi = StrToInt(Edit12->Text);      // inNasi adalah variable tempat menyimpan inputan user di  Edit12->Text

    if ((inAyam==0)&&(inTempe==0)&&(inTahu ==0)&&(inNasi==0 )){   // jika inputan user di edit1 = 0 dan inputan user di edit2 = 0 dan inputan user di edit3 = 0 dan inputan user di edit12 = 0 ,maka:
        ShowMessage("Isi dulu stoknya");                          // akan muncul pesan "isi dulu stoknya"

    }else{                                                        // selain itu
        kulkas = kulkas - StrToInt(Edit1->Text);  // stok di kulkas dikurangi sesuai inputan user di edit 1
        ListBox45->Clear();                       // isi listbox45 dihapus
        ListBox45->Items->Add(kulkas);            // di listbox 45 tampilkan nilai dari kulkas
        ayam = ayam + inAyam *8 ;                 // memproses setiap inputan user akan dikali 8 potong ayam dan tersimpan di variabel ayam
        tempe= tempe +inTempe*15 ;                // memproses setiap inputan user dikali 15 potong tempe dan tersimpan di variabel tempe
        tahu = tahu + inTahu*15  ;                // memproses setiap inputan user dikali 15 potong tahu dan tersimpan di variabel tahu
        nasi = nasi + inNasi*5*20  ;              // memproses setiap inputan user dikali 5 dan dikali 20  porsi nasi dan tersimpan di variabel nasi
                                                  // karena 1 ayam dipotong lalu dibuat 2 varian dengan 4 ukuran berbeda maka setiap ayam akan di bagi stoknya
        dadak = dadak + ayam/8;                   // dadak adalah variabel dada krispi yang berasal dari operasi var ayam
        dadas = dadas + ayam/8;                   // dadas adalah variabel dada spicy yang berasal dari operasi var ayam
        pahaak = pahaak +  ayam/8;                // pahaak adalah variabel paha atas krispi yang berasal dari operasi var ayam
        pahaas = pahaas + ayam/8;                 // pahaas adalah variabel paha atas spicy yang berasal dari operasi var ayam
        pahabk = pahabk + ayam/8;                 // pahabk adalah variabel paha bawah krispi yang berasal dari operasi var ayam
        pahabs = pahabs + ayam/8;                 // pahabs adalah variabel paha bawah spicy yang berasal dari operasi var ayam
        sayapk = sayapk + ayam/8;                 // sayapk adalah variabel sayap krispi yang berasal dari operasi var ayam
        sayaps = sayaps + ayam/8;                 // sayaps adalah variabel sayap spicy yang berasal dari operasi var ayam


        ListBox18->Clear();                       // isi listbox 18 dihapus
        for(i =0; i<11; i++) {                    // untuk i =0 ; i < 11 ; i incremenr    adalah perulangan untuk nilai array stok
            ListBox18->Items->Add(stok[i]);       // menampilkan array stok dengan indeks i ke listbox 18
        }

            tdadak =  dadak;                      //tdadak adalah variable yang menampun nilai dadak
            tpahaak=  pahaak;                     //tpahaak adalah variable yang menampun nilai pahaak
            tsayapk=  sayapk;                     //tsayapk adalah variable yang menampun nilai sayapk
            tpahabk = pahabk;                     //tpahabk adalah variable yang menampun nilai pahabk
            tpahaas =pahaas ;                     //tpahaas adalah variable yang menampun nilai pahaas
            tdadas = dadas;                       //tdadas adalah variable yang menampun nilai dadas
            tsayaps= sayaps;                      //tsayaps adalah variable yang menampun nilai sayaps
            tpahabs = pahabs;                     //tpahabs adalah variable yang menampun nilai pahabs
            ttahu   =  tahu ;                     //ttahu adalah variable yang menampun nilai tahu
            ttempe  =  tempe ;                    //ttempe adalah variable yang menampun nilai tempe
            tnasi   =  nasi;                      //tnasi adalah variable yang menampun nilai nasi

                ListBox1->Clear();                // lisbox 1 dihapus
                ListBox1->Items->Add(tdadak);     // di listbox t akan menampilkan nilai tdadak
                ListBox1->Items->Add(tdadas);     // di listbox t akan menampilkan nilai tdadas
                ListBox1->Items->Add(tpahaak);    // di listbox t akan menampilkan nilai tpahaak
                ListBox1->Items->Add(tpahaas);    // di listbox t akan menampilkan nilai tpahaas
                ListBox1->Items->Add(tpahabk);    // di listbox t akan menampilkan nilai tpahabk
                ListBox1->Items->Add(tpahabs);    // di listbox t akan menampilkan nilai tpahabs
                ListBox1->Items->Add(tsayapk);    // di listbox t akan menampilkan nilai tsayapk
                ListBox1->Items->Add(tsayaps);    // di listbox t akan menampilkan nilai tsayaps
                ListBox1->Items->Add(ttempe);     // di listbox t akan menampilkan nilai ttempe
                ListBox1->Items->Add(ttahu);      // di listbox t akan menampilkan nilai ttahu
                ListBox1->Items->Add(tnasi);      // di listbox t akan menampilkan nilai tnasi


 Edit1->Text="0";               // edit 1 akan menampilkan "0"
 Edit2->Text="0";               // edit 2 akan menampilkan "0"
 Edit3->Text="0";               // edit 3 akan menampilkan "0"
 Edit12->Text="0";              // edit 12 akan menampilkan "0"
 GroupBox8->Enabled=true;       // grupbox 8  diaktifkan
 Button7->Enabled=true;         // button 7 diaktifkan
 Button2->Enabled=false;        // button 2 diaktifkan

}

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button7Click(TObject *Sender)              // button inputan nama
{
 nama=Edit4->Text;                                                 // nama adalah variabel untuk menyimpan nama pelanggan dari edit4
 if(nama==""){                                                     // jika user tidak menginputkan sesuatu pada variabel nama maka
  ShowMessage("Isi nama dulu:)");                                  // akan muncul pesan "isi nama dulu"
 }
 else{                                                             // kondisi lain
  pembeli[y]= nama;                                                // data pelanggan di variabel nama akan tersimpan di array pembeli indeks y
  y++;                                                             // y increment

  ComboBox2->Text="Varian Ayam";   // combobox2 akan menampilkan "varian ayam"
  ComboBox3->Text="Jenis Ayam";    // combobox3 akan menampilkan "jenis ayam"
  Button7->Enabled=false;          // button 7 diaktifkan
  Button13->Enabled=true;          // button  13 diaktifkan
   Button15->Enabled=true;         // button 15 diaktifkan
 }
}
//---------------------------------------------------------------------------







void __fastcall TForm1::Button13Click(TObject *Sender)//button input dibagian toping
{

    rasa_ayam=(ComboBox2->Text);                              // rasa ayam adalah var yang menampung pilihan user di combobox2
    bagian_ayam=(ComboBox3->Text);                            // bagian ayam adalah var yang menampungpilihan user di combobox3

    if(tdadak < Edit5->Text || tdadas<Edit5->Text  || tpahaak<Edit5->Text  ||tpahaas<Edit5->Text  ||tpahabk<Edit5->Text || tpahabs<Edit5->Text  || tsayapk<Edit5->Text  ||tsayaps<Edit5->Text  || tnasi<Edit8->Text  || ttahu<Edit7->Text || ttempe<Edit6->Text ){
        ShowMessage("stok kurang");                           // jika masing-masing stok kurang dari inputan user maka akan tampil pesan "stok kurang"
        Edit1->SetFocus();                                    // kursor akan menuju ke edit 1
        Button3->Enabled=true;                                // button 3 diaktifkan
        Edit4->Enabled=false;                                 // button 4 dinonaktifkan
        Button7->Enabled=false;                               // button 7 dinonaktifkan
        Edit5->Clear();                                       // isi data di edit 5 dihapus
        Edit6->Clear();                                       // isi data di edit 6 dihapus
        Edit7->Clear();                                       // isi data di edit 7 dihapus
        Edit8->Clear();                                       // isi data di edit 8 dihapus
        Edit5->Text="0";                                      // di edit5 akan menampilkan "0"
        Edit8->Text="0";                                      // di edit8 akan menampilkan "0"
        Edit7->Text="0";                                      // di edit7 akan menampilkan "0"
        Edit6->Text="0";                                      // di edit6 akan menampilkan "0"
    } else{                                                   // kondisi lain

         if(rasa_ayam=="Ayam Krispi"){                        // jika user memilih ayam krispi di combobox2
            if(bagian_ayam=="Dada"){                          // jika user mimilih dada di combobox3
                kbd = kbd + StrToInt(Edit5->Text) *harga[0];  //kbd adalah variable yang menampung array harga[0] dikali inputan user
                jl_kbd[x] = StrToInt(Edit5->Text) ;           // setiap inputan user akan masuk ke array jl_kbd dengan indeks x

                untungDada = untungDada + (StrToInt(Edit5->Text)*8000);  // untungDada adalah variable yang menampung keuntungan dada dikali inputan user
                tdadak = tdadak - StrToInt(Edit5->Text);       //  stok di tdadak akan berkurang sesuai inputan user

                ListBox1->Clear();               // lisbox 1 dihapus
                ListBox1->Items->Add(tdadak);     // di listbox t akan menampilkan nilai tdadak
                ListBox1->Items->Add(tdadas);     // di listbox t akan menampilkan nilai tdadas
                ListBox1->Items->Add(tpahaak);    // di listbox t akan menampilkan nilai tpahaak
                ListBox1->Items->Add(tpahaas);    // di listbox t akan menampilkan nilai tpahaas
                ListBox1->Items->Add(tpahabk);    // di listbox t akan menampilkan nilai tpahabk
                ListBox1->Items->Add(tpahabs);    // di listbox t akan menampilkan nilai tpahabs
                ListBox1->Items->Add(tsayapk);    // di listbox t akan menampilkan nilai tsayapk
                ListBox1->Items->Add(tsayaps);    // di listbox t akan menampilkan nilai tsayaps
                ListBox1->Items->Add(ttempe);     // di listbox t akan menampilkan nilai ttempe
                ListBox1->Items->Add(ttahu);      // di listbox t akan menampilkan nilai ttahu
                ListBox1->Items->Add(tnasi);      // di listbox t akan menampilkan nilai tnasi

            }else if(bagian_ayam=="Paha Atas"){                  // jika user memilih paha atas di combobox3 maka :
                kbp = kbp + StrToInt(Edit5->Text) *harga[1];     // jika user memilih paha atas di combobox3 maka :
                jl_kbp[x] =  StrToInt(Edit5->Text) ;                   // setiap inputan user akan masuk ke array jl_kbp dengan indeks x

                untungPahaA = untungPahaA + (StrToInt(Edit5->Text)*7500);  //untungPaha adalah variable yang menampung keuntungan paha dikali inputan user
                tpahaak = tpahaak - StrToInt(Edit5->Text) ;                 //  stok di tpahaak akan berkurang sesuai inputan user

                 ListBox1->Clear();                // lisbox 1 dihapus
                ListBox1->Items->Add(tdadak);     // di listbox t akan menampilkan nilai tdadak
                ListBox1->Items->Add(tdadas);     // di listbox t akan menampilkan nilai tdadas
                ListBox1->Items->Add(tpahaak);    // di listbox t akan menampilkan nilai tpahaak
                ListBox1->Items->Add(tpahaas);    // di listbox t akan menampilkan nilai tpahaas
                ListBox1->Items->Add(tpahabk);    // di listbox t akan menampilkan nilai tpahabk
                ListBox1->Items->Add(tpahabs);    // di listbox t akan menampilkan nilai tpahabs
                ListBox1->Items->Add(tsayapk);    // di listbox t akan menampilkan nilai tsayapk
                ListBox1->Items->Add(tsayaps);    // di listbox t akan menampilkan nilai tsayaps
                ListBox1->Items->Add(ttempe);     // di listbox t akan menampilkan nilai ttempe
                ListBox1->Items->Add(ttahu);      // di listbox t akan menampilkan nilai ttahu
                ListBox1->Items->Add(tnasi);      // di listbox t akan menampilkan nilai tnasi

            }else if(bagian_ayam=="Sayap"){                         // jika user memilih sayap di combobox3 maka :
                kbs = kbs+  StrToInt(Edit5->Text) *harga[2];        // kbs adalah  variable yang menampung array harga[2] dikali inputan user
                jl_kbs[x] = StrToInt(Edit5->Text) ;                 // setiap inputan user akan masuk ke array jl_kbs dengan indeks x

                untungSayap = untungSayap + (StrToInt(Edit5->Text)*7000); //untungSayap adalah variable yang menampung keuntungan sayap dikali inputan user
                tsayapk = tsayapk - StrToInt(Edit5->Text) ;     // stok di tsayapk akan berkurang sesuai inputan user

                ListBox1->Clear();                // lisbox 1 dihapus
                ListBox1->Items->Add(tdadak);     // di listbox t akan menampilkan nilai tdadak
                ListBox1->Items->Add(tdadas);     // di listbox t akan menampilkan nilai tdadas
                ListBox1->Items->Add(tpahaak);    // di listbox t akan menampilkan nilai tpahaak
                ListBox1->Items->Add(tpahaas);    // di listbox t akan menampilkan nilai tpahaas
                ListBox1->Items->Add(tpahabk);    // di listbox t akan menampilkan nilai tpahabk
                ListBox1->Items->Add(tpahabs);    // di listbox t akan menampilkan nilai tpahabs
                ListBox1->Items->Add(tsayapk);    // di listbox t akan menampilkan nilai tsayapk
                ListBox1->Items->Add(tsayaps);    // di listbox t akan menampilkan nilai tsayaps
                ListBox1->Items->Add(ttempe);     // di listbox t akan menampilkan nilai ttempe
                ListBox1->Items->Add(ttahu);      // di listbox t akan menampilkan nilai ttahu
                ListBox1->Items->Add(tnasi);      // di listbox t akan menampilkan nilai tnasi


            }else if(bagian_ayam=="Paha Bawah"){                    // jika user memilih paha bawah di combobox3 maka :
                ksp = ksp +StrToInt(Edit5->Text) *harga[3];         // ksp adalah variable yang menampung array harga[3] dikali inputan user
                jl_ksp[x] = StrToInt(Edit5->Text) ;                 // setiap inputan user akan masuk ke array jl_ksp dengan indeks x

                untungPahaB = untungPahaB + (StrToInt(Edit5->Text)*6000); //untungPahaB adalah variable yang menampung keuntungan paha bawah dikali inputan user
                tpahabk= tpahabk - StrToInt(Edit5->Text) ;                 // stok di tpahabk akan berkurang sesuai inputan user

                ListBox1->Clear();                // lisbox 1 dihapus
                ListBox1->Items->Add(tdadak);     // di listbox t akan menampilkan nilai tdadak
                ListBox1->Items->Add(tdadas);     // di listbox t akan menampilkan nilai tdadas
                ListBox1->Items->Add(tpahaak);    // di listbox t akan menampilkan nilai tpahaak
                ListBox1->Items->Add(tpahaas);    // di listbox t akan menampilkan nilai tpahaas
                ListBox1->Items->Add(tpahabk);    // di listbox t akan menampilkan nilai tpahabk
                ListBox1->Items->Add(tpahabs);    // di listbox t akan menampilkan nilai tpahabs
                ListBox1->Items->Add(tsayapk);    // di listbox t akan menampilkan nilai tsayapk
                ListBox1->Items->Add(tsayaps);    // di listbox t akan menampilkan nilai tsayaps
                ListBox1->Items->Add(ttempe);     // di listbox t akan menampilkan nilai ttempe
                ListBox1->Items->Add(ttahu);      // di listbox t akan menampilkan nilai ttahu
                ListBox1->Items->Add(tnasi);      // di listbox t akan menampilkan nilai tnasi


            }else{                                           // komdisi lain
                ShowMessage("masukan input ");               // akan muncul pesan "masukan input"
                Edit5->Text="0";                             // edit 5 menampilkan "0"
                ComboBox2->Text="Varian Ayam";               // combobox2 menampilkan varian ayam
                ComboBox3->Text="Jenis Ayam";                // combobox3 menampilkan Jenis ayam
            }


        }else if (rasa_ayam=="Ayam Spicy"){                      // jika user memilih ayam spicy di combobox2 maka :
            if(bagian_ayam=="Dada"){                             // jika user mimilih dada di combobox3
                sbd = sbd + StrToInt(Edit5->Text)  *harga[0];    // sbd adalah variable yang menampung array harga[0] dikali inputan user
                jl_sbd[x] = StrToInt(Edit5->Text) ;              // setiap inputan user akan masuk ke array jl_sbd dengan indeks x

                untungDada = untungDada + (StrToInt(Edit5->Text)*8000);    // untungDada adalah variable yang menampung keuntungan dada dikali inputan user
                tdadas = tdadas - StrToInt(Edit5->Text) ;         //  stok di tdadak akan berkurang sesuai inputan user

                 ListBox1->Clear();                // lisbox 1 dihapus
                ListBox1->Items->Add(tdadak);     // di listbox t akan menampilkan nilai tdadak
                ListBox1->Items->Add(tdadas);     // di listbox t akan menampilkan nilai tdadas
                ListBox1->Items->Add(tpahaak);    // di listbox t akan menampilkan nilai tpahaak
                ListBox1->Items->Add(tpahaas);    // di listbox t akan menampilkan nilai tpahaas
                ListBox1->Items->Add(tpahabk);    // di listbox t akan menampilkan nilai tpahabk
                ListBox1->Items->Add(tpahabs);    // di listbox t akan menampilkan nilai tpahabs
                ListBox1->Items->Add(tsayapk);    // di listbox t akan menampilkan nilai tsayapk
                ListBox1->Items->Add(tsayaps);    // di listbox t akan menampilkan nilai tsayaps
                ListBox1->Items->Add(ttempe);     // di listbox t akan menampilkan nilai ttempe
                ListBox1->Items->Add(ttahu);      // di listbox t akan menampilkan nilai ttahu
                ListBox1->Items->Add(tnasi);      // di listbox t akan menampilkan nilai tnasi


            }else if(bagian_ayam=="Paha Atas"){                 // jika user memilih paha atas di combobox3 maka :
                sbp = sbp + StrToInt(Edit5->Text) *harga[1];    // setiap inputan user akan masuk ke array jl_sbp dengan indeks x
                jl_sbp[x] = StrToInt(Edit5->Text) ;

                untungPahaA = untungPahaA + (StrToInt(Edit5->Text)*7500);  //untungPaha adalah variable yang menampung keuntungan paha dikali inputan user
                tpahaas = tpahaas - StrToInt(Edit5->Text) ;                //  stok di tpahaas akan berkurang sesuai inputan user


                 ListBox1->Clear();                // lisbox 1 dihapus
                ListBox1->Items->Add(tdadak);     // di listbox t akan menampilkan nilai tdadak
                ListBox1->Items->Add(tdadas);     // di listbox t akan menampilkan nilai tdadas
                ListBox1->Items->Add(tpahaak);    // di listbox t akan menampilkan nilai tpahaak
                ListBox1->Items->Add(tpahaas);    // di listbox t akan menampilkan nilai tpahaas
                ListBox1->Items->Add(tpahabk);    // di listbox t akan menampilkan nilai tpahabk
                ListBox1->Items->Add(tpahabs);    // di listbox t akan menampilkan nilai tpahabs
                ListBox1->Items->Add(tsayapk);    // di listbox t akan menampilkan nilai tsayapk
                ListBox1->Items->Add(tsayaps);    // di listbox t akan menampilkan nilai tsayaps
                ListBox1->Items->Add(ttempe);     // di listbox t akan menampilkan nilai ttempe
                ListBox1->Items->Add(ttahu);      // di listbox t akan menampilkan nilai ttahu
                ListBox1->Items->Add(tnasi);      // di listbox t akan menampilkan nilai tnasi


            }else if(bagian_ayam=="Sayap"){                     // jika user memilih sayap di combobox3 maka :
                sbs = sbs + StrToInt(Edit5->Text) *harga[2];    // sbs adalah  variable yang menampung array harga[2] dikali inputan user
                jl_sbs[x] =  StrToInt(Edit5->Text) ;            // setiap inputan user akan masuk ke array jl_sbs dengan indeks x

                untungSayap = untungSayap + (StrToInt(Edit5->Text)*7000);  //untungSayap adalah variable yang menampung keuntungan sayap dikali inputan user
                tsayaps= tsayaps - StrToInt(Edit5->Text) ;                 // stok di tsayaps akan berkurang sesuai inputan user

                ListBox1->Clear();                // lisbox 1 dihapus
                ListBox1->Items->Add(tdadak);     // di listbox t akan menampilkan nilai tdadak
                ListBox1->Items->Add(tdadas);     // di listbox t akan menampilkan nilai tdadas
                ListBox1->Items->Add(tpahaak);    // di listbox t akan menampilkan nilai tpahaak
                ListBox1->Items->Add(tpahaas);    // di listbox t akan menampilkan nilai tpahaas
                ListBox1->Items->Add(tpahabk);    // di listbox t akan menampilkan nilai tpahabk
                ListBox1->Items->Add(tpahabs);    // di listbox t akan menampilkan nilai tpahabs
                ListBox1->Items->Add(tsayapk);    // di listbox t akan menampilkan nilai tsayapk
                ListBox1->Items->Add(tsayaps);    // di listbox t akan menampilkan nilai tsayaps
                ListBox1->Items->Add(ttempe);     // di listbox t akan menampilkan nilai ttempe
                ListBox1->Items->Add(ttahu);      // di listbox t akan menampilkan nilai ttahu
                ListBox1->Items->Add(tnasi);      // di listbox t akan menampilkan nilai tnasi


            }else if(bagian_ayam=="Paha Bawah"){                    // jika user memilih paha bawah di combobox3 maka :
                ssp = ssp + StrToInt(Edit5->Text) *harga[3];        // ssp adalah variable yang menampung array harga[3] dikali inputan user
                jl_ssp[x] = StrToInt(Edit5->Text) ;                  // setiap inputan user akan masuk ke array jl_ssp dengan indeks x

                untungPahaB = untungPahaB + (StrToInt(Edit5->Text)*6000);   //untungPahaB adalah variable yang menampung keuntungan paha bawah dikali inputan user
                tpahabs = tpahabs - StrToInt(Edit5->Text) ;                 // stok di tpahabs akan berkurang sesuai inputan user

                ListBox1->Clear();                // lisbox 1 dihapus
                ListBox1->Items->Add(tdadak);     // di listbox t akan menampilkan nilai tdadak
                ListBox1->Items->Add(tdadas);     // di listbox t akan menampilkan nilai tdadas
                ListBox1->Items->Add(tpahaak);    // di listbox t akan menampilkan nilai tpahaak
                ListBox1->Items->Add(tpahaas);    // di listbox t akan menampilkan nilai tpahaas
                ListBox1->Items->Add(tpahabk);    // di listbox t akan menampilkan nilai tpahabk
                ListBox1->Items->Add(tpahabs);    // di listbox t akan menampilkan nilai tpahabs
                ListBox1->Items->Add(tsayapk);    // di listbox t akan menampilkan nilai tsayapk
                ListBox1->Items->Add(tsayaps);    // di listbox t akan menampilkan nilai tsayaps
                ListBox1->Items->Add(ttempe);     // di listbox t akan menampilkan nilai ttempe
                ListBox1->Items->Add(ttahu);      // di listbox t akan menampilkan nilai ttahu
                ListBox1->Items->Add(tnasi);      // di listbox t akan menampilkan nilai tnasi

                }else{                                           // komdisi lain
                ShowMessage("masukan input ");               // akan muncul pesan "masukan input"
                Edit5->Text="0";                             // edit 5 menampilkan "0"
                ComboBox2->Text="Varian Ayam";               // combobox2 menampilkan varian ayam
                ComboBox3->Text="Jenis Ayam";                // combobox3 menampilkan Jenis ayam
            }
        }


        tp = tp +StrToInt(Edit6->Text)*harga[4];                       // tp adalah variable yg menampung inputan user di edit6 dikali dengan arry indeks 4
        jl_tp[x] = StrToInt(Edit6->Text);                             // setiap inputan user akan masuk ke array jl_tp dengan indeks x
        ttempe = ttempe - StrToInt(Edit6->Text) ;                      //  stok di ttempe akan berkurang sesuai inputan user
        untungTempe = untungTempe + (StrToInt(Edit6->Text)*1500);      //untungTempe adalah variable yang menampung keuntungan tempe dikali inputan user

        th = th + StrToInt(Edit7->Text)*harga[5];                      // th adalah variabel yang menampung inputan user diedit7 dikali dengan array indeks 5
        jl_th[x] = StrToInt(Edit7->Text);                             // setiap inputan user akan masuk ke array jl_th dengan indeks x
        ttahu = ttahu - StrToInt(Edit7->Text);                         //   stok di ttahu akan berkurang sesuai inputan user
        untungTahu = untungTahu + (StrToInt(Edit7->Text)*1000);        // untungTahu adalah variable yang menampung keuntungan tahu dikali inputan user


        ns = ns + StrToInt(Edit8->Text)*harga[6];                      // ns adalah variabel yang menampung inputan user diedit8 dikali dengan array indeks 6
        jl_ns[x] = StrToInt(Edit8->Text);                             // setiap inputan user akan masuk ke array jl_ns dengan indeks x
        tnasi = tnasi - StrToInt(Edit8->Text);                         //stok di ttahu akan berkurang sesuai inputan user
        untungBeras = untungBeras + (StrToInt(Edit7->Text)*2000);     //   untungBeras adalah variable yang menampung keuntungan beras dikali inputan user

        x++;
                ListBox1->Clear();                // lisbox 1 dihapus
                ListBox1->Items->Add(tdadak);     // di listbox t akan menampilkan nilai tdadak
                ListBox1->Items->Add(tdadas);     // di listbox t akan menampilkan nilai tdadas
                ListBox1->Items->Add(tpahaak);    // di listbox t akan menampilkan nilai tpahaak
                ListBox1->Items->Add(tpahaas);    // di listbox t akan menampilkan nilai tpahaas
                ListBox1->Items->Add(tpahabk);    // di listbox t akan menampilkan nilai tpahabk
                ListBox1->Items->Add(tpahabs);    // di listbox t akan menampilkan nilai tpahabs
                ListBox1->Items->Add(tsayapk);    // di listbox t akan menampilkan nilai tsayapk
                ListBox1->Items->Add(tsayaps);    // di listbox t akan menampilkan nilai tsayaps
                ListBox1->Items->Add(ttempe);     // di listbox t akan menampilkan nilai ttempe
                ListBox1->Items->Add(ttahu);      // di listbox t akan menampilkan nilai ttahu
                ListBox1->Items->Add(tnasi);      // di listbox t akan menampilkan nilai tnasi
   

   t_harga = kbd + kbp +kbs + ksp + sbd + sbp + sbs + ssp + th + tp + ns;  // semua variable untuk pendapatan dijumlahkan dan diinisiasikan ke variabel  t_harga
     total_harga[z] = t_harga ;                                            // nilai dari t_harga dimasukan ke array total_harga dengan indeks z
     z++;                                                                  // z increment

    ListBox2->Clear();                                                     // isi data listbox2 dihapus
    ListBox2->Items->Add(t_harga);                                          // diListBox2 akan ditampilkan total harga

    Button16->Enabled=true;                                                // button 16 diaktifkan
    Edit9->SetFocus();                                                     // kursor otomatis menuju eidt 9
    }

  }

//---------------------------------------------------------------------------


void __fastcall TForm1::Button15Click(TObject *Sender) // button batal pada bagian pembelian
{

 Edit5->Enabled=true;                   // button5 diaktifkan
 ComboBox2->Text="Varian Ayam";         // combobox2 akan menampilkan "Varian Ayam"
 ComboBox3->Text="Jenis Ayam";          // combobox3 akan menampilkan "Ukuran Ayam"
 Edit5->Clear();                        // isi data di edit5 dihapus
 Edit6->Clear();                        // isi data di edit6 dihapus
 Edit7->Clear();                        // isi data di edit7 dihapus
 Edit8->Clear();                        //  isi data di edit8 dihapus
 Button13->Enabled=true;                // button13 diaktifkan
 ListBox2->Clear();                     // isi data di edit2 dihapus
 Edit5->Text="0";                       // edit 5 menampilkan "0"
 Edit6->Text="0";                        // edit 6 menampilkan "0"
 Edit7->Text="0";                        // edit 7 menampilkan "0"
 Edit8->Text="0";                         // edit 8 menampilkan "0"

 }
//---------------------------------------------------------------------------


void __fastcall TForm1::Button16Click(TObject *Sender)    // button bayar
{
      bayar =StrToInt(Edit9->Text);                 // bayar adalah variabel yang menampung inputab du edit9->teks

    if(bayar<total_harga[z-1]){                     // jika  uang yang dibayar kecil dari total_harga [z-1 artinya setiap indeks z dikurangi 1]
        ShowMessage("uang masih kurang ");          // tampil pesan uang masih kurang
        Edit9->Clear();             //              // isi data di eidt 9 dihapus
    }else {                                         // kondisi lain
        kembalian = bayar - total_harga[z-1];       // variable kembalian menampung uang yang dibayar - total harga[z-1 artinya setiap indeks z dikurangi 1]
        ListBox42->Items->Add(kembalian);           // nilai dari kembalian akan ditampilkan di listbox42

        ListBox4->Clear();                          // isi data dari listbox4 di hapus
        ListBox5->Clear();                          // isi data dari ListBox5 di hapus
        ListBox6->Clear();                          // isi data dari listbox6 di hapus
        ListBox7->Clear();                          // isi data dari listbox7 di hapus
        ListBox8->Clear();                          // isi data dari listbox8 di hapus
        ListBox9->Clear();                          // isi data dari listbox9 di hapus
        ListBox10->Clear();                         // isi data dari listbox10 di hapus
        ListBox11->Clear();                         // isi data dari listbox11 di hapus
        ListBox12->Clear();                         // isi data dari listbox12 di hapus
        ListBox13->Clear();                         // isi data dari listbox13 di hapus
        ListBox14->Clear();                         // isi data dari listbox14 di hapus
        ListBox15->Clear();                         // isi data dari listbox15 di hapus
        ListBox16->Clear();                         // isi data dari listbox16 di hapus
        ListBox17->Clear();                         // isi data dari listbox17 di hapus

            for(i=0; i<z ; i++){                                // untuk i = 0 , i kecil dari z ; i increment adalah perulangan untuk nilai array
              ListBox17->Items->Add(total_harga[i]);            // nilai perulangan total harga dengan indeks 1 ditampilkan di listbox 7
            }
            for(i=0;i<x ;i++){                                          // untuk i = 0 , i kecil dari x ; i increment adalah perulangan untuk nilai array
                ListBox4->Items->Add(i+1);                              // dilistbox 4 akan menampilkan increment dari no dari 1 dengan batas x
                ListBox6->Items->Add(jl_kbd[i]);                        // dilistbox 6 akan menampilkan nilai dari   jl_kbd dengan increment i
                ListBox7->Items->Add(jl_kbp[i]);                        // dilistbox 7 akan menampilkan nilai dari   jl_kbp dengan increment i
                ListBox8->Items->Add(jl_kbs[i]);                        // dilistbox 8 akan menampilkan nilai dari   jl_kbs dengan increment i
                ListBox9->Items->Add(jl_ksp[i]);                        // dilistbox 9 akan menampilkan nilai dari   jl_ksp dengan increment i
                ListBox10->Items->Add(jl_sbd[i]);                       // dilistbox 10 akan menampilkan nilai dari   jl_sbd dengan increment i
                ListBox11->Items->Add(jl_sbp[i]);                       // dilistbox 11 akan menampilkan nilai dari   jl_sbp dengan increment i
                ListBox12->Items->Add(jl_sbs[i]);                       // dilistbox 12 akan menampilkan nilai dari   jl_sbs dengan increment i
                ListBox13->Items->Add(jl_ssp[i]);                       // dilistbox 13 akan menampilkan nilai dari   jl_ssp dengan increment i
                ListBox14->Items->Add(jl_th[i]);                        // dilistbox 14 akan menampilkan nilai dari   jl_th dengan increment i
                ListBox15->Items->Add(jl_tp[i]);                        // dilistbox 15 akan menampilkan nilai dari   jl_tp dengan increment i
                ListBox16->Items->Add(jl_ns[i]);                        // dilistbox 16 akan menampilkan nilai dari   jl_ns dengan increment i

                }

            for(i=0; i<y ; i++){
                ListBox5->Items->Add(pembeli[i]);                  // untuk i = 0 , i kecil dari y ; i increment adalah perulangan untuk nilai array
                }                                                   //nilai perulangan pembeli dengan indeks 1 ditampilkan di listbox 5

          pendapatan = 0;                                           // nilai pendapatan  = 0
          for (i=0 ;i<z ; i++){                                     // untuk i = 0 , i kecil dari y ; i increment adalah perulangan untuk nilai array
            pendapatan = pendapatan + total_harga[i];               // varibel pendaptan menampung pendapatan di + array total harga dengan indeks i
          }

          for(i=0;i<x;i++){                                      // untuk i = 0 , i kecil dari x ; i increment adalah perulangan untuk nilai array
            tkbd = tkbd +jl_kbd[i];                              // tkbd adalah variable yang menampung tkbd + array   jl_kbd dengan indeks i
            tkbp = tkbp +jl_kbp[i];                              // tkbp adalah variable yang menampung tkbp + array   jl_kbp dengan indeks i
            tkbs = tkbs +jl_kbs[i];                              // tkbs adalah variable yang menampung tkbs + array   jl_kbs dengan indeks i
            tksp = tksp +jl_ksp[i];                              // tksp adalah variable yang menampung tksp + array   jl_ksp dengan indeks i
            tsbd = tsbd +jl_sbd[i];                              // tsbd adalah variable yang menampung tsbd + array   jl_sbd dengan indeks i
            tsbp = tsbp +jl_sbp[i];                              // tsbp adalah variable yang menampung tsbp + array   jl_sbp dengan indeks i
            tsbs = tsbs +jl_sbs[i];                              // tsbs adalah variable yang menampung tsbs + array   jl_sbs dengan indeks i
            tssp = tssp +jl_ssp[i];                              // tssp adalah variable yang menampung tssp + array   jl_ssp dengan indeks i
            tth = tth +jl_th[i];                                 // tth adalah variable yang menampung tth + array   jl_th dengan indeks i
            ttp = ttp +jl_tp[i];                                 // ttp adalah variable yang menampung ttp + array   jl_tp dengan indeks i
            tns = tns +jl_ns[i];                                 // tns adalah variable yang menampung tns + array   jl_ns dengan indeks i
          }


     ListBox30->Clear();                                        // isi data di listbox30 dihapus
     ListBox31->Clear();                                         // isi data di listbox31 dihapus
     ListBox32->Clear();                                        // isi data di listbox30 dihapus
     ListBox33->Clear();                                        // isi data di listbox30 dihapus
     ListBox34->Clear();                                        // isi data di listbox30 dihapus
     ListBox35->Clear();                                         // isi data di listbox30 dihapus
     ListBox36->Clear();                                          // isi data di listbox30 dihapus
     ListBox37->Clear();                                         // isi data di listbox30 dihapus
     ListBox38->Clear();                                         // isi data di listbox30 dihapus
     ListBox39->Clear();                                         // isi data di listbox30 dihapus
     ListBox40->Clear();                                        // isi data di listbox30 dihapus
     ListBox41->Clear();                                         // isi data di listbox30 dihapus
     ListBox43->Clear();                                         // isi data di listbox30 dihapus

     ListBox30->Items->Add(tkbd);                               // nilai tkbd akan tampil di listbox 30
     ListBox31->Items->Add(tkbp);                                // nilai tkbp akan tampil di ListBox31
     ListBox32->Items->Add(tkbs);                               // nilai tkbs akan tampil di listbox 32
     ListBox33->Items->Add(tksp);                                // nilai tksp akan tampil di listbox 33
     ListBox34->Items->Add(tsbp);                               // nilai tsbp akan tampil di listbox 34
     ListBox35->Items->Add(tsbd);                                // nilai tsbd akan tampil di listbox 35
     ListBox36->Items->Add(tsbs);                               // nilai tsbs akan tampil di listbox 36
     ListBox37->Items->Add(tssp);                                // nilai tssp akan tampil di listbox 37
     ListBox38->Items->Add(tth);                                  // nilai ttp akan tampil di listbox 38
     ListBox39->Items->Add(ttp);                                 // nilai tth akan tampil di listbox 39
     ListBox40->Items->Add(tns);                                 // nilai tns akan tampil di listbox 40
     ListBox41->Items->Add(pendapatan);                          // nilai pendapatan akan tampil di listbox 41

     untungTotal= untungDada+untungPahaA+untungPahaB+untungSayap+untungTempe+untungTahu+untungBeras;      //untung totoal adalah variabel yang menampung semua nilai keuntungan dimasing masing varible untung
     ListBox43->Items->Add(untungTotal);                                       // nilai untungTOtal akan ditampilkan di listbox 43
      ayamTerjual = tkbd+tkbp+tkbs+tksp+tsbd+tsbp+tsbs+tssp;                   // ayam terjual adlah variabel yang menampung semua total ayam yang terjual pada hari penjualan
    tahuTerjual = tth;                                                         // tahu terjual adalah variabel yang menampung  total tahu yang terjual
    tempeTerjual= ttp;                                                         //tempe terjual adalah variabel yang menampung totsal tempe yang terjual
    nasiTerjual = tns;                                                         //nasiterjual adalah variabela yang menampy=ung total porsi nasi yang terjual
    totalSemua =ayamTerjual + tempeTerjual + tahuTerjual + nasiTerjual;        // total semua adalah variabael yang menampung total semua penjualan dihari penjualan

    ListBox46->Clear();                                                        // isi data di listbox46 di hapus
    ListBox46->Items->Add(totalSemua);                                         // nilai dari toal semua akan di tampilkan di listbox46

    Button4->Enabled=true;                                                     //button4 di aktifkan
    Button9->Enabled=true;                                                     //button9 di aktifkan
    Button18->Enabled=true;                                                    //button18 di aktifkan
    Button19->Enabled=true;                                                     //button19 di aktifkan
    Button16->Enabled=false;                                                   //button16 di aktifkan
    GroupBox11->Enabled=true;                                                  //grupbox11 di aktifkan

    }
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)     // button pesan berikut
{
    kbd = 0; kbp=0;kbs=0;ksp=0;sbd=0;sbp=0;sbs=0;ssp=0;th=0;tp=0;ns=0;            // nilai dari kbd kbp ksp sbd sbp sbs ssp th tp dan ns = 0
    tkbd= 0; tkbp=0;tkbs=0;tksp=0;tsbd=0;tsbp=0;tsbs=0;tssp=0;tth=0;ttp=0;tns=0; // nilai dari total yang ditas = 0
    Button7->Enabled=true;                                                      // button 7 diaktifkan
        Edit4->Enabled=true;                                                    // edit 4 diaktifkan
        Edit5->Enabled=true;                                                    // edit5 diaktifkan
        Edit4->SetFocus();                                                      // kursor otomatis menuju edit4
    ComboBox2->ClearSelection();                                                //pilihan  combobox 2 dihapus
    ComboBox3->ClearSelection();                                                // pilihan di kombobox 3 dihapus
    ComboBox2->Text="Varian Ayam";                                              // combobox2 akan menampilkan "Varian Ayam"
    ComboBox3->Text="Jenis Ayam";                                               // combobox3 akan menampilkan "Ukuran Ayam"
        Edit5->Text="0";                                                        // edit 5 menampilkan = 0
        Edit6->Text="0";                                                        // edit 6 menampilkan = 0
        Edit7->Text="0";                                                        // edit 7 menampilkan
        Edit8->Text="0";                                                        // edit 8 menampilkan

    Button15->Enabled=true;                                                     // button 15 diaktifkan
    Button13->Enabled=true;                                                     // button 13 diaktifkan
        ListBox2->Clear();                                                      // isi data di listbox 2 dihapus
        Edit9->Clear();                                                         // isi data di edit 9 dihapus
        ListBox42->Clear();                                                     // isi data di listbox 42 dihapus
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button18Click(TObject *Sender)// button cari
{
ListBox3->Clear();                                            //isi data di listbox 3 dihapus
ListBox19->Clear();                                           //isi data di listbox 19 dihapus
ListBox20->Clear();                                           //isi data di listbox 20 dihapus
ListBox21->Clear();                                           //isi data di listbox 21 dihapus
ListBox22->Clear();                                          //isi data di listbox 22 dihapus
ListBox23->Clear();                                         //isi data di listbox 23 dihapus
ListBox24->Clear();                                          //isi data di listbox 24 dihapus
ListBox25->Clear();                                         //isi data di listbox 25 dihapus
ListBox26->Clear();                                          //isi data di listbox 26 dihapus
ListBox27->Clear();                                          //isi data di listbox 27 dihapus
ListBox28->Clear();                                          //isi data di listbox 28 dihapus
ListBox29->Clear();                                          //isi data di listbox 29 dihapus

    bool cari = false;                                       //bool cari bernilai false
        nama=Edit10->Text;                                   // nilai yang ada di edit 10 akan tersimpan di var nama
        int a=0;                                             // deklarasi int a = 0
        while(a<x){                                          // ketika a<x
            if(pembeli[a]==nama){                            // jika nama sama dengan nilai array pembeli dg indeks a
                cari = true;                                 // cari bernilai true
                ShowMessage("data ditemukan");               // tampil pesan data ditemukan
                ListBox19->Items->Add(jl_kbd[a]);            // nilai array jl_kbd dengan indeks a akan tampil di listbox 19
                ListBox20->Items->Add(jl_kbp[a]);            // nilai array jl_kbp dengan indeks a akan tampil di listbox 20
                ListBox21->Items->Add(jl_kbs[a]);            // nilai array jl_kbs dengan indeks a akan tampil di listbox 21
                ListBox22->Items ->Add(jl_ksp[a]);           // nilai array jl_ksp dengan indeks a akan tampil di listbox 22
                ListBox23->Items->Add(jl_sbd[a]);            // nilai array jl_sbd dengan indeks a akan tampil di listbox 23
                ListBox24->Items->Add(jl_sbp[a]);            // nilai array jl_sbp dengan indeks a akan tampil di listbox 24
                ListBox25->Items->Add(jl_sbs[a]);            // nilai array jl_sbs dengan indeks a akan tampil di listbox 25
                ListBox3->Items->Add(jl_ssp[a]);             // nilai array jl_ssp dengan indeks a akan tampil di listbox 3
                ListBox26->Items->Add(jl_th[a]);             // nilai array jl_th dengan indeks a akan tampil di listbox 26
                ListBox27->Items->Add(jl_tp[a]);             // nilai array jl_tp dengan indeks a akan tampil di listbox 27
                ListBox28->Items->Add(jl_ns[a]);             // nilai array jl_ns dengan indeks a akan tampil di listbox 28
                ListBox29->Items->Add(total_harga[a]);       // nilai array total_harga dengan indeks a akan tampil di listbox 29
                }
                a++ ;                                        // a increment;
        }
            if(cari==false){                                 // jika cari == false
                cari=false ;                                 // cari bernilai false
                ShowMessage("datanya gada");                 // tampil pesan datanya gada
                }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button19Click(TObject *Sender)// button reset
{
Edit10->Clear();             // isidata di edit10 dihapus
ListBox3->Clear();           // isi data di listbox 3 dihapus
ListBox19->Clear();          // isi data di listbox 19 dihapus
ListBox20->Clear();          // isi data di listbox 20 dihapus
ListBox21->Clear();          // isi data di listbox 21 dihapus
ListBox22->Clear();          // isi data di listbox 22 dihapus
ListBox23->Clear();          // isi data di listbox 23 dihapus
ListBox24->Clear();          // isi data di listbox 24 dihapus
ListBox25->Clear();          // isi data di listbox 25 dihapus
ListBox26->Clear();          // isi data di listbox 26 dihapus
ListBox27->Clear();          // isi data di listbox 27 dihapus
ListBox28->Clear();          // isi data di listbox 28 dihapus
ListBox29->Clear();          // isi data di listbox 29 dihapus
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender) //button reset all
{
Edit1->Clear();                                     // isi data di edit 1 dihapus
Edit2->Clear();                                     // isi data di edit 2 dihapus
Edit3->Clear();                                     // isi data di edit 3 dihapus
Edit12->Clear();                                    // isi data di edit 12 dihapus
Edit1->Enabled=true;                                // button 1 diaktifkan
Edit2->Enabled=true;                                // button 2 diaktifkan
Edit3->Enabled=true;                                // button 3 diaktifkan
Edit12->Enabled=true;                               // button 12 diaktifkan
Edit1->Text="0";                                    // edit 1 menampilkan "0"
Edit2->Text="0";                                    // edit 2 menampilkan "0"
Edit3->Text="0";                                    // edit 3 menampilkan "0"
Edit12->Text="0";                                   // edit 12 menampilkan "0"
Edit11->Clear();
Button2->Enabled=true;                              // button 2 diaktifkan
ListBox1->Clear();                                  // isi data di edit 12 dihapus
Edit4->Clear();                                     // isi data di edit 7 dihapus
Button7->Enabled=true;                              // button 7 diaktifkan
ComboBox2->ClearSelection();                        // menghapus pilihan di combobox2
ComboBox3->ClearSelection();                        // menghapus pilihan di combobox3
ComboBox2->Text="Varian Ayam";                      // combobox2 menampilkan "varian ayam"
ComboBox3->Text="Jenis Ayam";                       // combobox3 menampilkan jenis ayam
Edit5->Clear();                                     // isi data di edit 5 dihapus

Edit6->Clear();                                     // isi data di edit 6 dihapus
Edit7->Clear();                                     // isi data di edit 7 dihapus
Edit8->Clear();                                     // isi data di edit 8 dihapus
Button13->Enabled=true;                             // button 13 diaktifkan
ListBox2->Clear();                                  // isi data di listbox 2 dihapus
Button15->Enabled=true;                             // button 15 diaktifkan
Edit9->Clear();                                     // isi data di edit 9 dihapus
ListBox42->Clear();                                 // isi data di listbox 42 dihapus
Button9->Enabled=true;                              // button 9 diaktifkan
Button16->Enabled=true;                             // button 16 diaktifkan
        ListBox4->Clear();                          // isi data dari listbox4 di hapus
        ListBox5->Clear();                          // isi data dari ListBox5 di hapus
        ListBox6->Clear();                          // isi data dari listbox6 di hapus
        ListBox7->Clear();                          // isi data dari listbox7 di hapus
        ListBox8->Clear();                          // isi data dari listbox8 di hapus
        ListBox9->Clear();                          // isi data dari listbox9 di hapus
        ListBox10->Clear();                         // isi data dari listbox10 di hapus
        ListBox11->Clear();                         // isi data dari listbox11 di hapus
        ListBox12->Clear();                         // isi data dari listbox12 di hapus
        ListBox13->Clear();                         // isi data dari listbox13 di hapus
        ListBox14->Clear();                         // isi data dari listbox14 di hapus
        ListBox15->Clear();                         // isi data dari listbox15 di hapus
        ListBox16->Clear();                         // isi data dari listbox16 di hapus
        ListBox17->Clear();                         // isi data dari listbox17 di hapus
Button18->Enabled=true;               // button 18 diaktifkan
Button19->Enabled=true;               // button 19 diaktifkan
Button4->Enabled=true;               // button 4 diaktifkan
Edit10->Clear();             // isidata di edit10 dihapus
ListBox3->Clear();           // isi data di listbox 3 dihapus
ListBox19->Clear();          // isi data di listbox 19 dihapus
ListBox20->Clear();          // isi data di listbox 20 dihapus
ListBox21->Clear();          // isi data di listbox 21 dihapus
ListBox22->Clear();          // isi data di listbox 22 dihapus
ListBox23->Clear();          // isi data di listbox 23 dihapus
ListBox24->Clear();          // isi data di listbox 24 dihapus
ListBox25->Clear();          // isi data di listbox 25 dihapus
ListBox26->Clear();          // isi data di listbox 26 dihapus
ListBox27->Clear();          // isi data di listbox 27 dihapus
ListBox28->Clear();          // isi data di listbox 28 dihapus
ListBox29->Clear();          // isi data di listbox 29 dihapus
   ListBox30->Clear();                                        // isi data di listbox30 dihapus
     ListBox31->Clear();                                         // isi data di listbox31 dihapus
     ListBox32->Clear();                                        // isi data di listbox30 dihapus
     ListBox33->Clear();                                        // isi data di listbox30 dihapus
     ListBox34->Clear();                                        // isi data di listbox30 dihapus
     ListBox35->Clear();                                         // isi data di listbox30 dihapus
     ListBox36->Clear();                                          // isi data di listbox30 dihapus
     ListBox37->Clear();                                         // isi data di listbox30 dihapus
     ListBox38->Clear();                                         // isi data di listbox30 dihapus
     ListBox39->Clear();                                         // isi data di listbox30 dihapus
     ListBox40->Clear();                                        // isi data di listbox30 dihapus
     ListBox41->Clear();                                         // isi data di listbox30 dihapus
     ListBox43->Clear();                                         // isi data di listbox30 dihapus
     ListBox46->Clear();                                         // isi data di listbox30 dihapus
     ListBox45->Clear();
     ListBox44->Clear();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
    Form2->Show();                                                                                       // menampilkan form 2
    Form2->ListBox1->Clear();                                                                            // mengahpus data di form2 listbox 1
    Form2->ListBox1->Items->Add("================================================================= ");
    Form2->ListBox1->Items->Add("                                      ADO CHICKEN             " );
    Form2->ListBox1->Items->Add("          Jl.Kampung Baru NO. 10, Pariaman-Sumatera Barat       ");
    Form2->ListBox1->Items->Add("================================================================= ");
    Form2->ListBox1->Items->Add("                          JAM BUKA : 10:00 - 22:00 WIB             ");
    Form2->ListBox1->Items->Add("");
    Form2->ListBox1->Items->Add("  Nama Pemesan   :  " + nama);
      if(rasa_ayam=="Ayam Krispi"){
            if(bagian_ayam=="Dada"){
    Form2->ListBox1->Items->Add("  Ayam Krispi Dada ");
    Form2->ListBox1->Items->Add(   "   "+ Edit5->Text +  " potong    " + " x    Rp.13000  =  " + kbd);
            }
            else if(bagian_ayam=="Paha Atas"){
    Form2->ListBox1->Items->Add("  Ayam Krispi Paha Atas ");
    Form2->ListBox1->Items->Add(   "   "+ Edit5->Text +  " potong    " + " x    Rp.12500  =  " + kbp);
            }
            else if(bagian_ayam=="Sayap"){
    Form2->ListBox1->Items->Add("  Ayam Krispi Sayap     ");
    Form2->ListBox1->Items->Add(   "   "+ Edit5->Text +  " potong    " + " x    Rp.12000  =  " + kbs);
            }
            else if(bagian_ayam=="Paha Bawah"){
    Form2->ListBox1->Items->Add("  Ayam Krispi Paha Bawah  ");
    Form2->ListBox1->Items->Add(   "   "+ Edit5->Text +  " potong    " + " x    Rp.11000  =  " + ksp);
            }
      }
      else if (rasa_ayam=="Ayam Spicy"){
            if(bagian_ayam=="Dada"){
    Form2->ListBox1->Items->Add("  Ayam Spicy  Dada ");
    Form2->ListBox1->Items->Add(   "   "+ Edit5->Text +  " potong    " + " x    Rp.13000  =  " + sbd);
            }
            else if(bagian_ayam=="Paha Atas"){
    Form2->ListBox1->Items->Add("  Ayam Spicy Paha Atas  ");
    Form2->ListBox1->Items->Add(   "   "+ Edit5->Text +  " potong    " + " x    Rp.12500  =  " + sbp);
            }
            else if(bagian_ayam=="Sayap"){
    Form2->ListBox1->Items->Add("  Ayam Spicy Sayap     ");
    Form2->ListBox1->Items->Add(   "   "+ Edit5->Text +  " potong    " + " x    Rp.12000  =  " + sbs);
            }
            else if(bagian_ayam=="Paha Bawah"){
    Form2->ListBox1->Items->Add("  Ayam Spicy Paha Bawah ");
    Form2->ListBox1->Items->Add(   "   "+ Edit5->Text +  " potong    " + " x    Rp.11000  =  " + ssp);
            }
       }
        if(Edit6->Text != "0" && Edit7->Text != "0" && Edit8->Text != "0" ){
    Form2->ListBox1->Items->Add("  Tempe   ");
    Form2->ListBox1->Items->Add(   "   "+ Edit6->Text +  " buah       " + " x    Rp.3000   =  " + tp);
    Form2->ListBox1->Items->Add("  Tahu    ");
    Form2->ListBox1->Items->Add(   "   "+ Edit7->Text +  " buah       " + " x    Rp.2500   =  " + th);
    Form2->ListBox1->Items->Add("  Nasi   ");
    Form2->ListBox1->Items->Add(   "   "+ Edit8->Text +  " porsi        " + " x    Rp.4000   =  " + ns);
         }
        else if(Edit6->Text != "0" && Edit7->Text == "0" && Edit8->Text == "0" ){
    Form2->ListBox1->Items->Add("  Tempe   ");
    Form2->ListBox1->Items->Add(   "   "+ Edit6->Text +  " buah       " + " x    Rp.3000   =  " + tp);
         }
        else if(Edit6->Text == "0" && Edit7->Text != "0" && Edit8->Text == "0"){
    Form2->ListBox1->Items->Add("  Tahu    ");
    Form2->ListBox1->Items->Add(   "   "+ Edit7->Text +  " buah       " + " x    Rp.2500   =  " + th);
        }
        else if(Edit6->Text == "0" && Edit7->Text == "0" && Edit8->Text != "0"){
    Form2->ListBox1->Items->Add("  Nasi   ");
    Form2->ListBox1->Items->Add(   "   "+ Edit8->Text +  " porsi        " + " x    Rp.4000   =  " + ns);
        }
        else if (Edit6->Text != "0" && Edit7->Text != "0" && Edit8->Text == "0"){
    Form2->ListBox1->Items->Add("  Tempe   ");
    Form2->ListBox1->Items->Add(   "   "+ Edit6->Text +  " buah       " + " x    Rp.3000   =  " + tp);
    Form2->ListBox1->Items->Add("  Tahu    ");
    Form2->ListBox1->Items->Add(   "   "+ Edit7->Text +  " buah       " + " x    Rp.2500   =  " + th);
        }
        else if (Edit6->Text == "0" && Edit7->Text != "0" && Edit8->Text != "0"){
    Form2->ListBox1->Items->Add("  Tahu    ");
    Form2->ListBox1->Items->Add(   "   "+ Edit7->Text +  " buah       " + " x    Rp.2500   =  " + th);
    Form2->ListBox1->Items->Add("  Nasi   ");
    Form2->ListBox1->Items->Add(   "   "+ Edit8->Text +  " porsi        " + " x    Rp.4000   =  " + ns);
        }
        else if (Edit6->Text != "0" && Edit7->Text == "0" && Edit8->Text != "0"){
    Form2->ListBox1->Items->Add("  Tempe   ");
    Form2->ListBox1->Items->Add(   "   "+ Edit6->Text +  " buah       " + " x    Rp.3000   =  " + tp);
    Form2->ListBox1->Items->Add("  Nasi   ");
    Form2->ListBox1->Items->Add(   "   "+ Edit8->Text +  " porsi        " + " x    Rp.4000   =  " + ns);
        }
        else{
     Form2->ListBox1->Items->Add("  No Toping");
        }


    Form2->ListBox1->Items->Add("");
    Form2->ListBox1->Items->Add("                        Total              : "+ IntToStr(t_harga) );
    Form2->ListBox1->Items->Add("                        Bayar             : "+ IntToStr(bayar) );
    Form2->ListBox1->Items->Add("                        Kembalian      : "+ IntToStr(kembalian));
    Form2->ListBox1->Items->Add("----------------------------------------------------------------------------------------------------------------");
    Form2->ListBox1->Items->Add("");
    Form2->ListBox1->Items->Add("");
    Form2->ListBox1->Items->Add("                                  SELAMAT MENIKMATI                       ");
    Form2->ListBox1->Items->Add("                  TERIMA KASIH ATAS KUNJUNGAN ANDA              ");

 Form2->ListBox1->Items->Add("======================================================================");

}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button3Click(TObject *Sender)         // button restok
{

         ListBox18->Clear();                                 // isi data di listbox 18 dihapus
        for(i =0; i<11; i++) {                               // perulangan
            ListBox18->Items->Add(stok[i]);                  //nilai dari array stok dengan indeks i akan tmpil di listbox 18
        }
              kulkas = kulkas - StrToInt(Edit1->Text);       // var kulkas menampung  kulkas dikurangi inputan user
              ListBox45->Clear();                            // isi data di listbox45 di hapus
              ListBox45->Items->Add(kulkas);                 // nilai dari kulkas ditampilkan di listbox 45
            tdadak =  tdadak  + StrToInt(Edit1->Text);       // tdadak adalh var yang menampung nilai tdadak + inputan user
            tpahaak= tpahaak +  StrToInt(Edit1->Text);       // tpahaak adalh var yang menampung nilai tpahaak + inputan user
            tsayapk=  tsayapk +  StrToInt(Edit1->Text);      // tsayapk adalh var yang menampung nilai tsayapk + inputan user
            tpahabk = tpahabk +  StrToInt(Edit1->Text);      // tpahabk adalh var yang menampung nilai tpahabk + inputan user
            tpahaas =tpahaas+  StrToInt(Edit1->Text);        // tpahaas adalh var yang menampung nilai tpahaas + inputan user
            tdadas = tdadas+  StrToInt(Edit1->Text);         // tdadas adalh var yang menampung nilai tdadas + inputan user
            tsayaps= tsayaps+  StrToInt(Edit1->Text);         // tsayaps adalh var yang menampung nilai tsayaps + inputan user
            tpahabs =tpahabs +  StrToInt(Edit1->Text);       // tpahabs adalh var yang menampung nilai tpahabs + inputan user
            ttahu   =  ttahu +  StrToInt(Edit3->Text)*15 ;   // ttahu adalh var yang menampung nilai ttahu + inputan user
            ttempe  = ttempe+  StrToInt(Edit2->Text)*15  ;  // ttempe adalh var yang menampung nilai ttempe + inputan user
            tnasi   =tnasi +  StrToInt(Edit12->Text)*5*20 ;  // tnasi adalh var yang menampung nilai tnasi + inputan user

                 ListBox1->Clear();                // lisbox 1 dihapus
                ListBox1->Items->Add(tdadak);     // di listbox t akan menampilkan nilai tdadak
                ListBox1->Items->Add(tdadas);     // di listbox t akan menampilkan nilai tdadas
                ListBox1->Items->Add(tpahaak);    // di listbox t akan menampilkan nilai tpahaak
                ListBox1->Items->Add(tpahaas);    // di listbox t akan menampilkan nilai tpahaas
                ListBox1->Items->Add(tpahabk);    // di listbox t akan menampilkan nilai tpahabk
                ListBox1->Items->Add(tpahabs);    // di listbox t akan menampilkan nilai tpahabs
                ListBox1->Items->Add(tsayapk);    // di listbox t akan menampilkan nilai tsayapk
                ListBox1->Items->Add(tsayaps);    // di listbox t akan menampilkan nilai tsayaps
                ListBox1->Items->Add(ttempe);     // di listbox t akan menampilkan nilai ttempe
                ListBox1->Items->Add(ttahu);      // di listbox t akan menampilkan nilai ttahu
                ListBox1->Items->Add(tnasi);      // di listbox t akan menampilkan nilai tnasi
       Button3->Enabled=false;                    // button 3 dinonaktifkan
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button10Click(TObject *Sender)   //button close
{
Application->Terminate();      // aplikasi di close

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button8Click(TObject *Sender) // button stok kandang
{
stock = StrToInt(Edit11->Text);                 // stock adalah var yang menampung
if (stock % 20 ==0){                            // jika stok mod 20 == 0
if(kandang + stock <= 300){                     // jika kandang + stok kecil dari 200
     kandang =   kandang + stock;               // var kandang menampung kandan + stok
     wadah[a] = stock;                          // nilai stok disimpan di array wadah indeks a
     a++;                                       // increment a
     ListBox44->Clear();                        // isi data di listbox 44 dihapus
     for (i=0 ; i<a ; i++){                     // perulanagan
          ListBox44->Items->Add(wadah[i]);      // listbox 44 menampilkan array wadah indeks i
     }
}else if(kandang + stock > 300){                // jika kandang + stok > 300
     ShowMessage("kandang penuh");               //tampil pesan kandang penuh
}
}else{                                          // selain itu
  ShowMessage("harus kelipatan 20")  ;          // tampil pesan harus kelipatan 20
}
Edit11->Clear();                                // edi11 datanya dihpus
Button11->Enabled=true;                         // button 11 diaktifkan

}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button14Click(TObject *Sender)  //button ascending
{
int asce ;                           // deklarasi var lokal
  ListBox44->Clear();                        // isi data listbox44 dihapus
for(i = 0 ;i<a-1 ; i++ ){                    // perulangan
     for (int j =i+1 ; j<a ; j++){           // perulangan
       if (wadah[i]>wadah[j]){               // jika nilai wadah indeks i > nilai wadah indeks j
        asce = wadah[i];                     // wadah indeks i = asce
        wadah[i]= wadah [j];                 // wadag indeks i = wadah indeks j
        wadah [j] =asce ;                    // wadah indeks j = asce
       }
     }
}

 for (i =0 ; i<a ; i++ ){                    // perulangan
  ListBox44->Items->Add(wadah[i]);           // menampilkan nilai array wadah indeks i di listbox 44
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)  // button descending
{
int desce ;                      // deklarasi var lokal
  ListBox44->Clear();                     // isi data listbox44 dihapus
for(i = 0 ;i<a-1 ; i++ ){                // perulangan
     for (int j =i+1 ; j<a ; j++){       // perulangan
       if (wadah[i]<wadah[j]){          // jika nilai wadah indeks i < nilai wadah indeks j
        desce = wadah[i];               // wadah indeks i = desce
        wadah[i]= wadah [j];            // wadag indeks i = wadah indeks j
        wadah [j] =desce ;              // wadah indeks j = desce
       }
     }
}
 for (i =0 ; i<a ; i++ ){             // perulangan
  ListBox44->Items->Add(wadah[i]);    // menampilkan nilai array wadah indeks i di listbox 44
 }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button11Click(TObject *Sender)     // button add to freezer
{
Button2->Enabled=true;                                     // button 2 diaktifkan
int pakai = wadah [0];                                     // deklarasi var pakai = wadah indeks 0

if(kulkas + pakai <= 100){                                 //jika kulkas + pakai <= 100
 kulkas = kulkas + pakai;                                  // nilai var kulkas + nilai var pakai
 pakai = pakai - wadah[0];                                 // nilai pakai dikurangin nilai array wadah indek 0

 for (int k = 0 ; k<a; k++){                               // perulangan
 wadah [k] = wadah[k+1];                                   // wadah [k] = wadah[k+1]
 }
 a--;                                                      // a decrement
 kandang = kandang - pakai;                                // nilai kandang dikurangi var pakai
}
 else if (kulkas + pakai > 100){                           // jika kulkas + pakai > 100
  wadah[0] = wadah[0] - (100 - kulkas);                    // nilai array indeks 0 dikurangi 100 - nilai kulkas
  kulkas = 100;                                            // inisiasi kulkas = 100
  kandang = kandang - (100 - kulkas);                      // nilai kandang di kurangi 100 - nilai kulkas
  ShowMessage("kulkas penuh");                             // tampilkan pesan kulkas penuh
 }
 ListBox45->Clear();                                       // isi data di listbox 45 di hapus
 ListBox45->Items->Add(kulkas);                            // listbox 45 menampilkan nilai kulkas

    ListBox44->Clear();                                    // isi nilai listbox 44 dihapus
   for(int r = 0; r<a ; r++){                              // perulangan
     ListBox44->Items->Add(wadah[r]);                      // menampilkan nilai wadah indeks r di listbox 44
   }
}
//---------------------------------------------------------------------------

                                                                                                 // button list harga
void __fastcall TForm1::Button17Click(TObject *Sender)
{
Form4->List->Clear();                                                                                   // form 4 list di hapus datanta
Form4->Show();                                                                                          // menanmpilkan form 4
Form4->List->Items->Add("                   DAFTAR MENU ADO CHIKEN                  ");                //   menanmpilkan daftar menu ado chiken
Form4->List->Items->Add("=====================================================");                     // menampilkan    ===========================================
Form4->List->Items->Add("");                                                                          // menampilkan spasi line
Form4->List->Items->Add("Dada Ayam (Krispi/Spicy)                                RP 13000");          // menampilkan   Dada Ayam (Krispi/Spicy)                                RP 13000
Form4->List->Items->Add("Paha Atas Ayam (Krispi/Spicy)                         RP 12500");             // menampilkan   paha Atas Ayam (Krispi/Spicy)                         RP 12500
Form4->List->Items->Add("Sayap Ayam (Krispi/Spicy)                                RP 12000");           // menampilkan Sayap Ayam (Krispi/Spicy)                                RP 12000
Form4->List->Items->Add("Paha Bawah Ayam (Krispi/Spicy)                     RP 11000");                  // menampilkan   aha Bawah Ayam (Krispi/Spicy)                     RP 11000
Form4->List->Items->Add("Tahu                                                                RP 3000");   // menampilkan  Tahu                                                                RP 3000
Form4->List->Items->Add("Tempe                                                              RP 2500");    // menampilkan   Tempe                                                              RP 2500
Form4->List->Items->Add("Nasi                                                                  RP 4000"); // menampilkan Nasi                                                                  RP 4000"
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
Form3->Show();
}

//---------------------------------------------------------------------------



