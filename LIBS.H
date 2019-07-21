#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<logo.h>
void calculator();
void currency();
void tic_tac_toe();
void hp();
void piano();
void display();
void load();
void add_to_file();
int cheak_valid(char name_ch[],char pass_ch[]);
int cheak_usr(char name[]);
void start();
void start1();
void login();
void exit_pro();
void rainbow();
void enter_page();
void start()
{
      int gd=DETECT,gm;
      initgraph(&gd,&gm,"C:\\TC\\BGI");
      clearviewport();
      cleardevice();
      display();
}
void start1()
{
  int i,s,t,y,j,l;
  clrscr();
  textcolor(6);
  gotoxy(35,11);
  cprintf("LOADING...");

  t=19,y=22;
  for(i=0;i<=19;i++)
  {

    textcolor(8);
    gotoxy(t,13);
    cprintf("%c",219);
    gotoxy(t,13);
    t=t+2;
  }

   s=t=19;
    i=1;
     textcolor(15);

     if(i==1)
     {
      gotoxy(t,13);
      cprintf("%c",219);
      gotoxy(t,13);
      delay(100);
      i++;
      if(i==2)
      {
       gotoxy(t+2,13);
       cprintf("%c",219);
       gotoxy(t+2,13);
       delay(100);
       i++;
       if(i==3)
       {
	 gotoxy(t+4,13);
	 cprintf("%c",219);
	 gotoxy(t+4,13);
	 delay(100);

       }


      }
     }

 for(j=1;j<=5;j++)
 {
     t=19,y=22;

    for(i=1;i<=18;i++)
    {

      textcolor(15);
      gotoxy(t,13);
      cprintf("%c %c %c",219,219,219);
      gotoxy(t,13);
      delay(100);
      textcolor(8);
      gotoxy(t,13);
      cprintf("%c",219);
      gotoxy(t,13);

      t=t+2;
    }
     delay(100);
     gotoxy(t,13);
     cprintf("%c",219);

     gotoxy(t,13);
     delay(100);
     gotoxy(t+2,13);
     cprintf("%c",219);
     gotoxy(t+2,13);

  }
  enter_page();
}
void enter_page()
{
    int gd = DETECT, gm;
    char usr[11],pass[11];
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    while(1)
    {
		setcolor(6);
		rectangle(20,20,600,390);
		setcolor(8);
		rectangle(23,23,597,387);
		if(1==(button(145,60,475,185,"Login",8,5,7)))
		{
			closegraph();
			login();
		}
		if(1==(button(145,215,475,345,"Singup",8,5,7)))
		{
			closegraph();
			add_to_file();
		}
		if(1==(button(29,29,125,90,"EXIT",4,2,7)))
		{
		      closegraph();
		      exit_pro();
		}
    }
}
void login()
{
     int gd=DETECT,gm;
     char usr[11],pass[11],ch;
     int a=0;
     initgraph(&gd,&gm,"C:\\TC\\BGI");
     while(1)
     {
		settextstyle(0,0,0);
		if(1==(button(400,20,480,50,"Back",15,0,0)))
		{
		     closegraph();
		     enter_page();
		}
		outtextxy(25,25,"Name : ");
		if(1==(button(85,15,300,39,"",15,0,0)))
		{
		      gotoxy(14,2);
		      printf("                  ");
		      gotoxy(14,2);
		      scanf("%s",usr);
		}
		outtextxy(4,89,"Password : ");
		if(1==(button(85,75,300,100,"",15,0,0)))
		{
			 gotoxy(14,6);
			 printf("                  ");
			 gotoxy(14,6);
			 while((ch=getch())!=13)
			 {
				a=(a<0) ? 0 : a;
				if(ch==8)
				{
				      a--;
				      continue;
				}
				pass[a]=ch;
				a++;
			 }
			 pass[a]='\0';
		}
		if(1==(button(85,150,300,250,"DONE",15,3,0)))
		{
		      if(1==(cheak_valid(usr,pass)))
		      {
			  closegraph();
			  start();
		      }
		     else
		     {
			  closegraph();
			  printf("\n\n\tDont Worry");
			  getch();
		     }
		}


     }
}
void rainbow()
{
      int x,y,i;
      x=getmaxx() / 2;
      y=getmaxy() / 2;
      for(i=30;i<=200;i++)
      {
	   setcolor(i/10);
	   arc(x,y,0,180,i);
      }
}
void display()
{
     rainbow();
     outlogo(10,50,1);
     outlogo(10,120,3);
     outlogo(12,200,4);
     outlogo(10,270,2);
     while(1)
     {                                                            
	     if(1==(button(10,50,60,110,"",2,2,1)))
	     {
                      clearviewport();
		      currency();
	     }
	     if(1==(button(10,120,78,188,"",7,2,1)))
	     {
                     clearviewport();
		     calculator();
	     }
	     if(1==(button(10,200,72,263,"",0,2,1)))
	     {
                     clearviewport();
		     load();
	     }
     	     if(1==(button(10,270,55,317,"",0,2,1)))
     	     {
		     hp();
     	     } 
	     if(1==(button(550,50,630,100,"Exit",4,2,1)))
	     {
	 	     closegraph();
                     exit_pro();
      	     }

     }
}
void add_to_file()
{
     FILE *fp;
     static char name_student[16],coppy_name[16];
     static char add[30],ent_pass[10],test_name[16];
     static char birthday[9],phone[11];
     static int roll;
     int len;
     int gd = DETECT, gm;
     static int na=0,pho=0,bir=0,rol=0,addr=0,pas=0;
     initgraph(&gd,&gm,"C:\\TC\\BGI");
     fp=fopen("info","ab+");
     while(1)
     {
	  settextstyle(0,0,0);
	  if(1==(button(400,50,480,100,"Back",15,0,0)))
	  {
		   closegraph();
		   start();
	  }
	  outtextxy(25,25,"Name : ");
	  if(1==(button(85,15,300,39,"",15,0,0)))
	  {
		gotoxy(14,2);
		printf("                      ");
		gotoxy(14,2);
		scanf("%s",name_student);
		strcpy(coppy_name,name_student);
		len=strlen(coppy_name);
		if(len<2 && len>16)
		{
			na=0;
			setcolor(4);
			outtextxy(320,30,"Maximum length is 10");
			gotoxy(14,2);
			printf("                      ");

		}
		if((cheak_usr(coppy_name))==1)
		{
		    na=0;
		    setcolor(4);
		    outtextxy(320,15,"Already Exist");
		    gotoxy(14,2);
		    printf("                      ");
		}
		else
		{   na=1;
		}
	  }
	  outtextxy(18,89,"Mo No : ");
	  if(1==(button(85,76,300,100,"",15,0,0)))
	  {
		gotoxy(14,6);
		printf("                     ");
		gotoxy(14,6);
		scanf("%s",phone);
		len=strlen(phone);
		if(10!=len)
		{
		    pho=0;
		    setcolor(4);
		    outtextxy(310,90,"Invalid Length");
		    gotoxy(14,6);
		    printf("                      ");
		}
		else
		{   pho=1;
		}
	  }
	  outtextxy(4,142,"Birthday : ");
	  if(1==(button(85,137,300,161,"",15,0,0)))
	  {
		gotoxy(14,10);
		printf("                     ");
		gotoxy(14,10);
		scanf("%s",birthday);
		len=strlen(birthday);
		if(10!=len)
		{
		     bir=0;
		     setcolor(4);
		     outtextxy(310,151,"Invalid Birth-date(dd/mm/yyyy)");
		     gotoxy(14,10);
		     printf("                      ");
		}
		else
		{
		     bir=1;
		}
	  }
	  outtextxy(4,204,"Roll No : ");
	  if(1==(button(85,190,300,215,"",15,0,0)))
	  {
		gotoxy(14,13);
		printf("                     ");
		gotoxy(14,13);
		scanf("%d",&roll);
		rol=1;

	  }
	  outtextxy(4,264,"Address : ");
	  if(1==(button(85,252,300,279,"",15,0,0)))
	  {
		gotoxy(14,17);
		printf("                  ");
		gotoxy(14,17);
		scanf(" %[^\t\n]s",add);
		addr=1;

	  }
	  outtextxy(4,315,"Password : ");
	  if(1==(button(85,303,300,325,"",15,0,0)))
	  {
		gotoxy(14,20);
		printf("                     ");
		gotoxy(14,20);
		scanf("%s",ent_pass);
		len=strlen(ent_pass);
		if(len!=10)
		{
			pas=0;
			setcolor(4);
			outtextxy(310,315,"Length should be 10");
			gotoxy(14,20);
			printf("                      ");
		}
		else
		{
			pas=1;
		}
	  }
	  if(1==(button(85,350,300,390,"Submit",15,0,0)))
	  {
		if(na==1 && pho==1 && bir==1 && rol==1 && addr==1 && pas==1)
		{
			closegraph();
			fprintf(fp,"%s\t",name_student);
			fprintf(fp,"%s\t",phone);
			fprintf(fp,"%s\t",birthday);
			fprintf(fp,"%d\t",roll);
			fprintf(fp,"%s\t",add);
			fprintf(fp,"%s",ent_pass);
			fprintf(fp,"\n");
			fclose(fp);
			getch();
			printf("\n write");
                        closegraph();
                        enter_page();
		}
		else if(na==0 || pho==0 || bir==0 || rol==0 || addr==0 || pas==0)
		{
		  closegraph();
		  textcolor(4);
		  cprintf("\n : Fail to add to data base : ");
		  getch();
		  getch();
		  exit(1);
		}
	  }
     }
}
int cheak_usr(char name[])
{
     FILE *fp;
     char add[30],pass[10];
     char test_name[10],coppy_name[10];
     char birthday[9],phone[11];
     int roll,len;
     fp=fopen("info","rb");
	while(!feof(fp))
	{
		fscanf(fp,"%s%s%s%d",test_name,phone,birthday,&roll);
		strcpy(coppy_name,test_name);
		fscanf(fp," %[^\t\n]s",add);
		fscanf(fp,"%s",pass);
		if((strcmp(name,coppy_name))==0)
		{
			  return 1;
		}
	}
	fclose(fp);
	return 0;
}
int cheak_valid(char name_ch[],char pass_ch[]){

     FILE *fp;
     char pass[10],add[30],name[10],coppy_name[10];
     char birthday[9],phone[11];
     int roll;
     clrscr();
     fp=fopen("info","rb");
     while(!feof(fp)){
	fscanf(fp,"%s%s%s%d",name,phone,birthday,&roll);
	strcpy(coppy_name,name);
	fscanf(fp," %[^\t\n]s",add);
	fscanf(fp,"%s",pass);
	if((strcmp(name_ch,coppy_name))==0){
	   if((strcmp(pass,pass_ch))==0){
		  fclose(fp);
		  return 1;
	       }
	   }
	}
	fclose(fp);
	return 0;
}

