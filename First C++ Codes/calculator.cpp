#include <iostream>
using namespace std;

int main(){
int a;
int b;
int c;
string islem="topla";
string islem2;
string islem3="carp";
string islem4="bol";
string islem5="cıkar";
cout<< "sayilari giriniz"<<endl;
cout<< "birinci sayi:";
cin>> a;
cout<< "ikinci sayi:";
cin>> b;
cout<< "hangi islemi yapmak istiyorsunuz"<<endl;
cin>> islem2;
if(islem2 ==islem )
{
    cout<<"toplam="<<a+b<<endl;
}
if(islem2 == islem3){
  cout<<"carpim="<<a*b<<endl;
}
if(islem2 == islem4){
   cout<< "bolum="<<a/b<<endl;
}
if(islem2 == islem5){
    cout<< "sonuc="<<a-b<<endl;
}
return 0;
}
