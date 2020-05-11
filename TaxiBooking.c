#include<stdio.h>
#include <string.h>
#include <math.h>
int cab_i=0,cust_i=0;


struct customer
{
    char username[20];
    char password[20];
    char stations[100];

    int stat_i;

};
struct customer cust[6];



struct cabdriver
{
    char username[20];
    char password[20] ;
    char stations[100];
    char cur_loc;
    int money_earned;
    int time;
    int stat_i;
    int dis_travelled;
}cab[6];

struct admin
{
   char username[20];
   char password[20];
}admin;

void basic(){
   int i;
   for(i=0;i<5;i++){
    cab[i].cur_loc='a';
   }

   strcpy(cab[0].username,"cabdriver-a");
   strcpy(cab[0].password,"zoho-a");
   strcpy(cab[1].username,"cabdriver-b");
   strcpy(cab[1].password,"zoho-b");
   strcpy(cab[2].username,"cabdriver-c");
   strcpy(cab[2].password,"zoho-c");
   strcpy(cab[3].username,"cabdriver-d");
   strcpy(cab[3].password,"zoho-d");
   strcpy(cab[4].username,"cabdriver-e");
   strcpy(cab[4].password,"zoho-e");

     strcpy(admin.username,"klu");
   strcpy(admin.password,"zoho");

}

void customerhistory(int cust_no){
    printf("Customer Username : %s\n",cust[cust_no].username);
    int money_spent=0,i;
    printf("\nFROM\tTO\tMONEYSPENT\n");
    for(i=0;i<cust[cust_no].stat_i;i=i+2){
            int m=(abs(cust[cust_no].stations[i]-cust[cust_no].stations[i+1])*5)*30;
        printf("%c\t%c\t%d\n",cust[cust_no].stations[i],cust[cust_no].stations[i+1],m);
        money_spent=money_spent+m;
    }

    printf("\n\t TOTAL COST : %d /- ",money_spent);

    printf("\n-----------------------------------------------------------------------------\n\n");

}
void findcar(char from,char to,int t,int cust_no){

    int i,car=-1,max=10000;
    for(i=0;i<5;i++){
           if(cab[i].cur_loc==from){

                if(cab[i].time<=t){
            if(cab[i].money_earned<max){
            max=cab[i].money_earned;
            car=i;
            }
                }
        }

    }
    if(car==-1){
        for(i=0;i<5;i++){
            if(cab[i].cur_loc,from-1==0 || cab[i].cur_loc,from+1==0 ){
                    if(cab[i].time<=t){
                        if(cab[i].money_earned<max){
                        max=cab[i].money_earned;
                        car=i;
                        }
                }
            }
        }
    }
    if(car==-1){
        for(i=0;i<5;i++){
            if(cab[i].time<=t){
                if(cab[i].money_earned<max){
                        max=cab[i].money_earned;
                        car=i;
                        }
            }
        }
    }

    if(car==-1){
        printf("\nSORRY ! NO CAR IS AVAILABLE AS OF NOW \n\n");
    }
    else{
        printf("\n CAR ALLOCATED : %c \n",car+'a');
        cust[cust_no].stations[cust[cust_no].stat_i]=from;
        cust[cust_no].stat_i++;
        cust[cust_no].stations[cust[cust_no].stat_i]=to;
        cust[cust_no].stat_i++;
        cab[car].cur_loc=to;
        cab[car].time=t+15;
        cab[car].stations[cab[car].stat_i]=from;
        cab[car].stat_i++;
        cab[car].stations[cab[car].stat_i]=to;
        cab[car].stat_i++;
    }

}

void bookride(int cust_no){
    printf("Customer Username : %s\n",cust[cust_no].username);
      char time[5],from,to;
      printf("Enter Time : ");
      scanf("%s",time);
      int hour=(time[0]-'0')*10+(time[1]-'0');
      int min=(time[3]-'0')*10+time[4]-'0';
      int t=hour*60+min;
      //printf("%d\n",t);
        printf("Enter From : \n");
        scanf(" %c", &from);

        printf("Enter To : \n");
        scanf(" %c", &to);



         findcar(from,to,t,cust_no);


}

