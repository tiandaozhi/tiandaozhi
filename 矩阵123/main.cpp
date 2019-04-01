<code class="language-cpp">//“”matrix.h“”  

  

class matrix {  

  

“”matrix.h“”  

  

class matrix {  

  

  

public:  

matrix(int mm,int nn){  

int i,j;  

m=mm;  

n=nn;  

data=new double *[m];  

for(int j=0;j<m;j++){  

data[j]=new double [n];  

}  

for(i=0;i<m;i++)//矩阵所有元素清零    

            for(j=0;j<n;j++) {   

                data[i][j]=0.0;   

}  

}  

matrix(const matrix &src){  

m=src.m;  

n=src.n;  

data=new double *[m];  

for(int j=0;j<m;j++){  

data[j]=new double [n];  

}  

for(int i=0;i<m;i++){  

for(int j=0;j<n;j++){  

data[i][j]=src.data[i][j];  

}  

}  

}  

~matrix(){  

for(int i=0;i<m;i++){  

delete []data[i];  

}  

delete []data;  

}  

void input();  

void display();  

matrix &operator=(const matrix &src);  

matrix operator*(const matrix &src);  

matrix operator +(const matrix &src);  

matrix operator-(const matrix &src);  

private:  

int m,n;  

double **data;  

  

};  

  

//"matrix.cpp"  

  

#include<iostream>  

  

  

#include"matrix.h"  

using namespace std;  

void matrix::input(){  

int i,j;  

for(i=0;i<m;i++){  

for(j=0;j<n;j++){  

cin>>data[i][j];   

}  

}  

  

  

}  

void matrix::display(){  

int i,j;  

for(i=0;i<m;i++){  

for(j=0;j<n;j++){  

cout<<data[i][j]<<" ";  

}  

cout<<endl;  

}  

}  

matrix& matrix::operator=(const matrix &src){  

  

for(int i=0;i<m;i++)    

        delete []data[i];    

delete [] data;  

m=src.m;  

n=src.n;  

  

data=new double*[m];//动态建立二维数组    

    for(int i=0;i<m;i++)    

        data[i]=new double[n];   

for(int i=0;i<m;i++){  

for(int j=0;j<n;j++){  

data[i][j]=src.data[i][j];  

}   

}  

return *this;  

}  

matrix matrix::operator*(const matrix &src){  

  

matrix mm(this->m,src.n);  

if(this->n!=src.m){  

cout<<"矩阵不能相乘"<<endl;  

}  

for(int i=0;i<this->m;i++){  

for(int j=0;j<src.n;j++){  

for(int k=0;k<this->n;k++){  

mm.data[i][j]+=(this->data[i][k]*src.data[k][j]);  

}   

}  

  

}  

return mm;  

}  

matrix matrix::operator+(const matrix &src){  

matrix mm(src.m,src.n);  

if((src.m!=this->m)||(src.n!=this->n))  

cout<<"矩阵纬度不一致"<<endl;  

for(int i=0;i<src.m;i++){  

for(int j=0;j<src.n;j++){  

mm.data[i][j]=this->data[i][j]+src.data[i][j];  

}  

}  

  

  

  

return mm;  

}  

matrix matrix::operator-(const matrix &src){  

matrix mm(src.m,src.n);  

if((src.m!=this->m)||(src.n!=this->n))  

cout<<"矩阵纬度不一致"<<endl;  

for(int i=0;i<src.m;i++){  

for(int j=0;j<src.n;j++){  

mm.data[i][j]=this->data[i][j]-src.data[i][j];//一开始错误出在定义了一个类，但是没指名那个变量赋值  

}  

}  

  

  

  

return mm;  

}  

  

//"main.cpp"  

  

//author:crz  

//matrix construction  

//2017,2,21  

#include<iostream>  

#include"matrix.h"  

using namespace std;  

  

  

int main(){  

 int x,y;    

 cout<<"输入矩阵行列"<<endl;  

    cin>>x;    

    cin>>y;    

    matrix A(x,y);    

    cout<<"请输入矩阵1元素"<<endl;    

    A.input();    

    cout<<"矩阵1："<<endl;    

    A.display();   

 cout<<"输入矩阵行列"<<endl;  

    cin>>x;    

    cin>>y;    

    matrix B(x,y);    

    cout<<"请输入矩阵2元素"<<endl;    

    B.input();    

    cout<<"矩阵2："<<endl;    

    B.display();    

    matrix C=A-B;    

    cout<<"矩阵1 与 矩阵2 的差值："<<endl;    

    C.display();    

cout<<"矩阵1 与 矩阵2 的求和："<<endl;   

matrix D=A+B;  

D.display();  

matrix E=A*B;  

cout<<"矩阵1 与 矩阵2 的乘积："<<endl;   

E.display();  

system("pause");  

    return 0;   

}  

  

  

public:  

matrix(int mm,int nn){  

in
