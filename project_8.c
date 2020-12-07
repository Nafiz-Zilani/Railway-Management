#include<stdio.h>
#include<string.h>

char dhaka [5] = "Dhaka";
char chittagong [11] = "Chittagong";
char khulna [7] = "Khulna";
char sylhet [7] = "Sylhet";
char shonar_bangla [15] = "Shonar Bangla";
char mahanagar [18] = "Mahanagar Express";
char paharika [17] = "Paharika Express";
char chitra [16] = "Chitra Express";
char parabat [16] = "Parabat Express";
char sundarban [18] = "Sundarban Express";
char jayantika [18] = "Jayantika Express";
char first_class [11] = "First Class";
char secend_class [13] = "Secend Class";
int dhaka_2=1, chittagong_2=2, khulna_2=3, sylhe_2=4;
int from, to;
char error[5]="Error";


///--------------------------------------Structure Start------------------------------///
struct log_in{
    char user_name[30];
    int password;
}user_1;

struct create_account{
    char user_name_create[30];
    char father_name[30];
    char mother_name[30];
    char user_name_create_for_login[30];
    char password_create;
    char confirm_password;
    int nid_or_birth_certificate;
    int phone_number;
}create_user_1;

struct review{
    char review[200];
}review_1;

struct admin_log_in{
    char admin_user_name[10];
    int admin_password;
}admin_1;
///--------------------------------------Structure Finish------------------------------///

///------------------------------------Purches ticket Start----------------------------///
void purcher_ticket(){
    select_station();
    seat_class();
    back_in();
}
///------------------------------------Purches ticket Start----------------------------///

