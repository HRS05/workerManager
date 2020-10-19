#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct Worker
{
int codeNumber;
    // unique number provide by boss of workers
char name[1001];
int workingHours;
int wage;
int age;
    // wage is fix for per hour (50rupees for per hours)
};


void addWorker()
{
char name[22];
int age,codeNumber,workingHours;
struct Worker *w;
char m;
FILE *f;
system("cls");
printf("WORKER (Add Module)\n");

w=(struct Worker *)malloc(sizeof(struct Worker));
if(w==NULL)
{
printf("Unable to add worker,insufficient memory\n");
printf("\n\n press enter to continue.....");
m=getchar();
fflush(stdin);
return;
} 
printf("Enter the CODE :-");
scanf("%d",&codeNumber);
fflush(stdin);
if(codeNumber<=0)
{
printf("Invalid Code\n");
printf("\n\n press enter to continue.....");
m=getchar();
fflush(stdin);
return;
}
f=fopen("worker.k","rb");
if(f!=NULL)
{
while(1)
{
fread(w,sizeof(struct Worker),1,f);
if(feof(f)) break;
if(codeNumber==w->codeNumber)
{
printf("That code is already alloted to %s \n",w->name);
fclose(f);
printf("\n\n press enter to continue.....");
m=getchar();
fflush(stdin);
return;
}
}
fclose(f);
}
printf("Enter the name:-");
fgets(name,22,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
printf("Enter the AGE :-");
scanf("%d",&age);
fflush(stdin);
printf("Enter the Working Hours of %s:-",name);
scanf("%d",&workingHours);
fflush(stdin);
printf("save (Y/N):-");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("worker not added\n");
printf("\n\n press enter to continue.....");
m=getchar();
fflush(stdin);
return;
}
w->workingHours=workingHours;
w->wage=workingHours*50; 
w->codeNumber=codeNumber;
w->age=age;
strcpy(w->name,name);
//printf("%d %d %s",w->workingHours,w->wage,w->name);
f=fopen("worker.k","ab");
fwrite(w,sizeof(struct Worker),1,f);
fclose(f);
printf("Worker Added\n\n press enter to continue.....\n");
m=getchar();
fflush(stdin);
}


void displayListOfWorkingHourAndWage()
{
int x;
char m;
FILE *f;
struct Worker *w;
w=(struct Worker *)malloc(sizeof(struct Worker));	//Yeh Line missing thi
f=fopen("worker.k","rb");
system("cls");
printf("WORKER (List Module)\n");
if(f==NULL)
{
printf("No Worker Added In File");
printf("\n\n press enter to continue.....");
m=getchar();
fflush(stdin);
return;
}
x=0;
while(1)
{
fread(w,sizeof(struct Worker),1,f);
if(feof(f)) break;
x++;
printf("%d. Code Number:- %d | Name:- %s | Age:- %d |\n  Working Hours:- %d | Total Wage:- %d rupees|\n\n",x,w->codeNumber,w->name,w->age,w->workingHours,w->wage);
}
fclose(f);
if(x==0)
{
printf("No worker is added \n\npress enter to continue....");
}
else
{
printf("\n\npress enter to continue....");
}
m=getchar();
fflush(stdin);
}


void searchWorker()
{
int x,code;
char m;
FILE *f;
struct Worker *w;
w=(struct Worker *)malloc(sizeof(struct Worker));	
f=fopen("worker.k","rb");
system("cls");
printf("WORKER (Search Module)\n");
if(f==NULL)
{
printf("No Worker Added In File");
printf("\n\n press enter to continue.....");
m=getchar();
fflush(stdin);
return;
}
printf("Enter the code of worker to find:- ");
scanf("%d",&code);
fflush(stdin);
x=0;
while(1)
{
fread(w,sizeof(struct Worker),1,f);
if(feof(f)) break;
if(code==w->codeNumber)
{
printf("Worker Found\n");
printf("Code Number:- %d | Name:- %s | Age:- %d |\n  Working Hours:- %d | Total Wage:- %d rupees |\n\n",w->codeNumber,w->name,w->age,w->workingHours,w->wage);
x=1;
}

}
fclose(f);
if(x==0)
{
printf("No worker is found of code number:- %d,\n\n press enter to continue",code);
}
else
{
printf("\n\npress enter to continue....");
}
m=getchar();
fflush(stdin);

}

