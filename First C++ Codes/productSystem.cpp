#include<iostream>
using namespace std;

struct Employee{

int kod;
string urun_adi;
int urun_fiyati;

};

int main(){

Employee employee1;
Employee *ptr=&employee1;
int sayi;

employee1.kod=12345;
employee1.urun_adi="ayran";
employee1.urun_fiyati=2;
cout<<"urun bilgilerini gormek icin herhangi bir sayiya basin"<<endl;
cout<<"1:urun kodu"<<endl;
cout<<"2:urun adi"<<endl;
cout<<"3.urun fiyati"<<endl;
cin>>sayi;
if(sayi == 1){
cout<<ptr->kod<<endl;
}
if(sayi == 2){
cout<<ptr->urun_adi<<endl;
}
if(sayi == 3){
cout<<ptr->urun_fiyati<<endl;
}

return 0;

}