///--------------------------------------Admin Start------------------------------///
void admin(){
    printf("Name : ");
    gets(admin_1.admin_user_name);
    printf("\nPassword : ");
    scanf("%d",  &admin_1.admin_password);

    if(admin_1.admin_user_name == admin){
        if(admin_1.admin_password == 1234){

        }
    }
    else
    {
        printf("\n%s", error);
    }
}
///--------------------------------------Admin Finish------------------------------///
///--------------------------------------Select seat Start------------------------------///
void seat_class()
{
    system("cls");
    FILE* ticket;
    ticket = fopen("ticket.txt", "a");
    char no1;
    seat_class:
    system("cls");
    printf("Select Seat Class:");
    printf("\na. First Class.");
    printf("\nb. Secend Class.");
    printf("\nSelect NO :");
    scanf("%c", &no1);
    switch(no1)
    {
    case'a':
        printf("\n%s", first_class);
        fprintf(ticket,"%s\n", first_class);
        fclose(ticket);
        break;
    case'b':
        printf("\n%s", secend_class);
        fprintf(ticket,"%s\n", secend_class);
        fclose(ticket);
        break;
    default:
        printf("\nerroe");
        goto seat_class;
    }
}
///--------------------------------------Select seat Finish------------------------------///
///--------------------------------------Select station Start------------------------------///
void  select_station(){
    char no1, no2;
    system("cls");
    FILE* ticket;
    ticket = fopen("ticket.txt", "a");

    station_3:
    station_1:
    printf("Select station\nFrom :");
    printf("\na. Dhaka.");
    printf("\nb. Chittagong.");
    printf("\nc. Khulna");
    printf("\nd. Sylhet");
    printf("\nSelect NO :");
    scanf("%c", &no1);
    switch(no1)
    {
    case'a':
        printf("\n%s\n", dhaka);
        from = dhaka_2;
        break;
    case'b':
        printf("\n%s\n", chittagong);
        from = chittagong_2;
        break;
    case'c':
        printf("\n%s\n", khulna);
        from = khulna_2;
        break;
    case'd':
        printf("\n%s\n", sylhet);
        from = sylhe_2;
        break;
    default:
        printf("error\n");
        goto station_1;
    }

    fflush(stdin);

    station_2:
    printf("\nSelect station\nTo :");
    printf("\na. Dhaka.");
    printf("\nb. Chittagong.");
    printf("\nc. Khulna");
    printf("\nd. Sylhet");
    printf("\nSelect NO :");
    scanf("%c", &no2);
    switch(no2)
    {
    case'a':
        printf("\n%s\n", dhaka);
        to = dhaka_2;
        break;
    case'b':
        printf("\n%s\n", chittagong);
        to = chittagong_2;
        break;
    case'c':
        printf("\n%s\n", khulna);
        to = khulna_2;
        break;
    case'd':
        printf("\n%s\n", sylhet);
        to = sylhe_2;
        break;
    default:
        printf("\nerror\n");
        goto station_2;
    }

    if((from==1&&to==2) || (from==2&&to==1)){//Dhaka to Chittahong
        if(from==1&&to==2){
            printf("%s to %s\nTrain Name : %s", dhaka, chittagong,shonar_bangla);
            fprintf(ticket,"\n%s\t\t\t%s\t\t\t%s\t\t\t", dhaka, chittagong,shonar_bangla);
        }
        else{
            printf("%s to %s\nTrain Name : %s",chittagong, dhaka, mahanagar);
            fprintf(ticket,"\n%s\t\t\t%s\t\t\t%s\t\t\t", chittagong, dhaka, mahanagar);
        }
    }
    else if ((from==1&&to==3) || (from==3&&to==1)){//Dhaka to khulna
       if(from==1&&to==3){
            printf("%s to %s\nTrain Name : %s", dhaka, khulna, chitra);
            fprintf(ticket,"\n%s\t\t\t%s\t\t\t%s\t\t\t", dhaka, khulna, chitra);
        }
        else{
            printf("%s to %s\nTrain Name : %s", khulna, dhaka, sundarban);
            fprintf(ticket,"\n%s\t\t\t%s\t\t\t%s\t\t\t", khulna, dhaka, sundarban);
        }
    }
    else if ((from==1&&to==4) || (from==4&&to==1)){//Dhaka to sylhat
        if(from==1&&to==4){
            printf("%s to %s\nTrain Name : %s", dhaka, sylhet, parabat);
            fprintf(ticket,"\n%s\t\t\t%s\t\t\t%s\t\t\t", dhaka, sylhet, parabat);
        }
        else{
            printf("%s to %s\nTrain Name : %s", sylhet, dhaka, jayantika);
            fprintf(ticket,"\n%s\t\t\t%s\t\t\t%s\t\t\t", sylhet, dhaka, jayantika);
        }
    }
    else if ((from==2&&to==4) || (from==4&&to==2)){//Chittahong to sylhat
        if(from==2&&to==4){
            printf("%s to %s\nTrain Name : %s", chittagong, sylhet, paharika);
            fprintf(ticket,"\n%s\t\t\t%s\t\t\t%s\t\t\t", chittagong, sylhet, paharika);
        }
        else{
            printf("%s to %s\nTrain Name : %s", sylhet, chittagong, paharika);
            fprintf(ticket,"\n%s\t\t\t%s\t\t\t%s\t\t\t",sylhet, chittagong, paharika);
        }
    }
    else{
        goto station_3;
        printf("Error");
    }
    fclose(ticket);
}
///--------------------------------------Select station Finish------------------------------///

///------------------------------------Create account Start----------------------------///
void create_account(){

    FILE* create_account;
    create_account = fopen("account information.txt", "a");

    create_account:

    printf("Name : ");
    gets(create_user_1.user_name_create);
    fflush(stdin);
    printf("\nFather Name : ");
    gets(create_user_1.father_name);
    printf("\nMother Name : ");
    gets(create_user_1.mother_name);
    printf("\nNID/Birth certificate no. = ");
    scanf("%d", &create_user_1.nid_or_birth_certificate);
    printf("\nPhone Number = +880");
    scanf("%d", &create_user_1.phone_number);
    fflush(stdin);
    printf("\nUser Name = ");
    gets(create_user_1.user_name_create_for_login);
    printf("\nPassword = ");
    scanf("%s", &create_user_1.password_create);
    printf("\nConfirm Password = ");
    scanf("%s", &create_user_1.confirm_password);
    fflush(stdin);

    if(create_user_1.password_create == create_user_1.confirm_password){
        fprintf(create_account,"Name : %s\nFather's Name : %s\nMother's Name : %s\nNID/Birth certificate : %d\nPhone No. : %d\nPassword : %d\n", create_user_1.user_name_create, create_user_1.father_name, create_user_1.mother_name, create_user_1.nid_or_birth_certificate, create_user_1.phone_number, create_user_1.password_create);
        fclose(create_account);
        sine_in();
    }
    else{
        system("cls");
        printf("Incorrect Password.\n");
        goto create_account;
    } 
}
///------------------------------------Create account Finish----------------------------///

