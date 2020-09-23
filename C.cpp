#include<iostream>
#include<string>
using namespace std;


int main (){
	int n;
	cin >> n;
	string A[n];
	string B;	
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	for(int i = 0; i < n; i++){
		B = A[i];
		for (int l = 0; l < B.size(); l++) {
			if(isupper(B[l])){
				B[l] = tolower(B[l]);
			}
			
		}
		A[i] = B;
	}
	
	
	
	for(int i = 0; i < n; i++){
		cout << A[i] << ' ';
	}
	cout << endl << endl;
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j >= 0; j--){
			if (A[j] < A[j + 1])
			{
				B = A[j];
				A[j] = A[j + 1];
				A[j + 1 ] = B;
			}
		}
	}
	
		for(int i = 0; i < n; i++){
		cout << A[i] << ' ';
	}
	cout << endl << endl;
	
	int x = 0;
	
	for (int i = 0; i < n; i++) {
		if (A[i+1] == A[i]) {
			x++;
		} else {
			cout << A[x] << ' ' ;
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
