#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Function Prototypes
void box(void);
void insert(void);
void dellete(void);
void login(void);
void sell(void);
void display(void);
void update_existing(int);
void average_monthly_sale(void);
void profit_loss(void);
void Stock_Status(void);
int tax(int);
void search(void);
void sorting();
void save_file();

//Structure
struct dlist
	{
   char product[15];
	int serial;
   int quantity;
   int act_price;
   int sell_price;
   dlist *next;
   dlist *prev;
   };

void bill(dlist *,int);

//Global Pointers\variables
dlist *First=NULL;
dlist *Last=NULL;

fstream myfile("project.txt",ios::app);

//Main function
main()
{

int i,j,k,t;
char c,l;
system("color 81");
for(int cev=0 ;cev<3 ;cev++)
	{
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n");
   gotoxy(25,9);
   printf("Accessing files, Please be patient");
	for(int cv=0 ;cv<6 ;cv++)
		{
		cout<<setw(1)<<".";
		Sleep(100);
		}
	}
int ch;
char cursor;
n:
system("color 81");
clrscr();
login();
system("cls");
m:
do
	{

   system("color 81");
   gotoxy(27,2);
   box();
	gotoxy(30,3);
   printf("Shop Inventory DataBase\n\n");
	gotoxy(27,4);
   box();
   gotoxy(27,6);
   box();
   gotoxy(27,7);
   printf("   0) Exit                   ");
   gotoxy(27,8);
   box();
   gotoxy(27,9);
   printf("   1) Display Stock          ");
   gotoxy(27,10);
   box();
   gotoxy(27,11);
   printf("   2) Insert Stock           ");
   gotoxy(27,12);
   box();
   gotoxy(27,13);
   printf("   3) Average Sale Items     ");
   gotoxy(27,14);
   box();
   gotoxy(27,15);
   printf("   4) Sell Item              ");
   gotoxy(27,16);
   box();
   gotoxy(27,17);
   printf("   5) Delete Item            ");
   gotoxy(27,18);
   box();
   gotoxy(27,19);
   printf("   6) Check Profit Loss      ");
   gotoxy(27,20);
   box();
   gotoxy(27,21);
   printf("   7) Stock Status           ");
   gotoxy(27,22);
   box();
   gotoxy(27,23);
   printf("   8) Search                 ");
   gotoxy(27,24);
   box();
   gotoxy(30,26);
   printf("Enter Choice:");
   cin>>ch;
	switch(ch)
   	{
      case 0:
      textcolor(WHITE);
      gotoxy(27,7);
      cprintf("   0) Exit                   ");
      Sleep(1000);
      system("cls");
      break;

      case 2:
      textcolor(WHITE);
      gotoxy(27,11);
      cprintf("   2) Insert Stock           ");
      Sleep(1000);
      system("cls");
      insert();
      break;

      case 5:
      textcolor(WHITE);
      gotoxy(27,17);
      cprintf("   5) Delete Item            ");
      Sleep(1000);
      system("cls");
      dellete();
      break;

      case 1:
      textcolor(WHITE);
      gotoxy(27,9);
      cprintf("   1) Display Stock          ");
      Sleep(1000);
      display();
      break;

      case 4:
      textcolor(WHITE);
      gotoxy(27,15);
      cprintf("   4) Sell Item              ");
      Sleep(1000);
      system("cls");
      sell();
      break;

      case 6:
      textcolor(WHITE);
      gotoxy(27,19);
      cprintf("   6) Check Profit Loss      ");
      Sleep(1000);
      profit_loss();
   	break;

      case 3:
      textcolor(WHITE);
      gotoxy(27,13);
      cprintf("   3) Average Sale Items     ");
      Sleep(1000);
   	average_monthly_sale();
   	break;

   	case 7:
      textcolor(WHITE);
		gotoxy(27,21);
      cprintf("   7) Stock Status           ");
      Sleep(1000);
      Stock_Status();
      break;

      case 8:
      textcolor(WHITE);
      gotoxy(27,23);
      cprintf("   8) Search                 ");
      Sleep(1000);
      search();
      break;
		}
   }

   while(ch!=0);
   	{
   	gotoxy(27,3);
   	box();
   	gotoxy(36,4);
   	printf("Thank  You");
   	gotoxy(27,5);
   	box();
		gotoxy(28,8);
		for(int a=0;a<3;a++)
      	{
         printf("\a");
         }
      printf("Do you want to exit[y/n]:");
   	scanf("%c",&c);
   	if(c=='n' || c=='N')
      	{
      	clrscr();
   		goto m;
      	}
   	else if(c=='y' || c=='Y')
   		{
      	Sleep(100);
      	}
   	else if(c!='n' && c!='N' && c!='y' && c!='Y')
   		{
      	gotoxy(32,12);
      	for(int a=0;a<3;a++)
      	printf("\a");
   		cout<<"Invalid selection"<<endl;
      	Sleep(800);
      	clrscr();
     	 	goto m;
			}
   	}
  // read_file();
   system("pause");
}



