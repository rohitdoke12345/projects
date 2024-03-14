#include <stdio.h>
#include <string.h>
#include<stdlib.h>
struct customer {
    char name[20];
    char address[20];
    char prescribed_doctor[20];
    char mname[10];
    int quantity;
};

struct medicine {
    int mid;
    char mname[10];
    int mprice;
    char mtype[10];
    int strip;
    char exp[13];
    int quantity;
};

struct tbill { // for total bill for single customer
	char name[10];
	int quantity;
	float tprice;
};
//----------------------------------------pointers & Global variable----------------------------

struct medicine *data,*data1;// malloc and realloc for case 1 and 2nd
int len,n,i,k,size,j; // "len " = is number of medicine in stock to add // "size " = malloc and realloc for case 7 for adding number customer
struct customer *cust, *cust1; // malloc and realloc for case 7 for adding number customer

//------------------------------------Aunthentication--------------------------------------------

int admin_auth(char x[], char y[], char a[], char b[]) { // comper user id and password
    return (strcmp(x, a) == 0 && strcmp(y, b) == 0);
}

//-------------------------------------Malloc-Add-Data-------------------------------------------

int add() // case 1 - adding stock of medicine at 1st using malloc
{
	printf("Enter number of product to add :  ");
    scanf("%d",&len);
    data = (struct medicine *) malloc (sizeof(struct medicine)*len);
	
	for(i=0;i<len;i++)
	{
		printf("\nEnter details of %d product\n",++k);
		printf("\nEnter ID\t "); 
		scanf("%d",&data[i].mid);
		_flushall(); // string buffer removal 
		printf("Enter Name\t ");
        gets(data[i].mname);
        _flushall();
        printf("Enter Price\t ");
        scanf("%d", &data[i].mprice);
        _flushall();
        printf("Enter Type\t ");
        gets(data[i].mtype);
        _flushall();
        printf("Enter Strip\t ");
        scanf("%d",&data[i].strip);
        _flushall();
        printf("Enter Expiry\t ");
        gets(data[i].exp);
        _flushall();
        printf("Enter Quantity\t ");
        scanf("%d", &data[i].quantity);	
		_flushall();	
		printf("\n----- Product added successfully -----\n");
	}
}
//--------------------------------Realloc-Add_Data-------------------------------------------------

int add1() // case 2 - adding extra stock of medicine using realloc 
{
	printf("Enter number of product to add :  ");
    scanf("%d",&n);//1000 10002 10004
    data1 = (struct medicine *) realloc (data,sizeof(struct medicine)*n);
		
	len = len+n; 	
	for(i=len-n;i<len;i++)
	{
		printf("\nEnter details of %d product\n",++k);
		printf("\nEnter ID\t ");
		scanf("%d",&data1[i].mid);
		_flushall();
		printf("Enter Name\t ");
        gets(data1[i].mname);
        _flushall();
        printf("Enter Price\t ");
        scanf("%d", &data1[i].mprice);
        _flushall();
        printf("Enter Type\t ");
        gets(data1[i].mtype);
        _flushall();
        printf("Enter Strip\t ");
        scanf("%d",&data1[i].strip);
        _flushall();
        printf("Enter Expiry\t ");
        gets(data1[i].exp);
        _flushall();
        printf("Enter Quantity\t ");
        scanf("%d", &data1[i].quantity);	
		_flushall();	
		printf("\n----- Product added successfully -----\n");
	}
}
//-------------------------------------Display Data---------------------------------------------
void display()  // case 3
{
	int i;
	if(k!=0)
	{
	printf("\nID\t\tName\t\tPrice\t\tType\t\tStrip\t\tExpiary Date\tQuantity\n\n");
	for(i=0;i<len;i++)
	{
		if(data[i].mid!=-1) //  id replace by -1 so while seraching it should not print
		{
			printf("%d\t\t%s\t\t%d\t\t%s\t\t%d\t\t%s\t\t%d\n",data[i].mid,data[i].mname,
				data[i].mprice,data[i].mtype,data[i].strip,data[i].exp,data[i].quantity);
		}
	}
	}
	else
	{
		printf("\n*** Stock is EMPTY !!! ***");
	}
}
//-------------------------------Update and delete Function-----------------------------------------
int update_delete(struct medicine data[],int x) // case 4 and 5 // int x = id passed by case 4 and 5
{
	int i,flag=0;
	for( i=0;i<len;i++)
	{
		if(data[i].mid==x)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		return i;
	}
	else
	{
		return -1;
	}
}

