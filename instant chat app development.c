#include<stdio.h>
#include<string.h>
int n,c,mes_count=0,g=-1;

struct user
{
    int contacts[50];
    int cont_i;
    int groups[50];
    int group_i;
    int messages[100];
    int mes_i;
    int group_status[50];
    int gs_i;
    int starg[50];

    int gmute_status[50];
    int gmute_i;
    int sent_receive[100];
    int sr;
    int cont_star[50];
    int cont_del[50];
    int cont_mute[50];
    int cont_block[50];
    int read[50];
    int starred[50];


}user[6];
struct messages
{
    char messages[200];
    int readr;
    int reads;
    int delr;
    int stars;
    int group_no;

}mes[100];
struct group
{
    char name[10];
    int contacts[100];
    int cont_i;
    int cont_status[100];
    int admin;
    int messages[100];
    int mes_i;


}group[10];
void notifications(){

            int i,c=0;
            for(i=0;i<user[n].mes_i;i++){
                if(user[n].read[i]==1)
                    c++;
            }
            printf("You have %d unread messages \n\n ",c);
}
int checkcontact(int cn){
   int i;
   for(i=0;i<user[n].cont_i;i++){
    if(user[n].contacts[i]==cn){
            c=i;
        return 1;
    }
   }
   return 0;
}
void addcontact(){
    int cn;
     printf("Enter Contact Number to Add : ");
     scanf("%d",&cn);
     user[n].contacts[user[n].cont_i]=cn;
     user[n].cont_i++;

}
void viewcontact(){

   printf("Your Contact List is : ");
   int i;
   for(i=0;i<user[n].cont_i;i++){

    printf("%d ",user[n].contacts[i]);
   }
 printf("\nBlocked Contacts are : ");

    for(i=0;i<user[n].cont_i;i++){
        if(user[n].cont_block[i]==1)
            printf("%d ",user[n].contacts[i]);
    }
    printf("\n");

    printf("starred Contacts are : ");

    for(i=0;i<user[n].cont_i;i++){
        if(user[n].cont_star[i]==1)
            printf("%d ",user[n].contacts[i]);
    }
    printf("\n");
             printf("deleted Contacts are : ");

    for(i=0;i<user[n].cont_i;i++){
        if(user[n].cont_del[i]==1)
            printf("%d ",user[n].contacts[i]);
    }
    printf("\n");
      printf("muted Contacts are : ");

    for(i=0;i<user[n].cont_i;i++){
           // printf("%d ",user[n].cont_mute[i]);
        if(user[n].cont_mute[i]==1)
            printf("%d ",user[n].contacts[i]);
    }
    printf("\n");
   printf("\n\n");
}
void starcontact(){
    int cn;
    printf("Enter Contact number to be make it star : ");
    scanf("%d",&cn);

    if(checkcontact(cn)==0)
        printf("Contact Not found \n");
    else{
        user[n].cont_star[c]=1;


    }

}

void deletecontact(){
    int cn;
    printf("Enter Contact to delete : ");
    scanf("%d",&cn);
    if(checkcontact(cn)==0)
        printf("Contact not found\n");
    else{
        user[n].cont_del[c]=1;


    }
}

void mutecontact(){
     printf("1.Mute \n 2.Unmute \n");
     int op,cn;
     scanf("%d",&op);
     if(op==1){

     printf("Enter Contact to mute : ");
    scanf("%d",&cn);
    //printf("%d\n",cn);
    if(checkcontact(cn)==0)
        printf("Contact not found\n");
    else{
        printf("%d\n",cn);
        user[n].cont_mute[c]=1;
    }

     }
     else{
            printf("Enter Contact to Unmute : ");
    scanf("%d",&cn);
    if(checkcontact(cn)==0)
        printf("Contact not found\n");
    else{
        user[n].cont_mute[c]==0;
    }

     }
}
void blockcontact(){
    printf("1.Block \n 2.Unblock \n");
    int op,cn;
    scanf("%d",&op);
    if(op==1){

     printf("Enter Contact to block : ");
     scanf("%d",&cn);
    if(checkcontact(cn)==0)
        printf("Contact not found\n");
    else{
        user[n].cont_block[c]=1;

    }
    }
    else{
          printf("Enter Contact to Unblock : ");
    scanf("%d",&cn);
    if(checkcontact(cn)==0)
        printf("Contact not found\n");
    else{
        user[n].cont_block[cn]==0;
    }
    }
}
void contactmanagement(){
           int ch=0,op;
           while(ch==0){
           printf("\n1.Add Contact \n 2.Vew Contact \n 3.Star/Unstar Contact \n 4.Delete Contact \n 5.Mute/Unmute Contact \n 6.Block/Unblock Contact \n 7.Back to main menu \n\n");
           scanf("%d",&op);
           switch(op){
           case 1 : addcontact();
                    break;
            case 2: viewcontact();
                    break;
            case 3: starcontact();
                     break;
           case 4: deletecontact();
                 break;
          case 5: mutecontact();
                break;
           case 6: blockcontact();
               break;
            case 7 : ch=1;
                break;
           }
           }
}

