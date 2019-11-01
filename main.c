#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct nidinfo
{
    char name[50] , fathersName[50] , cityname[20] , mothersName[50] , userName[20] , password[20]  ;
    int idn , age;


} nidarray[100];

void clrscr();

void userLogin();

void regLogin();

void createRegister();

void registration();

void apply();

void afterRegLogin();

void showUserinfo(char usrName[50]);

void search_area();

void search_name();

void search_father();

void search_id();

void searchOption();

void afterUserLogin(char USERNAME[30]);

void editInfo();

void deleteUser();

void userMessages();



int num = 0;


int main()
{
    int x;


    do
    {
        system("cls");
        printf("*****************************************************************************************************\n");
        printf("%25cWelcome To National ID System BD\n",' ');

        printf("\n_____________________________________________________________________________________________________\n");
        printf("\n%25cPress <1> to apply for a NID \n",' ');
        printf("\n%25cPress <2> to Login as a Register officer\n",' ');
        printf("\n%25cPress <3> to Login as a NID User\n",' ');
        printf("\n%25cPress <4> to Send a message to the NID Officer\n",' ');
        printf("\n______________________________________________________________________________________________________\n");
Food:
        scanf("%d",&x);

        switch(x)
        {
        case 1:
            apply();
            break;
        case 2:
            regLogin();
            break;
        case 3:
            userLogin();
            break;
        case 4:
            userMessages();
            break;
        default:
            printf("%20cYou have pressed the WRONG key! Try again.\n",' ');
            goto Food;

        }
    }
    while(x!=0 && x<=4);



    return 0;
}



void registration()
{

    FILE *file;
    file = fopen ("registration.dat","a");
    if (file == NULL)
    {
        fprintf(stderr, "\nError opening accounts.dat\n\n");
        exit (1);
    }


    int i;

    for(i=0;  ; i++)
    {
        printf("\n%10cPlease Enter the information carefully to Register a new NID");
        printf("\n\n");
        puts("Enter Name : ");
        gets(nidarray[i].name);
        fflush(stdin);
        if(strcmp(nidarray[i].name,"")==0) break;
        puts("Enter Fathers name : ");
        gets(nidarray[i].fathersName);
        fflush(stdin);
        puts("Enter Mothers name : ");
        gets(nidarray[i].mothersName);
        fflush(stdin);
        puts("Enter Age : ");
        scanf("%d",&nidarray[i].age);
        getchar();
        puts("Enter Cityname : ");
        gets(nidarray[i].cityname);
        fflush(stdin);
        puts("Enter UserName : ");
        gets(nidarray[i].userName);
        fflush(stdin);
        puts("Enter Password : ");
        gets(nidarray[i].password);
        fflush(stdin);
        nidarray[i].idn = i+100;
        printf("\n");

    }

    num = i;
    fwrite(nidarray, sizeof(struct nidinfo), i, file);
    fclose(file);


}

void userLogin()
{
    int i=0;


    char UserName[20];
    char Password[20] , c=' ';

    getchar();
    printf("Enter Username : ");
    gets(UserName);
    fflush(stdin);
    printf("Enter Password [Not more than 9 Character]: ");
    while (i<=9)
    {
        Password[i]=getch();
        c=Password[i];
        if(c==13) break;
        else printf("*");
        i++;
    }
    Password[i]='\0';
    i=0;
    fflush(stdin);


    clrscr();

    printf("\n");

    FILE *file;
    file = fopen ("registration.dat","r");
    num = fread(nidarray, sizeof(struct nidinfo), 100, file);
    fclose(file);





    for (i=0; i<num; i++)
    {
        if (strcmp(UserName, nidarray[i].userName) == 0 && strcmp(Password , nidarray[i].password) == 0)
        {

            printf("\n%25c you have logged in Sucesfully as a NID User!\n");
            fflush(stdin);
            afterUserLogin(UserName);
            getchar();



            break;


        }


    }



}


void regLogin()
{
    int i=0;


    char UserName[20];
    char Password[20] , c=' ';

    getchar();
    printf("Enter Username : ");
    gets(UserName);
    fflush(stdin);
    printf("Enter Password [Not more than 9 Character]: ");
    while (i<=9)
    {
        Password[i]=getch();
        c=Password[i];
        if(c==13) break;
        else printf("*");
        i++;
    }
    Password[i]='\0';
    i=0;
    fflush(stdin);


    clrscr();

    printf("\n");

    FILE *file;
    file = fopen ("officeid.dat","r");
    num = fread(nidarray, sizeof(struct nidinfo), 100, file);





    for (i=0; i<num; i++)
    {
        if (strcmp(UserName, nidarray[i].userName) == 0 && strcmp(Password , nidarray[i].password) == 0)
        {

            printf("\n%25c you have logged in Sucesfully as a Register!\n");
            afterRegLogin();
            break;


        }


    }



}


