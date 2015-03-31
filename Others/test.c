/*                           ====================
	     CODE OF QUIZ PROGRAM
	     ====================

   Q U I Z Program by Mr.K.Chandrasekhar Omkar & Devendra Surana
   Q.DAT --> Questions Database file
   HISCORE.DAT --> High scorer's file
   USER.DAT --> Stores user id's ans passwords

   FUNCTIONS USED :-
   ==============
    addq() --> The function which adds questions to the database
    delq() --> The function which deletes questions from the database
    modq() --> The function which modifies questions in the database
    viewrec(int id,int i) --> This function displays a record of ID
number
	      "id". If i==1 it displays the record with answer
    viewrec1(struct question *,int a) --> This function displays a
record
with call
	  be reference method with answer if a=1
    test1() --> This function displays menu of Manipulating Records
    viewmenu() --> This function displays menu for Viewing Records
    reg1() --> This function registers a username
    login() --> This function logins a user into the game


   Question structure :
   ==================
   1. ques[] --> STRING VARIABLE WHICH STORES THE QUESTION
   2. id     --> INTEGER VARIABLE WHICH STORES THE QUESTION ID
   3. op1[]  --> OPTION VARIABLE 1 (STRING)
   4. op2[]  --> OPTION VARIABLE 2 (STRING)
   5. op3[]  --> OPTION VARIABLE 3 (STRING)
   6. op4[]  --> OPTION VARIABLE 4 (STRING)
   7. ans    --> INTEGER VARIABLE WHICH STORES THE ANSWER

	  "q" IS THE QUESTION STRUCTURE VARIABLE
	   Another sturcture variable "t1" is also declared for temporary
	   access.
	   This structure is declared globally



   User structure :-
   ==============

   name[]      --> NAME OF THE USER (STRING)
   id[]        --> THIS IS A UNIQUE ID WITH WHICH THE USER ACCESSES
HIS/HER
	   ACCOUNT. (STRING)
   password[]  --> THIS IS LIKE A KEY FOR A USER TO ACCESS HIS ACCOUNT
(STRING)
   log         --> THIS STORES THE NUMBER OF TIMES THE USER ACCESSED
HIS/HER
	   ACCOUNT. (INTEGER)

	    "usr" IS THE USER STRUCTURE VARIABLE
	     This structute is decalred globally




  Accessing of Files :
  ==================
  TWO FILES ARE USED IN THE PROGRAM. THEY ARE:-
  1.  Q.DAT       -->  THE FILE WHICH STORES THE QUESTIONS DATABASE
	       This file is accessed using the file pointer "q"

  2. HISCORES.DAT -->  THE FILE WHICH STORES THE WINNERS OF THE QUIZ
	       This file is accessed using the file pointer "h"

  3. USER.DAT     -->  THIS FILE STORES THE REGISTERED USERS DETAILS
  Both these file pointers are declared globally. Both these files are
opened in APPENDED BINARY READ/WRITE mode (ab+) at the beginning of
the program and are closed finally at the end of the program. Remember, file
opening and closing are done only once in the program to avoid confusion.



  CODE BEGINS HERE :-
  ================                                          	 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <process.h>
FILE *q,*h,*idd;
FILE *reg,*log;

struct question           /* Structure Question */
{
  char ques[200];
  int id;
  char op1[200];
  char op2[200];
  char op3[200];
  char op4[200];
  char ans;
}qe,t1;

struct user
{
  char name[100];
  char id[100];
  char password[100];
  int log;
}usr;