void addgroup(){
    printf("Enter the group number you want to add : ");
    int gn;
    scanf("%d",&gn);

    user[n].groups[user[n].group_i++]=gn;


}

void viewgroup(){
    printf("Your Groups are : ");
    int i;
    for(i=0;i<user[n].group_i;i++){
            if(user[n].group_status[i]==0)
        printf("%d ",user[n].groups[i]);
    }
    printf("Enter group number to view : ");
    int m;
    scanf("%d",&m);
    for(i=0;i<group[m].cont_i;i++){

        if(group[m].cont_status[i]==0){
                if(group[m].admin==n)
            printf("[ %d ] ",group[m].contacts[i]);
        else
        printf("[ %d ] ",group[m].contacts[i]);

        }
    }
    printf("\n");
}

void stargroup(){
    viewgroup();
    printf("Enter the group you want to star : ");
    int n1;
    scanf("%d",&n1);
    user[n].starg[n1]=1;
}

void deletegroup(){
    printf("Enter the group you want to delete : ");
    int n1;
    scanf("%d",&n1);
    user[n].group_status[n1]=1;
}

void mutegroup(){
    printf("Enter the group you want to mute : ");
    int n1;
    scanf("%d",&n1);
    user[n].gmute_status[n1]=1;
}
void addmember(){
    printf("Enter group number to add : ");
    int gn;
    scanf("%d",&gn);
    if(n!=group[gn].admin && group[gn].admin!=0)
        printf("Your not eligible to add members\n");
    else{
        printf("Enter number to add : ");
        int m;
        scanf("%d",&m);
        group[gn].contacts[group[gn].cont_i++]=m;
        user[m].groups[user[m].group_i++]=gn;

    }

}

void removemember(){
    printf("Enter group number to remove : ");
    int gn;
    scanf("%d",&gn);
    if(n!=group[gn].admin)
        printf("Your not eligible to remove members\n");
    else{
        printf("Enter number to remove : ");
        int m,k;
        scanf("%d",&m);
        int i;
         for(i=0;i<group[gn].cont_i;i++){
            if(group[gn].contacts[i]==m){
                k=i;
                break;
            }
         }
         group[gn].cont_status[k]=1;


    }
}

void addadmin(){
    int gn;
    printf("Enter group no : ");
    scanf("%d",&gn);
    printf("Enter Admin no : ");
    int ad;
    scanf("%d",&ad);
    group[gn].admin=ad;


}
void removeadmin(){
    printf("Enter the group number : ");
    int gn;
    scanf("%d",&gn);

    printf("Successfully removed the admin \n");
    group[gn].admin=0;

}
void exitgroup(){
    printf("Enter the group you want to exit : ");
    int gn;
    scanf("%d",&gn);

    int i,cn=-1;
    for(i=0;i<group[gn].cont_i;i++){
        if(group[gn].contacts[i]==n)
        {
            cn=i;
            break;

        }
    }
    if(cn==-1)
        printf("Your not prasent in this group\n");
    else{
        group[gn].cont_status[cn]=1;
        printf("Successfully came out from group\n");
    }
}
void groupmanagement(){
        int op,ch=0;
         while(ch==0){
        printf("\n1.Add Group \n 2.View Group \n 3.Star/Unstar Group \n 4.Delete Group \n 5.Mute/Unmute Group \n 6.Add Member \n 7.Remove Member \n 8.Add Admin \n 9.Remove Admin \n 10 .Exit Group \n 11 . Back to main menu \n\n");
         printf("Enter Your Option : ");
         scanf("%d",&op);
         switch(op){
             case 1: addgroup();   break;
            case 2 : viewgroup();    break;
            case 3: stargroup(); break;
            case 4: deletegroup(); break;
            case 5: mutegroup(); break;
            case 6: addmember(); break;
            case 7: removemember(); break;
            case 8: addadmin(); break;
            case 9: removeadmin(); break;
            case 10 : exitgroup(); break;
            case 11: ch=1;
                    break;

         }
         }

}
void directmes(){
      int cn;
      char s[100];
      printf("\nEnter Number to Send Message : ");
      scanf("%d",&cn);
      if(cn<=0 && cn>5)
        printf("Contact not found \n");
      else{
        printf("Enter Message : \n");
        scanf("%s",s);

       strcpy(mes[mes_count].messages,s);
       user[cn].messages[user[cn].mes_i]=mes_count;
       user[cn].sent_receive[user[cn].mes_i]=1;
       user[n].messages[user[n].mes_i]=mes_count;
       user[cn].read[user[cn].mes_i]=1;
       mes_count++;
       user[cn].mes_i++;
       user[n].mes_i++;
      }
      //printf("messages sent from %d to %d  is %s\n",n,cn,mes[mes_count-1].messages);
    int i=0;
    for(i=0;i<mes_count;i++)
        printf("%s ",mes[i].messages);
}

