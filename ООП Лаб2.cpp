#include<iostream>
#include<string>
using namespace std;

int main() {
	srand(time(0));
	int size;
	cout << "Inter n: ";
	cin >> size;
	int** arr=new int*[size];//rows строчки
	for (int i = 0; i < size; i++) {
		arr[i] = new int[size]; //cals колонки
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == size-(j+1)) arr[i][j] = 0;
			else arr[i][j] = rand() % 49+1;
			
			cout << arr[i][j]<<"\t";
		}
		cout << endl;
	}

	int maxDown = 0;
	int minUp = 10;



	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i + j + 1 < size) {
				if (minUp > arr[i][j]) minUp = arr[i][j];
			}
			if (i + j + 1 > size) {
				if (maxDown < arr[i][j]) maxDown = arr[i][j];
			}
		}
	}

	cout << "max down: " << maxDown<<endl;
	cout << "min up: " << minUp;

	for (int i = 0; i < size; i++) {
		delete [] arr[i];
	}

	delete [] arr;
}