void currency()
{

  long float no=0;
  int che=0,store=0;
  clearviewport();
  while(1)
  {

      if(1==(button(100,50,420,90,"",3,1,6)))
      {
	 gotoxy(20,5);
	 printf("                       ");
	 gotoxy(20,5);
	 scanf("%lf",&no);
      }
      if(1==(button(100,100,180,150,"Ruppes",2,1,6)))
      {
	 che=1;
      }
      if(1==(button(100,160,180,210,"Doller",6,1,6)))
      {
	 che=2;
      }
      if(1==(button(100,220,180,270,"Euro",4,1,6)))
      {
	 che=3;
      }
      if(1==(button(190,100,270,150,"Pound",5,1,6)))
      {
	 che=4;
      }
      if(1==(button(190,160,270,210,"Ruble",7,1,6)))
      {
	 che=5;
      }
      if(1==(button(190,220,270,270,"Yen",8,1,6)))
      {
	 che=6;
      }
      if(1==(button(280,100,360,150,"convert",9,1,6)))
      {
	 switch(che)
	 {
	     case 1:
		  store=1;
		  break;
	     case 2:
		  store=2;
		  break;
	     case 3:
		  store=3;
		  break;
	     case 4:
		  store=4;
		  break;
	     case 5:
		  store=5;
		  break;
	     case 6:
		  store=6;
		  break;
	     default:
		  outtextxy(370,140,"Plese Select the currency : ");
		  clearviewport();
		  break;
	 }
      }
      if(1==(button(280,160,360,210,"Answer",10,1,6)))
      {
	 if(che==store)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no);
	 }
	 if(store==1  && che==2)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no*0.014);
	 }
	 if(store==2  && che==1)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no/0.014);
	 }
	 if(store==1  && che==3)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no*0.012);
	 }
	 if(store==3  && che==1)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no/0.012);
	 }
	 if(store==1  && che==4)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no*0.011);
	 }
	 if(store==4  && che==1)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no/0.011);
	 }
	 if(store==1  && che==5) 
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no*0.93);
	 }
	 if(store==5  && che==1)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no/0.93);
	 }
	 if(store==1  && che==6)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no*1.55);
	 }
	 if(store==6  && che==1)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no/1.55);
	 }
	 if(store==2  && che==3)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no*0.89);
	 }
	 if(store==3  && che==2)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no/0.89);
	 }
	 if(store==2  && che==4)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no*0.78);
	 }
	 if(store==4  && che==2)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no/0.78);
	 }
	 if(store==2  && che==5)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no*66.29);
	 }
	 if(store==5  && che==2)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no/66.29);
	 }
	 if(store==2  && che==6)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no*110.50);
	 }
	 if(store==6  && che==2)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no/110.50);
	 }
	 if(store==3  && che==4)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no*0.88);
	 }
	 if(store==4  && che==3)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no/0.88);
	 }
	 if(store==3  && che==5)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no*74.88);
	 }
	 if(store==5  && che==3)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no/74.88);
	 }
	 if(store==3  && che==6)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no*124.82);
	 }
	 if(store==6  && che==3)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no/124.82);
	 }
	 if(store==4  && che==5)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no*85.48);
	 }
	 if(store==5  && che==4)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no/85.48);
	 }
	 if(store==4  && che==6)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no*142.50);
	 }
	 if(store==6  && che==4)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no/142.50);
	 }
	 if(store==5  && che==6)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no*1.67);
	 }
	 if(store==6  && che==5)
	 {
	     clearviewport();
	     gotoxy(20,5);
	     printf("%lf",no/1.67);
	 }

      }
      if(1==(button(280,220,360,270,"Exit",11,1,6)))
      {
         clearviewport();
	 display();
      }
      if(1==(button(370,100,420,270,"Clear",11,1,6)))
      {
	 clearviewport();
      }

  }
}
void calculator()
{
  long float no1=0,no2=0,c=0,che=0,b;
  clearviewport();
  while(1)
  {
      if(1==(button(80,40,470,80,"",3,0,5)))
      {

      }
      if(1==(button(80,100,120,145,"1",7,7,2)))
      {
	 if(c==0)
	 {
	   no1=(no1*10)+1;
	   gotoxy(12,4);
	   printf("%lf",no1);
	 }
	 if(c==1)
	 {
	   no2=(no2*10)+1;
	   gotoxy(30,4);
	   printf("%lf",no2);
	 }
      }
      if(1==(button(80,155,120,200,"2",7,7,2)))
      {
	 if(c==0)
	 {
	   no1=(no1*10)+2;
	   gotoxy(12,4);
	   printf("%lf",no1);
	 }
	 if(c==1)
	 {
	   no2=(no2*10)+2;
	   gotoxy(30,4);
	   printf("%lf",no2);

	 }
      }
      if(1==(button(80,210,120,260,"3",7,7,2)))
      {
	 if(c==0)
	 {
	   no1=(no1*10)+3;
	   gotoxy(12,4);
	   printf("%lf",no1);
	 }
	 if(c==1)
	 {
	   no2=(no2*10)+3;
	   gotoxy(30,4);
	   printf("%lf",no2);

	 }
      }
      if(1==(button(130,100,170,145,"4",7,7,2)))
      {
	 if(c==0)
	 {
	   no1=(no1*10)+4;
	   gotoxy(12,4);
	   printf("%lf",no1);

	 }
	 if(c==1)
	 {
	   no2=(no2*10)+4;
	   gotoxy(30,4);
	   printf("%lf",no2);

	 }
      }
      if(1==(button(130,155,170,200,"5",7,7,2)))
      {
	 if(c==0)
	 {
	   no1=(no1*10)+5;
	   gotoxy(12,4);
	   printf("%lf",no1);

	 }
	 if(c==1)
	 {
	   no2=(no2*10)+5;
	   gotoxy(30,4);
	   printf("%lf",no2);

	 }
      }
      if(1==(button(130,210,170,260,"6",7,7,2)))
      {
	 if(c==0)
	 {
	   no1=(no1*10)+6;
	   gotoxy(12,4);
	   printf("%lf",no1);

	 }
	 if(c==1)
	 {
	   no2=(no2*10)+6;
	   gotoxy(30,4);
	   printf("%lf",no2);

	 }
      }
      if(1==(button(180,100,220,145,"7",7,7,2)))
      {
	 if(c==0)
	 {
	   no1=(no1*10)+7;
	   gotoxy(12,4);
	   printf("%lf",no1);

	 }
	 if(c==1)
	 {
	   no2=(no2*10)+7;
	   gotoxy(30,4);
	   printf("%lf",no2);

	 }
      }
      if(1==(button(180,155,220,200,"8",7,7,2)))
      {
	 if(c==0)
	 {
	   no1=(no1*10)+8;
	   gotoxy(12,4);
	   printf("%lf",no1);

	 }
	 if(c==1)
	 {
	   no2=(no2*10)+8;
	   gotoxy(30,4);
	   printf("%lf",no2);

	 }
      }

      if(1==(button(180,210,220,260,"9",7,7,2)))
      {
	 if(c==0)
	 {
	   no1=(no1*10)+9;
	   gotoxy(12,4);
	   printf("%lf",no1);

	 }
	 if(c==1)
	 {
	   no2=(no2*10)+9;
	   gotoxy(30,4);
	   printf("%lf",no2);

	 }
      }
      if(1==(button(230,100,270,145,"0",7,7,2)))
      {
	 if(c==0)
	 {
	   no1=(no1*10)+0;
	   gotoxy(12,4);
	   printf("%lf",no1);

	 }
	 if(c==1)
	 {
	   no2=(no2*10)+0;
	   gotoxy(30,4);
	   printf("%lf",no2);

	 }
      }
      if(1==(button(230,210,270,260,"=",6,7,2)))
      {
	if(che==1)
	{
	    gotoxy(37,5);
	    printf("  = %lf",no1+no2);
	}
	if(che==2)
	{
	    gotoxy(37,5);
	    printf("  = %lf",no1-no2);

	}
	if(che==3)
	{
	    gotoxy(37,5);
	    printf("  = %lf",no1*no2);

	}
	if(che==4)
	{
	    gotoxy(37,5);
	    printf("  = %lf",no1/no2);

	}
	if(che==5)
	{
	    gotoxy(37,5);
	    printf("  = %lf",no1*no1);

	}
	if(che==6)
	{
	    gotoxy(37,5);
	    printf("  =  %lf",no1*no1*no1);

	}
      }
      if(1==(button(230,155,270,200,"+",6,7,2)))
      {
	c=1;
	che=1;
	clearviewport();
	gotoxy(12,4);
	printf("%lf + ",no1);

      }
      if(1==(button(280,100,320,145,"-",6,7,2)))
      {
	c=1;
	che=2;
	clearviewport();
	gotoxy(12,4);
	printf("%lf  - ",no1);

      }
      if(1==(button(280,155,320,200,"*",6,7,2)))
      {
	c=1;
	che=3;
	clearviewport();
	gotoxy(12,4);
	printf("%lf  * ",no1);

      }
      if(1==(button(280,210,320,260,"/",6,7,2)))
      {
	c=1;
	che=4;
	clearviewport();
	gotoxy(12,4);
	printf("%lf  / ",no1);

      }
      if(1==(button(330,210,450,260,"clear",4,6,2)))
      {
	c=0;
	che=0;
	no1=0;
	no2=0;
	clearviewport();

      }
      if(1==(button(380,100,450,200,"exit",4,6,2)))
      {
        clearviewport();
	display();
      }
      if(1==(button(330,100,370,145,"^2",6,6,2)))
      {
	     c=1;
	     che=5;
	     clearviewport();
	     gotoxy(12,4);
	     printf("%lf  ^2 ",no1);

      }
      if(1==(button(330,155,370,200,"^3",6,6,2)))
      {
	     c=1;
	     che=6;
	     clearviewport();
	     gotoxy(12,4);
	     printf("%lf  ^3 ",no1);

      }
  }
}
void load()
{
     clearviewport();
     setcolor(14);
     rectangle(30,30,580,330);
     settextstyle(1,0,5);
     setcolor(11);
     outtextxy(140,35," * Tic Tac Toe *");
     while(1)
     {
	  if(1==(button(200,130,400,190,"  Start",6,3,1)))
	  {
                 clearviewport();
		 tic_tac_toe();
	  }
	  if(1==(button(200,210,400,270,"  Exit ",4,3,1)))
	  {
                clearviewport();
		display();
	  }

     }
}
void exit_pro()
{
     int gd=DETECT,gm,stx=15,sty=180,enx=520,eny=0,calmov=510;
     int movex=0,movey=380;
     initgraph(&gd,&gm,"C:\\TC\\BGI");
     while(1)
     {
       if(movey> eny)
       {
	outlogo(0,movey,4);
	movey-=3;
       }
       if(movex< enx)
       {
	outlogo(movex,0,1);
	movex+=3;
       }
       if(movex > enx && movey< eny)
       break;
       outlogo(enx,movex<350 ? movex : 350 ,2);
       outlogo(calmov> 0 ? calmov-=3 : 0,340,3);
       rectangle(calmov+70,400,calmov+65,415);
     }
     settextstyle(9,0,1);
     outtextxy(190,100,"# About Developer #");
     settextstyle(7,0,1);
     outtextxy(170,170,"Mr.Shitij Shailendra Agrawal");
     outtextxy(170,200,"Mr.Digambar Balu Chaduhari");
     outtextxy(170,230,"Mr.Hemant Yashwant Patil");
     outtextxy(170,260,"Mr.Jayesh Ramchandra Punjabi");
     outtextxy(170,290,"Mr.Rushikesh Madhukar Patil");
     outtextxy(170,320,"Mr.Pavan Pravin Patil");
     outtextxy(170,350,"Mr.Amol Ramesh Patil");
     getch();
     closegraph();
     exit(1);
}
void tic_tac_toe()
{

  int ch[9]={0,0,0,0,0,0,0,0,0},c=1,d=0;
  int b1=0,b2=0,b3=0,b4=0,b5=0,b6=0,b7=0,b8=0,b9=0;
  clearviewport();
  while(1)
  {
       rectangle(30,30,600,330);
       settextstyle(9,0,1);
       outtextxy(40,40,": Two Player Game : ");
       settextstyle(3,0,1);
       outtextxy(300,110," X : First Player");
       outtextxy(300,130," O : Second Player");
       outtextxy(300,200," Result :");
       if(1==(button(130,110,170,160,"",14,4,1)))
       {
	   if(ch[0]==0)
	   {
	       c++;
	       if(c%2==0)
	       {
		  outtextxy(140,125,"X");
		  b1=1;
	       }
	       else
	       {
		  outtextxy(140,125,"O");
		  b1=2;
	       }
	   }
	   ch[0]=1;
       }
       if(1==(button(171,110,211,160,"",14,4,1)))
       {
	   if(ch[1]==0)
	   {
	       c++;
	       if(c%2==0)
	       {
		  outtextxy(181,125,"X");
		  b2=1;
	       }
	       else
	       {
		  outtextxy(181,125,"O");
		  b2=2;
	       }
	   }
	   ch[1]=1;
       }
       if(1==(button(212,110,252,160,"",14,4,1)))
       {
	   if(ch[2]==0)
	   {
	       c++;
	       if(c%2==0)
	       {
		  outtextxy(220,125,"X");
		  b3=1;
	       }
	       else
	       {
		  outtextxy(220,125,"O");
		  b3=2;
	       }
	   }
	   ch[2]=1;
       }
       if(1==(button(130,161,170,211,"",14,4,1)))
       {
	   if(ch[3]==0)
	   {
	       c++;
	       if(c%2==0)
	       {
		  outtextxy(140,176,"X");
		  b4=1;
	       }
	       else
	       {
		  outtextxy(140,176,"O");
		  b4=2;
	       }
	   }
	   ch[3]=1;
       }
       if(1==(button(171,161,211,211,"",14,4,1)))
       {
	   if(ch[4]==0)
	   {
	       c++;
	       if(c%2==0)
	       {
		  outtextxy(181,176,"X");
		  b5=1;
	       }
	       else
	       {
		  outtextxy(181,176,"O");
		  b5=2;
	       }
	   }
	   ch[4]=1;
       }
       if(1==(button(212,161,252,211,"",14,4,1)))
       {
	   if(ch[5]==0)
	   {
	       c++;
	       if(c%2==0)
	       {
		  outtextxy(220,176,"X");
		  b6=1;
	       }
	       else
	       {
		  outtextxy(220,176,"O");
		  b6=2;
	       }
	   }
	   ch[5]=1;
       }
       if(1==(button(130,212,170,262,"",14,4,1)))
       {
	   if(ch[6]==0)
	   {
	       c++;
	       if(c%2==0)
	       {
		  outtextxy(140,225,"X");
		  b7=1;
	       }
	       else
	       {
		  outtextxy(140,225,"O");
		  b7=2;
	       }
	   }
	   ch[6]=1;
       }
       if(1==(button(171,212,211,262,"",14,4,1)))
       {
	   if(ch[7]==0)
	   {
	       c++;
	       if(c%2==0)
	       {
		  outtextxy(181,225,"X");
		  b8=1;
	       }
	       else
	       {
		  outtextxy(181,225,"O");
		  b8=2;
	       }
	   }
	   ch[7]=1;
       }
       if(1==(button(212,212,252,262,"",14,4,1)))
       {
	   if(ch[8]==0)
	   {
	       c++;
	       if(c%2==0)
	       {
		  outtextxy(220,225,"X");
		  b9=1;
	       }
	       else
	       {
		  outtextxy(220,225,"O");
		  b9=2;
	       }
	   }
	   ch[8]=1;
       }
       if((b1==1 && b4==1 && b7==1) || (b1==2 && b4==2 && b7==2) || (b2==1 && b5==1 && b8==1) || (b2==2 && b5==2 && b8==2) || (b3==1 && b6==1 && b9==1) || (b3==2 && b6==2 && b9==2) || (b1==1 && b5==1 && b9==1) || (b1==2 && b5==2 && b9==2) || (b3==1 && b5==1 && b7==1) || (b3==2 && b5==2 && b7==2) || (b4==1 && b5==1 && b6==1) || (b4==2 && b5==2 && b6==2) || (b1==1 && b2==1 && b3==1) || (b1==2 && b2==2 && b3==2) || (b7==1 && b8==1 && b9==1) || (b7==2 && b8==2 && b9==2))
       {
	      if(b1==1 && b4==1 && b7==1)
	      {
		  settextstyle(3,0,1);
		  outtextxy(390,240,": First Player is Win :");
		  getch();
                  clearviewport();
		  load();
	      }
	      if(b1==2 && b4==2 && b7==2)
	      {
		  settextstyle(3,0,1);
		  outtextxy(390,240,": Second Player is Win :");
		  getch();
                  clearviewport();
		  load();
	      }
	      if(b2==1 && b5==1 && b8==1)
	      {
		  settextstyle(3,0,1);
		  outtextxy(390,240,": First Player is Win :");
		  getch();
                  clearviewport();
		  load();
	      }
	      if(b2==2 && b5==2 && b8==2)
	      {
		  settextstyle(3,0,1);
		  outtextxy(390,240,": Second Player is Win :");
		  getch();
                  clearviewport();
		  load();
	      }
	      if(b3==1 && b6==1 && b9==1)
	      {
		  settextstyle(3,0,1);
		  outtextxy(390,240,": First Player is Win :");
		  getch();
                  clearviewport();
		  load();
	      }
	      if(b3==2 && b6==2 && b9==2)
	      {
		  settextstyle(3,0,1);
		  outtextxy(390,240,": Second Player is Win :");
		  getch();
                  clearviewport();
		  load();
	      }
	      if(b1==1 && b5==1 && b9==1)
	      {
		  settextstyle(3,0,1);
		  outtextxy(390,240,": First Player is Win :");
		  getch();
                  clearviewport();
		  load();
	      }
	      if(b1==2 && b5==2 && b9==2)
	      {
		  settextstyle(3,0,1);
		  outtextxy(390,240,": Second Player is Win :");
		  getch();
                  clearviewport();
		  load();
	      }
	      if(b3==1 && b5==1 && b7==1)
	      {
		  settextstyle(3,0,1);
		  outtextxy(390,240,": First Player is Win :");
		  getch();
                  clearviewport();
		  load();
	      }
	      if(b3==2 && b5==2 && b7==2)
	      {
		  settextstyle(3,0,1);
		  outtextxy(390,240,": Second Player is Win :");
		  getch();
                  clearviewport();
		  load();
	      }
	      if(b4==1 && b5==1 && b6==1)
	      {
		  settextstyle(3,0,1);
		  outtextxy(390,240,": First Player is Win :");
		  getch();
                  clearviewport();
		  load();
	      }
	      if(b4==2 && b5==2 && b6==2)
	      {
		  settextstyle(3,0,1);
		  outtextxy(390,240,": Second Player is Win :");
		  getch();
                  clearviewport();
		  load();
	      }
	      if(b1==1 && b2==1 && b3==1)
	      {
		  settextstyle(3,0,1);
		  outtextxy(390,240,": First Player is Win :");
		  getch();
                  clearviewport();
		  load();
	      }
	      if(b1==2 && b2==2 && b3==2)
	      {
		  settextstyle(3,0,1);
		  outtextxy(390,240,": Second Player is Win :");
		  getch();
                  clearviewport();
		  load();
	      }
	      if(b7==1 && b8==1 && b9==1)
	      {
		  settextstyle(3,0,1);
		  outtextxy(390,240,": First Player is Win :");
		  getch();
                  clearviewport();
		  load();
	      }
	      if(b7==2 && b8==2 && b9==2)
	      {
		  settextstyle(3,0,1);
		  outtextxy(390,240,": Second Player is Win :");
		  getch();
                  clearviewport();
		  load();
	      }
       }
       if(ch[0]==1 && ch[1]==1 && ch[2]==1 && ch[3]==1 && ch[4]==1 && ch[5]==1 && ch[6]==1 && ch[7]==1 && ch[8]==1)
       {
	      settextstyle(3,0,1);
	      outtextxy(390,240,": Draw :");
	      getch();
              clearviewport();
	      load();
       }
       if(b1==1)
       {
		   outtextxy(140,125,"X");
	   }
	   if(b1==2)
	   {
		   outtextxy(140,125,"O");		   
	   }
       if(b2==1)
       {
		   outtextxy(181,125,"X");
	   }
	   if(b2==2)
	   {
		   outtextxy(181,125,"O");		   
	   }
       if(b3==1)
       {
		   outtextxy(220,125,"X");
	   }
	   if(b3==2)
	   {
		   outtextxy(220,125,"O");		   
	   }
       if(b4==1)
       {
		   outtextxy(140,176,"X");
	   }
	   if(b4==2)
	   {
		   outtextxy(140,176,"O");		   
	   }
       if(b5==1)
       {
		   outtextxy(181,176,"X");
	   }
	   if(b5==2)
	   {
		   outtextxy(181,176,"O");		   
	   }
       if(b6==1)
       {
		   outtextxy(220,176,"X");
	   }
	   if(b6==2)
	   {
		   outtextxy(220,176,"O");		   
	   }
       if(b7==1)
       {
		   outtextxy(140,225,"X");
	   }
	   if(b7==2)
	   {
		   outtextxy(140,225,"O");		   
	   }
	   if(b8==1)
       {
		   outtextxy(181,225,"X");
	   }
	   if(b8==2)
	   {
		   outtextxy(181,225,"O");		   
	   }
	   if(b9==1)
       {
		   outtextxy(220,225,"X");
	   }
	   if(b9==2)
	   {
		   outtextxy(220,225,"O");		   
	   }


  }

}
void hp()
{
  int i,a,b,p,q,c1,c2,op,v,v1,m1,m2;
  long char str1[100];
  closegraph();
  textbackground(0);
M:
  clrscr();
  gotoxy(12,5);
  textmode(40);
  textcolor(6);
  cprintf("ENTER YOUR NAME : ");
  strupr(str1);cscanf("%s",str1);

  M1:
  clrscr();
  c1=25,c2=3;

  textcolor(3);

  for(i=0;i<=27;i++)
  {
    gotoxy(c1,c2);
    cprintf("%c",178);
    gotoxy(c1,c2+1);
    cprintf("%c",177);
    gotoxy(c1,c2+2);
    cprintf("%c",176);
    c1++;
  }
  for(i=0;i<=18;i++)
  {
    gotoxy(c1-1,c2+2);
    cprintf("%c",176);
    c2++;
  }
  for(i=0;i<=18;i++)
  {
    gotoxy(c1-28,c2-17);
    cprintf("%c",176);
    c2++;
  }
    c1=25,c2=21;


  for(i=0;i<=27;i++)
  {
    gotoxy(c1,c2);
    cprintf("%c",176);
    gotoxy(c1,c2+1);
    cprintf("%c",177);
    gotoxy(c1,c2+2);
    cprintf("%c",178);
    c1++;
  }

  a=33,b=8,p=45,q=8;
  delay(1000);
  textcolor(15);
  gotoxy(33,8);
  cprintf("%c MAIN MENU %c",175,174);

  delay(1000);

 for(i=0;i<=0;i++)
 {
     textcolor(6);
     gotoxy(a,b);
     cprintf("%c",175);
     delay(100);
     textcolor(0);
     gotoxy(a,b);
     cprintf("%c",175);

     textcolor(2);
     gotoxy(p,q);
     cprintf("%c",174);
     delay(100);
     textcolor(0);
     gotoxy(p,q);
     cprintf("%c",174);
     q++;
     b--;
 }

     textcolor(6);
     gotoxy(a,b);
     cprintf("%c",24);

     textcolor(2);
     gotoxy(p,q);
     cprintf("%c",25);

     delay(1000);

     textcolor(6);
     gotoxy(a,b);
     cprintf("%c",26);

     textcolor(2);
     gotoxy(p,q);
     cprintf("%c",27);

     delay(1000);
 for(i=0;i<=12;i++)
 {
     textcolor(6);
     gotoxy(a,b);
     cprintf("%c",175);

     textcolor(2);
     gotoxy(p,q);
     cprintf("%c",174);
     delay(10);
     p--;
     a++;
 }
    delay(500);

  textcolor(8);
  gotoxy(30,11);
  cprintf("1] PLAY.( %c )",14);
  gotoxy(30,13);
  cprintf("2] ABOUT.");
  gotoxy(30,15);
  cprintf("3] HELP.");
  gotoxy(30,17);
  cprintf("4] EXIT.");

A:
J:
  textbackground(0);
  clrscr();
  c1=25,c2=3;

  textcolor(3);

  for(i=0;i<=27;i++)
  {
    gotoxy(c1,c2);
    cprintf("%c",178);
    gotoxy(c1,c2+1);
    cprintf("%c",177);
    gotoxy(c1,c2+2);
    cprintf("%c",176);
    c1++;
  }
  for(i=0;i<=18;i++)
  {
    gotoxy(c1-1,c2+2);
    cprintf("%c",176);
    c2++;
  }
  for(i=0;i<=18;i++)
  {
    gotoxy(c1-28,c2-17);
    cprintf("%c",176);
    c2++;
  }
    c1=25,c2=21;


  for(i=0;i<=27;i++)
  {
    gotoxy(c1,c2);
    cprintf("%c",176);
    gotoxy(c1,c2+1);
    cprintf("%c",177);
    gotoxy(c1,c2+2);
    cprintf("%c",178);
    c1++;
  }

  a=33,b=8,p=45,q=8;
  textcolor(15);
  gotoxy(33,8);
  cprintf("%c MAIN MENU %c",175,174);


 for(i=0;i<=0;i++)
 {
     textcolor(6);
     gotoxy(a,b);
     cprintf("%c",175);
     textcolor(0);
     gotoxy(a,b);
     cprintf("%c",175);

     textcolor(2);
     gotoxy(p,q);
     cprintf("%c",174);
     textcolor(0);
     gotoxy(p,q);
     cprintf("%c",174);
     q++;
     b--;
 }

     textcolor(6);
     gotoxy(a,b);
     cprintf("%c",24);

     textcolor(2);
     gotoxy(p,q);
     cprintf("%c",25);

     textcolor(6);
     gotoxy(a,b);
     cprintf("%c",26);

     textcolor(2);
     gotoxy(p,q);
     cprintf("%c",27);

 for(i=0;i<=12;i++)
 {
     textcolor(6);
     gotoxy(a,b);
     cprintf("%c",175);

     textcolor(2);
     gotoxy(p,q);
     cprintf("%c",174);
     p--;
     a++;
 }

  textcolor(8);
  gotoxy(30,11);
  cprintf("1] PLAY.( %c )",14);
  gotoxy(30,13);
  cprintf("2] ABOUT.");
  gotoxy(30,15);
  cprintf("3] HELP.");
  gotoxy(30,17);
  cprintf("4] EXIT.");

  textcolor(15);
  gotoxy(28,20);
  cprintf("%s SELECT option : ",str1);

  scanf("%d",&op);

  switch(op)
  {
    case 1: goto L;
    case 2: goto O;
    case 3: goto PIA;
    case 4: goto I;

    default:  goto J;

  }




  ////ABOUT PIANO,...

 O:
 S1:
   clrscr();
   gotoxy(5,5);
   printf(" ABOUT PIANO:");

   textcolor(7);

   gotoxy(23,8);
   textcolor(7);
   printf(" DURATION : 2 Days.");
   gotoxy(23,10);
   printf(" USE OF GRAPHICS : NO.");

   textcolor(7);
   gotoxy(20,15);
   cprintf("press :   ENTER to back the MAIN MENU.");
   gotoxy(20,17);
   cprintf("          ESC to EXIT.");


  switch(getch())
  {
    case 27: goto I1;
    case 13: goto J;
    default: goto S1;
  }

  PIA:


      ///PIANO HELP
      clrscr();

      textcolor(3);
      gotoxy(30,5);
      cprintf("%c%c%c CONTROL OF PIANO %c%c%c",3,3,3,3,3,3);
      textcolor(2);
      gotoxy(10,8);
      cprintf("HOW TO PLAY :");
      textcolor(7);
      gotoxy(15,10);
      cprintf("* LIGHT SOUND From 'Q'=>> Key Of Keyboard And To The 'P' Key");
      gotoxy(15,11);
      cprintf("* DARK SOUND From '1' Key Of Keyboard And To The '0'(ZERO) Key");
      textcolor(7);
   gotoxy(20,15);
   cprintf("press :   ENTER to back the MAIN MENU.");
   gotoxy(20,17);
   cprintf("          ESC to EXIT.");


  switch(getch())
  {
    case 27: goto I1;
    case 13: goto J;
    default: goto PIA;
  }
   ///PIANO HELP
    a=3,b=3;

      for(i=0;i<=50;i++)
      {
	gotoxy(a,b);
	cprintf("%c",219);
	a++;
      }
      textcolor(7);
      gotoxy(5,12);
      cprintf("HELP : To ENJOY PIANO BUTTONS Start from , >>> [Q] [W] [E] .");
      gotoxy(5,13);
      cprintf("    BUTTONS Ends to , [ F10 ]  [ F11 ]  [ F12 ] <<< .");


   textcolor(12);
   gotoxy(5,17);
   cprintf("press :   ENTER to back the MAIN MENU.");
   gotoxy(5,19);
   cprintf("          ESC to EXIT.");

  switch(getch())
  {
    case 27: goto I1;
    case 13: goto J;
  }

  ////EXIT PIANO






   if(op==3)
   {
    I:
    clrscr();
    gotoxy(25,12);
    textcolor(6);
    cprintf("THANK YOU ");
    textcolor(15);
    cprintf("FOR VISITING ");
    textcolor(2);
    cprintf("MY PIANO !");

    delay(2000);

    gotoxy(25,12);
    textcolor(6+128);
    cprintf("THANK YOU ");
    textcolor(15);
    cprintf("FOR VISITING ");
    textcolor(2+128);
    cprintf("MY PIANO !");
    delay(2000);
    gotoxy(25,12);
    textcolor(0+128);
    cprintf("THANK YOU ");
    textcolor(15);
    gotoxy(38,12);
    cprintf("FOR VISITING ");
    textcolor(0+128);
    cprintf("MY PIANO !");

    gotoxy(38,11);
    textcolor(6);
    cprintf("THANK YOU ");
    gotoxy(38,13);
    textcolor(2);
    cprintf("MY PIANO !");
    delay(3000);
    start();
  }
  else
  { if(op==0)
   {
    I1:
    clrscr();
    gotoxy(30,12);
    strupr(str1);
    textcolor(2);
    cprintf("%s, THANKS FOR USING MY PIANO !",str1);
    delay(1000);
    gotoxy(30,12);
    textcolor(2+128);
    cprintf("%s, THANKS FOR USING MY PIANO !",str1);
    delay(3000);
    start();
   }
  }

    //// COMPLETE PIANO

 L:
      a=10,b=6,v=3,v1=2;

   textbackground(1);
   clrscr();



  for(i=0;i<=76;i++)
  {
    textcolor(4);
    gotoxy(v,v1);
    cprintf("%c",178);
    gotoxy(v,v1+1);
    cprintf("%c",177);
    v++;

    if(i==75)
    {
      goto K;
    }

  }

  K:
   v=v-2;
   for(i=0;i<=23;i++)
  {
    textcolor(4);
    gotoxy(v,v1);
    cprintf("%c%c",178,178);
     gotoxy(v-2,v1+1);
    cprintf("%c%c",177,177);

    v1++;

    if(i==21)
    {
       goto K1;
    }
  }

  K1:
  v++;
  for(i=0;i<=75;i++)
  {
    textcolor(4);
    gotoxy(v,v1);
    cprintf("%c",178);
    gotoxy(v-2,v1-1);
    cprintf("%c",177);

    v--;

    if(i==75)
    {

    }

  }
   v++;

   for(i=0;i<=20;i++)
  {
    textcolor(4);
    gotoxy(v,v1-1);
    cprintf("%c%c%c%c",178,178,177,177);
    v1--;

    if(i==20)
    {
	}
  }

  textcolor(1);
  gotoxy(1,23);
  cprintf("%c%c",219,219);

  gotoxy(a,b);
  textcolor(3);
  for(i=0;i<=60;i++)
  {
    gotoxy(a,b);
    cprintf("%c",219);
    gotoxy(a,b+1);
    cprintf("%c",219);
    gotoxy(a,b+2);
    cprintf("%c",219);
    a++;
    if(i==60)
    {
      goto H;
    }
   }
   H:
    for(i=0;i<=13;i++)
      {
       gotoxy(a,b);
       cprintf("%c",219);
       b++;
	if(i==15)
	{
	  goto H1;
	}
      }
    H1:
   for(i=0;i<=60;i++)
   {
    gotoxy(a,b);
    cprintf("%c",219);
    a--;
    if(i==60)
    {
      goto H3;
    }
   }
    H3:

      for(i=0;i<=14;i++)
      {
       gotoxy(a,b);
       cprintf("%c",219);
       b--;

      }

  a=14,b=12;
  gotoxy(a,b);


   for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
   gotoxy(1,1);
   cprintf("ESC - EXIT PIANO.");
   a++,b=b-1;
   for(i=0;i<=2;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b--;
   }
   for(i=0;i<=3;i++)
   {  textcolor(0);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b--;
   }
   a=a+2,b++;
     for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
     a=a+1,b=b-4;

    for(i=0;i<=3;i++)
   {  textcolor(0);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b--;
   }
      a=a+2,b++;
     for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
     a=a+1,b=b-4;

    for(i=0;i<=3;i++)
   {  textcolor(0);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b--;
   }
      a=a+2,b++;
     for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
   a=a-1,b=b-1;
   for(i=0;i<=2;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b--;
   }
       a=a+3,b=b-3;
     for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
   a=a+1,b=b-1;
   for(i=0;i<=2;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",221);
      b--;
   }
    for(i=0;i<=3;i++)
   {  textcolor(0);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b--;
   }
	 a=a+2,b++;
     for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
   a=a-1,b=b-1;
   for(i=0;i<=2;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b--;
   }
      a=a+2,b=b+3;
   for(i=0;i<=2;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",221);
      b--;
   }
       for(i=0;i<=3;i++)
   {  textcolor(0);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b--;
   }

   a=a+2,b++;
     for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
   a=a-1,b=b-1;
   for(i=0;i<=2;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b--;
   }

   a=a+3,b=b-3;
   for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
   a++,b=b-1;
   for(i=0;i<=2;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b--;
   }
   for(i=0;i<=3;i++)
   {  textcolor(0);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b--;
   }
   a=a+2,b++;
     for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
     a=a+1,b=b-4;

    for(i=0;i<=3;i++)
   {  textcolor(0);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b--;
   }
      a=a+2,b++;
     for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
     a=a+1,b=b-4;

    for(i=0;i<=3;i++)
   {  textcolor(0);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b--;
  }
      a=a+2,b++;
     for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
      a=a+1,b=b-4;

    for(i=0;i<=3;i++)
   {  textcolor(0);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b--;
  }
      a=a+2,b++;
     for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
     a=a-1,b=b-1;
   for(i=0;i<=2;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b--;
   }


   a=a+3,b=b-3;

   for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
   a++,b=b-1;
   for(i=0;i<=2;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b--;
   }
   for(i=0;i<=3;i++)
   {  textcolor(0);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b--;
   }
   a=a+2,b++;
     for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
     a=a+1,b=b-4;

    for(i=0;i<=3;i++)
   {  textcolor(0);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b--;
   }
      a=a+2,b++;
     for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
     a=a+1,b=b-4;

    for(i=0;i<=3;i++)
   {  textcolor(0);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b--;
   }
      a=a+2,b++;
     for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
   a=a-1,b=b-1;
   for(i=0;i<=2;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b--;
   }
       a=a+3,b=b-3;
     for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
   a=a+1,b=b-1;
   for(i=0;i<=2;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",221);
      b--;
   }
    for(i=0;i<=3;i++)
   {  textcolor(0);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b--;
   }
	 a=a+2,b++;
     for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
   a=a-1,b=b-1;
   for(i=0;i<=2;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b--;
   }
      a=a+2,b=b+3;
   for(i=0;i<=2;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",221);
      b--;
   }
       for(i=0;i<=3;i++)
   {  textcolor(0);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b--;
   }

   a=a+2,b++;
     for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
   a=a-1,b=b-1;
   for(i=0;i<=2;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b--;
   }
   a=a+3,b=b-3;

   for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b++;
   }


  a=12,b=9;

  gotoxy(a,b);
  textcolor(6);
  for(i=0;i<=56;i++)
  {
    gotoxy(a,b);
    cprintf("%c",219);
    a++;
    if(i==56)
    {
      goto S;
    }
   }
   S:
    for(i=0;i<=12;i++)
      {
       gotoxy(a,b);
       cprintf("%c",219);
       b++;
	if(i==10)
	{
	  goto S5;
	}
      }
    S5:
   for(i=0;i<=56;i++)
   {
    gotoxy(a,b);
    cprintf("%c",219);
    a--;
    if(i==56)
    {
      goto S3;
    }
   }
    S3:

      for(i=0;i<=10;i++)
      {
       gotoxy(a,b);
       cprintf("%c",219);
       b--;

      }

  m1=70,m2=8;

 for(i=0;i<=11;i++)
 {
  textcolor(6);
  gotoxy(m1,m2);
  cprintf("%c",219);
  m2++;
 }
    m1=11,m2=8;

 for(i=0;i<=11;i++)
 {

 gotoxy(m1,m2);
  cprintf("%c",219);
  m2++;
 }

  piano();

  EXIT:
}

