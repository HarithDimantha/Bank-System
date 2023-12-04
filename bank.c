#include<stdio.h>// standard Input Output header file 
#include<stdlib.h>//standard library file
#include<string.h>//declares the set of functions to work string.

int main_exit;//global variable declararion

float interest(float t,float amount,int rate);//interest function declaration
void newacc();//newacc function declaration
void update();//update function declaration
void transact();//transact function declaration
void checkb();//chechb function declaration
void delete();//delete function declaration
void mainmenu();//mainmenu function declaration
void close();//close function declarion

//create a structure which name is date 
struct date
{
    int month,day,year;
};

struct{

    //structer members or elements
    char name[60];
    int accno,age;
    char address[60];
    char citizenship[15];
    double phoneno;
    char acctype[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;// declare variable for the structure


//...........main function definition..............
    int main()
{
  
    char pass[10],password[10]="pass";//initialization of password="pass"
    int i;
 
    printf("\n\n\n\t\t\t\t   Bank Management System\n\t\t\t\t\t User Login ");
    printf("\n\n\n\n\n\t\t\t\tEnter the password to login:");//get password from user(login password is "pass")
    scanf("%s",pass);//scan the user input
                     
    if (strcmp(pass,password)==0)// string comparison

        {
            printf("\n\nPassword Match!\nLOADING");
            for(i=0;i<=6;i++) //for loop execution
             {
                
                 printf(". ");
             }
                printf("\n");// print the new line
                system("pause");////terminal wait for a key press
                system("cls");//clear the terminal
	   
            mainmenu();//call the mainmenu function
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");

            login://label 
            printf("\nEnter 1 to try again and 0 to exit:");//user input
            scanf("%d",&main_exit);
            // if user enter the 1 
            if (main_exit==1)
                    {

                        system("cls");//clear the terminal
                        //retry to password
                        main();//call the mainfunction
                    }
            //if user enter the 0
            else if (main_exit==0)
                    {
                    system("cls");
                    close();//call the close function
                    }
            //if user enter a invalid input.(expect the 1 or 0)  
            else
                    {
                    printf("\nInvalid Entered!");
                    goto login;// go to jump if the user enter a invalid input(expect 0 or 1)
                    }

        }


        return 0;//function will return null function
}//end the  main function


//.........interest function definition...........
float interest(float t,float amount,int rate)
{
    float SI;//local varibal declaration
    SI=(rate*t*amount)/100.0;
    return (SI);
}

//...........create the new account function definition...............
void newacc(void)

{
   
    FILE *ptr;//local variable declaration(ptr= record.dat file pointer)

    ptr=fopen("file.dat","a+");//open a text file in apend mode using "a+"


    acc_no://label
    system("cls");
    printf("\t\t\t.....ADD RECORD.....");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the account number:");//get the account number from the user
    scanf("%d",&check.accno);
    //read and separate data frome the file
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.accno,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phoneno,add.acctype,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.accno==add.accno)
            {
                printf("Account no. already in use!");
          
                goto acc_no;//go to jump if the user enter a accoun no, already in use
             }
         }
    add.accno=check.accno;//asign the user input(new acc no) to add.accno 
    //get the details from user for creat the new account
    printf("\nEnter the name with initials:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the hometown:");
    scanf("%s",add.address);
    printf("\nEnter the NIC:");
    scanf("%s",add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phoneno);
    printf("\nEnter the amount to deposit:Rs.");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\n\t\tSaving\n\t\tCurrent\n\t\tFixed1(for 1 year)\n\t\tFixed2(for 2 years)\n\t\tFixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.acctype);
       // writing a block of data to a file
    fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phoneno,add.acctype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
     fclose(ptr);//close the file

    printf("\n........Account has been created successfully!...........");

    invalid://label
    printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
     system("cls");

    if (main_exit==1)
        mainmenu();// call the main menu function
    else if(main_exit==0)
        close();//call the close function
    else
        {
            printf("\nInvalid Enered! \a");
            goto invalid;//go to jump if user enters a invlid input(expect 1 or 0)
        }
}

