#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct by_ticket{
     char station_1[30], station_2[30], train_name[30],seat_class[30],time[30];
     struct by_ticket *next;
};
struct log_in{
    char user_name[30],password[30];
    struct log_in *next;
};

struct create_account{
    char user_name_create[30];
    char father_name[30];
    char mother_name[30];
    char user_name_create_for_login[30];
    char password_create[30];
    char confirm_password[30];
    int nid_or_birth_certificate;
    int phone_number;
}create_user_1;

struct review{
    char review[200];
}review_1;
void admin(){
    char station_1[30], station_2[30], train_name[30], error[7] = "error",seat_class[30],time[30];
    int admin_password,admin_name;

    FILE* station_i;
    station_i = fopen("station 1.txt", "a");
    FILE* station_ii;
    station_ii = fopen("station 2.txt", "a");
    FILE* trainname;
    trainname = fopen("train name.txt", "a");
    FILE* seat_class_f;
    seat_class_f = fopen("select seat.txt", "a");
    FILE* time_f;
    time_f = fopen("time.txt", "r");

    printf("Name : ");
    scanf("%d",  &admin_name);
    printf("\nPassword : ");
    scanf("%d",  &admin_password);

    if(admin_name == 1234){
        if(admin_password == 1234){
            fflush(stdin);
            printf("\nStation 1 (Please type in small letter): ");
            gets(station_1);
            fflush(stdin);
            printf("\nStation 2 (Please type in small letter): ");
            gets(station_2);
            printf("\nTrain: ");
            gets(train_name);
            printf("\nSelect seat : ");
            scanf("%s", seat_class);
            printf("\nTime : ");
            scanf("%s", time);
            fflush(stdin);
            fprintf(station_i,"%s*",station_1);
            fclose(station_i);
            fprintf(station_ii,"%s*",station_2);
            fclose(station_ii);
            fprintf(trainname,"%s*",train_name);
            fclose(trainname);
            fprintf(seat_class_f,"%s*",seat_class);
            fclose(seat_class_f);
            fprintf(time_f,"%s*",time);
            fclose(time_f);
        }
    }
    else
    {
        printf("\n%s", error);
    }
}
void by_ticket(){
    struct by_ticket *head=NULL,*temp=NULL,*st;
    char by_station_1[30000], all_station_1[10000][30],by_station_2[30000], all_station_2[10000][30],by_train_name[30000],all_train_name[10000][30],by_seat_class[30000],all_seat_class[10000][30],by_time[30000],all_time[10000][30];
    FILE* station_i;
    station_i = fopen("station 1.txt", "r");
    FILE* station_ii;
    station_ii = fopen("station 2.txt", "r");
    FILE* trainname;
    trainname = fopen("train name.txt", "r");
    FILE* seat_class_f;
    seat_class_f = fopen("select seat.txt", "r");
    FILE* time_f;
    time_f = fopen("time.txt", "r");
    fscanf(station_i,"%s",by_station_1);
    fclose(station_i);
    fscanf(station_ii,"%s",by_station_2);
    fclose(station_ii);
    fscanf(trainname,"%s", by_train_name);
    fclose(trainname);
    fscanf(seat_class_f,"%s", by_seat_class);
    fclose(seat_class_f);
    fscanf(time_f,"%s", by_time);
    fclose(time_f);
    int i=0,k=0,l=0;
  while(by_station_1[i]!=NULL){
     if(by_station_1[i]=='*'){
            k++;
            l=0;
        }
        else{
            all_station_1[k][l]=by_station_1[i];
             l++;
        }
        i++;
  }
   for(i=0;i<k;i++){
         st=(struct by_ticket*)malloc(sizeof(struct by_ticket));
          st->next=NULL;
        strcpy(st->station_1,all_station_1[i]);
        if(head == NULL){
            head=st;
            temp=head;
        }
        else{
            temp->next=st;
            temp=temp->next;
        }
    }
    temp=head;
    i=0,k=0,l=0;
    while(by_station_2[i]!=NULL){
     if(by_station_2[i]=='*'){
            k++;
            l=0;
        }
        else{
            all_station_2[k][l]=by_station_2[i];
             l++;
        }
        i++;
  }
  for(i=0;i<k;i++){
     strcpy(temp->station_2,all_station_2[i]);
        temp=temp->next;

}
temp=head;
    i=0,k=0,l=0;
    while(by_train_name[i]!=NULL){
     if(by_train_name[i]=='*'){
            k++;
            l=0;
        }
        else{
            all_train_name[k][l]=by_train_name[i];
             l++;
        }
        i++;
  }
  for(i=0;i<k;i++){
     strcpy(temp->train_name,all_train_name[i]);
        temp=temp->next;

}
temp=head;
    i=0,k=0,l=0;
    while(by_seat_class[i]!=NULL){
     if(by_seat_class[i]=='*'){
            k++;
            l=0;
        }
        else{
            all_seat_class[k][l]=by_seat_class[i];
             l++;
        }
        i++;
  }
  fflush(stdin);
  for(i=0;i<k;i++){
     strcpy(temp->seat_class,all_seat_class[i]);
        temp=temp->next;
        }
        temp=head;
    i=0,k=0,l=0;
    while(by_time[i]!=NULL){
     if(by_time[i]=='*'){
            k++;
            l=0;
        }
        else{
            all_time[k][l]=by_time[i];
             l++;
        }
        i++;
  }
  for(i=0;i<k;i++){
     strcpy(temp->time,all_time[i]);
        temp=temp->next;
        }
 char ary1[30],ary2[30];
 system("cls");
 printf("Form: ");
 scanf("%s",ary1);
 printf("To: ");
 scanf("%s",ary2);
 temp=head;
 while(temp!=NULL){
    if(strcmp(ary1 ,temp->station_1)==0 && strcmp(ary2 ,temp->station_2)==0){
        printf("****Train : %s****\nSeat price :%s \nTime : %s\n\n");
    }
    temp=temp->next;
 }

}

