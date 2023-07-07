#include "ezxml/ezxml.h"



int main(void) {

	ezxml_t bible = ezxml_parse_file("kjv.xml"), book,chap,vers;

	const char *bname,*bsname;
	int cnum,vnum;	
	const char *text;

	FILE *fp=fopen("alt.txt","w");

	for(book=ezxml_child(bible,"BIBLEBOOK");book;book=book->next) {

		bname = ezxml_attr(book,"bname");
		bsname = ezxml_attr(book,"bsname");

		fprintf(fp,"%s|%s\n",bname,bsname);
		
		for(chap=ezxml_child(book,"CHAPTER");chap;chap=chap->next) {
			for(vers=ezxml_child(chap,"VERS");vers;vers=vers->next) {

				bname = ezxml_attr(book,"bname");
				cnum = atoi(ezxml_attr(chap,"cnumber"));
				vnum = atoi(ezxml_attr(vers,"vnumber"));
				text = ezxml_txt(vers);

				printf("%s|%d|%d|%s\n",bname,cnum,vnum,text);
				
			}
		}
	}

	ezxml_free(bible);

	return 0;
}
