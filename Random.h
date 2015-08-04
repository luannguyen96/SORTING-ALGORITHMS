#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;


void NhapMang(long *&a, int n){
	a = new(long[n]);
	for (int i = 0; i < n; i++){
		a[i] = rand() % (n + 1);
	}
}

void XuatMang(long *a, int n){
	for (int i = 0; i < n; i++){
		cout << a[i] << "\t";
	}
	cout << endl;
}