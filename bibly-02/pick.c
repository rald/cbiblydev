#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

double drand() {
	return rand()/(1.0+RAND_MAX);
}

int main(void) {

	srand(time(NULL));

	FILE *fin=fopen("kjv.csv","r");	

	char *line=NULL;
	size_t llen=0;
	ssize_t rlen=0;

	size_t n=0;

	char *sel=NULL;

	while((rlen=getline(&line,&llen,fin))!=-1) {

		if(drand()<1.0/++n) {
			if(sel!=NULL) free(sel);
			sel=strdup(line);
		}
	
		free(line);
		line=NULL;
		llen=0;
		rlen=0;
	}

	free(line);
	line=NULL;
	llen=0;
	rlen=0;

	printf("%s",sel);

	free(sel);
	sel=NULL;

	fclose(fin);
	
	return 0;
}
