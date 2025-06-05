#include <iostream>
using namespace std;

int main(){
int i=1;
int sayi;
int giris_sayisi;
cout<< "sayi girin:";
cin>>giris_sayisi;
cout<< "ikinici sayiyi girin:";
cin>>sayi;
for(i=1;i<=giris_sayisi;i++)
{
    sayi=sayi*i;
    cout<< "sayinin degeri:"<<sayi<<endl;
}

return 0;

}
