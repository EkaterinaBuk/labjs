#include <iostream>
#include <limits>
using namespace std;
int main(){
setlocale (LC_ALL, "Russian");
cout<<"Hello World!"<<endl;
cout<<"---------------------------------------"<<endl;
cout<<"Тип данных | Размер | Диапазон значений"<<endl;
cout<<"|----------+------------------+------------------------------------------------------------|"<<endl;
cout<<"|bool\t\t|"<<sizeof(bool)<<"\t|"<<std::numeric_limits<bool>::min()<<".."<<std::numeric_limits<bool>::max()<<"..";
cout<<"|char\t\t|"<<sizeof(char)<<"\t|"<<endl;
cout<<"|short\t\t|"<<sizeof(short)<<"\t|"<<std::numeric_limits<short>::min()<<".."<<std::numeric_limits<short>::max()<< "..";
cout<<"|int\t\t|"<<sizeof(int)<<"\t|"<<std::numeric_limits<int>::min()<<".."<<std::numeric_limits<int>::max()<< "..";
cout<<"|int*\t\t|"<<sizeof(int*)<<"\t|"<<endl;
cout<<"|unsigned int\t|"<<sizeof(unsigned int)<<"\t|"<<std::numeric_limits<unsigned int>::min()<<".."<<std::numeric_limits<unsigned int>::max()<<"..";
cout<<"|long\t\t|"<<sizeof(long)<<"\t|"<<std::numeric_limits<long>::min()<<".."<<std::numeric_limits<long>::max()<<"..";
cout<<"|long long\t\t|"<<sizeof(long long)<<"\t|"<<std::numeric_limits<long long>::min()<<".."<<std::numeric_limits<long long>::max()<<"..";
cout<<"|float\t\t|"<<sizeof(float)<<"\t|"<<std::numeric_limits<float>::min()<<".."<<std::numeric_limits<float>::max()<<"..";
cout<<"|double\t|"<<sizeof(double)<<"\t|"<<std::numeric_limits<double>::min()<<".."<<std::numeric_limits<double>::max()<<"..";
cout<<"|double*\t|"<<sizeof(double*)<<"\t|"<<endl;
cout<<"|long double\t|"<<sizeof(long double)<<"\t|"<<std::numeric_limits<long double>::min()<<".."<<std::numeric_limits<long double>::max()<<"..";
cout<<"|unsigned char\t\t|"<<sizeof(unsigned char)<<"\t|"<<std::numeric_limits<unsigned char>::min()<<".."<<std::numeric_limits<unsigned char>::max()<<"..";
cout<<"|signed char\t\t|"<<sizeof(signed char)<<"\t|"<<std::numeric_limits<signed char>::min()<<".."<<std::numeric_limits<signed char>::max()<<"..";
cout<<"|wchar_t\t\t|"<<sizeof(wchar_t)<<"\t|"<<std::numeric_limits<wchar_t>::min()<<".."<<std::numeric_limits<wchar_t>::max()<<"..";
cout<<"|short int\t\t|"<<sizeof(short int)<<"\t|"<<std::numeric_limits<short int>::min()<<".."<<std::numeric_limits<short int>::max()<< "..";
cout<<"|signed short int\t\t|"<<sizeof(signed short int)<<"\t|"<<std::numeric_limits<signed short int>::min()<<".."<<std::numeric_limits<signed short int>::max()<< "..";
cout<<"|signed short\t\t|"<<sizeof(signed short)<<"\t|"<<std::numeric_limits<signed short>::min()<<".."<<std::numeric_limits<signed short>::max()<< "..";
cout<<"|unsigned short\t\t|"<<sizeof(unsigned short)<<"\t|"<<std::numeric_limits<unsigned short>::min()<<".."<<std::numeric_limits<unsigned short>::max()<< "..";
cout<<"|unsigned short int\t\t|"<<sizeof(unsigned short int)<<"\t|"<<std::numeric_limits<unsigned short int>::min()<<".."<<std::numeric_limits<unsigned short int>::max()<< "..";
cout<<"|signed int\t\t|"<<sizeof(signed int)<<"\t|"<<std::numeric_limits<signed int>::min()<<".."<<std::numeric_limits<signed int>::max()<<"..";
cout<<"|signed\t\t|"<<sizeof(signed)<<"\t|"<<std::numeric_limits<signed>::min()<<".."<<std::numeric_limits<signed>::max()<<"..";
cout<<"|unsigned\t\t|"<<sizeof(unsigned)<<"\t|"<<std::numeric_limits<unsigned>::min()<<".."<<std::numeric_limits<unsigned>::max()<<"..";
cout<<"|long int\t\t|"<<sizeof(long int)<<"\t|"<<std::numeric_limits<long int>::min()<<".."<<std::numeric_limits<long int>::max()<<"..";
cout<<"|signed long int\t\t|"<<sizeof(signed long int)<<"\t|"<<std::numeric_limits<signed long int>::min()<<".."<<std::numeric_limits<signed long int>::max()<< "..";
cout<<"|signed long\t\t|"<<sizeof(signed long)<<"\t|"<<std::numeric_limits<signed long>::min()<<".."<<std::numeric_limits<signed long>::max()<<"..";
cout<<"|unsigned long\t|"<<sizeof(unsigned long)<<"\t|"<<std::numeric_limits<unsigned long>::min()<<".."<<std::numeric_limits<unsigned long>::max()<<"..";
cout<<"|unsigned long int\t\t|"<<sizeof(unsigned long int)<<"\t|"<<std::numeric_limits<unsigned long int>::min()<<".."<<std::numeric_limits<unsigned long int>::max()<< "..";
cout<<"|long long int\t\t|"<<sizeof(long long int)<<"\t|"<<std::numeric_limits<long long int>::min()<<".."<<std::numeric_limits<long long int>::max()<<"..";
cout<<"|signed long long int\t\t|"<<sizeof(signed long long int)<<"\t|"<<std::numeric_limits<signed long long int>::min()<<".."<<std::numeric_limits<signed long long int>::max()<<"..";
cout<<"|signed long long\t\t|"<<sizeof(signed long long)<<"\t|"<<std::numeric_limits<signed long long>::min()<<".."<<std::numeric_limits<signed long long>::max()<<"..";
cout<<"|unsigned long long\t\t|"<<sizeof(unsigned long long)<<"\t|"<<std::numeric_limits<unsigned long long>::min()<<".."<<std::numeric_limits<unsigned long long>::max()<<"..";
cout<<"|unsigned long long int\t\t|"<<sizeof(unsigned long long int)<<"\t|"<<std::numeric_limits<unsigned long long int>::min()<<".."<<std::numeric_limits<unsigned long long int>::max()<<"..";
return 0;
}