addq()
{
  char ch,an='Y';
  int id1,f,flag;
  while (toupper(an)=='Y')
  {
    clrscr();
    printf ("ENTER AN ID TO THE QUESTION : ");
    rewind(q);
    printf ("ENTER THE QUESTION : ");
    printf ("ENTER OPTION 1 : ");
    printf ("ENTER OPTION 2 : ");
    printf ("ENTER OPTION 3 : ");
    printf ("ENTER OPTION 4 : ");
    printf ("ENTER THE ANSWER NUMBER : ");
    enid : flag = 0;
    while (flag==0)
    {
      id1 = NULL;
      gotoxy (31,1);
      flag = scanf ("%d",&id1);
    }
    rewind(q);
    while (fread(&qe,sizeof(qe),1,q)==1)
    {
      if (qe.id==id1)
      {
	textcolor(-3);
	gotoxy (10,15);
	cprintf ("ID NUMBER IS REPEATED ");
	getch();
	gotoxy(10,15);
	clreol();
	textcolor (7);
	cprintf (" ");
	goto enid;
      }
    }
    qe.id = id1;
    flushall();
    enqe : gotoxy (22,2);
    gets(qe.ques);
    if (strlen(qe.ques)<=2)
    {
      gotoxy (10,15);
      textcolor (-4);
      cprintf ("INVALID QUESTION. PLEASE ENTER IT AGAIN");
      textcolor (7);
      getch();
      gotoxy (10,15);
      printf ("                                        ");
      goto enqe;
    }
    flushall();
    enop1 : gotoxy(18,6);
    gets(qe.op1);
    if (strlen(qe.op1)<1)
    {
      gotoxy (10,15);
      textcolor (-5);
      cprintf ("AN OPTION FIELD CANNOT BE EMPTY");
      getch();
      gotoxy (10,15);
      cprintf ("                              ");
      textcolor(7);
      cprintf (" ");
      goto enop1;
    }
    flushall();
    enop2 : gotoxy(18,7);
    gets(qe.op2);
    if (strlen(qe.op2)<1)
    {
      gotoxy (10,15);
      textcolor (-5);
      cprintf ("AN OPTION FIELD CANNOT BE EMPTY");
      getch();
      gotoxy (10,15);
      textcolor (7);
      cprintf ("                               ");
      goto enop2;
    }
    flushall();
    enop3 : gotoxy(18,8);
    gets(qe.op3);
    if (strlen(qe.op3)<1)
    {
      gotoxy (10,15);
      textcolor (-5);
      cprintf ("AN OPTION FIELD CANNOT BE EMPTY");
      getch();
      textcolor (7);
      gotoxy (10,15);
      cprintf ("                               ");
      goto enop3;
    }
    flushall();
    enop4 : gotoxy(18,9);
    gets(qe.op4);
    if (strlen(qe.op4)<1)
    {
      gotoxy (10,15);
      textcolor (-5);
      cprintf ("AN OPTION FIELD CANNOT BE EMPTY");
      getch();
      textcolor(7);
      gotoxy (10,15);
      cprintf ("                               ");
      goto enop4;
    }
    flushall();

    enans : gotoxy(27,10);
    qe.ans = getchar();
    if (qe.ans!='1' && qe.ans!='2' && qe.ans!='3' && qe.ans!='4')
    {
      gotoxy (10,15);
      textcolor (-3);
      cprintf ("ANSWER MUST BE ONLY 1 OR 2 OR 3 OR 4. INPUT ERROR");
      getch();
      gotoxy (10,15);
      textcolor(7);
      cprintf ("                                                 ");
      goto enans;
    }
    flushall();
    fwrite (&qe,sizeof(qe),1,q);
    printf ("ADD ANOTHER QUESTION (Y/N) : ");
    an = getche();
  }
}

test()
{
  int i=0,j=0;
  clrscr();
  rewind(q);
  textcolor(7);
  cprintf ("");
  while (fread(&qe,sizeof(qe),1,q)==1)
  {
    j++;
  }
  if (j!=0)
  {
  rewind(q);
  while (fread(&qe,sizeof(qe),1,q)==1)
  {
    clrscr();
    i++;
    printf ("QUESTION %d/%d",i,j);
    viewrec1(&qe);
    getch();
  }
  }
  else
  {
    clrscr();
    printf ("NO RECORDS IN THE FILE Q.DAT");
  }

  printf ("TOTAL QUESTIONS LISTED : %d",i);
  getch();
}

