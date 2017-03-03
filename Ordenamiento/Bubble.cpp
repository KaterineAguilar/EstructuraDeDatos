#include <iostream>

using namespace std;

void Bubble(int v[],int n);

int main(int args, char** argv){
	
	int v[]={13,9,15,17,11,7,16,14,8,2};
	int n=10;
	
	Bubble(v,n);
	
	for(int i=0;i<n;i++) cout << v[i] << " ";
	
	return 0;
}

void Bubble(int v[],int n){
	int temp;
	for (int i=0; i<n; i++){
		for (int j=0 ; j<n-1; j++){
			if (v[j] > v[j+1]){
				temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;	
			}	
		}		
	}	
}
