#include <iostream>
#include <fstream>
using namespace std;
//Описание функции сортировки простым слиянием
void Simple_Merging_Sort (char *name){
  int a1, a2, k, i, j, kol, tmp;
  ofstream f1("f1.txt"), f2("f2.txt");
  fstream f("f.txt");
  kol = 0;
  if ( (f = fopen(name,"r")) == NULL )
    printf("\nИсходный файл не может быть прочитан...");
  else {
    while ( !f.eof() ) {
      f>>a1;//выборка элемента 
      kol++;//увеличение количества элементов
    }
    f.close();
  }
  k = 1;
  while ( k < kol ){
    f.open("f.txt");
    if ( !f.eof() ) f>>a1;
    while ( !f.eof() ){
      for ( i = 0; i < k && !f.eof() ; i++ ){
        f1 << a1;
        f>>a1;
      }
      for ( j = 0; j < k && !f.eof() ; j++ ){
        f2 << a1;
        f>>a1;
      }
    }
    f.close(); f1.close(); f2.close();

    f = fopen(name,"w");
    f1 = fopen("smsort_1","r");
    f2 = fopen("smsort_2","r");
    if ( !f1.eof() ) f1>>a1;
    if ( !f2.eof() ) f2>>a2;
    while ( !f1.eof() && !f2.eof() ){
      i = 0;
      j = 0;
      while ( i < k && j < k && !f1.eof() && !f2.eof() ) {
        if ( a1 < a2 ) {
			f << a1;
			f1 >>a1;
			i++;
        }
        else {
          f << a2;
		  f2 >>a2;
          j++;
        }
      }
      while ( i < k && !f1.eof() ) {
        f << a1;
		f1 >>a1;
        i++;
      }
      while ( j < k && !f2.eof() ) {
        f << a2;
		f2 >>a2;
        j++;
      }
    }
    while ( !f1.eof() ) {
      f << a1;
	  f1 >>a1;
    }
    while ( !f2.eof() ) {
      f << a2;
	  f2 >>a2;
    }
    f.close(); f1.close(); f2.close();
    k *= 2;
  }
  //remove("smsort_1");
  //remove("smsort_2");
}