delq()
{
  int id1,i,j=0,k,flag=0;
  char an='Y';
  FILE *t;
  rewind(q);
  while (fread(&qe,sizeof(qe),1,q)==1)
  {
   j++;
  }
  if (j==0)
  {
    clrscr();
    gotoxy (20,10);
    printf ("NO RECORDS TO DELETE");
    gotoxy (20,11);
    printf ("The file Q.DAT is empty");
    getch();
    return;
  }
  while (toupper(an)=='Y')
  {
    clrscr();
    flag=0;
    printf ("ENTER THE QUESTION ID TO BE DELETED : ");
    scanf ("%d",&id1);
    rewind(q);
    while (fread(&qe,sizeof(qe),1,q)==1)
    {
      if (id1==qe.id)
      {
	flag=1;
	break;
      }
    }
    rewind(q);
    if (flag==1)
    {
      unlink ("TEMP.DAT");
      t = fopen("TEMP.DAT","ab+");
      while (fread(&qe,sizeof(qe),1,q)==1)
      {
	if (id1!=qe.id)
	{
	  fwrite (&qe,sizeof(qe),1,t);
	}
      }
      rewind (t);
      fclose (q);
      unlink ("Q.DAT");
      q = fopen ("Q.DAT","ab+");
      if (q==NULL)
      {
	printf ("UNABLE TO CREATE Q.DAT.");
	getch();
	fclose(q);
	fclose(h);
	fclose(t);
	exit(0);
      }
      while (fread(&qe,sizeof(qe),1,t)==1)
      {
	 fwrite (&qe,sizeof(qe),1,q);
      }
      fclose (t);
      printf ("DO YOU WANT TO DELETE ANOTHER RECORD (Y/N) : ");
      an = getche();
    }
    if (flag!=1)
    {
      printf ("ID NUMBER %d NOT FOUND",id1);
      printf ("DO YOU WANT TO DELETE ANOTHER RECORD (Y/N) : ");
      an = getche();
    }
  }
}


reg1()
{
 int nrec=0,flag=0;
 char password[100],usrid[100];
 rewind(reg);
 while (fread(&usr,sizeof(usr),1,reg)==1)
 {
   nrec++;
 }
 clrscr();
 printf ("ENTER YOUR FULL NAME   : ");
 printf ("ENTER DESIRED USERNAME : ");
 printf ("ENTER PASSWORD         : ");
 gotoxy (26,1);
 gets(usr.name);
 enusrid : gotoxy (26,2);
 gets(usrid);
 rewind (reg);
 while (fread(&usr,sizeof(usr),1,reg)==1)
 {
   flag=0;
   if (strcmp(usrid,usr.id)==0)
   {
     flag = 1;
     break;
   }
 }
 if (flag==1 || strlen(usrid)<2)
 {
   gotoxy (1,5);
   textcolor (-3);
   cprintf ("This USER ID is already in use by someone");
   gotoxy (1,6);
   cprintf ("Please Choose another one");
   getch();
   gotoxy (1,5);
   clreol();
   gotoxy (1,6);
   clreol();
   textcolor (7);
   cprintf ("");
   gotoxy (26,2);
   clreol();    /* CLREOL() --> THIS FUNCTIONS CLEARS A LINE */
   textcolor (7);
   cprintf ("");
   goto enusrid;
 }
 gotoxy (26,3);
 gets(usr.password);
 strcpy(usr.id,usrid);
 fseek(reg,0,SEEK_END);
 fwrite (&usr,sizeof(usr),1,reg);
}