void apply()
{

    char name[50], fathersName[50], mothersName[50], occupation[50] , cityName[50] , email[50] , marrStatus[50] , phone[50] , enter[1];
    int age ;

    FILE *ifile;
    ifile = fopen ("application.txt","a");
    if (ifile == NULL)
    {
        fprintf(stderr, "\nError opening file\n\n");
        exit (1);
    }

    getchar();
    printf("Please fillup this application form carefully \n");
    fflush(stdin);
    printf("\n%25c1.Please enter your Name: ",' ');
    gets(name);
    fflush(stdin);
    fprintf(ifile,"Applicant's name: %s\n",name);
    printf("\n%25c2.Please enter your Fathers Name: ",' ');
    gets(fathersName);
    fflush(stdin);
    fprintf(ifile,"Applicant's Fathersname: %s\n",fathersName);
    printf("\n%25c3.Please enter your Mothers Name: ",' ');
    gets(mothersName);
    fflush(stdin);
    fprintf(ifile,"Applicant's Mothersname: %s\n",mothersName);
    printf("\n%25c4.Please enter your Occupation: ",' ');
    gets(occupation);
    fflush(stdin);
    fprintf(ifile,"Applicant's Occupation: %s\n",occupation);

    printf("\n%25c5.Enter your age: ",' ');
    scanf("%d",&age);
    getchar();
    fprintf(ifile,"Applicant's Age: %d\n",age);

    printf("\n%25c6.Please enter your City Name: ",' ');
    gets(name);
    fflush(stdin);
    fprintf(ifile,"Applicant's Cityname: %s\n",cityName);

    printf("\n%25c7.Please enter your Marritual Status: ",' ');
    gets(marrStatus);
    fflush(stdin);
    fprintf(ifile,"Applicant's MarritualStatus: %s\n",marrStatus);

    printf("\n%25c8.Please enter your Email address: ",' ');
    gets(email);
    fflush(stdin);
    fprintf(ifile,"Applicant's Email: %s\n",email);

    printf("\n%25c9.Please enter your Phone Number: ",' ');
    gets(phone);
    fflush(stdin);
    fprintf(ifile,"Applicant's Phone No: %s\n\n",phone);



    fclose(ifile);

    printf("\n%25cYour Information's are Successfully Submitted ! Please wait for the verification \n%Press ENTER to Continue\n");
    gets(enter);
    fflush(stdin);



}

void createRegister()
{
    FILE *ofile;
    ofile = fopen ("officeid.dat","a");
    if (ofile == NULL)
    {
        fprintf(stderr, "\nError opening officeid.dat\n\n");
        exit (1);
    }



    int i;

    for(i=0;  ; i++)
    {
        printf("\n%10cPlease Enter the information carefully to appoint a new Register Officer");
        printf("\n\n");
        puts("Enter Name : ");
        gets(nidarray[i].name);
        fflush(stdin);
        if(strcmp(nidarray[i].name,"")==0) break;
        puts("Enter Fathers name : ");
        gets(nidarray[i].fathersName);
        puts("Enter Mothers name : ");
        gets(nidarray[i].mothersName);
        fflush(stdin);
        puts("Enter Age : ");
        scanf("%d",&nidarray[i].age);
        getchar();
        puts("Enter Cityname : ");
        gets(nidarray[i].cityname);
        fflush(stdin);
        puts("Enter UserName : ");
        gets(nidarray[i].userName);
        fflush(stdin);
        puts("Enter Password : ");
        gets(nidarray[i].password);
        fflush(stdin);
        nidarray[i].idn = i+100;
        printf("\n");

    }

    num = i;
    fwrite(nidarray, sizeof(struct nidinfo), i, ofile);
    fclose(ofile);

}

void afterRegLogin()
{
    int z;


    printf("\n%25cPress <1> to Register a New NID \n",' ');
    printf("\n%25cPress <2> to Register a New Register Officer \n",' ');
    printf("\n%25cPress <3> to Search With NID Element\n",' ');
    printf("\n%25cPress <4> to Delete NID Info\n",' ');
    fflush(stdin);

    scanf("%d",&z);
    getchar();


    switch(z)
    {
    case 1:
        registration();
        break;
    case 2:
        createRegister();
        break;
    case 3:
        searchOption();
        break;
    case 4:
        deleteUser();
        break;
    default:
        printf("%20cYou have pressed the WRONG key! Try again.\n",' ');


    }

}



