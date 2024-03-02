#include <iostream>
using namespace std;
struct Gora {
	 string name;
	 double visota;
 };
 int main(){
	 SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Gora gora[2];
    cout<<gora.name<<" "<< gora.visota<<endl;
    for (size_t i=0; i<10; i++){
		cout<<"Введите название"<<i+1<<"-ой горы"<<endl;
		cin>>gora[i].name;
		cout<<"Введите высоту"<<i+1<<"-ой горы"<<endl;
		cin>>gora[i].visota;
	}
    for (size_t i=0; i<10; i++){
		cout<<gora[i].name<<" ";
		cout<<gora[i].visota<<endl;}
	}
