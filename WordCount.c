#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int   argc,char*  argv[]){
	char log[1024]={0};
	char p;

	int i=0;//字符数

	int j=0;
	int flag=1;
	int w_num=0;
	FILE *fp=fopen(argv[2],"r");

	if(fp==NULL){
		printf("error");
	}
	while(1){
		if(EOF==fscanf(fp,"%c",&p))
			break;
		log[i]=p;
		i++;
	}
	if(strcmp(argv[1],"-c")){//99为C的ASCII码
		printf("字符数:%d\n",i);
	}
	else if(argv[2],"-w"){//119为w的ASCII码
		for(j=0;log[j]!='\0';j++){
			if(flag==1){
				if(log[j]!=' '){
					flag=0;
					w_num++;
				}
			}
			else if(log[j]==' '||log[j]==','){
				flag=1;
			}
		}
		printf("单词数:%d\n",w_num);
	}
	fclose(fp);
	system("pause");
}

