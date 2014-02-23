     #include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

#define LEN (128/8)

int CutMp3(double strat,double end,char a[])
{
	FILE *fp_Read_Mp3,*fp_Write_Mp3;
	int i;
	char Buf[LEN];  //(128/8)����16B������ÿ�λ���16b����ÿ���и�Ҳ��16b
    int   start=strat*1000;
    int   endd = end*1000;
	fp_Read_Mp3 = fopen("E:/song.mp3","rb");
	char name[80];
	strcpy(name,"E:/");
	int lena=strlen(a);
	for(int y=lena;y>0;y--)
	{
        if(a[lena]=='\r'||a[lena]=='\n'||a[lena]=='\0')
        {
            lena--;
        }
         else
         {
            continue;
         }
    }
    char temp[30];
    memset(temp,0,sizeof(temp));
    for(int y=0;y<=lena;y++)
    {
        temp[y]=a[y];
    }
	strcat(name,temp);
	strcat(name,".mp3");

	fp_Write_Mp3 = fopen(name,"wb");

	if(fp_Read_Mp3 == NULL || fp_Write_Mp3 == NULL)
	{
		puts("Open the mp3 source failure!~");
		return 0;
	}
	
	fseek(fp_Read_Mp3,(long)(start*LEN),SEEK_CUR);


	puts("�ļ����ڽ�ȡ....");
	for (i=start; i<endd; i++)
	{
		fread(Buf,LEN,1,fp_Read_Mp3);
		fwrite(Buf,LEN,1,fp_Write_Mp3);
	}
	Sleep(1000);
	fclose(fp_Read_Mp3);
	fclose(fp_Write_Mp3);

	puts("��Ƶ��ȡ�ɹ���~");

	return 1;
}

double  stringToDouble(char buf[])
{
           char *endptr;
           double value=strtod(buf,&endptr);
           return value;
}

int main()
{
	double m,n;
	int i,h=0,k=0;
	int x=0;
	char str[500][30]; //�����������е�MP3�ļ���
	char buf[1024];    //��ʱ�洢һ��MP3�ļ���
    double time1[500];   //��������ʱ��㣬ÿ����ʱ���ȷ��һ��MP3�ļ�
     FILE *fp;
     int len;

     if((fp=fopen("E:/test1.txt","rb"))==NULL)
     {
    	puts("Open the txt source failure!~");
		return 0;
     }
      else
      {
        while(fgets(buf,1024,fp) != NULL)
        {
        len = strlen(buf);   //���ַ����ĳ���
       // printf("%s\n",buf);
         char a1[6];
         memset(a1,0,sizeof(a1));
        int j=0;
         for(i=0;i<6;i++)       //���ַ�������ȡ��ʼʱ����ַ���
         {
             a1[j++]=buf[i];
         }
         j=0;
         //printf("%s\n",a1);
        double startTime=stringToDouble(a1); //����ʼʱ����ַ�����Ϊdouble�͵�
        time1[k++]=startTime;
         memset(a1,0,sizeof(a1));
         for(i=7;i<13;i++)                // ���ַ�������ȡ��ֹʱ����ַ���
         {
               a1[j++]=buf[i];
         }
         // printf("%s\n",a1);
         j=0;
         double endTime=stringToDouble(a1);  //����ֹʱ����ַ�����Ϊdouble�͵�
         time1[k++]=endTime;

         char name[100];
         memset(name,0,sizeof(name));
          for(i=14;i<len;i++)
          {
             name[j++]=buf[i];
          }
           printf("%s\n",name);
           strcat(str[h++],name);
        }
        fclose(fp);
      }
       for(i=0;i<k;i=i+2)
       {
        printf("%lf %lf %s",time1[i],time1[i+1],str[x]);
         int flag=CutMp3(time1[i],time1[i+1],str[x++]);
          	
	if (flag == 1)
	{
		puts("��ϲ����~");
	}
    else
	{
		puts("��ȡʧ�ܣ�~");
	}	
       }
	
	
//
   return 0;
	/*���ݲ�ͬ�ĸ�����Ҫ�ı�LEN�Ĵ�С*/
}




