#include<stdio.h>
#include<string.h>
#include<math.h>
struct logdata
{
	char admin_username[20]={'klu'};
	char admin_password[20]={'zoho'};
	char cab_username[5][20]={"cabdriver-a","cabdriver-b","cabdriver-c","cabdriver-d","cabdriver-e"};
	char cab_password[5][20]={"zoho-a","zoho-b","zoho-c","zoho-d","zoho-e"};
	char cust_password[20]={'customer'};
	char cust_username[20]={'book'};
}ld;

struct cabdriver
{
	char stations[100];
	char cur_loc='a';
	int loc;
	int money;
	int t=0;
	
}cab[6];
struct customer
{
	char stations[100];
	char cur_loc;
};


int menu(){

	
	int ch;
	printf("1.Book Ride  2.See History 3.Logout\n");
	printf("Enter Your Option : ");
	scanf("%d",&ch);
	return ch;
}
int menu1(){
	int ch;
	printf("1.Prebook  2.SpotBook\n");
	printf("Enter Your Option : ");
	scanf("%d",&ch);
	return ch;
}
int login(){
	char user_name[20],password[20];
	printf("Enter Username : ");
	scanf("%s",&user_name);
	printf("Enter Password: ");
	scanf("%s",&password);	
	
}
int main(void){
		
	struct customer cust;
	
	for(int i=1;i<=5;i++)
	cab[i].loc=0;
	
	char f,t,p;
	while(1){
		
		int ps=menu1();			
		if(ps==1){	
		int hh,mm,time;
		printf("Enter Time : ");
		scanf("%d%d",&hh,&mm);
		time=hh*60 + mm;
		printf("Enter From : \n");
        scanf(" %c", &f);
      
     
        printf("Enter To : \n");
        scanf(" %c", &t);     
		
	
				int car=0;
		int max=100000;
		for(int i=1;i<=5;i++){
			if(cab[i].t<time){
				if(cab[i].money<max){
					max=cab[i].money;
					car=i;
				}
				
			}
		}
		if(car!=0){
		cab[car].t=time+15;	
			
	    cab[car].money= cab[car].money + 150 ;
		printf("Car allocated : %c \n",car+'a'-1);
		cab[car].stations[cab[car].loc]=f;
		cab[car].loc++;
		cab[car].stations[cab[car].loc]=t;
		cab[car].loc++;
		cab[car].cur_loc=t;
		for(int i=0;i<cab[car].loc;i++){
			printf("%c ",cab[car].stations[i]);
		}
		printf("\n");
		
		for(int i=1;i<=5;i++)
        {
	       printf(" %d : %c %d %d \n ",i,cab[i].cur_loc,cab[i].money,cab[i].t);
		}		
		
	}
	else
	printf("Sorry! No cars are available ");
	int p=menu();
		
		switch(p){
			
			case 1: break;
			case 2: break;			
			case 3: printf("Logged Out\n");			         
			break;
			default : printf("Please Select Valid Option \n"); 
		}
		if(p==3)
		break;
	}
		
	}
	
return 0;	
}