//..........update the account function definition................
void update(void)
{
    int change,test=0;
    FILE *old,*newrec;// old = record.dat and newrec = new.dat file pointer
    old=fopen("file.dat","r");//open a text file in read mode using "r"
    newrec=fopen("new.dat","w");//open a text file in write mode using "w"

    printf("\nEnter the account no. of the customer whose information you want to change:");
    scanf("%d",&upd.accno);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accno,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phoneno,add.acctype,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        //if acc.no which is need to update is equal to the acc.no which is user input
        if (add.accno==upd.accno)
        {   
            test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&change);
            system("cls");

            //if user need to change the address(user input the 1)
            if(change==1)
                {
                printf("Enter the new hometown:");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phoneno,add.acctype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }
            //if user need to change the name(user input the 2)
            else if(change==2)
                {
                printf("Enter the new phone number:");
                scanf("%lf",&upd.phoneno);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phoneno,add.acctype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }

        }
        else
        // writing a block of data to a file
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phoneno,add.acctype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("file.dat");//remove the previous acc
    rename("new.dat","file.dat");//rename the new acc as "record.dat"

if(test!=1)//if the  user input the invalid acc.no
        {  
             system("cls");
            printf("\nRecord not found!!\a\a\a");
            enter://label
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==0)
                    update();
                else if (main_exit==1)
                    mainmenu();
                else if(main_exit==2)
                    close();
                else
                    {
                    printf("\nInvalid Entered!\a");
                    goto enter;//go to jump if the user enter a invalid input
                    }
        }
    else
    //if user need go to the main menu or exit  
        {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            mainmenu();
        else
            close();
        }
}

//...........transaction function definition................
void transact(void)
{   int choice,test=0;

    FILE *old,*newrec;//file pointer declaration
    old=fopen("file.dat","r");//open a text file in read mode using "r"
    newrec=fopen("new.dat","w");//open a text file in write mode using "w"


    printf("\n\nEnter the account no. of the customer:");
    scanf("%d",&transaction.accno);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accno,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phoneno,add.acctype,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.accno==transaction.accno)//if check acc.no which is the user input equal to acc.no which is need to transaction  
            {   test=1;//if add.accno equal to transaction,accno ,test=1

            //if this function return the 0,acc.type is same to fixed1 or fixed2 or fixed3  
                if(strcmpi(add.acctype,"fixed1")==0||strcmpi(add.acctype,"fixed2")==0||strcmpi(add.acctype,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                
                    system("cls");
                    mainmenu();// call the mainmenu function

                }
                printf("\n\nDo you want to\n\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                //if user enter the choice as 1(for deposit)
                if (choice==1)
                {
                    printf("\n\nEnter the amount you want to deposit:Rs. ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;//add.amt=add.amt+transaction.amt
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phoneno,add.acctype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\n.........Deposited successfully!........\n\n");
                }
                else
                //if user enter the choice as 2(for withdrawn)
                {
                    printf("\n\nEnter the amount you want to withdraw:Rs. ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;//add.amt=add.amt-transaction.amt
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phoneno,add.acctype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\n.......Withdrawn successfully........!\n\n");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phoneno,add.acctype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);//close the record.dat file
   fclose(newrec);//close the new.dat file
   remove("file.dat");//remove the previous acc
   rename("new.dat","file.dat");//rename the new acc as "record.dat"

//tesl not equal to 1= no mathcing the acc no which is user input 
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact://label
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");

      //if user enter the 0
      if (main_exit==0)
        transact();//call the transact function

        //if user enter the 1
    else if (main_exit==1)
        mainmenu();//call the mainmenu function

        //if user enter the 2
    else if (main_exit==2)
        close();//call the close function
    else
    {
        printf("\nInvalid Entered!");
        goto transact;//go to jump if the user enter a invalid input
    }

   }

   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        //if user need to go to mainmenu(enter the 1)
        if (main_exit==1)
            mainmenu();
        else
            close();
   }

}


//............check the balance function definition....................
void checkb(void)
{
    FILE *ptr;
    //declare the local varibles
    int test=0,rate,choice;
    float time,intrst;
  
    ptr=fopen("file.dat","r");
     //get the choice from user (from 1.acc.no or 2.name)
    printf("\n\nDo you want to check by\n\n\t1.Account no\n\t2.Name\n\nEnter your choice:");
    scanf("%d",&choice);
    //if user choose the 1
    if (choice==1)
      //check the detailes from the acc.no
    {   printf("\n\nEnter the account number:");
        scanf("%d",&check.accno);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accno,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phoneno,add.acctype,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.accno==check.accno)
            {   system("cls");
                test=1;

                  //print the detailes of acc
                  printf("\n\tAccount NO:%d\n",add.accno);
                  printf("\tName:%s\n",add.name);
                  printf("\tDOB:%d/%d/%d\n",add.dob.month,add.dob.day,add.dob.year );
                  printf("\tAge:%d\n",add.age );
                  printf("\tHometown:%s\n",add.address );
                  printf("\tNIC:%s\n",add.citizenship );
                  printf("\tPhone number:%.0lf\n",add.phoneno );
                  printf("\tType Of Account:%s\n",add.acctype );
                  printf("\tAmount deposited: Rs. %.2f\n",add.amt );
                  printf("\tDate Of Deposit:%d/%d/%d\n" ,add.deposit.month,add.deposit.day,add.deposit.year);
              
                if(strcmpi(add.acctype,"fixed1")==0)//if acc.type is fixed1
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\tYou will get $%.2f as interest on %d/%d/%d\n\n",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acctype,"fixed2")==0)//if acc type is fixed2
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\tYou will get $.%.2f as interest on %d/%d/%d\n\n",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acctype,"fixed3")==0)//if acc type is fixed3
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\tYou will get $.%.2f as interest on %d/%d/%d\n\n",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acctype,"saving")==0)//if the acc.type is saving 
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\tYou will get $.%.2f as interest on %d of every month\n\n",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acctype,"current")==0)//if the acc.type is current
                    {

                        printf("\n\n\tYou will get no interest\n\n\a\a");

                     }

            }
        }
    }
      //if user enter the 2
    else if (choice==2)
     //check the detials of acc from the account name 
    {   printf("\nEnter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accno,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phoneno,add.acctype,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n",add.accno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phoneno,
                add.acctype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acctype,"fixed1")==0)//if acc type is fixed1
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d\n\n",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acctype,"fixed2")==0)//if acc type is fixed2
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d\n\n",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acctype,"fixed3")==0)//if acc type is fixed3
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d\n\n",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acctype,"saving")==0)//if the acc.type is saving 
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d of every month\n\n",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acctype,"current")==0)//if the acc.type is current
                    {

                        printf("\n\nYou will get no interest\n\n\a\a");

                     }

            }
        }
    }


    fclose(ptr);//file close
     if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            check://label
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
              //if user input the 1
                 if (main_exit==1)
                    mainmenu();//call the mainmenu function
                else if (main_exit==2)
                    close();
              //if user input the 0
                else if(main_exit==0)
                    checkb();//call the checkb function
              //if user input the expect of 1 or 0
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto check;//go to jump if the user enter a invalid input
                    }
        }
    else
        {
         printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        }
        if (main_exit==1)//if user enter the 1
        {
            system("cls");
            mainmenu();//call the mainmenu function
        }

        else//if user enter the 0
           {

            system("cls");
            close();//call the close function
            }

}

