#include<iostream>
#include"Random.h"
#include"CountTime.h"
#include<stdlib.h>
#include"Gotoxy.h"
#include<conio.h>
using namespace std;

#define MAX_1 1000
#define MAX_2 10000
#define MAX_3 100000
#define MAX_4 1000000

void Swap(long &x, long &y) {
	int temp = x;
	x = y;
	y = temp;
} 
 // Bubble sort
void BubbleSort(long *a, int n, unsigned long &sosanh, unsigned long &gan){
	gan++;
	sosanh++;
	for (int i = 0; i < n - 1; i++){
		sosanh+=2;
		gan +=2;
		for (int j = n - 1; j >i; j--){
			sosanh+=2;
			gan ++;
			if (a[j-1] > a[j]){
				gan += 3;
				long tam = a[j-1];
				a[j-1] = a[j];
				a[j] = tam;
			}
		}
	}
}


 // Heap sort
void Heapify(long *a, int n, int i,unsigned long &sosanh, unsigned long &gan) {
	
	int Left = 2 * (i + 1) - 1;
	int Right = 2 * (i + 1);
	gan += 2;
	int Largest;

	if (Left<n && a[Left]>a[i]){
		Largest = Left;
		sosanh += 2;
		gan++;
	}
	else{
		sosanh++;
		Largest = i;
		gan++;
	}
	sosanh += 2;
	if (Right<n && a[Right]>a[Largest]){
		Largest = Right;
		
		gan++;
	}
	sosanh++;
	if (i != Largest) {
		gan += 3;
		Swap(a[i], a[Largest]);
		Heapify(a, n, Largest,sosanh,gan);
	}
}

void BuildHeap(long *a, int n, unsigned long &sosanh, unsigned long &gan) {
	gan++;
	for (int i = n / 2 - 1; i >= 0; i--){
		gan++;
		sosanh++;
		Heapify(a, n, i,sosanh ,gan);
	}
}

void HeapSort(long *a, int n, unsigned long &sosanh ,unsigned long &gan) {
	BuildHeap(a, n,sosanh, gan);
	gan++;
	for (int i = n - 1; i>0; i--){
		Swap(a[0], a[i]);
		gan += 4;
		sosanh++;
		Heapify(a, i, 0,sosanh,gan);
	}
}

// Insertion sort
void InsertionSort(long *a, int n,unsigned long &sosanh, unsigned long &gan){
	
	int vt, key;
	gan++;
	for (int i = 1; i < n; i++){ // cho vong lap chay tu 1 den n ptu
		
		vt = i - 1; // gan vt la vi tri dau tien trog mang
		key = a[i]; // gan key la phan tu dau tien trong mang
		sosanh++;
		gan += 3;
		while ((vt >= 0) && (a[vt] > key)){ // so sanh thag truoc co lon hon thag phia sau hay khong?
			a[vt + 1] = a[vt];  //neu co thi chen dang sau
			vt--; // giam vi tri xuog r lai so sanh tiep
			sosanh += 2;
			gan += 2;
		} // neu da chay vao vong lap thi key se duoc chen vao vi tri phia truoc vi tri cua a[vt] do vt--
			// neu khong thi van giu nguyen
		a[vt + 1] = key;
		sosanh++;
		gan++;
	}
}

//Interchange Sort
void InterchangeSort(long *a, int n,unsigned long &sosanh, unsigned long &gan){
	gan++;
	for (int i = 0; i < n - 1; i++){
		sosanh++;
		gan +=2;	
		for (int j = i + 1; j < n; j++){
			sosanh+=2;
			gan ++;
			
			if (a[i] > a[j]){
				gan += 3;
				int tam = a[i];
				a[i] = a[j];
				a[j] = tam;
			}
		}
	}
}

//Merge Sort
void Merge(long *a, int left, int mid, int right,unsigned long &sosanh, unsigned long &gan){
	int n = 0;
	
	int *tam = new(int[right - left + 1]);  // tao 1 mang co so luong la so phan tu trong mang cu dc chia nho
	int i = left;
	int j = mid + 1;
	gan += 4;
	while (i <= mid || j <= right){
		sosanh += 2;
		if ((i <= mid && j <= right && a[i] < a[j]) || j > right){
			sosanh += 4;	
			tam[n++] = a[i++];
			gan += 1;
		}
		else{
			sosanh++;
			gan += 1;
			tam[n++] = a[j++];
		}
	}
	gan++;
	for (int i = 0; i < n; i++){ //bo cac phan tu da dc sap xep trong mang tam vao mang ban dau
		a[left + i] = tam[i];
		sosanh += 1;
		gan += 2;
	}
	sosanh+=2;
	delete[]tam;

}