void afterUserLogin(char USERNAME[30])
{

    int x;


    printf("\n%25cPress <1> to Show Info \n",' ');
    printf("\n%25cPress <2> to Edit info \n",' ');
    fflush(stdin);

    scanf("%d",&x);
    getchar();


    switch(x)
    {
    case 1:
        showUserinfo(USERNAME);
        break;
    case 2:
        editInfo();

        /*printf("\n Your Info Updated Successfully");
        showUserinfo(USERNAME);*/
        break;
    default:
        printf("%20cYou have pressed the WRONG key! Try again.\n",' ');


    }





}


void searchOption()
{

    char ch;

    printf("press \n 1 . For search people by City . \n 2 . For search people by Name . \n 3 . For search people by Fathers Name .\n 4 . For search people by NID. \n");
    scanf("%c",&ch);
    getchar();
    if(ch == '1')
    {

        search_area();
        getchar();
    }
    else if(ch == '2')
    {
        search_name();
        getchar();
    }
    else if(ch == '3')
    {
        search_father();
        getchar();
    }
    else if(ch == '4')
    {
        search_id();
        getchar();
    }
    else
    {
        printf("You've Entered Wrong Keyword");
    }


}


void showUserinfo(char usrName[50])
{
    char enter[1];

    FILE *file;
    file = fopen ("registration.dat","r");
    num = fread(nidarray, sizeof(struct nidinfo), 100, file);

    if (file == NULL)
    {
        fprintf(stderr, "\nError opening accounts.dat\n\n");
        exit (1);
    }


    int i ;

    for (i=0; i<num; i++)
    {
        if(strcmp(nidarray[i].userName , usrName ) == 0)
        {
            printf("\n");
            printf("NID Number : %d\n",nidarray[i].idn);
            printf("Name :");
            puts(nidarray[i].name);
            printf("Fathers Name :");
            puts(nidarray[i].fathersName);
            printf("Mothers Name :");
            puts(nidarray[i].mothersName);
            printf("Age :%d\n",nidarray[i].age);
            printf("City Name :");
            puts(nidarray[i].cityname);
            printf("\n\nPress Enter To Back to the main menue");



        }

    }

}



void search_area()
{
    FILE *file;
    file = fopen ("registration.dat","r");
    num = fread(nidarray, sizeof(struct nidinfo), 100, file);


    char area[10];
    int i ;

    printf("Enter The City Name You Want to Search: ");
    gets(area);

    for (i=0; i<num; i++)
    {
        if(strstr(nidarray[i].cityname , area ) != NULL)
        {
            printf("NID Number : %d\n",nidarray[i].idn);
            printf("Name :");
            puts(nidarray[i].name);
            printf("Fathers Name :");
            puts(nidarray[i].fathersName);
            printf("Mothers Name :");
            puts(nidarray[i].mothersName);
            printf("Age :%d\n",nidarray[i].age);
            printf("City Name :");
            puts(nidarray[i].cityname);
            printf("\n");
        }

    }
}


void search_id()
{

    FILE *file;
    file = fopen ("registration.dat","r");
    num = fread(nidarray, sizeof(struct nidinfo), 100, file);


    int id;
    int i ;

    printf("Enter NID to search : ");
    scanf("%d",&id);

    for (i=0; i<num; i++)
    {
        if(strcmp(nidarray[i].idn , id ) == 0)
        {
            printf("NID Number : %d\n",nidarray[i].idn);
            printf("Name :");
            puts(nidarray[i].name);
            printf("Fathers Name :");
            puts(nidarray[i].fathersName);
            printf("Mothers Name :");
            puts(nidarray[i].mothersName);
            printf("Age :%d\n",nidarray[i].age);
            printf("City Name :");
            puts(nidarray[i].cityname);
            printf("\n");
        }

    }
}

void search_name()
{

    FILE *file;
    file = fopen ("registration.dat","r");
    num = fread(nidarray, sizeof(struct nidinfo), 100, file);


    char nam[10];
    int i ;

    printf("Enter The Name to search : ");
    gets(nam);

    for (i=0; i<num; i++)
    {
        if(strstr(nidarray[i].name , nam ) != NULL)
        {
            printf("NID Number : %d\n",nidarray[i].idn);
            printf("Name :");
            puts(nidarray[i].name);
            printf("Fathers Name :");
            puts(nidarray[i].fathersName);
            printf("Mothers Name :");
            puts(nidarray[i].mothersName);
            printf("Age :%d\n",nidarray[i].age);
            printf("City Name :");
            puts(nidarray[i].cityname);
            printf("\n");
        }

    }
}