//-----------------------------Search by ID Function---------------------------------------------------

void search(int x)  // case 6 // from the above function return i ; int x= i which is returned 
{
	printf("\nID\t\tName\t\tPrice\t\tType\t\tStrip\t\tExpiary Date\tQuantity\n\n");
	for(i=0;i<len;i++)
	{
		if(i==x)
		{
			printf("%d\t\t%s\t\t%d\t\t%s\t\t%d\t\t%s\t\t%d\n",data[i].mid,data[i].mname,
				data[i].mprice,data[i].mtype,data[i].strip,data[i].exp,data[i].quantity);
		}
	}
	
}
//--------------------------------Search by Name function----------------------------------------------------------------

void nsearch(char x[]) // case -6
{
	int count=0;
	
	for(i=0;i<len;i++)
	{
		if(strcmp(data[i].mname,x)==0)
		{
			count ++;
			if(count==1)
			      printf("\nID\t\tName\t\tPrice\t\tType\t\tStrip\t\tExpiary Date\tQuantity\n\n");
			printf("%d\t\t%s\t\t%d\t\t%s\t\t%d\t\t%s\t\t%d\n",data[i].mid,data[i].mname,
				data[i].mprice,data[i].mtype,data[i].strip,data[i].exp,data[i].quantity);
		}
	}
	if(count==0)
	{
		printf("\n*** Name of medicine not found !!! ***");
	}
}

//-------------------------------Search by Type Function------------------------------------------

void tsearch(char x[])   // case 6
{
	int count=0;
	
	for(i=0;i<len;i++)
	{
		if(strcmp(data[i].mtype,x)==0)
		{
			count ++;
			if(count==1)
			      printf("\nID\t\tName\t\tPrice\t\tType\t\tStrip\t\tExpiary Date\tQuantity\n\n");
			printf("%d\t\t%s\t\t%d\t\t%s\t\t%d\t\t%s\t\t%d\n",data[i].mid,data[i].mname,
				data[i].mprice,data[i].mtype,data[i].strip,data[i].exp,data[i].quantity);
		}
	}
	if(count==0)
	{
		printf("\n*** Type of medicine not found !!! ***");
	}
}

//--------------------------------Search by Price Function---------------------------------------

void psearch(int x)  // case 6
{
	int count=0;
	

	for(i=0;i<len;i++)
	{
		if(data[i].mprice == x)
		{
			count ++;
			if(count==1)
			      printf("\nID\t\tName\t\tPrice\t\tType\t\tStrip\t\tExpiary Date\tQuantity\n\n");
			printf("%d\t\t%s\t\t%d\t\t%s\t\t%d\t\t%s\t\t%d\n",data[i].mid,data[i].mname,
				data[i].mprice,data[i].mtype,data[i].strip,data[i].exp,data[i].quantity);
		}
	}
	if(count==0)
	{
		printf("\n*** Price of medicine not found !!! ***");
	}
}
//-----------------------------Prescreption Function---------------------------------------------