void MergeSort(long *a, int left, int right,unsigned long &sosanh ,unsigned long &gan){
	
	sosanh++;
	if (left < right){
	
		gan++;
		int mid = (left + right) / 2;
		MergeSort(a, left, mid,sosanh,gan); // chia nho mang ban dau thanh 2 phan, day la phan thu 1
		MergeSort(a, mid + 1, right,sosanh,gan); //day la phan thu 2;
		Merge(a, left, mid, right,sosanh,gan); //gom cac phan nho thanh phan lon
	}
}

//QuickSort
void QuickSort(long *a, int l, int r, unsigned long &sosanh, unsigned long &gan){
	
	int i = l, j = r, x = a[(l + r) / 2]; //khoi tao gia tri chinh giua, gia tri nay co the la 1 so bat ki trog mang
	gan += 3;
	do{
		sosanh++;
		while (a[i] < x){  // neu ma phan tu ben trai be hon x thi tiep tuc tang
			i++;
			sosanh++;
			gan += 1;
		}
		sosanh++;
		while (a[j] >x){ // tuong tu voi phan tu ben phai
			j--;
			sosanh++;
			gan++;
		}
		sosanh++;
		if (i <= j){ // doi cho 2 phan tu nay
			Swap(a[i], a[j]);
			
			gan += 5;
			i++;
			j--;
		}
		sosanh++;
	} while (i < j); // thuc hien cho den khi het mang
	sosanh++;
	if (l < j){ // lam lai cho den khi chay tu phai sang = gia tri l ban dau < thuc hien voi mang a[l]...a[j] >
		QuickSort(a, l, j,sosanh,gan);
	}
	sosanh++;
	if (i < r){ // lam lai cho den khi chay tu trai sang = gia tri r ban dau < thuc hien voi mang a[i]...a[r] >
		
		QuickSort(a, i, r,sosanh,gan);
	}
}

//Radix Sort
void RadixSort(long *a, int n,unsigned long &sosanh, unsigned long &gan)
{
	
	int i, exp = 1;
	double  *b, max = 0;
	b = new double[n];
	gan += 4;
	for (i = 0; i < n; i++)
	{
		gan ++;
		sosanh += 2;
		if (a[i] > max){
			
			gan++;
			max = a[i];
		}
	}
	
	while ((int)max / exp > 0)
	{
		sosanh++;
		int box[10] = { 0 };
		gan+=11;
		for (i = 0; i < n; i++){

			box[(int)(a[i] / exp) % 10]++;
			sosanh++;
			gan += 2;
		}
		gan++;
		for (i = 1; i < 10; i++){
			sosanh++;
			gan += 2;
			box[i] += box[i - 1];
		}
		gan++;
		for (i = n - 1; i >= 0; i--){
			sosanh++;
			gan += 2;
			b[--box[(int)(a[i] / exp) % 10]] = a[i];
		}
		gan++;
		for (i = 0; i < n; i++){
			sosanh++;
			gan += 2;
			a[i] = b[i];
		}
		exp *= 10;
		gan++;
	}
	sosanh++;
	delete[]b;
}



