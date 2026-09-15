#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
    long double x;
unsigned int k,bottom_number=1,i=0;
cout<<"Введите степень (под модулем) числа e : "<<endl;
cin>>x;
cout<<"Введите натуральное число большее единицы в которое возводится число  1/10 : "<<endl;
cin>>k;
long double Emax=pow(10.0 ,-int(k));
long double component_i=1,summ=0,top_number=1;


while (abs(component_i)>=Emax)
{
    summ+=component_i;
top_number*=-x;
bottom_number*=i+1;
i++;
component_i=top_number/bottom_number;
}
cout<<fixed<<setprecision(k);
cout<<"Итоговое число: "<<summ<<endl;

    return 0;
}