void prescription() // case 7
{
	int counter1=0; //one execution of total bill
	float day_bill=0;  //one execution of total bill 
	if(len>0) // if stock is avilable
	{
		int num1, m=1 ;
		float total_p; 
		
		printf("\nEnter number of customer :\n");
		scanf("%d",&size);
		
		struct tbill info[size]; // structure varibale create 
		
   		cust = (struct customer *) malloc (sizeof(struct customer)*0); // not storing any value coz readding data 
    	
    	cust1= (struct customer *) realloc (cust, sizeof(struct customer)*size);
    	
    	for(i=0;i<size;i++)
    	{
    
    		printf("\n\tEnter details of %d customer \n",m++);
    		printf("\n\tEnter name :");
    		_flushall();
    		gets(cust[i].name);
    		printf("\n\tEnter address :");
    		_flushall();
    		gets(cust[i].address);
    		printf("\n\tEnter prescribed doctor name :");
    		_flushall();
    		gets(cust[i].prescribed_doctor);
    		
    		int l,counter=0;
			float bill=0;
    		printf("\nEnter number of medicines\n");//2
    		scanf("%d",&num1);
    		
    		for(l=0;l<num1;l++)
    		{
    			printf("\n\tEnter medicine name  :");
    			_flushall();
    			gets(cust[i].mname);
    			printf("\n\tEnter quantity :");
 	   			scanf("%d",&cust[i].quantity);
				
				for(j=0;j<len;j++)
				{		
					int total_med = data[j].quantity * data[j].strip; // counting total medicine = strip * quantity (struct medicine)
					float total_price = data[j].mprice / data[j].strip;	// counting price of one tablet 
					
    				if(strcmp(data[j].mname,cust[i].mname)==0)
    				{
    					if(total_med>=cust[i].quantity)
    					{
						total_p=total_price*(float)cust[i].quantity;  // price of tablet  added by customer 
						data[j].quantity=data[j].quantity-(cust[i].quantity/data[j].strip); // update quantity in stock after customer prescription
						
						for(int p = counter ; p<counter+1; p++) // storing avilable medicine in strucure info for printing bill
						{
    						strcpy(info[p].name,data[j].mname);
    						info[p].quantity=cust[i].quantity;
    						info[p].tprice=total_p;
						}
    					counter++; 
    					counter1++;
    					
    					
						bill=bill+total_p; // bill for each customer 
						}
					}
					if(counter==0)
					{
						printf("\n\t*** Medicine is not avilable ***\n");
					}	
				}
			}
				day_bill= day_bill + bill; // total bill in one execution 
			
			if(counter>0)
    		{
    			printf("\n\n\t*** Bill ***\n\n");
    			printf("\n\t------------------------------+ Lifeline Medical +----------------------------------");
    			printf("\n\tName      : %s\n",cust[i].name);
   				printf("\tAdd         : %s\n",cust[i].address);
    			printf("\tDoctor name : %s\n",cust[i].prescribed_doctor);
  				printf("\t--------------------------------------------------------------------------------------\n");
   				printf("\n\tName\tQuantity\tPrice\n");
   				
   				for(j=0;j<counter;j++)
   				{
   					printf("\n\t%s\t %d\t   %.2f\n",info[j].name,info[j].quantity,info[j].tprice);
				}
				printf("\n\tTotal bill without  GST is %.2f\n",bill);
				printf("\n\tTotal bill with  GST is %.2f\n",bill+(bill*0.18)); // GST
				printf("\n\t--------------------------------+ Get well soon +------------------------------------\n\n");
			}
		}
	}
	else
	{
		printf("\n*** No medicine is availble ***\n");
	}
	printf("\n\t--------------------------------+ Today's total bill +------------------------------------\n\n");
	if(counter1>0)
	{
		printf("\n \tToday's total bill : %.2f",day_bill+(day_bill*0.18));
	}
	printf("\n\n\t----------------------------------------------------------------------------------------\n");
}
		
//-----------------------------Main Function------------------------------------------------------

