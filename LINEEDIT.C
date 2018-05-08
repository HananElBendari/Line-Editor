#include <conio.h>
#include <stdio.h>

char m1[50];
int p;

char strlength(char x[])
   {
	  int ic=0;
	  do{
		   ic++;
		}while(((x[ic]>=97)&&(x[ic]<=122))||((x[ic]>=48)&&(x[ic]<=57))||((x[ic]>=65)&&(x[ic]<=90)));

	  return ic;
   }

int main()
   {
	  int flag=0,flag2=0,j,i,j1,j2,j3,n1=0,i1,v;
	  char c;

	  for(i1=0;i1<50;i1++)
		 {
			m1[i1]='-';
		 }

	  do{
	  clrscr();
	  for(i=0;i<50;i++)
		 {
			if(i==p)
			   {
				  textattr(0x71);
			   }
			if(i<25)
			   gotoxy(30+n1,15);
			else
			   {
				  if(i==25)
					 n1=0;
				  gotoxy(30+n1,16);
			   }
			cprintf("%c",m1[i]);
			textattr(0x07);
			n1++;
		 }
	  n1=0;
	  c=getch();
	  if(c==NULL)
		 flag2=1;
	  else
		 flag2=0;

	  switch(c)
		 {
			case NULL:
			   c=getch();
			   switch(c)
				  {
					 case 75:
						if(flag2==1)
						   {
							  if((p>0)&&(p<=strlength(m1)))
								 p--;
						   }
					 break;
					 case 77:
						if(flag2==1)
						   {
							  if(p==0)
								 {
									if(m1[0]!='-')
									   p++;
								 }
							  if((p<strlength(m1))&&(p>0)&&(m1[p-1]!='-'))
								 p++;
						   }

					 break;
				  }
			break;
			case 27:
			   flag=1;
			break;
			case 8:
			   v=p;
			   while((m1[p] != '-')&&p>0&&p<49)
				  {
					 m1[p]=m1[p+1];
					 p++;
				  }
			   p=v;
			break;
			case 13:
			   gotoxy(20,10);
			   for(j=0;j<strlength(m1);j++)
				  {
					 printf("%c",m1[j]);
				  }
			   getch();
			break;
		 }

	  for(j=97;j<=122;j++)
		 {
			if(c==j)
			   {
				  m1[p]=c;
				  p++;
			   }
		 }
	  for(j2=48;j2<=57;j2++)
		 {
			if(c==j2)
			   {
				  m1[p]=c;
				  p++;
			   }
		 }

	  if((flag2==0))
		 {
			for(j3=65;j3<=90;j3++)
			   {
				  if(c==j3)
					{
					   m1[p]=c;
					   p++;
					}
			   }
		 }

	  }while(flag==0);

	  getch();
	  return 0;
   }

