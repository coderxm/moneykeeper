#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>


// �����ṹ�� 
typedef struct{
	char hum[100];
//	char money[10];
}hums;

// ���캯��
void outdata(void); 
void empty(char *sf);
void putdata(hums *hm);
void qorw(hums *hm);
int strint(char *s);

int main(void){
		
	hums zhanghu[11];	//���廧���ṹ������ 
	char get[4]; 
	char command[4];
	
	FILE *fpr;
	fpr = fopen("E:\\wokfilc\\moneykeeper\\data.txt","r");
	fgets(get,5,fpr);
	fclose(fpr);
	
	if(get=='\0'||get==" "){
		printf("���˻���Ϣ!");
		qorw(zhanghu);
	}else{
		outdata();
		printf("�����д��wd���˳�quit��\n");
		scanf("%s",command);
		if(strcmp(command,"quit")==0){
			exit(0);
		}else if(strcmp(command,"wd")==0){
			putdata(zhanghu);
			outdata();
			qorw(zhanghu);
		}else{
			printf("����������������룺\n");
			qorw(zhanghu);
		}
	}
	
	return 0;
} 

//�����Ϣ 
void outdata(){
	FILE *fpr;
	fpr = fopen("E:\\wokfilc\\moneykeeper\\data.txt","r");
	
	int sum=0;
	char DataStr[100];
	printf("*****$$*****\n��������˻���Ϣ��\n");
	while(feof(fpr)==0){
		fseek(fpr,0L,SEEK_CUR);				//?
		fgets(DataStr,100,fpr);
		if(DataStr!='\0'&&DataStr!=" "){
			printf("%s \n",DataStr);
		}		
		sum = sum+strint(DataStr);
		empty(DataStr);
	} 
	fclose(fpr);
	printf("�������ʽ�ϼ�Ϊ��%dԪ\n",sum);
}

//empty��ʼ��������� 
void empty(char *sf){
	int sfsize = 0;
	sfsize = sizeof(sf); 
	for(int n=0;n<sfsize;n++){
		sf[n] = '\0'; 
	}
} 

//д������ 
void putdata(hums *hm){
	FILE *fpw;
	fpw = fopen("E:\\wokfilc\\moneykeeper\\data.txt","w+");
	
	int i = 0;
	char input[100];
	printf("(�س�)��д���˻����ݣ�\n");
	
	do{
		int len = 0;
		empty(input); 
		printf("��д���%d���˻�����:\n",i+1);
		scanf("%s",input);	
		len = strlen(input);
		strcpy(hm[i].hum,input); 
		strcat(hm[i].hum,"\n");
		fputs(hm[i].hum,fpw);
		i = i+1;
	}while( (strcmp(input,"end"))!=0&&(i<11) );
	
	fclose(fpw);	//д����Ϻ�ر��ļ� 
}

//�ַ�������ȡ���� 
int strint(char *s){
	int slen=0;
	int Money=0;
	int ml = 0;
	char money[10];
	slen = strlen(s);
	for(int n=0;n<slen;n++){
		if(s[n]>=48&&s[n]<=57){
			money[ml]=s[n];
			ml++;
		}
	}
	Money = atoi(money);
	return Money;
}

//ѡ���˳�������д�룩����
void qorw(hums *hm){
    char getput[10];
	printf("��ѡ��(����)����wrdo���˳�quit��\n");
	scanf("%s",getput);
	while(strcmp(getput,"quit")!=0){
		if(strcmp(getput,"quit")==0){
			return;
		}else if(strcmp(getput,"wrdo")==0){
			putdata(hm);
			qorw(hm);
			return;
		}else{
			printf("��������,");
			qorw(hm);
			return;
		}
	}
} 