//Shaker sort
void ShakerSort(long *a, int n, unsigned long &sosanh ,unsigned long &gan){ // luot di: day ptu min ve dau, luot ve: day ptu max ve cuoi
	

	
		int Left = 0;
		int Right = n - 1;
		int temp = 0;
		gan += 3;
	
		while (Left < Right)
		{
			sosanh++;
			gan++;
			for (int i = Left; i < Right; i++)
			{
				gan++; 
				sosanh++;
				if (a[i] > a[i + 1])
				{
					sosanh++;
					Swap(a[i], a[i + 1]);
					temp = i;// luu lai vi tri cuoi cung
					gan += 4;
				}
				else
				{
					sosanh++;
				}
			}
			
			sosanh++; 
			gan++;
			Right = temp; // bat dau tu vi tri cuoi cung chay ve truoc
			gan++;
			for (int i = Right; i > Left; i--)
			{
				sosanh++; 
				gan++;
				if (a[i] < a[i - 1])
				{
					sosanh++;
					Swap(a[i], a[i - 1]);
					temp = i;
					gan += 4;
				}
				else
				{
					sosanh++;
				}
			}
			sosanh++; 
			gan++;
			Left = temp; // luu lai vi tri ban dau
			gan++;
		}
		sosanh++;
	
}
void NhapMenu(int &menu){
	int tam = 0;
	do{
		fflush(stdin);
		cin.clear();
		gotoxy(20, 5 + tam);
		cout << "nhap loai sap xep" << endl;
		gotoxy(20, 7 + tam);
		cout << "1. Bubble Sort" << endl;
		gotoxy(20, 9 + tam);
		cout << "2. Interchange Sort" << endl;
		gotoxy(20, 11 + tam);
		cout << "3. Insertion Sort" << endl;
		gotoxy(20, 13 + tam);
		cout << "4. Shaker Sort" << endl;
		gotoxy(20, 15 + tam);
		cout << "5. Quick Sort" << endl;
		gotoxy(20, 17 + tam);
		cout << "6. Merge Sort" << endl;
		gotoxy(20, 19 + tam);
		cout << "7. Radix Sort" << endl;
		gotoxy(20, 21 + tam);
		cout << "8. Heap Sort" << endl;
		gotoxy(20, 23 + tam);
		cin >> menu;
		tam += 10;
	} while (menu <1 || menu >8);
}

void NhapSoLuong(int &ptu){
	int tam = 0;

	do{
		fflush(stdin);
		cin.clear();
		gotoxy(20, 5 + tam);
		cout << "nhap so luong phan tu" << endl;
		gotoxy(20, 7 + tam);
		cout << "1. n = 1000" << endl;
		gotoxy(20, 9 + tam);
		cout << "2. n = 10000" << endl;
		gotoxy(20, 11 + tam);
		cout << "3. n = 100000" << endl;
		gotoxy(20, 13 + tam);
		cout << "4. n = 1000000" << endl;
		gotoxy(20, 15 + tam);
		cin >> ptu;
		tam += 10;
	} while (ptu < 1 || ptu >4);

}

void KhaiBaoN(int &n){
	int ptu;
	NhapSoLuong(ptu);
	switch (ptu)
	{
	case 1:
		n = MAX_1;
		break;
	case 2:
		n = MAX_2;
		break;
	case 3:
		n = MAX_3;
		break;
	case 4:
		n = MAX_4;
	default:
		break;
	}
}

