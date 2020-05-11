#include<stdio.h>
#include <string.h>

int cust_no;
struct customer
{
  char account_name[20];
  int id;
  char branch[10];
  long int balance;
  int new_id;
  char new_password[20];
  long int transfer;
  long int recharge;
  int rewards;
  int on;
  int fund_transfer;

}cust[5];

void data_entry(){
    strcpy(cust[0].account_name,"Sri");
    cust[0].id=101;
    strcpy(cust[0].branch,"vza");
    cust[0].balance=10000;


    strcpy(cust[1].account_name,"Ram");
    cust[1].id=103;
    strcpy(cust[1].branch,"tnl");
    cust[1].balance=20000;


    strcpy(cust[2].account_name,"Eswar");
    cust[2].id=903;
    strcpy(cust[2].branch,"bgl");
    cust[2].balance=50000;

    strcpy(cust[3].account_name,"Ravi");
    cust[3].id=1001;
    strcpy(cust[3].branch,"hwr");
    cust[3].balance=50000;

    strcpy(cust[4].account_name,"Kavi");
    cust[4].id=202;
    strcpy(cust[4].branch,"maa");
    cust[4].balance=60000;


}

int logincheck(int id,char* password){
     int i;

      for(i=0;i<5;i++){
        if(cust[i].id==id && strcmp(cust[i].account_name,password)==0)
        return i;
      }
            return -1;

}
int newlogincheck(int id,char* password){
      int i;
      for(i=0;i<5;i++){
        if(cust[i].new_id==id && strcmp(cust[i].new_password,password)==0)
        return i;
      }

return -1;
}

int check_cust_no(int acc_num){
  int i;
  for(i=0;i<5;i++){
    if(cust[i].id==acc_num)
        return i;
  }

  return -1;
}
void balanceEnquiry(){

   printf("\n\nYour Balance is : %ld \n",cust[cust_no].balance);
}
void balancededuction(){
if(cust[cust_no].balance<1000){
    cust[cust_no].balance-=100;
   printf("\n\n100 Rupees was deducted from your account because of low balance \n\n");
}
}

void ministatement(){

    printf("Transfer\t:\t%d\n\n",cust[cust_no].transfer);
    printf("Recharge\t:\t%d\n\n",cust[cust_no].recharge);
    printf("Rewards\t:\t%d\n\n",cust[cust_no].rewards);
    balanceEnquiry();

}

void recharge(){
    int ph_num ,amount;
 printf("Enter Mobile Number : ");
 scanf("%d",&ph_num);
 printf("Enter Amount : ");
 scanf("%d",&amount);
      if(amount>cust[cust_no].balance){
        printf("Low balance . ");
        balanceEnquiry();
    }
    else{
            if(amount>1000)
            cust[cust_no].rewards+=(amount*0.07);
            else if(amount>100)
                cust[cust_no].rewards+=amount*0.03;

         cust[cust_no].balance+=cust[cust_no].rewards;

        cust[cust_no].balance-=amount;
        cust[cust_no].recharge+=amount;
        printf("Recharge Successfull ...... \n\n");
        balancededuction();
    }
}

void transfer(){
    int acc_num;
    long int amount;
   printf("Enter Account Number to Transfer : ");
   scanf("%d",&acc_num);
   printf("Enter The Amount : ");
   scanf("%ld",&amount);

   if(amount>cust[cust_no].balance){
    printf("Low Balance . ");
    balanceEnquiry(cust_no);
   }
   else{
    int acc=check_cust_no(acc_num);
    if(acc==-1)
        printf("Your Entered Wrong Account number \n\n");
    else{
            cust[cust_no].fund_transfer++;
           if(cust[cust_no].fund_transfer>5)
            cust[cust_no].balance-=5;
    cust[acc].balance+=amount;
    cust[cust_no].balance-=amount;
    cust[cust_no].transfer+=amount;
    printf("Transferred Successfully . ");
    balancededuction();
    balanceEnquiry();
    }

   }

}

void changepassword(){

    printf("Enter New Password : ");
    scanf("%s",&cust[cust_no].new_password);
}

int main(void){

    data_entry();
    int id,ch1=0;
    char password[20];
    while(ch1==0){

    printf("Enter Id : ");
    scanf("%d",&id);
    printf("Enter Password : ");
    scanf("%s",&password);

    cust_no=logincheck(id,password);
     if(cust_no==-1)
        cust_no=newlogincheck(id,password);


    if(cust_no==-1)
        printf("\nYour Entered Wrong User id and password \n\n");
    else{
         if(cust[cust_no].new_id==0){
        printf("Enter New Id: ");
        scanf("%d",&cust[cust_no].new_id);
        printf("Enter New Password : ");
        scanf("%s",cust[cust_no].new_password);
        cust[cust_no].on=1;
         }

        int op,ch=0;
        while(ch==0){
        printf("\n\n1.BalanceEnquiry\t2.Ministatement\t3.Recharge\t4.Transfer\t5.Change Password\t6.LogOut\n\n");
        printf("Enter Your Option : ");
         scanf("%d",&op);
        switch(op){
        case 1: balanceEnquiry();
                break;
        case 2: ministatement();
                break;
        case 3:recharge();
                break;
        case 4: transfer();
               break;
        case 5: changepassword();
                break;
        case 6: printf("Logged Out Successfully .....\n\n");
                ch=1;
                break;
        default: printf("Entered Wrong Option ... \n\n");
        }
        }
    }
    printf("If You Want to Exit press 1 else press 0 \n \n ");
    scanf("%d",&ch1);

    }
return 0;
}