// .........delete the account function definition...........
void delete(void)
{
    
    FILE *old,*newrec;
    int test=0;
    old=fopen("file.dat","r");//open a text file in read mode using "r"
    newrec=fopen("new.dat","w");//open a text file in write mode using "w"
  
    printf("\n\nEnter the account no. of the customer you want to delete:");
    scanf("%d",&rem.accno);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accno,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phoneno,add.acctype,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
       
        if(add.accno!=rem.accno)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phoneno,add.acctype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {test++;//test=test+1
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);//close the record.dat file 
   fclose(newrec);//close the new.dat file
   remove("file.dat");//remove the record.dat file
   rename("new.dat","file.dat");//rename the "new.dat"  to "record.dat"
  
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            delete://label
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==0)
                     delete();
                else if (main_exit==1)
                    mainmenu();
                else if(main_exit==2)
                    close();
                else
                    {printf("\nInvalid Entered!\a");
                    goto delete;//go to jump if the user enter a invalid input
                    }
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            mainmenu();
        else
            close();
        }

}


//................mainmenu function definition..............
void mainmenu(void)

{   
    int choice;//declaration of variable which will use inside the switch case
    
    printf("\n\n\t========= BANKING MANAGEMENT SYSTEM =========");
    printf("\n\n\t\t WELCOME TO THE MAIN MENU ");
    //Main Menu options
    printf("\n\n\t\t[1] Create a new account");
    printf("\n\t\t[2] Update information of existing account");
    printf("\n\t\t[3] Transactions");
    printf("\n\t\t[4] Check the balance of account");
    printf("\n\t\t[5] Remove existing account");
    printf("\n\t\t[6] Exit");
    printf("\n\n\n\t\tEnter your choice:");
    scanf("%d",&choice); //get the choice from the user

    
    switch(choice)
    {
        case 1:newacc(); //call for the newacc function
        break;
        case 2:update(); //call for the update functon
        break;
        case 3:transact(); //call for the transact functon
        break;
        case 4:checkb(); //call for the checkb functon
        break;
        case 5:delete(); //call for the delete functon
        break;
        case 6:close(); //call for close functon
        break;
    }

}




//..............close function definition................
void close(void)
{
   
    printf("\n\n\n\n\t........Thank you......\n\n");
  
  
    }
//
