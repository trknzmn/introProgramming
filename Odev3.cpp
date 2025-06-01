// Ödev No: 3
// Ödev Konusu: Sipariş Planlama

#include <iostream>
#include <fstream>
#include <iomanip>
#include <clocale>
using namespace std;
string karakter(char);
int kalan();
void karistirma();

int no[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int talep[10];
int *bayiler;

int main()
{
    setlocale(LC_ALL, "Turkish"); // Türkçe karakterleri ekleme

    // 0-100 arası rastgele talep sayısı belirleme
    srand(time(0));

    for(int i = 0; i < 10; i++)
        talep[i] = rand() %101;

    bayiler = no;

    // dosyayı oluşturup bayi no, adresi ve talep sayısını dosyaya yazdırma
    ofstream dosyaYaz("siparisler.txt", ios::out);

    dosyaYaz << "Bayi No" << "\t" << "Adres" << setw(20) << "Talep Sayısı";
    
    for (int j = 0; j < 10; j++){
      dosyaYaz << "\n" << no[j] << "\t" << bayiler+j << "\t" << talep[j];
    }
    dosyaYaz << endl;

    // rastgele dağıtım rotası için dosyaya başlık yazdırma
    dosyaYaz << "\n" << karakter('-') << endl;
    dosyaYaz << "Belirlenen Dağıtım Rotası" << endl;
    dosyaYaz << karakter('-') << endl;

    // dağıtım rotasını dosyaya ve ekrana yazdırma
    karistirma();

    for (int j = 0; j < 10; j++){
      dosyaYaz << "\n" << no[j] << "\t" << bayiler+(no[j]-1) << "\t" << talep[no[j]-1];
      cout << "\n" << no[j] << "\t" << bayiler+(no[j]-1) << "\t" << talep[no[j]-1];
    }

    // kalan miktarı dosyaya yazdırma
    dosyaYaz << "\n" << karakter('*') << endl;
    dosyaYaz << "Kalan Miktar : " << kalan();

    dosyaYaz.close();

    // kalan miktarı ekrana yazdırma
    cout << "\n" << karakter('*') << endl;
    cout << "Kalan Miktar: " << kalan() << endl;
}

void karistirma()
{
    int sayi;
    for (int i=0; i < 10; i++){
        sayi = rand() % 10;
        swap(no[i], no[sayi]);
    }
}

int kalan()
{   
    int toplam = 0;
    for (int i = 0; i < 10; i++)
        toplam += talep[i];
    int kalan = 1000 - toplam;
    return kalan;
}

string karakter(char isaret)
{
    string isaretler;
    for (int i = 0; i < 30; i++)
        isaretler+=isaret;
    return isaretler;
}
