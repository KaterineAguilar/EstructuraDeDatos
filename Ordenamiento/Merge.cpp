#include <iostream>
#define sufpeq 5
void Mix(int v[],int p1[],int p2[],int n){
	int i,j,k;
	i=j=0;
	
	for(k=0;i<n/2&&j<n-n/2;k++){	
		if(p1[i]<p2[j]){
			v[k]=p1[i];
			i++;
		}else{
			v[k]=p2[j];
			j++;
		}
	}

	while(i<n/2){
		v[k]=p1[i];
		i++; k++;
	}
	while(j<n-n/2){
		v[k]=p2[j];
		j++; k++;
	}
	
}
void Divide(int v[],int p1[],int p2[],int n){
	int i;
	for(i=0;i<n/2;i++) p1[i]=v[i];
	for(i;i<n;i++) p2[i-n/2]=v[i];
}
void Bubble(int v[],int n){
	int i,j,temp;
	for (i=1; i<n; i++)
		for (j=0 ; j<n - 1; j++)
        	if (v[j] > v[j+1])
            	temp = v[j];
                v[j] = v[j+1];
				v[j+1] = temp;
}
void Merge(int v[],int n){
	int *p1,*p2;
	if(n<=sufpeq) Bubble(v,n);
	else{
		p1 = new int[n/2];
		p2 = new int[n-n/2];
		Divide(v,p1,p2,n);
		Merge(p1,n/2);
		Merge(p2,n-n/2);
		Mix(v,p1,p2,n);
	}
}

int main(){
	
	int v[]={13,9,15,17,11,7,16,14,8,2};
	int p1[]={13,9,15,17,11};
	int p2[]={7,16,14,8,2};
	int n=10;
	
//	Merge(v,n);
	//voy por el metodo divide
	
		
	for(int i=0;i<n;i++) std::cout << v[i] << " ";
	
	
	return 0;	
}
