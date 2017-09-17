#include <iostream>
#include <string>
using namespace std;
//num=tamaño de la torre
//A,B,C;son el noombre de cada una de las piramdes
void construir_array(string array[],string x,int n){
	int con=0;
	for (int j=0;j<n;j++){
		for (int i=0;i<n-con;i++){
			array[n-1-con]+=x;
			if (i<n-con-1){
				array[n-1-con]+=".";
				}
			}	
		con++;	
	}
}
void llenar_fila(string array[],int fila){
	for (int i=0;i<fila+1;i++){
			array[fila]+="-";
			if (i<fila){
				array[fila]+=".";
				}
			}
}
void print(string array_1[],string array_2[],string array_3[],int n){
	int nu=n;
	for (int i=0;i<n;i++){
		nu=3*n-i;
		for(int a=0;a<nu;a++){
			cout<<" ";
		}
		cout<<array_1[i];
		for(int a=0;a<nu-i;a++){
			cout<<" ";
		}	
		cout<<array_2[i];
		for(int a=0;a<nu-i;a++){
			cout<<" ";
		}	
		cout<<array_3[i];
		cout<<"\n";	
	}	
}
void print_ordenado(string array_1[],string array_2[],string array_3[],string d,int n){

		if (d== "ABC"){
			print(array_1,array_2,array_3,n);
		}else if (d=="ACB"){
			print(array_1,array_3,array_2,n);
		}else if(d=="BAC"){
			print(array_2,array_1,array_3,n);
		}else if (d=="BCA"){
			print(array_2,array_3,array_1,n);
		}else if (d=="CAB"){
			print(array_3,array_1,array_2,n);
		}else if (d=="CBA"){
			print(array_3,array_2,array_1,n);				
		}
	
	}
	
void poner(int num,string array_1[],string array_3[],string a ,string c){
	array_3[num-1]=array_1[num-1];
	array_1[num-1]="";
	llenar_fila(array_1,num-1);
	cout<<"El disco "<<num<<" se traslada de::"<<a<<" hacia "<<c<<"\n";
	} 
void hanoi(int num ,int n,string array_1[],string array_2[],string array_3[],string d,string a,string b, string c){
	if (num==1){
		poner(num,array_1,array_3,a,c);
		d=a+b+c;
		print_ordenado(array_1,array_2,array_3,d,n);
		d="";
		return ;
		}
	hanoi(num-1,n,array_1,array_3,array_2,d,a,c,b);
	poner(num,array_1,array_3,a,c);
	d=a+b+c;
	print_ordenado(array_1,array_2,array_3,d,n);
	d="";
	hanoi(num-1,n,array_2,array_1,array_3,d,b,a,c);
}	
int main(){
	int n;
	string d="";
	cout<<"ingresar el numero de discos::\n";
	cin>>n;
	string torre_1[n]={};
	string torre_2[n]={};
	string torre_3[n]={};
	construir_array(torre_1,"x",n);
	construir_array(torre_2,"-",n);
	construir_array(torre_3,"-",n);
	//print(torre_1,torre_2,torre_3,n);
	print(torre_1,torre_2,torre_3,n);
	hanoi(n,n,torre_1,torre_2,torre_3,d,"A","B","C");
	print(torre_1,torre_2,torre_3,n);
	return 0;
}

