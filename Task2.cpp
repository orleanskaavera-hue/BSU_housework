#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
int main()
{
srand(time(nullptr));
 int size_massiv;
 cout<<"введите размер массива до 100: "<<endl;
cin>>size_massiv;

long double massiv[100];
cout<<"Вы хотите заполнять массив сами (введите число 1) или не хотите самостоятельно заполнять массив(введите число 2)"<<endl;
int n;
cin>>n;
switch(n)
{
 case 1: 
for (int i=0;i<size_massiv;i++)
{
cin>>massiv[i];


}
cout<<"Массив заполнен полностью"<<endl;

 break;
 case 2:
cout<<"Введите минимальную и максимальную границу интервала, которому должны принадлежать числа в массиве"<<endl;
cout<<"введите минимальную границу: "<<endl;
 long double min_el;
cin>>min_el;
cout<<"введите максимальную границу: "<<endl;
long double max_el;
cin>>max_el;
for (int i=0;i<size_massiv;i++)
{
massiv[i]=min_el+(double)rand()/RAND_MAX*(max_el -min_el);


}
cout<<"Массив заполнен полностью"<<endl;




 break;





}
long double summ_odd=0;

for (int i=0;i<size_massiv;i++)
{
 if(i%2!=0)
 {
summ_odd+=massiv[i];


 }

}
int first_minus=-1;
int last_minus=-1;
for (int i=0;i<size_massiv;i++){
if (massiv[i]<0.0)
{
    first_minus=i;
    break;
}


}
for (int i=size_massiv-1;i>=0;i--){
if (massiv[i]<0.0)
{
    last_minus=i;
    break;
}


}
if(first_minus==-1 || last_minus==-1 || first_minus>=last_minus-1)
{
    cout<<"произведение между двумя отрицательными числами вычислить невозможно"<<endl;
}
else{
long double multipl=1.0;
for (int i=first_minus+1;i<last_minus;i++)
{

    multipl*=massiv[i];

}
cout<<"ПРоизведение элементов между первым и последним отрицательными элементами : "<<multipl<<endl;
}

cout<<"Сумма элементов на нечетных позициях: "<<summ_odd<<endl;
int write_ind=0;

for (int i=0;i<size_massiv;i++) 
{
    if (fabsl(massiv[i])>1.0L) 
    {
        massiv[write_ind]=massiv[i];
        write_ind++;
    }

    
}
for (int i=write_ind;i<size_massiv;i++) 
{
    massiv[i]=0.0L;
}
cout<<"Сжатый массив: "<<endl;
for(int i=0;i<size_massiv;i++)
{
    cout<<massiv[i]<<endl;
}
return 0;
}