void piano()
{
   int p,q,a,b,i;



 H:

  p=600,q=260;

  switch(getch())
  {

   case 113:
	 {

      a=14,b=12;
      gotoxy(a,b);


      for(i=0;i<=6;i++)
      {  textcolor(7);
	 gotoxy(a,b);
	 cprintf("%c",219);
	 b++;
      }
      a++,b=b-1;
      for(i=0;i<=2;i++)
      {  textcolor(7);
	 gotoxy(a,b);
	 cprintf("%c",219);
	 b--;
      }

	    sound(p-300);
	    delay(q);
	    nosound();

      a=14,b=12;
      gotoxy(a,b);

      for(i=0;i<=6;i++)
      {  textcolor(15);
	 gotoxy(a,b);
	 cprintf("%c",219);
	 b++;
      }
      a++,b=b-1;
      for(i=0;i<=2;i++)
      {  textcolor(15);
	 gotoxy(a,b);
	 cprintf("%c",219);
	 b--;
      }
	  break;

	 }

   case 119:
	 {
	      a=15,b=12;

	       for(i=0;i<=3;i++)
	       {   textcolor(8);
		   gotoxy(a,b);
		   cprintf("%c%c",219,219);
		   b++;
	       }

	    sound(p-270);
	    delay(q);
	    nosound();
	      a=15,b=12+3;

	      for(i=0;i<=3;i++)
	       {   textcolor(0);
		   gotoxy(a,b);
		   cprintf("%c%c",219,219);
		   b--;
	       }

	    break;
	 }

   case 101:
	 {
      a=17,b=12;
      gotoxy(a,b);

      for(i=0;i<=6;i++)
      {  textcolor(7);
	 gotoxy(a,b);
	 cprintf("%c",219);
	 b++;
      }

	    sound(p-240);
	    delay(q);
	    nosound();
	a=17,b=12;

      for(i=0;i<=6;i++)
      {  textcolor(15);
	 gotoxy(a,b);
	 cprintf("%c",219);
	 b++;
      }
	    break;
	 }

  case 114:
	 {
	      a=18,b=15;

	      for(i=0;i<=3;i++)
	       {   textcolor(8);
		   gotoxy(a,b);
		   cprintf("%c%c",219,219);
		   b--;
	       }
	    sound(p-210);
	    delay(q);
	    nosound();
	     a=18,b=15;

	      for(i=0;i<=3;i++)
	       {   textcolor(0);
		   gotoxy(a,b);
		   cprintf("%c%c",219,219);
		   b--;
	       }
	     break;
	 }

    case 116:
	 {
      a=20,b=12;

    for(i=0;i<=6;i++)
      {  textcolor(7);
	 gotoxy(a,b);
	 cprintf("%c",219);
	 b++;
      }
	    sound(p-180);
	    delay(q);
	    nosound();
      a=20,b=12;

    for(i=0;i<=6;i++)
      {  textcolor(15);
	 gotoxy(a,b);
	 cprintf("%c",219);
	 b++;
      }
	    break;
	 }

    case 121:
	 {
		a=21,b=15;

	       for(i=0;i<=3;i++)
	       {   textcolor(8);
		   gotoxy(a,b);
		   cprintf("%c%c",219,219);
		   b--;
	       }
	    sound(p-150);
	    delay(q);
	    nosound();
		a=21,b=15;

	       for(i=0;i<=3;i++)
	       {   textcolor(0);
		   gotoxy(a,b);
		   cprintf("%c%c",219,219);
		   b--;
	       }
	      break;
	 }

    case 117:
	 {
		a=23,b=12;

  for(i=0;i<=6;i++)
   {  textcolor(7);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
   a=a-1,b=b-1;
   for(i=0;i<=2;i++)
   {  textcolor(7);
      gotoxy(a,b);
      cprintf("%c",219);
      b--;
   }
	    sound(p-120);
	    delay(q);
	    nosound();
	a=23,b=12;

  for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
   a=a-1,b=b-1;
   for(i=0;i<=2;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b--;
   }
	     break;
	 }

    case 105:
	 {

   a=25,b=12;

   for(i=0;i<=6;i++)
   {  textcolor(7);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
   a=a+1,b=b-1;
   for(i=0;i<=2;i++)
   {  textcolor(7);
      gotoxy(a,b);
      cprintf("%c",219);
      b--;
   }
	    sound(p-90);
	    delay(q);
	    nosound();
   a=25,b=12;

   for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
   a=a+1,b=b-1;
   for(i=0;i<=2;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",221);
      b--;
   }


	    break;
	 }


    case 111:
	 {
       a=26,b=15;

   for(i=0;i<=3;i++)
   {  textcolor(8);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b--;
   }

	    sound(p-60);
	    delay(q);
	    nosound();
    a=26,b=15;

   for(i=0;i<=3;i++)
   {  textcolor(0);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b--;
   }

	    break;
	 }


    case 112:
	 {
	     a=28,b=12;

   for(i=0;i<=6;i++)
   {  textcolor(7);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
   a=a-1,b=b-1;
   for(i=0;i<=2;i++)
   {  textcolor(7);
      gotoxy(a,b);
      cprintf("%c",219);
      b--;
   }
      a=a+2,b=b+3;
   for(i=0;i<=2;i++)
   {  textcolor(7);
      gotoxy(a,b);
      cprintf("%c",221);
      b--;
   }
	    sound(p-30);
	    delay(q);
	    nosound();

   a=28,b=12;

   for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
   a=a-1,b=b-1;
   for(i=0;i<=2;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b--;
   }
      a=a+2,b=b+3;
   for(i=0;i<=2;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",221);
      b--;
   }
    break;
	 }

    case 49:
	 {
   a=29,b=15;

   for(i=0;i<=3;i++)
   {  textcolor(8);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b--;
   }

	    sound(p);
	    delay(q);
	    nosound();

   a=29,b=15;

   for(i=0;i<=3;i++)
   {  textcolor(0);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b--;
   }
	    break;
	 }
    case 50:
	 {

   a=31,b=12;

   for(i=0;i<=6;i++)
   {  textcolor(7);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
   a=a-1,b=b-1;
   for(i=0;i<=2;i++)
   {  textcolor(7);
      gotoxy(a,b);
      cprintf("%c",219);
      b--;
   }

	    sound(p+30);
	    delay(q);
	    nosound();

     a=31,b=12;

   for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
   a=a-1,b=b-1;
   for(i=0;i<=2;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b--;
   }


	    break;
	 }
    case 51:
	 {
   a=33,b=12;

   for(i=0;i<=6;i++)
   {  textcolor(7);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
   a=a+1,b=b-1;
   for(i=0;i<=2;i++)
   {  textcolor(7);
      gotoxy(a,b);
      cprintf("%c",219);
      b--;
   }


	    sound(p+60);
	    delay(q);
	    nosound();
    a=33,b=12;

   for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }
   a=a+1,b=b-1;
   for(i=0;i<=2;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b--;
   }
	    break;
	 }
    case 52:
	 {
   a=34,b=15;

   for(i=0;i<=3;i++)
   {  textcolor(8);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b--;
   }


	    sound(p+90);
	    delay(q);
	    nosound();

   a=34,b=15;

   for(i=0;i<=3;i++)
   {  textcolor(0);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b--;
   }
	    break;
	 }
    case 53:
	 {
     a=36,b=12;

   for(i=0;i<=6;i++)
   {  textcolor(7);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }

	    sound(p+120);
	    delay(q);
	    nosound();

   a=36,b=12;

   for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }

	    break;
	 }
 case 54:
	 {
      a=37,b=15;

   for(i=0;i<=3;i++)
   {  textcolor(8);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b--;
   }

	    sound(p+150);
	    delay(q);
	    nosound();

      a=37,b=15;

   for(i=0;i<=3;i++)
   {  textcolor(0);
      gotoxy(a,b);
      cprintf("%c%c",219,219);
      b--;
   }

	    break;
	 }
 case 55:
	 {
     a=39,b=12;
   for(i=0;i<=6;i++)
   {  textcolor(7);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }

	    sound(p+180);
	    delay(q);
	    nosound();
     a=39,b=12;

  for(i=0;i<=6;i++)
   {  textcolor(15);
      gotoxy(a,b);
      cprintf("%c",219);
      b++;
   }


	    break;
	 }
 case 56:
	 {
	    sound(p+210);
	    delay(q);
	    nosound();
	    break;
	 }
 case 57:
	 {
	    sound(p+240);
	    delay(q);
	    nosound();
	    break;
	 }
 case 48:
	 {
	    sound(p+270);
	    delay(q);
	    nosound();
	    break;
	 }
 case 58:
	 {
	    sound(p+300);
	    delay(q);
	    nosound();
	    break;
	 }
 case 59:
    {
	    sound(p+330);
	    delay(q);
	    nosound();
	    break;
	 }
 case 60:
	 {
	    sound(p+360);
	    delay(q);
	    nosound();
	    break;
	 }
 case 61:
	 {
	    sound(p+390);
	    delay(q);
	    nosound();
	    break;
	 }
 case 62:
	 {
	    sound(p+420);
	    delay(q);
	    nosound();
	    break;
	 }
 case 63:
	 {
	    sound(p+450);
	    delay(q);
	    nosound();
	    break;
	 }
 case 64:
	 {
	    sound(p+480);
	    delay(q);
	    nosound();
	    break;
	 }
 case 65:
	 {
	    sound(p+510);
	    delay(q);
	    nosound();
	    break;
	 }
 case 66:
	 {
	    sound(p+540);
	    delay(q);
	    nosound();
	    break;
	 }
 case 67:
	 {
	    sound(p+570);
	    delay(q);
	    nosound();
	    break;
	 }
 case 68:
	 {
	    sound(p+600);
	    delay(q);
	    nosound();
	    break;
	 }
 case 133:
	 {
	    sound(p+630);
	    delay(q);
	    nosound();
	    break;
	 }
 case 134:
	 {
	    sound(p+660);
	    delay(q);
	    nosound();
	    break;
	 }
 case 27:
	 {
	    sound(p+1105);
	    delay(q);

	    sound(p+100);
	    delay(100);

	    sound(p+1000);
	    delay(100);
	    sound(p+10000);
	    delay(100);
	    nosound();
	    goto h;


	     }

	 default: goto H;
  }


	 goto H;


h:
   textbackground(0);
   clrscr();
   textcolor(13);
   gotoxy(33,12);
   cprintf("<\4> Thank You <\4>");
   delay(2000);
   start();
}

    getch();


