#include<iostream>
#include<vector>
using namespace std;
class Matrix{
protected:
	vector<vector<int>>mat1;//存储初始化矩阵
	int row,col;
public:
	Matrix(){row=this->row;col=this->col;};//无参构造函数
	Matrix(int a,int b):row(a),col(b){
		mat1.resize(row,vector<int>(col));
		cout<<"请输入矩阵的"<<row<<"*"<<col<<"个元素";
		for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			cin>>mat1[i][j];
	}
	friend Matrix operator*( const Matrix &x,const  Matrix &y);//运算符重载函数
	void show(){
		for(int i=0;i<this->row;i++){
		for(int j=0;j<this->col;j++){
			cout<<mat1[i][j]<<" ";
		}
		cout<<endl;
		}
	
	}
};
	Matrix operator*( const Matrix &x,const  Matrix &y){
	   Matrix m;//调用无参数默认构造函数
	   m.row=x.row;//初始化存储数据的矩阵行列数，否则将一直默认为构造函数中的值
	   m.col=y.col;
	   m.mat1.resize(x.row,vector<int>(y.col));//重置储存数据的矩阵大小
	  
	   //下面为矩阵乘法的算法
	   for(int i=0;i<x.row;i++)
		   for(int j=0;j<y.col;j++){
			  m.mat1[i][j]=0;
			   for(int k=0;k<y.row;k++)//左矩阵的列数=右矩阵的行数
				   m.mat1[i][j]+=x.mat1[i][k]*y.mat1[k][j];
			   
	}
		  
			   return m;
	}
		   
	
void main(){
	Matrix m1(2,3);
	Matrix m2(3,2);
	(m1*m2).show();
	
}