modq()
{
  int id1;
  int flag=0;
  char an='Y',ch;
  FILE *t;
  while (toupper(an)=='Y')
  {
    clrscr();
    flag=0;
    textcolor(GREEN);
    gotoxy (10,12);
    cprintf ("ENTER THE RECORD ID TO BE MODIFIED : ");
    textcolor(7);
    cprintf ("");
    scanf ("%d",&id1);
    rewind(q);
    while (fread(&qe,sizeof(qe),1,q)==1)
    {
      if (id1==qe.id)
      {
	clrscr();
	flag=1;
	textcolor(LIGHTRED);
	gotoxy (1,1);
	cprintf ("DETAILS OF CURRENT RECORD NUMBER %d : ",id1);
	textcolor(GREEN);
	gotoxy(20,10);
	cprintf ("QUESTION : ");
	textcolor (CYAN);
	cprintf ("%s",qe.ques);
	gotoxy (20,12);
	textcolor (GREEN);
	cprintf ("OPTION 1 : ");
	textcolor(CYAN);
	cprintf ("%s",qe.op1);
	gotoxy (20,13);
	textcolor (GREEN);
	cprintf ("OPTION 2 : ");
	textcolor(CYAN);
	cprintf ("%s",qe.op2);
	gotoxy (20,14);
	textcolor (GREEN);
	cprintf ("OPTION 3 : ");
	textcolor (CYAN);
	cprintf ("%s",qe.op3);
	textcolor(GREEN);
	gotoxy (20,15);
	cprintf ("OPTION 4 : ");
	textcolor (CYAN);
	cprintf ("%s",qe.op4);
	gotoxy (20,16);
	textcolor (GREEN);
	cprintf ("ANSWER   : ");
	textcolor (CYAN);
	cprintf ("%c",qe.ans);
	getch();
	textcolor(7);
	cprintf ("");
	printf ("Press any key to modify this record...");
	break;
      }
    }
    clrscr();
    if (flag==1)
    {
      sure :
      printf ("Are you sure that you want to modify this record (Y/N) : ");
      ch = getche();
      switch(toupper(ch))
      {
	case 'Y' :  clrscr();
	    printf ("ENTER AN ID TO THE QUESTION : %d",id1);
	    rewind(q);
	    printf ("ENTER THE QUESTION : ");
	    printf ("ENTER OPTION 1 : ");
	    printf ("ENTER OPTION 2 : ");
	    printf ("ENTER OPTION 3 : ");
	    printf ("ENTER OPTION 4 : ");
	    printf ("ENTER THE ANSWER NUMBER : ");

	    t1.id = id1;
	    flushall();
	    enqe1 : gotoxy (22,2);
	    gets(t1.ques);
	    if (strlen(t1.ques)<=2)
	    {
	      gotoxy (10,15);
	      textcolor (-4);
	      cprintf ("INVALID QUESTION. PLEASE ENTER IT AGAIN");
	      textcolor (7);
	      getch();
	      gotoxy (10,15);
	      printf ("                                        ");
	      goto enqe1;
	    }
	    flushall();
	    enop11 : gotoxy(18,6);
	    gets(t1.op1);
	    if (strlen(t1.op1)<1)
	    {
	      gotoxy (10,15);
	      textcolor (-5);
	      cprintf ("AN OPTION FIELD CANNOT BE EMPTY");
	      getch();
	      gotoxy (10,15);
	      cprintf ("                              ");
	      textcolor(7);
	      cprintf (" ");
	      goto enop11;
	    }
	    flushall();
	    enop21 : gotoxy(18,7);
	    gets(t1.op2);
	    if (strlen(t1.op2)<1)
	    {
	      gotoxy (10,15);
	      textcolor (-5);
	      cprintf ("AN OPTION FIELD CANNOT BE EMPTY");
	      getch();
	      gotoxy (10,15);
	      textcolor (7);
	      cprintf ("                               ");
	      goto enop21;
	    }
	    flushall();
	    enop31 : gotoxy(18,8);
	    gets(t1.op3);
	    if (strlen(t1.op3)<1)
	    {
	      gotoxy (10,15);
	      textcolor (-5);
	      cprintf ("AN OPTION FIELD CANNOT BE EMPTY");
	      getch();
	      textcolor (7);
	      gotoxy (10,15);
	      cprintf ("                               ");
	      goto enop31;
	    }
	    flushall();
	    enop41 : gotoxy(18,9);
	    gets(t1.op4);
	    if (strlen(t1.op4)<1)
	    {
	      gotoxy (10,15);
	      textcolor (-5);
	      cprintf ("AN OPTION FIELD CANNOT BE EMPTY");
	      getch();
	      textcolor(7);
	      gotoxy (10,15);
	      cprintf ("                               ");
	      goto enop41;
	    }
	    flushall();

	    enans1 : gotoxy(27,10);
	    t1.ans = getchar();
	    if (t1.ans!='1' && t1.ans!='2' && t1.ans!='3' && t1.ans!='4')
	    {
	      gotoxy (10,15);
	      textcolor (-3);
	      cprintf ("ANSWER MUST BE ONLY 1 OR 2 OR 3 OR 4. INPUT ERROR");
	      getch();
	      gotoxy (10,15);
	      cprintf ("                                                 ");
	      goto enans1;
	    }
	    flushall();
	    unlink("TEMP.DAT");
	    t = fopen("TEMP.DAT","ab+");
	    t1.id = id1;
	    rewind(q);
	    while (fread(&qe,sizeof(qe),1,q)==1)
	    {
	      if (id1!=qe.id)
	      {
	fwrite (&qe,sizeof(qe),1,t);
	      }
	      if (id1==qe.id)
	      {
	fwrite (&t1,sizeof(t1),1,t);
	      }
	    }
	    rewind(t);

	    fclose(q);
	    unlink("Q.DAT");
	    q = fopen("Q.DAT","ab+");
	    while (fread(&qe,sizeof(qe),1,t)==1)
	    {
	      fwrite(&qe,sizeof(qe),1,q);
	    }
	    fclose(t);
	    unlink ("TEMP.DAT");
	    printf (" Record modified...");
	    break;
      case 'N' : break;
      default : goto sure;
    }
    }
    else
    {
    printf ("RECORD ID %d NOT FOUND ",id1);
    }


    printf ("Do you want to modify another record (Y/N) : ");
    an = getche();
  }
}