//Insert Function

void insert(void)
{
dlist *temp=First;
int number,quantity,act_price,sell_price;
dlist *newnode=new dlist;
system("color 81");
gotoxy(25,2);
box();
gotoxy(32,3);
printf("Stock  Purchase");
gotoxy(25,4);
box();
gotoxy(19,7);
printf("Please enter the following product details.");
gotoxy(27,10);
printf("Product Serial Number:");
scanf("%d",&number);
while(temp!=NULL)
   {
	if(number==temp->serial)
		{
      system("cls");
      gotoxy(17,9);
      char c;
      for(int a=0;a<3;a++)
      	{
         printf("\a");
         }
      printf("Product already exists, so update status? [Y/N]? : ");
      scanf("%s",&c);
      if(c=='y' || c== 'Y')
         {
         update_existing(number);
         }
      else if(c== 'N' || c== 'n');
         {
         goto m;
         }
      }
   temp=temp->next;
   }
gotoxy(27,12);
printf("Product Name:");
cin>>newnode->product;
gotoxy(27,14);
printf("Product Actual Price/unit:");
scanf("%d", &act_price);
gotoxy(27,16);
printf("Product Selling Price/unit:");
scanf("%d", &sell_price);
gotoxy(27,18);
printf("Product Quantity:");
scanf("%d", &quantity);
if(Last==NULL)
	{
   newnode->next=newnode->prev=NULL;
   newnode->serial=number;
	newnode->quantity=quantity;
   newnode->act_price=act_price;
   newnode->sell_price=sell_price;
   First=Last=newnode;
   }
else
	{
   newnode->next=NULL;
   newnode->prev=Last;
   Last->next=newnode;
   newnode->serial=number;
	newnode->quantity=quantity;
   newnode->act_price=act_price;
   newnode->sell_price=sell_price;
   Last=newnode;
   }
gotoxy(24,22);
cout<<"Item Successfully added to stock"<<endl;
Sleep(1400);
m:
clrscr();
sorting();
save_file();
return;
}


//Update Function

void update_existing(int number)
{
int n;
dlist *temp=First;
char existing[15];
clrscr();
system("color 81");
gotoxy(27,3);
box();
gotoxy(35,4);
printf("Update  Stock");
gotoxy(27,5);
box();
gotoxy(27,8);
while(temp->serial!=number)
	{
   temp=temp->next;
   }
gotoxy(27,10);
printf("Enter Quantity:");
cin>>n;
temp->quantity=temp->quantity+n;
gotoxy(29,14);
printf("Item Successfully Updated");
Sleep(1400);
clrscr();
return;
}



//Delete function

void dellete(void)
{
clrscr();
system("color 81");
char name[15];
char confirm;
dlist *temp=First;
gotoxy(27,2);
box();
gotoxy(33,3);
printf("Delete Stock Item");
gotoxy(27,4);
box();
gotoxy(33,6);
printf("Product Name:");
cin>>name;
while(temp!=NULL)
	{
	if(strcmp(temp->product,name)==0)
   	{
      gotoxy(36,8);
      printf("Product Found");
      gotoxy(17,10);
      printf("Are you sure to delete product (Serial no.%d):", temp->serial);
      scanf("%c",&confirm);
      if(confirm=='y')
       	{
        	if((temp->prev==NULL)&&(temp->next==NULL))
       		{
           	First=NULL;
            delete temp;
          	gotoxy(30,14);
            printf("Product Deleted from Stock\n");
          	break;
           	}
         else if((temp->prev==NULL)&&(temp->next!=NULL))
         	{
           	First=First->next;
            temp=First;
            delete temp->prev;
            temp->prev=NULL;
            gotoxy(30,14);
           	printf("Product Deleted from Stock\n");
           	break;
           	}
         else if(temp->next==NULL)
         	{
           	temp=temp->prev;
           	Last=temp;
           	delete temp->next;
           	temp->next=NULL;
            gotoxy(30,14);
          	printf("Product Deleted from Stock\n");
          	break;
            }
         else
         	{
         	temp->prev->next=temp->next;
         	temp->next->prev=temp->prev;
         	delete temp;
            gotoxy(30,14);
           	printf("Product Deleted from Stock\n");
         	break;
         	}
         }
      else if(confirm=='n')
      	{
         break;
         }
      }
   else
    	{
      gotoxy(28,14);
      for(int a=0;a<3;a++)
   	printf("\a");
      printf("Product not found\n");
      temp=temp->next;
     	}
   }
Sleep(1000);
clrscr();
}


