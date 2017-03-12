void swapName(vector <string> &name, int i, int k){
	string aux;
	
	aux = name[i];
	name[i] = name[k];
	name[k] = aux;
	
}
void swapLastName(vector <string> &lastName, int i, int k){
	string aux;
	
	aux = lastName[i];
	lastName[i] = lastName[k];
	lastName[k] = aux;
}
void swapId(vector <int> &id, int i, int k){
	int aux;
	
	aux = id[k];
	id[k] = id[i];
	id[i] = aux;
	
}

void shell(vector <int> &vec, int n, vector <string> &name, vector <string> &lastName){
	bool band;
	int incre, aux;
	incre = n/2;
	
	while(incre > 0){
		band = false;
		for(int i = 0; i+incre < n; i++){
			if(vec[i] > vec[i+incre]){
				aux = vec[i];
				vec[i] = vec[i+incre];
				vec[i+incre] = aux;
				band = true;
				swapName(name,i,i+incre);
				swapLastName(lastName,i,i+incre);
			}
		}
		if(!band) incre/=2;
	}
}

void strings(vector <string> &vec, int n, vector <int> &id, vector <string> &lastName){
	
	char nombre[10000][120];
    char aux[120];

    int i,j,k;
    int l=0;

	for(int i = 0;i < vec.size(); i++) {	
    	strcpy(nombre[l++], vec[i].c_str());
	}
    
    for(i=0; i<l-1; i++) {
        k=i;
        strcpy(aux, nombre[i]);
        for(j=i+1; j<l; j++) {
            if(strcmp(nombre[j], aux) < 0) {
                k=j;
                strcpy(aux, nombre[j]);
            }
        }
        swapId(id,i,k);
        swapName(vec,i,k);
        swapLastName(lastName,i,k);
        strcpy(nombre[k],nombre[i]); 
        strcpy(nombre[i],aux);
    }
}