void ListSort(long *&a, int &n, CStopWatch timer, float &khoangthoigian, unsigned long &sosanh, unsigned long &gan){
	sosanh = 0, gan = 0;
	srand(time(NULL));
	int menu;

	do{	
		system("cls");

		NhapMenu(menu);
		system("cls");
		switch (menu)
		{
		case 1:
			sosanh = 0, gan = 0;
			KhaiBaoN(n);
			system("cls");
			NhapMang(a, n);
			timer.startTimer();
			BubbleSort(a, n,sosanh,gan);
			timer.stopTimer();
			XuatMang(a, n);
			khoangthoigian = timer.getElapsedTime();
			cout << "so phep so sanh \t" << sosanh << endl;
			cout << "So phep gan \t" << gan << endl;
			cout << "Thoi gian chay \t" << khoangthoigian << " s" << endl;
			break;
		
		case 2:
			sosanh = 0, gan = 0;
			KhaiBaoN(n);
			system("cls");
			NhapMang(a, n);
			timer.startTimer();
			InterchangeSort(a, n, sosanh, gan);
			timer.stopTimer();
			XuatMang(a, n);
			khoangthoigian = timer.getElapsedTime();
			cout << "so phep so sanh \t" << sosanh << endl;
			cout << "So phep gan \t" << gan << endl;
			cout << "Thoi gian chay \t" << khoangthoigian << " s" << endl;
			
			break;
		case 3:
			sosanh = 0, gan = 0;
			KhaiBaoN(n);
			system("cls");
			NhapMang(a, n);
			timer.startTimer();
			InsertionSort(a, n, sosanh, gan);
			timer.stopTimer();
			XuatMang(a, n);
			khoangthoigian = timer.getElapsedTime();
			cout << "so phep so sanh \t" << sosanh << endl;
			cout << "So phep gan \t" << gan << endl;
			cout << "Thoi gian chay \t" << khoangthoigian << " s" << endl;
			break;
		case 4:
			sosanh = 0, gan = 0;
			KhaiBaoN(n);
			system("cls");
			NhapMang(a, n);
			timer.startTimer();
			ShakerSort(a, n, sosanh, gan);
			timer.stopTimer();
			XuatMang(a, n);
			khoangthoigian = timer.getElapsedTime();
			cout << "so phep so sanh \t" << sosanh << endl;
			cout << "So phep gan \t" << gan << endl;
			cout << "Thoi gian chay \t" << khoangthoigian << " s" << endl;
			break;
		case 5:
			sosanh = 0, gan = 0;
			KhaiBaoN(n);
			system("cls");
			NhapMang(a, n);
			timer.startTimer();
			QuickSort(a, 0, n - 1, sosanh, gan);
			timer.stopTimer();
			XuatMang(a, n);
			khoangthoigian = timer.getElapsedTime();
			cout << "so phep so sanh \t" << sosanh << endl;
			cout << "So phep gan \t" << gan << endl;
			cout << "Thoi gian chay \t" << khoangthoigian << " s" << endl;
			break;
		case 6:
			sosanh = 0, gan = 0;
			KhaiBaoN(n);
			system("cls");
			NhapMang(a, n);
			timer.startTimer();
			MergeSort(a, 0, n - 1, sosanh, gan);
			timer.stopTimer();
			XuatMang(a, n);
			khoangthoigian = timer.getElapsedTime();
			cout << "so phep so sanh \t" << sosanh << endl;
			cout << "So phep gan \t" << gan << endl;
			cout << "Thoi gian chay \t" << khoangthoigian << " s" << endl;
			break;
		case 7:
			sosanh = 0, gan = 0;
			KhaiBaoN(n);
			system("cls");
			NhapMang(a, n);
			timer.startTimer();
			RadixSort(a, n, sosanh, gan);
			timer.stopTimer();
			XuatMang(a, n);
			khoangthoigian = timer.getElapsedTime();
			cout << "so phep so sanh \t" << sosanh << endl;
			cout << "So phep gan \t" << gan << endl;
			cout << "Thoi gian chay \t" << khoangthoigian << " s" << endl;
			break;
		case 8:
			sosanh = 0, gan = 0;
			KhaiBaoN(n);
			system("cls");
			NhapMang(a, n);
			timer.startTimer();
			HeapSort(a, n, sosanh, gan);
			timer.stopTimer();
			XuatMang(a, n);
			khoangthoigian = timer.getElapsedTime();
			cout << "so phep so sanh \t" << sosanh << endl;
			cout << "So phep gan \t" << gan << endl;
			cout << "Thoi gian chay \t" << khoangthoigian << " s" << endl;
			break;
		default:
			break;
		}
		delete[]a;
		cout << "press any key to continue - esc to exit" << endl;
		
	} while (getch() != 27);
	

}