//Login Function

void login (void)
{
system("color 81");
char username[10],password[10];
char a[10]={'b','e','s','e','1','8','-','b'};
char b[10]={'m','c','s','@','1','2','3'};
char temp;
x:
system("color 81");
gotoxy(27,2);
box();
gotoxy(39,3);
printf("Login");
gotoxy(27,4);
box();
while(username!=a)
	{
   system("color 81");
   gotoxy(33,6);
	printf("Username: ");
	scanf("%s",&username);
   for(int i=0; username[i]!='\0';i++)
   	{
     	username[i]=tolower(username[i]);
      }

   if((strcmp(username,a))==0)
		{
      system("color 81");
      gotoxy(33,8);
      printf("Correct Username");
   	while(password!=b)
   		{
         system("color 81");
         gotoxy(33,12);
   		printf("Password: ");
         for(int i=0;i<7;i++)
     	   	{
				temp=getch();
				if(temp=='\n')
					{
               break;
               }
				password[i]=temp;
				cout<<"*";
				}
         getch();
   		if((strcmp(password,b))==0)
   			{
            system("color 81");
            gotoxy(33,14);
            printf("Correct Password");
            Sleep(1000);
            return;
      		}
         else
         	{
            gotoxy(33,14);
            }
         system("color 81");
         for(int a=0;a<3;a++)
      		{
            printf("\a");
            }
         printf("Access Denied !");
         Sleep(800);
         clrscr();
         goto x;
   		}
   	}
   else
   	{
      gotoxy(33,8);
      for(int a=0;a<3;a++)
      	{
         printf("\a");
         }
      printf("Incorrect Username");
      system("color 81");
      Sleep(800);
      clrscr();
      goto x;
		}
	}
}


//Sell function

void sell(void)
{
int num, quan,m;
char name[15];
dlist *temp=First;
system("color 81");
gotoxy(27,2);
box();
gotoxy(32,3);
printf("Sell Stock Products");
gotoxy(27,4);
box();
gotoxy(29,6);
printf("Enter Product name:");
cin>>name;
while(strcmp(temp->product,name)!=0)
	{
  	temp=temp->next;
   if(temp==NULL)
	   {
   	goto m;
      }
   }
gotoxy(29,8);
printf("Enter quantity:");
scanf("%d",&quan);
{
if(quan>temp->quantity)
	{
   gotoxy(30,12);
   for(int a=0;a<3;a++)
   	{
      printf("\a");
      }
   printf("Sorry, Not much  quantity !");
   Sleep(1300);
   clrscr();
   return;
   }
else if(quan<=temp->quantity && quan>=0)
	{
	temp->quantity=(temp->quantity)-quan;
   gotoxy(33,12);
   printf("Product Sold !");
   Sleep(1500);
   }
}
{
if(temp->quantity<6 && temp->quantity>0)
	{
   for(int a=0;a<4;a++)
   	{
   	clrscr();
   	system("color 81");
   	Sleep(500);
   	gotoxy(12,6);
   	printf("\a");
   	printf("Warning !! Please buy more items to overcome deficiency");
   	Sleep(500);
   	}
	}
else if(temp->quantity==0)
	{
   gotoxy(29,16);
	system("color 81");
   for(int a=0;a<3;a++)
   	{
      printf("\a");
      }
   printf("No items left in  stock");
   Sleep(1000);
   }
}

Sleep(1000);
clrscr();
bill(temp,quan);
getch();
system("cls");

m:
system("cls");
system("color 81");
printf("\a");
printf("No item found with this name\n");
Sleep(1000);
}


//Display function

