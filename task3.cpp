#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int size_of_matrics() {
int n;
do{
cout<<"Введите размер матрицы(квадратной) от 1 до 10 : "<<endl;
cin>>n;
if (n<1 || n>10) {
cout<<"Ваше n вышло за рамки допускаемого размера, попробуйте снова."<<endl;

}
else{
    cout<<"n было принято."<<endl;
}

} while ( n<1 || n>10 );

 return n;   
}

void fill_matrics( vector<vector<int>>& matrics ) {

int n=matrics.size();
for( int i=0; i<n ; i++) {

    for (int j=0; j<n; j++) {

if ((i+j)%2!=0) {

matrics[i][j]=1;

}
else {

cout<<"Введите элемент в матрице." <<endl;
cin>>matrics[i][j];

}

    }

}

}


void print_matrics(const vector<vector<int>>& matrics) {

cout<<"Вывод матрицы:"<<endl;

for( const auto& str :matrics ) {

    for (int item : str) {

cout<<setw(4)<<item<<" ";


    }
cout<<endl;

}


}


int sum_without_0(const vector<vector<int>>& matrics) {

int n=matrics.size();
int full_summ=0;
bool no_zero=false;

for (int i=0;i<n;i++) {
bool have_zero=false;

for (int j=0;j<n;j++) {

if (matrics[i][j]==0) {
have_zero=true;
break;


}

}

if (!have_zero) {
no_zero=true;

for (int j=0;j<n;j++) {
full_summ+=matrics[i][j];

}

}


}

if (!no_zero) {

   cout<<"Каждая из строк массива содержит минимум 1 ноль ."<<endl;
return 0; 
}

return full_summ;

}


long long max_parallel_diagonals (const vector<vector<int>>& matrics) {

    int n=matrics.size();

    if (n<=1) {

        cout<<"Для матрицы ваших размеров параллельные диагонали отсутсвуют. "<<endl;
        return 0;
    }

    long long max_item=-999999999999LL;
    bool real_first=true;

    for (int k=1;k<n;k++) {

long long curr_item=1;
for (int i=0; i<n-k ;i++) {

curr_item*=matrics[i][i+k];


}

if ((curr_item>max_item) || (real_first)) {


    max_item=curr_item;
    real_first=false;
}


    }
    
 for (int k=1;k<n;k++) {

    long long curr_item=1;

    for (int i=0;i<n-k;i++) {


curr_item*=matrics[i+k][i];

    }
if (curr_item>max_item) {

    max_item=curr_item;
}


    
 }


return max_item;
}



int main() {

int n=size_of_matrics();
vector<vector<int>> matrics(n,vector<int>(n, 0));

fill_matrics(matrics);
print_matrics(matrics);

int summ=sum_without_0(matrics);


cout<<"Сумма элементов из строк без нулей: "<< summ<<endl;



long long max_item=max_parallel_diagonals(matrics);
if (n>1) {
cout<<"Максімальное произведение параллельных диагоналей: "<<max_item<<endl;

}





    return 0;
}