void editWorkerInfo()
{
char name[22],newName[22];
int x,age,newAge,codeNumber,ch;
struct Worker *w,*j;
char m;
FILE *f,*k;
system("cls");
printf("Profile Editing Module)\n");

w=(struct Worker *)malloc(sizeof(struct Worker));
j=(struct Worker *)malloc(sizeof(struct Worker));

if(w==NULL)
{
printf("insufficient memory in system\n");
printf("\n\n press enter to continue.....");
m=getchar();
fflush(stdin);
return;
} 
printf("Enter the CODE of Editing Profile :-");
scanf("%d",&codeNumber);
fflush(stdin);

f=fopen("worker.k","rb");
if(f==NULL)
{
printf("Invalid code number");
printf("\n\n press enter to continue.....");
m=getchar();
fflush(stdin);
return;
}
x=0;
while(1)
{
fread(w,sizeof(struct Worker),1,f);
if(feof(f)) break;
if(codeNumber==w->codeNumber)
{
printf("Code Number:- %d \nName:- %s \nAge:- %d\n ",w->codeNumber,w->name,w->age);
x=1;
break;
}
}
fclose(f);
if(x==0)
{
printf("No worker found with Code Number %d",codeNumber);
printf("\n\n press enter to continue.....");
m=getchar();
fflush(stdin);
return;
}
printf("Want to edit? (Y/N)");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Informatin not Update\n");
printf("\n\n press enter to continue.....");
m=getchar();
fflush(stdin);
return;
}
while(1)
{
printf("Information You Can Edit\n");
printf("1. Name\n");
printf("2. Age\n");
printf("3.<--back\n");
printf("Enter your choice:-");
scanf("%d",&ch);
fflush(stdin);
if(ch==3) break;
while(1)
{
if(ch<1 || ch>2)
{
printf("Invalid choice");
break;
}
if(ch==1)
{
printf("Enter the new name:- ");
fgets(name,22,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
strcpy(w->name,name);
break;
}
if(ch==2)
{
printf("Enter the present age:- ");
scanf("%d",&age);
fflush(stdin);
w->age=age;
break;
}
}
f=fopen("worker.k","rb");
k=fopen("fhaltu.d","wb");
while(1)
{
fread(j,sizeof(struct Worker),1,f);
if(feof(f)) break;
if(w->codeNumber!=j->codeNumber)
{
fwrite(j,sizeof(struct Worker),1,k);
}
else
{
fwrite(w,sizeof(struct Worker),1,k);
}
}
fclose(f);
fclose(k);
f=fopen("worker.k","wb");
k=fopen("fhaltu.d","rb");
while(1)
{
fread(j,sizeof(struct Worker),1,k);
if(feof(k)) break;
fwrite(j,sizeof(struct Worker),1,f);
}
fclose(f);
fclose(k);
k=fopen("fhaltu.d","wb");
fclose(k);
printf("Profile updated\n");
}
printf("Information Updated\n\n press enter to continue.....\n");
m=getchar();
fflush(stdin);
}


void deleteWorker()
{
char name[22];
int x,age,codeNumber,ch;
struct Worker *w,*j;
char m;
FILE *f,*k;
system("cls");
printf("Deleting Module)\n");

w=(struct Worker *)malloc(sizeof(struct Worker));
j=(struct Worker *)malloc(sizeof(struct Worker));

if(w==NULL)
{
printf("insufficient memory in system\n");
printf("\n\n press enter to continue.....");
m=getchar();
fflush(stdin);
return;
}
if(j==NULL)
{
printf("insufficient memory in system\n");
printf("\n\n press enter to continue.....");
m=getchar();
fflush(stdin);
return;
} 

 
printf("Enter the CODE of Worker to Delete :-");
scanf("%d",&codeNumber);
fflush(stdin);

f=fopen("worker.k","rb");
if(f==NULL)
{
printf("Invalid code number");
printf("\n\n press enter to continue.....");
m=getchar();
fflush(stdin);
return;
}
x=0;
while(1)
{
fread(w,sizeof(struct Worker),1,f);
if(feof(f)) break;
if(codeNumber==w->codeNumber)
{
printf("Code Number:- %d \nName:- %s \nAge:- %d\n ",w->codeNumber,w->name,w->age);
x=1;
break;
}
}
fclose(f);
if(x==0)
{
printf("No worker found with Code Number %d",codeNumber);
printf("\n\n press enter to continue.....");
m=getchar();
fflush(stdin);
return;
}
printf("Want to Delete? (Y/N)");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Worker Not Delete\n");
return;
}

f=fopen("worker.k","rb");
k=fopen("fhaltu.d","wb");
while(1)
{
fread(j,sizeof(struct Worker),1,f);
if(feof(f)) break;
if(w->codeNumber!=j->codeNumber)
{
fwrite(j,sizeof(struct Worker),1,k);
}
}
fclose(f);
fclose(k);
f=fopen("worker.k","wb");
k=fopen("fhaltu.d","rb");
while(1)
{
fread(j,sizeof(struct Worker),1,k);
if(feof(k)) break;
fwrite(j,sizeof(struct Worker),1,f);
}
fclose(f);
fclose(k);
k=fopen("fhaltu.d","wb");
fclose(k);
printf("Worker Deleted\n\n press enter to continue.....\n");
m=getchar();
fflush(stdin);
}




int main()
{
char m;
system("cls");
printf("In this program, we can manage the data of all \nworkers and do proper management of their wages\n(which is 50 rupees per hour)");
printf("\n____________________________ press enter-->skip ");
m=getchar();
fflush(stdin); 
system("cls");
printf("      !THE WORKER MANAGER PROGRAM!\n");
printf("       !********WELCOME********!\n");
printf("PRESS ENTER FOR GOING TO MAIN MENU\n");
m=getchar();
fflush(stdin); 
int ch;
while(1)
{
system("cls");
printf("         !*******MAIN MENU*******!\n");
printf("1. Add\n");
printf("2. Edit Profile\n");
printf("3. Delete\n");
printf("4. search\n");
printf("5. List\n");
printf("6. Exit\n");
printf("ENTER YOUR CHOICE:-");
scanf("%d",&ch);
fflush(stdin);
if(ch>=1 && ch<=6)
{
if(ch==1) addWorker();
if(ch==2) editWorkerInfo();
if(ch==3) deleteWorker();
if(ch==4) searchWorker();
if(ch==5) displayListOfWorkingHourAndWage();
if(ch==6) break;
}
}
return 0;
}