int main() {
    char aname[10], pass[10], vname[10], vpass[10];
    int auth,a;
    char b[10]={-1}; // for delete string mname and m type in structure medicine

    printf("\n----- Welcome to Lifeline Medical Store -----\n\n");

    printf("\nEnter Admin details\n");
    printf("Enter a User_Name: ");
    gets(aname);
    printf("Enter a password: ");
    gets(pass);

    printf("\n----- Authentication of Admin -----\n");
    printf("Enter User_Name: ");
    gets(vname);
    printf("Enter password: ");
    gets(vpass);

    auth = admin_auth(aname, pass, vname, vpass); // calling fuction autho

    if (auth == 1) {
        int choice, sid,result;
        char sname[10];
        int len = 6 ;
        
        printf("\n** Logged in successfully **\n");
       
        do {
            printf("\n\t1. Add stock of medicine products\n");
            printf("\n\t2. Additional medical product\n");
            printf("\n\t3. Display all medical  product\n");
            printf("\n\t4. Update specific product by ID\n");
            printf("\n\t5. Delete specific product by ID\n");
            printf("\n\t6. Search specific product \n");
            printf("\n\t7. Upload prescription of doctor\n");
            printf("\n\t8. Exit\n");

            printf("\nEnter a choice:\t");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                 	add();
                    break;

                case 2:
                	add1();
                    break;

                case 3:
                	display();
                    break;

                case 4:
                	if(len>0)
                	{
                	printf("\nEnter id to update\n");
                	scanf("%d",&sid);
                	result=update_delete(data,sid); // calling
                	if(result!=-1)
                	{
                	do
                	{
                	printf("\n1:name\n2:Price\n3:Stipe\n4:Quantity\n5:Exit\n");
                	printf("\nEnter choice\n");
                	scanf("%d",&choice);
                	switch(choice)
                	{
                		case 1:
                			char nname[10];
                	
                				printf("Enetr new name\n");
                				_flushall();
                				gets(nname);
                				strcpy(data[result].mname,nname);
							printf("\n*** Name updated succesfully !!! ***\n");
                			break;
                		
                		case 2:
                			int price;
                		
                				printf("Enetr new price\n");
                				scanf("%d",&price);
                				data[result].mprice=price;
							
								printf("\n*** Price updated succesfully !!! ***\n");
                			break;
                			
                		case 3:
                			int strip;
                		
                				printf("Enetr new strip\n");
                				scanf("%d",&strip);
                				data[result].strip=strip;
							
								printf("\n*** Strip updated succesfully !!! ***\n");
                			break;
                			
                		case 4:
                			int quantity;
                		
                				printf("Enetr new quantity\n");
                				scanf("%d",&quantity);
                				data[result].quantity=data[result].quantity+quantity;
							
								printf("\n*** Quantity updated succesfully !!! ***\n");
                			break;
					}
					}while(choice>0 && choice<5);
					}
					else
					{
						printf("\n*** ID not found !!! ***\n");
					}
					}
					else
					{
						printf("\n*** Stock is EMPTY !!! **\n  ** Unable to update *  \n");
					}
                    break;

                case 5:
                	
                	if(len>0)
                	{
                	printf("\nEnter id to delete\n");
                	scanf("%d",&sid);
                	result=update_delete(data,sid);
                		if(result!=-1) // for deleting product putting -1 and will not found while serching until searched by -1
                		{
                			data[result].mid=-1;
                			strcpy(data[result].mname,b);
                			data[result].mprice=-1;
                			strcpy(data[result].mtype,b);
                			
                			
                			printf("\n----- Product deleted successfully -----\n");
                		}
                   		else
						{
							printf("\n*** ID not found !!! ***\n");
						}
					}
					else
					{
						printf("\n*** Stock is EMPTY !!! ***\n");
					}
                    break;
                    
                case 6:
                	if(len>0)
                	{
                		do
                		{
                			printf("\n\t1:ID\n\t2:Name\n\t3:Type\n\t4:Price\n\t5:Exit\n");
                			printf("\nEnter your choice  ");
                			scanf("%d",&choice);
                			
                			switch(choice)
                			{
                				case 1:
                					printf("\nEnter id to search\n");
               					 	scanf("%d",&sid);
              					  	result=update_delete(data,sid);
              					  	if(result!=-1)
              					  	{
            						  	search(result);
									}
									else
									{
										printf("\n*** ID not found !!! ***\n");
									}
                					break;
                					
                				case 2:
                					char nname[10];
                					printf("Enetr search name\n");
                					_flushall();
                					gets(nname);
                	
            						nsearch(nname);
                					break;
                				
                				case 3:
                					char type[10];
                					printf("Enetr search type\n");
                					_flushall();
                					gets(type);
                	
            						tsearch(type);
                					break;
                					
                				case 4:
                					int sprice;
                					printf("Enter search price\n");
                					scanf("%d",&sprice);
                					psearch(sprice);
                					break;
							}
						}while(choice>0 && choice<5);
					}
					else
					{
						printf("\n*** Stock is EMPTY !!! **\n  ** Unable to search *  \n");
					}
                    break;
                    
                case 7:
                	prescription();
                    break;    
            }

        } while (choice > 0 && choice < 8);
    } else {
        printf("\n** Authentication Failed **\n");
    }
    return 0;
}
