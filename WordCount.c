#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void WordCount(char vare,const char* file_name){//-c统计字符数，-w统计单词数

	char log[1024]={0};
	char p;
	int i=0;//字符数
	int mode=vare;
	int j=0;
	int flag=1;
	int w_num=0;
	FILE *fp=fopen(file_name,"r");

	if(fp==NULL){
		printf("error");
	}
	while(1){
		if(EOF==fscanf(fp,"%c",&p))

			break;
		log[i]=p;
		i++;
	}
	if(mode==99){//99为C的ASCII码
		printf("字符数:%d\n",i);
	}
	else if(mode=119){//119为w的ASCII码
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
}
int main(void){
	char mode;
	char path[1024]={0};
	scanf("-%c %s",&mode,&path);
	WordCount(mode,path);
	system("pause");
}