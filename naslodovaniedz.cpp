/*#include <iostream>
using namespace std;
int main(){
setlocale (LC_ALL, "RUS");
int i,j,N,M,a[20][20];
cout<<"N="; //ввод количества строк
cin>>N;
cout<<"M="; //ввод количества столбцов
cin>>M;
cout<<"Введите верхнеугольную матрицу A \n";
for (i=0; i<N; i++)//цикл по переменной i, в которой перебираем строки матрицы
for (j=0; j<M; j++)//цикл по переменной j, в котором перебираем элементы внутри строки
cin>>a[i][j]; //ввод очередного элемента матрицы
cout<<"Матрица A \n";
for (i=0; i<N; i++){//цикл по переменной i, в котором перебираем строки матрицы
for (j=0; j<M; j++)
cout<<a[i][j]<<"\t"; //вывод очередного элемента матрицы
cout<<endl; //переход на новую строку после вывода всех элементов строки
}
}*/
#include <iostream>
using namespace std;
int main(){
setlocale (LC_ALL, "RUS");
double eps1, eps;
eps = 1.0;
eps1 = 1+eps/2.0;
if (eps1 > 1){
eps = eps/2.0;
eps1 = 1.0+eps;
}
else{
cout<<eps<<endl;}
}