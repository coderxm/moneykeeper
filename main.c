#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>


// 户名结构体 
typedef struct{
	char hum[100];
//	char money[10];
}hums;

// 构造函数
void outdata(void); 
void empty(char *sf);
void putdata(hums *hm);
void qorw(hums *hm);
int strint(char *s);

int main(void){
		
	hums zhanghu[11];	//定义户名结构体数组 
	char get[4]; 
	char command[4];
	
	FILE *fpr;
	fpr = fopen("E:\\wokfilc\\moneykeeper\\data.txt","r");
	fgets(get,5,fpr);
	fclose(fpr);
	
	if(get=='\0'||get==" "){
		printf("无账户信息!");
		qorw(zhanghu);
	}else{
		outdata();
		printf("请继续写入wd或退出quit：\n");
		scanf("%s",command);
		if(strcmp(command,"quit")==0){
			exit(0);
		}else if(strcmp(command,"wd")==0){
			putdata(zhanghu);
			outdata();
			qorw(zhanghu);
		}else{
			printf("输入错误，请重新输入：\n");
			qorw(zhanghu);
		}
	}
	
	return 0;
} 

//输出信息 
void outdata(){
	FILE *fpr;
	fpr = fopen("E:\\wokfilc\\moneykeeper\\data.txt","r");
	
	int sum=0;
	char DataStr[100];
	printf("*****$$*****\n正在输出账户信息：\n");
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
	printf("您的总资金合计为：%d元\n",sum);
}

//empty初始化清空数组 
void empty(char *sf){
	int sfsize = 0;
	sfsize = sizeof(sf); 
	for(int n=0;n<sfsize;n++){
		sf[n] = '\0'; 
	}
} 

//写入数据 
void putdata(hums *hm){
	FILE *fpw;
	fpw = fopen("E:\\wokfilc\\moneykeeper\\data.txt","w+");
	
	int i = 0;
	char input[100];
	printf("(回车)请写入账户数据：\n");
	
	do{
		int len = 0;
		empty(input); 
		printf("请写入第%d个账户数据:\n",i+1);
		scanf("%s",input);	
		len = strlen(input);
		strcpy(hm[i].hum,input); 
		strcat(hm[i].hum,"\n");
		fputs(hm[i].hum,fpw);
		i = i+1;
	}while( (strcmp(input,"end"))!=0&&(i<11) );
	
	fclose(fpw);	//写入完毕后关闭文件 
}

//字符串中提取数字 
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

//选择（退出或重新写入）函数
void qorw(hums *hm){
    char getput[10];
	printf("请选择(重新)输入wrdo或退出quit：\n");
	scanf("%s",getput);
	while(strcmp(getput,"quit")!=0){
		if(strcmp(getput,"quit")==0){
			return;
		}else if(strcmp(getput,"wrdo")==0){
			putdata(hm);
			qorw(hm);
			return;
		}else{
			printf("重新输入,");
			qorw(hm);
			return;
		}
	}
} 




