#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime>
using namespace std;
bool perfect(int x){
     int s=0;
     for(int i=1;i<x;i++){
             if(x%i==0)
                       s+=i;
     }
     if(s==x)
         return true;
     else
         return false;
}
int main(){
	setlocale(LC_ALL,"");
	srand(time(NULL));
	int m,n;
	cout << "Введите количество строк и столбцов массива" << endl;
	cin >> m >> n;
	int a[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			a[i][j] = rand()%10;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}                       //Двумерный массив
    int max=-1, row=-1;
    for(int i=0;i<m;i++){
		int sum=0;
        for(int j=0;j<n;j++)
		        if(perfect(a[i][j])) 
                                    sum+=a[i][j];
		cout << sum << endl;
        if(max==-1 || sum>max){
                   row=i;
                   max=sum;          
        }
	}
	cout << "Номер строки с максимальным количеством совершенных чисел: " << row+1<< endl;  
	system("pause");
	return 0;
}
