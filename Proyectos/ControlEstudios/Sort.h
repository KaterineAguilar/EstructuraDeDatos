void shell2(char des[][30], char aut[][20], int n) 
{
	bool band;
	int incre;
	char descaux[30];
	char autoraux[20];
	incre= n/2;
	
	while (incre > 0){
		band=false;
		for (int i = 0; i+incre < n; i++) {
			if(strcmp(des[i], des[i+incre]) > 0) {
				strcpy(descaux, des[i]);
				strcpy(des[i], des[i+incre]);
				strcpy(des[i+incre],descaux);
				
				strcpy(autoraux, aut[i]);
				strcpy(aut[i], aut[i+incre]);
				strcpy(aut[i+incre],autoraux);
				
				band=true;
			}
		}
		if(!band) incre/=2;
	}
}