void search_father()
{
    FILE *file;
    file = fopen ("registration.dat","r");
    num = fread(nidarray, sizeof(struct nidinfo), 100, file);



    char father[10];
    int i ;

    printf("Enter Fathers name to search : ");
    gets(father);

    for (i=0; i<num; i++)
    {
        if(strstr(nidarray[i].fathersName , father ) != NULL)
        {
            printf("NID Number : %d\n",nidarray[i].idn);
            printf("Name :");
            puts(nidarray[i].name);
            printf("Fathers Name :");
            puts(nidarray[i].fathersName);
            printf("Mothers Name :");
            puts(nidarray[i].mothersName);
            printf("Age :%d\n",nidarray[i].age);
            printf("City Name :");
            puts(nidarray[i].cityname);
            printf("\n");

        }

    }
}



void deleteUser()
{
    char nullStr[50] = {"\0"};
    int zero = NULL;

    FILE *file;
    file = fopen ("registration.dat","r+");
    num = fread(nidarray, sizeof(struct nidinfo), 100, file);

    if (file == NULL)
    {
        fprintf(stderr, "\nError opening accounts.dat\n\n");
        exit (1);
    }


    int i ;

    char usrName[10];

    printf("Enter The user Name to Delete : ");
    gets(usrName);

    for (i=0; i<num; i++)
    {
        if(strcmp(nidarray[i].userName , usrName ) == 0)
        {
            strcpy(nidarray[i].name,nullStr);
            strcpy(nidarray[i].fathersName,nullStr);
            strcpy(nidarray[i].mothersName,nullStr);
            strcpy(nidarray[i].cityname,nullStr);
            nidarray[i].age = zero;

            printf("\nSuccessfully Deleted.\nPress Enter To Back to the main menue");
            getchar();

            break ;
        }

    }
    num = i;
    fwrite(nidarray, sizeof(struct nidinfo), i, file);
    fclose(file);

}




void editInfo()
{
    char name[50],fathersname[50],mothersname[50],cityName[50];
    char nullStr[50] = {"\0"};
    int zero = 0;

    FILE *file;
    file = fopen ("registration.dat","r+");
    num = fread(nidarray, sizeof(struct nidinfo), 100, file);

    if (file == NULL)
    {
        fprintf(stderr, "\nError opening accounts.dat\n\n");
        exit (1);
    }


    int i ;

    char usrName[10];

    printf("Enter The user Name again : ");
    gets(usrName);

    for (i=0; i<num; i++)
    {
        if(strcmp(nidarray[i].userName , usrName ) == 0)
        {


            printf("\n****Note that if you don't want to change anything,just write the previous one in the input section***\n");
            printf("\n%25cEnter your new name: ",' ');
            gets(name);
            fflush(stdin);
            strcpy(nidarray[i].name,name);

            printf("\n%25cEnter your new Fathers name: ",' ');
            gets(fathersname);
            fflush(stdin);
            strcpy(nidarray[i].fathersName,fathersname);

            printf("\n%25cEnter your new Mothers name: ",' ');
            gets(mothersname);
            fflush(stdin);
            strcpy(nidarray[i].mothersName,mothersname);

            printf("\n%25cEnter your new City name: ",' ');
            gets(cityName);
            fflush(stdin);
            strcpy(nidarray[i].cityname,cityName);
            break;


        }

    }

    num = i;
    fwrite(nidarray, sizeof(struct nidinfo), i, file);
    fclose(file);

}

void userMessages()
{
    char message[100] , enter[1];

    FILE *ifile;
    ifile = fopen ("message.txt","a");
    if (ifile == NULL)
    {
        fprintf(stderr, "\nError opening file\n\n");
        exit (1);
    }

    getchar();

    printf("\nPlease type your Message here and Press 'Enter' to send\n :- ",' ');
    gets(message);
    fflush(stdin);
    fprintf(ifile,message);

    fclose(ifile);

    printf("\n%25cYour Message is Successfully Sent! \nPress ENTER to Continue\n");
    gets(enter);
    fflush(stdin);

}



void clrscr()
{
    system("@cls || clear");
}

