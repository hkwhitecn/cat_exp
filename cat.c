/*
 *模拟命令行cat功能
 *written by：white
 *2016-6-7
 * */
#include<stdio.h>
int main(int argc,char *argv[]){

	FILE *fp;
	void filecopy(FILE *,FILE *);

	if (1 == argc){
		filecopy(stdin,stdout);
	}
	else
		while(--argc > 0){
		
			if((fp = fopen(*++argv,"r"))==NULL){
			
				printf("cat cont %s\n",*argv);
				return 1;
			}
			else{
			
				filecopy(fp,stdout);
				fclose(fp);
			}
			return 0;
		}

	return 0;
}


void filecopy(FILE *ifp,FILE *ofp){


	int c;
	while((c = getc(ifp)) != EOF){
	
		putc(c,ofp);
	}
}