void display()
{

dlist *temp=First;
int a=9;
system("cls");
system("color 81");
gotoxy(27,2);
box();
gotoxy(30,3);
printf("Stock Products  Display");
gotoxy(27,4);
box();
printf("\n\n   PRODUCT            SERIAL              QUANTITY             PRICE\n");
//myfile<<"\n\n   PRODUCT            SERIAL              QUANTITY             PRICE\n"<<endl;
printf("   -------            ------              --------             -----\n");
//myfile<<"   -------            ------              --------             -----\n"<<endl;
while(temp!=NULL)
	{
   gotoxy(4,a);
  // myfile<<"       ";
   printf("%s",temp->product);
   //myfile<<temp->product;
   //myfile<<"\t\t      ";
   gotoxy(23,a);
   printf("%d",temp->serial);
   //myfile<<temp->serial;
   //myfile<<"\t          ";
   gotoxy(43,a);
   printf("%d",temp->quantity);
   //myfile<<temp->quantity;
   //myfile<<"\t           ";
   gotoxy(64,a);
   printf("Rs.%d",temp->sell_price);
   //myfile<<temp->sell_price<<endl;
   temp=temp->next;
   a++;
   }

getch();
clrscr();
}


//Sale Function

void average_monthly_sale()
{
dlist *temp=First;
y:
clrscr();
char name [15];
system("color 81");
gotoxy(25,3);
box();
gotoxy(30,4);
printf("Monthly Average Sale");
//myfile<<"\t\tMonthly Average Sale"<<endl;
gotoxy(25,5);
box();
gotoxy(24,8);
printf("Enter Name of item to find average: ");
cin>>name;
gotoxy(24,10);
if((strcmp(name,temp->product))==0)
	{
   float no_of_items;
	printf("\nEnter initial number of items in stock:");
	scanf("%f",&no_of_items);
	float AB_ITEMS = no_of_items - temp->quantity;
	float average;
	average= AB_ITEMS / no_of_items;
	float k;
	k=average/12;
	float percent_average;
	percent_average=k*100;
	printf("Average Sale is %f",percent_average);
  //	myfile<<"Average Sale is";
	//myfile<<percent_average<<endl;
	}
else
	{
	temp=temp->next;
   }
getch();
clrscr();
}


//Tax function

int tax(int a)
{
float actual_price,final_price,TAX;
actual_price=a;
TAX= 0.17 * actual_price;
final_price= TAX + actual_price;
return final_price;
}


//Profit\Loss function

void profit_loss()
{
system("color 81");
char item_name[15];
dlist *temp=First;
int Diff,profit,Final;
clrscr();
system("color 81");
gotoxy(27,3);
box();
gotoxy(33,4);
printf("Check Profit Loss");
gotoxy(27,5);
box();
gotoxy(28,8);
printf("Enter the name of item:");
scanf("%s",&item_name);
gotoxy(25,10);
while(temp!=NULL)
	{
   if((strcmp(item_name,temp->product))==0)
   	{
      goto p;
      }
   else
   	{
      temp=temp->next;
      }
   }
p:

Diff = temp->sell_price - temp->act_price;
{
if(Diff>0)
{
gotoxy(30,14);
printf("Difference Profit is of %d", Diff);
}
else if(Diff<0)
{
gotoxy(30,14);
printf("Difference Loss is of %d", Diff);
}
}
getch();
clrscr();
}

//Line function

void box()
{
for(int l=1;l<=29;l++)
printf("\xC4");
}



//Billing Function


void bill(dlist *temp,int quan)
{
//fstream myfile("project.txt",ios::app);
system("color 81");
float a,final_price;
a=quan*temp->sell_price;
final_price=tax(a);
gotoxy(27,2);
box();
gotoxy(27,3);
cout<<" Inventory DataBase Billing"<<endl;
gotoxy(27,4);
box();
gotoxy(27,6);
box();
gotoxy(27,7);
cout<<" Item Name: "<<temp->product<<endl;
gotoxy(27,8);
box();
gotoxy(27,9);
cout<<" Item Serial: "<<temp->serial<<endl;
gotoxy(27,10);
box();
gotoxy(27,11);
cout<<" Item Quantity: "<<quan<<endl;
gotoxy(27,12);
box();
gotoxy(27,13);
cout<<" Item Price/Unit: "<<temp->sell_price<<endl;
gotoxy(27,14);
box();
gotoxy(27,15);
cout<<" Total (Excluding Tax): "<<temp->sell_price*quan<<endl;
if(temp->sell_price*quan>500)
	{
   gotoxy(27,16);
	box();
	gotoxy(27,17);
	cout<<" GST Tax: "<<0.17*a<<endl;
   gotoxy(27,18);
	box();
	gotoxy(27,19);
	cout<<" Total (Including Tax): "<<final_price<<endl;
   gotoxy(27,20);
	box();
   gotoxy(10,24);
   printf("* Tax is only applicable on items total purchase above Rs.500");
   return;
   }
else
	{
   gotoxy(27,16);
	box();
   gotoxy(10,19);
   printf("* Tax is only applicable on items total purchase above Rs.500");
   return;
   }
}