void Baocao(long *&a, int &n, CStopWatch timer, float &khoangthoigian, unsigned long &sosanh, unsigned long &gan){
	int tam = 0;
	srand(time(NULL));
	do{
		system("cls");
		KhaiBaoN(n);
		system("cls");
		gotoxy(0, 0);
		cout << "Ten phep so sanh \t";
		gotoxy(30, 0);
		cout << "Thoi gian chay \t";
		gotoxy(50, 0);
		cout << "So phep gan \t";
		gotoxy(70, 0);
		cout << "So phep so sanh \t";
		sosanh = 0, gan = 0;
		
		NhapMang(a, n);
		timer.startTimer();
		BubbleSort(a, n, sosanh, gan);
		timer.stopTimer();
		khoangthoigian = timer.getElapsedTime();
		gotoxy(0, 2);
		cout << "Bubble Sort \t";
		gotoxy(30, 2);
		cout << khoangthoigian << "s \t";
		gotoxy(50, 2 );
		cout << gan << "\t"; 
		gotoxy(70, 2);
		cout << sosanh << "\t";
		delete[]a;



		sosanh = 0, gan = 0;
		NhapMang(a, n);
		timer.startTimer();
		
		HeapSort(a, n, sosanh, gan);
		timer.stopTimer();
		khoangthoigian = timer.getElapsedTime();
		gotoxy(0, 4 );
		cout << "Heap Sort \t";
		gotoxy(30, 4);
		cout << khoangthoigian << "s \t";
		gotoxy(50, 4 );
		cout << gan << "\t";
		gotoxy(70, 4 );
		cout << sosanh << "\t";
		delete[]a;

		sosanh = 0, gan = 0;
		NhapMang(a, n);
		timer.startTimer();

		QuickSort(a, 0, n - 1, sosanh, gan);
		timer.stopTimer();
		khoangthoigian = timer.getElapsedTime();
		gotoxy(0, 6);
		cout << "Quick Sort \t";
		gotoxy(30, 6);
		cout << khoangthoigian << "s \t";
		gotoxy(50, 6 );
		cout << gan << "\t";
		gotoxy(70, 6 );
		cout << sosanh << "\t";
		delete[]a;


		sosanh = 0, gan = 0;
		NhapMang(a, n);
		timer.startTimer();
		RadixSort(a, n, sosanh, gan);
		timer.stopTimer();
		khoangthoigian = timer.getElapsedTime();
		gotoxy(0, 8 );
		cout << "Radix Sort \t";
		gotoxy(30, 8);
		cout << khoangthoigian << "s \t";
		gotoxy(50, 8 );
		cout << gan << "\t";
		gotoxy(70, 8 );
		cout << sosanh << "\t";
		delete[]a;


		sosanh = 0, gan = 0;
		NhapMang(a, n);
		timer.startTimer();
		InterchangeSort(a, n, sosanh, gan);
		timer.stopTimer();
		khoangthoigian = timer.getElapsedTime();
		gotoxy(0, 10);
		cout << "Interchange Sort \t";
		gotoxy(30, 10);
		cout << khoangthoigian << "s \t";
		gotoxy(50, 10);
		cout << gan << "\t";
		gotoxy(70, 10 );
		cout << sosanh << "\t";
		delete[]a;


		sosanh = 0, gan = 0;
		NhapMang(a, n);
		timer.startTimer();
		InsertionSort(a, n, sosanh, gan);
		timer.stopTimer();
		khoangthoigian = timer.getElapsedTime();
		gotoxy(0, 12 );
		cout << "Insertion Sort \t";
		gotoxy(30, 12);
		cout << khoangthoigian << "s \t";
		gotoxy(50, 12 );
		cout << gan << "\t";
		gotoxy(70, 12 );
		cout << sosanh << "\t";
		delete[]a;


		sosanh = 0, gan = 0;
		NhapMang(a, n);
	 	timer.startTimer();
		ShakerSort(a, n, sosanh, gan);
		timer.stopTimer();
		khoangthoigian = timer.getElapsedTime();
		gotoxy(0, 14 );
		cout << "Shaker Sort \t";
		gotoxy(30, 14);
		cout << khoangthoigian << "s \t";
		gotoxy(50, 14 );
		cout << gan << "\t";
		gotoxy(70, 14 );
		cout << sosanh << "\t";
		delete[]a;


		sosanh = 0, gan = 0;
		NhapMang(a, n);
		timer.startTimer();
		MergeSort(a, 0, n - 1, sosanh, gan);
		timer.stopTimer();
		khoangthoigian = timer.getElapsedTime();
		gotoxy(0, 16 );
		cout << "Merge Sort \t";
		gotoxy(30, 16);
		cout << khoangthoigian << "s \t";
		gotoxy(50, 16);
		cout << gan << "\t";
		gotoxy(70, 16 );
		cout << sosanh << "\t";
		delete[]a;
		gotoxy(0, 20 );
		
		cout << "press any key to continue - esc to exit" << endl;
	
	} while (getch() != 27);

}

void DanhSach(){
	long*a;
	int n;
	unsigned long sosanh, gan;
	CStopWatch timer;
	float khoangthoigian;
	int option;
	int tam = 0;
	do{
		fflush(stdin);
		cin.clear();
		gotoxy(15, 5 + tam);
		cout << "1. Thuc hien tung phep sap xep" << endl;
		gotoxy(15, 7 + tam);
		cout << "2. So sanh toan bo phep sap xep" << endl;
		gotoxy(15, 9 + tam);
		cin >> option;
		tam += 10;
	} while (option <1 || option >2);
	if (option == 1){
		ListSort(a, n, timer, khoangthoigian, sosanh, gan);
	}
	else{
		Baocao(a, n, timer, khoangthoigian, sosanh, gan);
	}
}

void main(){
	
	DanhSach();

	system("pause");
}