void log_in(){
     struct log_in *log_head=NULL,*log_temp=NULL,*log_st;
    FILE* log_username;
    log_username = fopen("account information username.txt", "r");
    FILE* log_password;
    log_password = fopen("account information password.txt", "r");
    char file_username[10000],all_username[5000][30],file_password[10000],all_password[5000][30];
    fscanf(log_username,"%s",file_username);
    fclose(log_username);
    fscanf(log_password,"%s",file_password);
    fclose(log_password);
   // printf("%s\n%s",file_username,file_password);
    int i=0,name_k=0,name_l=0,pass_k=0,pass_l=0;
     while(file_username[i]!=NULL){
        if(file_username[i]=='*'){
            name_k++;
            name_l=0;
        }
        else{
            all_username[name_k][name_l]=file_username[i];
            name_l++;
        }
        i++;
    }

    for(i=0;i<name_k;i++){
         log_st=(struct log_in*)malloc(sizeof(struct log_in));
        log_st->next=NULL;
        strcpy(log_st->user_name,all_username[i]);
        if(log_head == NULL){
            log_head=log_st;
            log_temp=log_head;
        }
        else{
            log_temp->next=log_st;
            log_temp=log_temp->next;
        }
    }

log_temp=log_head;
i=0;

 while(file_password[i]!=NULL){
         if(file_password[i]=='*'){
            pass_k++;
            pass_l=0;
        }
        else{
            all_password[pass_k][pass_l]=file_password[i];
            pass_l++;
        }
        i++;

 }
system("cls");
for(i=0;i<name_k;i++){
     strcpy(log_temp->password,all_password[i]);
        log_temp=log_temp->next;

}
fflush(stdin);
char ary_name[30],ary_pass[30];
printf("Enter name : ");
    scanf("%s",ary_name);
    printf("\nEnter password : ");
    scanf("%s",ary_pass);
    fflush(stdin);
    int r=0;
 for(i=1;i<=name_k;i++){
        if(strcmp(ary_name ,log_head->user_name)==0 && strcmp(ary_pass ,log_head->password)==0){
                r=1;
          break;
        }
        log_head=log_head->next;
    }
    if(r==1){
            by_ticket();

    }
    else{
        printf("User Name or Password incorrect.\nPlease try again.\n");
        log_in();
    }



}
///--------------------------------------Log In Finish------------------------------///