///-------------------------------------Sine In Start------------------------------///
void sine_in()
{
    system("cls");
    printf("Enter name : ");
    gets(user_1.user_name);
    fflush(stdin);
    printf("\nEnter password : ");
    scanf("%d",&user_1.password);  
    if(strcmp(user_1.user_name,create_user_1.user_name_create_for_login)==0 && strcmp(user_1.password,create_user_1.password_create)==0){
        printf("\nloged in");
    }
    else{
        printf("\nerror");
    }
}
///--------------------------------------Sine In Finish------------------------------///

///--------------------------------------Food Info Start------------------------------///
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
///--------------------------------------Food Info Finish------------------------------///

///----------------------------------------Track Start---------------------------------///
void sylhet_station(){///Sylhet station
    printf("Sylhet :\nSylhet Railway Station\n|\nKulaura Railway Station\n|\nSreemangal Railway station\n|\nShaistaganj Railway Station");
}

void dhaka_station(){///Dhaka station
    printf("Dhaka :\nKamalapur Railway Station\n|\nDhaka Airport Railway Station\n|\nNarayanganj Railway Station||Gazipur Railway Station\n|\nTangail Railway Station\n|\nGopalganj Railway Station\n|\nBhairab Bazar Railway Station\n|\nFaridpur Railway Station\n|\nNarsingdi Railway Station\n|\nTongi Railway Station\n|\nTejgaon Railway Station\n|\nJoydebpur Railway Station\n|\nB.B. East Railway Station\n|\nKishoreganj Railway Station\n|\nRajbari Railway Station");
}

void chittagong_station(){///Chittagong station
    printf("Chittagong :\nChittagong Railway Station\n|\nAkhaura Railway Station\n|\nAshuganj Railway Station\n|\nChandpur Railway Station\n|\nComilla Railway Station\n|\nFeni Railway Station\n|\nNabinagar Railway Station\n|\nBrahmanbaria Railway Station\n|\nChittagong Railway Station\n|\nLaksam Railway Station");
}

void khulna_station(){///khulna station
    printf("Khulna :\nKhulna Railway Station\n|\nJessore Railway Station\n|\nPhultala Railway Station\n|\nDarshana Railway Station\n|\nMirpur Railway Station\n|\nKustia Railway Station\n|\nChuadanga Railway Station\n|\nDaulatpur Railway Station\n|\nNoapara Railway Station\n|\nPoradha Railway Station\n|\nBheramara Railway Station\n|\nPakshi Railway Station");
}

void rajshi_station(){///Rajshi station
    printf("Rajshi :Akkelpur Railway Station\n|\nJoypurhat Railway Station\n|\nSonatola Railway Station\n|\nNatore Railway Station\n|\nPabna Railway Station\n|\nUllapara Railway Station\n|\nSantahar Railway Station\n|\nPanchbibi Railway Station\n|\nBogra Railway Station\n|\nRaninagar Railway Station\n|\nSingra Railway Station\n|\nFaridpur Railway Station\n|\nSirajganj Railway Station\n|\nRajshahi Railway Station\n|\nAhsanganj Railway Station\n|\nAmnura Railway Station");
}
void track(){//Compleat
    system("cls");
    dhaka_station();
    printf("\n-------------------\n");
    chittagong_station();
    printf("\n-------------------\n");
    khulna_station();
    printf("\n-------------------\n");
    sylhet_station();
    printf("\n-------------------\n");
    rajshi_station();
}

///----------------------------------------Track Finish---------------------------------///

///----------------------------------------Contect Start--------------------------------///
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
///----------------------------------------Contect Finish--------------------------------///

///--------------------------------------Review Start------------------------------///
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
///--------------------------------------Review Finish------------------------------///

void back_in(){
    char select_option,log;
    
    printf("Function\n");
    printf("a. Purcher Ticket\n");
    printf("b. Food Info\n");
    printf("c. Track\n");
    printf("d. Contect\n");
    printf("e. Review\n");
    printf("f. Admin log in\n");

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
    case'c':
        track();
        break;
    case'd':
        contect();
        break;
    case'e':
        review();
        break;
    case'f':
        admin();
        break;
    default:
        printf("\n%s", error);
    }
}

int main()
{
    back_in();
    return 0;
}