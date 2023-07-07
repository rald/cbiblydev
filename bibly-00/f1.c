#include "ezxml/ezxml.h"



int main(void) {

	ezxml_t bible = ezxml_parse_file("kjv.xml"), book,chap,vers;

	const char *bname,*bsname;
	int cnum,vnum;	
	const char *text;

	FILE *fout=fopen("alt.txt","w");

	for(book=ezxml_child(bible,"BIBLEBOOK");book;book=book->next) {

		bname = ezxml_attr(book,"bname");
		bsname = ezxml_attr(book,"bsname");

		fprintf(fout,"%s|%s\n",bname,bsname);

	}

	fclose(fout);

	ezxml_free(bible);

	return 0;
}