void broadcastmes(){
    int i;
    char s[100];
    printf("\n  Enter Messages  : ");
    scanf("%s",s);
    strcpy(mes[mes_count].messages,s);
      user[n].messages[user[n].mes_i]=mes_count;
      user[n].mes_i++;
    for(i=0;i<user[n].cont_i;i++){
            if(i!=n){
        if(user[n].cont_del[i]==0 && user[n].cont_block[i]==0 ){
                int b=user[n].contacts[i];
            user[b].messages[user[b].mes_i]=mes_count;
            user[b].sent_receive[user[b].mes_i]=1;

            user[b].read[user[b].mes_i]=1;
             user[b].mes_i++;
        }
    }
    }
    printf("Successfully sent the message to your contacts \n");

        mes_count++;
}
void sendmessage(){
       printf("\n1.Direct Message \n2.Broadcast Messages\n");
       int op;
       printf("Enter Your Option : ");
       scanf("%d",&op);
       switch(op){
       case 1: directmes();break;
       case 2: broadcastmes(); break;
       }
}
void sentmessages(){
    printf("Your Sent Messages are : \n\n");
    int i;
    printf(" user : %d\n",n);

    for(i=0;i<user[n].mes_i;i++){

        int k=user[n].sent_receive[i];

        if(k!=1){
            int p=user[n].messages[i];

            printf("%s \n",mes[p].messages);
        }
    }
    printf("\n");
}

void starredmessages(){
    char s[100];
    printf("Enter the message you want to star : ");
    scanf("%s",s);
    int i;
    for(i=0;i<user[n].mes_i;i++){
            int k=user[n].messages[i];
   // printf("%s\n ",mes[k].messages);
        if(strcmp(mes[k].messages,s)==0)
        {
            user[n].starred[i]=1;
            break;
        }
    }


      printf("Your Starred messages are : \n");
      for(i=0;i<user[n].mes_i;i++){
        if(user[n].starred[i]==1){
                int k=user[n].messages[i];
            printf("%s\n",mes[k].messages);
        }
      }


}

void received(){
    printf("1.Unread \n 2.Read \n");
    printf("Enter your option : ");
    int op;
    scanf("%d",&op);
    if(op==1){
         printf("1.groups \n 2.contacts \n");
         int p;
         printf("Enter option : ");
         scanf("%d",&p);
         if(p==1){

         }
         else if(p==2){
             int i;
             for(i=0;i<user[n].mes_i;i++){
                    if(user[n].read[i]==1){
               int k=user[n].sent_receive[i];

        if(k!=0){
            int p=user[n].messages[i];

                    user[n].read[i]=0;
            printf("%s \n",mes[p].messages);
            }
        }
             }
         }
    }
    else if(op==2){
        printf("1.groups \n 2.Contact \n");
        printf("Enter Your Option : ");
        int p;
        scanf("%d",&p);
        if(p==1){

        }
        else if(p==2){
             int i;
             for(i=0;i<user[n].mes_i;i++){
               int k=user[n].sent_receive[i];

        if(k!=0){
            int p=user[n].messages[i];
            if(user[n].read[i]==0){

            printf("%s \n",mes[p].messages);
            }
        }
        }
    }
}
}
void messages(){
    int ch=0;
    while(ch==0){
      printf("1.Send Message \n 2. Sent Messages \n3.Starred Messages \n 4. Received \n 5.exit\n");
      int op;
      printf("Enter your Option : ");
      scanf("%d",&op);
      switch(op){
      case 1: sendmessage();break;
      case 2: sentmessages(); break;
      case 3: starredmessages(); break;
      case 4: received(); break;
      case 5: ch=1;break;
      }
    }
}

int main(){
    int ch=0;
  while(ch==0){
     printf("Enter Your Number : ");
     scanf("%d",&n);
     if(n<1 && n>5){
        printf("Entered Wrong Number ! \n");
        ch==1;
     }
     else{
            int p=0;
     while(p==0){
            int op;
        printf("\n1.Notifications\n2.Contact Management\n3.Group Management \n 4.Messages \n5.Logout\n\n");
        printf("Enter Your Option : ");
        scanf("%d",&op);
     switch(op){
     case 1: notifications();
             break;
      case 2: contactmanagement();
              break;
    case 3: groupmanagement();
               break;
    case 4: messages();
         break;
    case 5: p=1;
        printf("Logged Out\n\n");
        break;
     }
     }

     }
  }



return 0;
}