///------------------------------------Create account Start----------------------------///
void create_account(){

    FILE* create_account;
    create_account = fopen("account information.txt", "a");
    FILE* log_username;
    log_username = fopen("account information username.txt", "a");
    FILE* log_password;
    log_password = fopen("account information password.txt", "a");

    create_account:

        printf("Name : ");
        gets(create_user_1.user_name_create);
        printf("\nFather Name : ");
        gets(create_user_1.father_name);
        printf("\nMother Name : ");
        gets(create_user_1.mother_name);
        printf("\nNID/Birth certificate no. = ");
        scanf("%d", &create_user_1.nid_or_birth_certificate);
        printf("\nPhone Number = +880");
        scanf("%d", &create_user_1.phone_number);
        fflush(stdin);
        printf("User Name = ");
        gets(create_user_1.user_name_create_for_login);
        printf("\nPassword = ");
        scanf("%s", create_user_1.password_create);
        printf("\nConfirm Password = ");
        scanf("%s", create_user_1.confirm_password);
        fflush(stdin);
        if(strcmp(create_user_1.password_create ,create_user_1.confirm_password)==0){
            fprintf(create_account,"Name : %s\nFather's Name : %s\nMother's Name : %s\nNID/Birth certificate : %d\nPhone No. : %d\n", create_user_1.user_name_create, create_user_1.father_name, create_user_1.mother_name, create_user_1.nid_or_birth_certificate, create_user_1.phone_number);
            fclose(create_account);
            fprintf(log_username,"%s*", create_user_1.user_name_create_for_login);
            fclose(log_username);
            fprintf(log_password,"%s*", create_user_1.password_create);
            fclose(log_password);
        }
        else{
            system("cls");
            printf("Incorrect Password.\n");

            goto create_account;
        }
}
void purcher_ticket(){
    char log;
        fflush(stdin);
        printf("\na. Login");
        printf("\nb. Create account");
        printf("\nEnter charecter : ");
        scanf("%c", &log);
        switch(log)
        {
            case'a':
                log_in();
                break;
            case'b':
                create_account();
                break;
            default:

                break;
        }
}
void food_info(){///which train sarve which food
    int dastination_chack;
    system("cls");
    food_info:
    printf("\nWhich dastination you want to chack : ");
    printf("\n1. Dhaka To Chittagong.");
    printf("\n2. Dhaka To Sylhet.");
    printf("\n3. Dhaka To Rajshi.");
    printf("\n4. Dhaka To Khulna.");
    printf("\nPress 1-4 to select : ");
    scanf("%d", &dastination_chack);


    if(dastination_chack == 1){
        system("cls");
        printf("Box (1 fruit, 2 chicken Fry, 1 150ml water , sauce) (Included on Suborna Train only with ticket)\nBurger 60/=\nCutlet 60/=\nWater 15/=\nTea 10/=\nCoffee 20/=");
    }
    else if(dastination_chack == 2){
        system("cls");
        printf("Beriny 120/=\nCutlet\nWater 15/=\nTea 10/=\nCoffee 20/=");
    }
    else if(dastination_chack == 3){
        system("cls");
        printf("Beriny 120/=\nCutlet\nWater 15/=\nTea 10/=\nCoffee 20/=");
    }
    else if(dastination_chack ==4){
        system("cls");
        printf("Beriny 120/=\nCutlet\nWater 15/=\nTea 10/=\nCoffee 20/=");
    }
    else
    {
        system("cls");
        printf("Didn't enter currect switch");
        goto food_info;
    }

}
void contect(){//Compleat
  system("cls");
  printf("Website                       =     https://railway.portal.gov.bd\n\n");
  printf("Main offce                    =     Bangladesh Railway Bhaban, 16 Abdul Gani Rd, Dhaka 1000\n\n");
  printf("Dhaka Station                 =     9358634\n");
  printf("Dhaka Cantonment Station      =     9112007\n");
  printf("Dhaka Airport Station         =     8924239\n");
  printf("Chittagong Station            =     635162\n");
  printf("Sylhet Station                =     716061\n");
  printf("Khukna Station                =     760691\n");
  printf("Rajshi Station                =     774122\n");
}
void review(){
    system("cls");
    FILE * review;
    review = fopen("review.txt", "a");

    if(review == NULL){
        printf("File does't exist");
    }
    else{
        fflush(stdin);
        printf("Give your feedback (Max 200 latter) : ");
        gets(review_1.review);
        fprintf(review,"Review : \n%s\n", review_1.review);
        fclose(review);
    }

}
int main()
{
    char select_option,log;

    printf("Function\n");
    printf("a. Purcher Ticket\n");
    printf("b. Food Info\n");
    printf("c. Coach View\n");
    printf("d. Track\n");
    printf("e. Contect\n");
    printf("f. Review\n");
    printf("g. Admin log in\n");

    printf("Enter charecter : ");
    scanf("%c", &select_option);
    system("cls");

    switch(select_option)
    {
    case'a':
        purcher_ticket();
        break;
     case'b':
        food_info();
        break;
    case'e':
        contect();
        break;
    case'f':
        review();
        break;
    case'g':
        admin();
        break;


    }

    return 0;
}