void cabdriverhistory(int cab_no){
    int i;
    printf("\n CAB DRIVER PORTAL : %c \n ",cab_no+'a');
    printf("\n CURRENT LOCATION : %c \n",cab[cab_no].cur_loc);
    printf("\nFROM\tTO\tMONEY EARNED\n");
    for(i=0;i<cab[cab_no].stat_i;i=i+2){
            int dis=abs(cab[cab_no].stations[i]-cab[cab_no].stations[i+1])*5;
            int m=(dis)*30;
        printf("%c\t%c\t%d\n",cab[cab_no].stations[i],cab[cab_no].stations[i+1],m);
        cab[cab_no].money_earned=cab[cab_no].money_earned+m;
        cab[cab_no].dis_travelled=cab[cab_no].dis_travelled+dis;
    }

    printf("\n TOTAL DISTANCE : %d \n",cab[cab_no].dis_travelled);
    printf("\n TOTAL REVENUE : %d \n",cab[cab_no].money_earned);

    printf("\n --------------------------------------------------------- \n\n");

}

int logincheck(char* u ,char* p,int n){
      int i;
        for(i=0;i<5;i++){
            if(strcmp(cab[i].username,u)==0 && strcmp(cab[i].password,p)==0){
                    cab_i=i;
                return 1;
            }
        }
        for(i=0;i<n;i++){
            if(strcmp(cust[i].username,u)==0 && strcmp(cust[i].password,p)==0){
                return 2;
            }
        }

        if(strcmp(admin.username,u)==0 && strcmp(admin.password,p)==0)
            return 3;

            return 0;

}


    void customer(char* u,char* p){
           int i,cust_no=-1,w=0;
                 for(i=0;i<cust_i;i++){
                  //printf(" %s %s %s %s\n",u,p,cust[i].username,cust[i].password);
                 if(strcmp(cust[i].username,u)==0 && strcmp(cust[i].password,p)==0){
                        w=1;
                        cust_no=i;
                 break;
                 }
                 }
                    int ch2=0;
                    while(ch2==0){
                    int p;

                    printf("\n1.Book Ride\t 2.See History \t 3.Logout \n");
                    printf("Enter Your Option : ");
                    scanf("%d",&p);

                    if(p==1)
                      bookride(cust_no);
                      else if(p==2)
                      customerhistory(cust_no);
                     else if(p==3){
                            ch2=1;
                    printf("\n Your Logged Out \t Thank You \n");
                     }
                    else{

                        printf("You Entered Wrong Option \n\n");
                    }
                    }

}


int main(void){

     basic();

     int ch=0;
     while(ch==0){
     int op;
     printf("1 . Log In \t 2. Creat Account 3.Exit \n");
     printf("Enter Your Option : ");
     scanf("%d",&op);

     if(op==2){

         printf("Enter Username : ");
         scanf("%s",cust[cust_i].username);
         printf("Enter Password : ");
         scanf("%s",cust[cust_i].password);

         cust[cust_i].stat_i=0;
            // printf("%d \n",cust_i);
         printf("Your Account is Created Successfully \n\n");
         //printf("%s %s \n",cust[cust_i].username,cust[cust_i].password);

             cust_i++;

     }
     else if(op==1){
            char u[100],p[100];
                 printf("Enter Your Username : ");
                 scanf("%s",u);
                 printf("Enter Your Password : ");
                 scanf("%s",p);
           int i;
                  //printf("%d\n",cust_i);
                  int lc=logincheck(u,p,cust_i);
                  if(lc==3){
                        for(i=0;i<cust_i;i++)
                    customerhistory(i);
                  for(i=0;i<5;i++)
                    cabdriverhistory(i);
                  }
                  else if(lc==2){
                    customer(u,p);
                  }
                  else if(lc==1){
                    cabdriverhistory(cab_i);
                  }
                  else{
                    printf("You Entered Wrong Username or Wrong Password \n \n");
                  }




     }
     else{
     printf("Thank You\n");
     ch=1;
     }

     }



return 0;
}
