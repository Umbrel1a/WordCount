#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void WordCount(char vare,const char* file_name){//-cͳ���ַ�����-wͳ�Ƶ�����

	char log[1024]={0};
	char p;
	int i=0;//�ַ���
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
	if(mode==99){//99ΪC��ASCII��
		printf("�ַ���:%d\n",i);
	}
	else if(mode=119){//119Ϊw��ASCII��
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
		printf("������:%d\n",w_num);
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