viewrec1 (struct question *q1,int a)
{
  printf ("
");
  textcolor (BROWN);
  cprintf ("Q.ID : %d",q1->id);
  printf ("");
  textcolor (LIGHTRED);
  cprintf ("QUESTION : %s",q1->ques);
  printf ("");
  textcolor(LIGHTCYAN);
  cprintf ("1. %s",q1->op1);
  printf ("");
  cprintf ("2. %s",q1->op2);
  printf ("");
  cprintf ("3. %s",q1->op3);
  printf ("");
  cprintf ("4. %s",q1->op4);
  if (a==1)
  {
    printf ("");
    textcolor (YELLOW);
    cprintf ("ANSWER : %c",q1->ans);
    textcolor (7);
    cprintf ("");
  }
  textcolor(7);
  cprintf ("");
}


viewrec(int id1,int a)
/*
	FUNCTION WHICH DISPLAYS A PARTICULAR RECORD
*/
{
  int found=0;
  idd = q;
  rewind(idd);
  gotoxy(1,25);
  printf ("OmDev Softwares Pvt. Ltd.");
  gotoxy(1,1);
  while(fread(&qe,sizeof(qe),1,idd)==1)
  {
    if (id1==qe.id)
    {
      found = 1;
      printf ("");
      textcolor (BROWN);
      cprintf ("Q.ID : %d",qe.id);
      textcolor (LIGHTRED);
      printf ("");
      cprintf ("QUESTION : %s",qe.ques);
      printf ("");
      textcolor (LIGHTCYAN);
      cprintf ("1. %s",qe.op1);
      printf ("");
      cprintf ("2. %s",qe.op2);
      printf ("");
      cprintf ("3. %s",qe.op3);
      printf ("");
      cprintf ("4. %s",qe.op4);
      if (a==1)
      {
	textcolor (YELLOW);
	printf ("");
	cprintf ("ANSWER : %c",qe.ans);
	textcolor (7);
	cprintf ("");
      }
    }
  }
  if (found==0)
  {
    printf ("RECORD NOT FOUND");
    getch();
  }
}

test1()
{
  char ch,an='Y';
  int i;
  do
  {
    clrscr();
    gotoxy (1,25);
    printf ("OmDev Softwares Pvt. Ltd.");
    gotoxy (28,8);
    printf ("1.ADD RECORDS");
    gotoxy (28,9);
    printf ("2.DELETE RECORDS");
    gotoxy (28,10);
    printf ("3.MODIFY RECORDS");
    gotoxy (28,11);
    printf ("4.VIEW ");
    gotoxy (28,12);
    printf ("0.RETURN TO PREVIOUS MENU");
    gotoxy (28,14);
    printf ("ENTER YOUR CHOICE : ");
    ch = getche();
    switch(ch)
    {
       case '1' : addq();
	  break;
       case '2' : delq();
	  break;
       case '3' : modq();
	  break;
       case '4' : clrscr();
	  viewmenu();
	  break;
       case '5' : clrscr();
	  gotoxy (1,25);
	  printf ("OmDev Softwares Pvt. Ltd.");
	  gotoxy (10,10);
	  printf ("ENTER RECORD ID TO BE VIEWED : ");
	  scanf ("%d",&i);
	  viewrec(i,1);
	  getch();
	  break;
       case '0' : an='N';
    }
  }while(an=='Y');
}

viewmenu()  /*DISPLAYS VIEWMENU */
{
  char ch;
  int i;
  char an='Y';
  do
  {
    clrscr();
    textcolor (7);
    cprintf ("");
    gotoxy (28,10);
    textcolor(7);
    cprintf ("");
    gotoxy(1,25);
    printf ("OmDev Softwares Pvt. Ltd.");
    printf ("1.VIEW ALL RECORDS");
    gotoxy (28,11);
    printf ("2.VIEW A PARTICULAR RECORD");
    gotoxy (28,12);
    printf ("0.RETURN TO PREVIOUS MENU");
    gotoxy (28,14);
    printf ("ENTER YOUR CHOICE : ");
    ch = getche();
    switch(ch)
    {
      case '1' : test();
	 break;
      case '2' : clrscr();
	 gotoxy(1,25);
	 printf ("OmDev Softwares Pvt. Ltd.");
	 gotoxy(1,1);
	 printf ("ENTER THE RECORD ID TO BE VIEWED : ");
	 scanf ("%d",&i);
	 viewrec(i,0);
	 getch();
	 break;
      case '0': an='N';
    }
  }while(an=='Y');
}

char usrname1[100],usr1[100];

conduct()
{
  char ans,temp;
  int i,j,k,nrec=0,qno=0,cond=1;
  int score=0,qualify;
  rewind(q);
  clrscr();
  while (fread(&qe,sizeof(qe),1,q)==1)
  {
    nrec++;
  }
  if (nrec<=0)
  {
    clrscr();
    gotoxy(1,25);
    printf ("OmDev Softwares Pvt. Ltd.");
    gotoxy (28,11);
    printf ("NO RECORDS TO PLAY QUIZ");
    gotoxy (28,12);
    printf ("Build Database and start playing");
    gotoxy (28,13);
    printf ("Press any key to continue...");
    getch();
    return;
  }

  printf ("TOTAL NUMBER OF QUESTIONS ARE : %d",nrec);
  printf ("YOUR MAXIMUM SCORE WILL BE    : %d",nrec);
  qualify = nrec*(0.75);
  printf ("QUALIFYING MARK               : %d",qualify);
  printf ("Press any key to start quiz...");
  gotoxy(1,25);
  printf ("OmDev Softwares Pvt. Ltd.");
  getch();
  flushall();
  clrscr();    /*viewrec1(struct *,0);*/
  rewind(q);
  while (fread(&qe,sizeof(qe),1,q)==1)
  {
    clrscr();
    gotoxy(40,1);
    {
      textcolor(LIGHTGRAY);
      cprintf ("CURRENTLY LOGGED : %s",usr1);
    }
    gotoxy (1,1);
    printf ("YOUR SCORE : %d",score);
    qno++;
    printf ("QUESTION NUMBER : %d",qno);
    viewrec1(&qe,0);
    printf ("");
    textcolor (LIGHTMAGENTA);
    cprintf ("ENTER YOUR ANSWER : ");
    scanf ("%c",&ans);
    flushall();
    flushall();
    cond++;
    if (cond>=4)
    {
      cond=0;
    }
    if (ans==qe.ans)
    {
      score++;
      if (cond==1)
      {
	printf ("");
	printf ("So, r u thinking that ur answer is right (Y/N) : ");
	temp = getche();
	switch(toupper(temp))
	{
case 'Y' :
printf ("U r absolutely correct.Really confidence builds a man");
getch();
break;
case 'N' : printf ("Hey, be confindent. You are right...!");
getch();
break;
default : printf ("Hey, dont get confused. You are right");
getch();
break;
	}
      }
      if (cond==2)
      {
	printf ("Hmmmmm...Thinking of your answer");
	sleep(2);
	printf ("YES, U R CORRECT!!!");
	getch();
      }
      if (cond==3)
      {
	printf ("Be cool. I am processing your answer");
	sleep(2);
	printf ("hmmmmmm...YES, U R RIGHT. Hurray!!!!");
	getch();
      }
      if (cond==4)
      {
	printf ("Yes, your answer is absolutely correct");
	getch();
      }
    }
    else
    {
      score=score+0;
      if (cond==1)
      {
	printf ("I am sorry to say....");
	printf ("Your guess is wrong");
	getch();
      }
      if (cond==2)
      {
	sleep(2);
	printf ("Just now we processed ur result.But, u r wrong");
	getch();
      }
      if (cond==3)
      {
	sleep(2);
	printf ("All the best to the next question...");
	printf ("Sorry 2 say that ur answer is wrong");
	getch();
      }
      if (cond==4)
      {
	sleep(2);
	printf ("Oh..NO..Your answer is wrong Koi bat nahi. All the best to next one.");
	getch();
      }

    }
    textcolor (7);
    cprintf ("");
  }
   clrscr();
   gotoxy (28,11);
   if (score>=qualify)
   {
     gotoxy (1,25);
     printf ("OmDev Softwares Pvt. Ltd.");
     textcolor (-5);
     cprintf ("CONGRATULATIONS YOU ARE QUALIFIED");
     gotoxy (28,12);
     textcolor (RED);
     cprintf ("So, when will you give the party???");
     getch();
     textcolor(7);
     cprintf ("");
     return;
   }
   else
   {
     gotoxy (1,25);
     printf ("OmDev Softwares Pvt. Ltd.");
     textcolor (2);
     cprintf ("Sorry, you are disqualified");
     gotoxy (28,12);
     cprintf ("Hey, cheer up ur mood and play again");
     gotoxy (28,13);
     cprintf ("Press any key to return to main menu...");
     getch();
     textcolor (7);
     cprintf ("");
     return;
   }
}


char id1[100];

login()
{
  char password[100],i;
  char c;
  int flag=0;
  enuid : clrscr();
  gotoxy (1,25);
  printf ("OmDev Softwares Pvt. Ltd.");
  gotoxy (28,11);
  printf ("ENTER USERID : ");
  gotoxy (28,12);
  printf ("PASSWORD     : ");
  gotoxy (44,11);
  gets(usr1);
  i=0;
  c='