void Stock_Status(void)
{
clrscr();
system("color 81");
int a=9;
dlist *temp=First;
gotoxy(27,2);
box();
gotoxy(35,3);
printf("Stock  Status");
gotoxy(27,4);
box();
gotoxy(29,6);
printf("Product             Status");
gotoxy(29,7);
printf("-------             ------");
while(temp!=NULL)
   {
   gotoxy(29,a);
   printf("%s",temp->product);
	gotoxy(46,a);
   if(temp->quantity<6 && temp->quantity>0)
   	{
   	printf("Poor Stock");
      }
   else if(temp->quantity>6)
      {
      printf("Available");
      }
   else if(temp->quantity==0)
     	{
     	printf("Not Available");
     	}
   temp=temp->next;
   a=a+2;
   }
getch();
clrscr();
return;
}


void search(void)
{
system("cls");
dlist *temp=First;
char c[30];
int a,m;
system("color 81");
gotoxy(27,2);
box();
gotoxy(36,3);
printf("Stock  Search");
gotoxy(27,4);
box();
gotoxy(27,8);
printf("Enter name of the product:");
scanf("%s", &c);
for(int i=0; c[i]!='\0';i++)
 	{
  	c[i]=tolower(c[i]);
   }
while(temp!=NULL)
   {
   if((strcmp(temp->product,c))==0)
      {
      system("cls");
      gotoxy(27,2);
		box();
		gotoxy(36,3);
		printf("Stock  Search");
      gotoxy(27,4);
		box();
      printf("\n\n      PRODUCT            SERIAL              QUANTITY             PRICE\n");
      printf("      -------            ------              --------             -----\n");
      gotoxy(7,9);
      printf("%s",temp->product);
      gotoxy(26,9);
	  	printf("%d",temp->serial);
      gotoxy(46,9);
   	printf("%d",temp->quantity);
      gotoxy(67,9);
   	printf("Rs.%d",temp->sell_price);
      getch();
      clrscr();
      return;
      }
   temp=temp->next;
   }

system("cls");
gotoxy(27,2);
box();
gotoxy(35,3);
printf("Stock   Search");
gotoxy(27,4);
box();
gotoxy(33,9);
for(int a=0;a<3;a++)
  	{
   printf("\a");
   }
printf("Product Not Found");
Sleep(1000);
clrscr();
return;
}


// reading from file
/*void read_file()
{
clrscr();
system("color 81");
ifstream fin("project.txt");
char c[100];
while(!fin.eof())
	{
   fin.getline(c,100,'\n');
	cout<<c<<endl;
	}
fin.close();
} */


void sorting ()
{
dlist *temphead;
dlist *tempnode;
int temp,PRICE,Price,quanti;
char temp_name[20];
for  (temphead=First;temphead!=NULL;temphead=temphead->next)
	{
	for(tempnode=temphead;tempnode!=NULL;tempnode=tempnode->next)
   	{
      if(temphead->serial > tempnode->serial)
      	{
        	temp=temphead->serial;
         PRICE=temphead->act_price;
         Price=temphead->sell_price;
         quanti=temphead->quantity;
         strcpy(temp_name,temphead->product);

         temphead->serial = tempnode->serial;
         temphead->act_price = tempnode->act_price;
         temphead->sell_price= tempnode->sell_price;
         temphead->quantity= tempnode->quantity;
         strcpy(temphead->product,tempnode->product);

         tempnode->serial = temp;
         tempnode->act_price=PRICE;
         tempnode->quantity=quanti;
         strcpy(tempnode->product,temp_name);
         tempnode->sell_price=Price;
         }
      }
	}
}

void save_file()
{
   ofstream myfile("project.txt");
	dlist *temp=First;
   while(temp!=NULL)
   	{
      myfile<<temp->product<<endl;
      myfile<<temp->serial<<endl;
      myfile<<temp->quantity<<endl;
      myfile<<temp->act_price<<endl;
      myfile<<temp->sell_price<<endl;
      temp=temp->next;
   	}
      myfile.close();
}
