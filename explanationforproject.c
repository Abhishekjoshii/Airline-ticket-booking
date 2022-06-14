Functions used in “Airline Ticket Booking System Project in C”:
isFileExists():
This function verifies that a file has been created or not. If the file exists, the function return 1 otherwise returns 0.

int isFileExists(const char *path)
{
    // Try to open file
    FILE *fp = fopen(path, "rb");//opening a file *fp-// opened in read mode
    int status = 0;
    // If file does not exists
    if (fp != NULL)
    {
        status = 1;
        // File exists hence close file
        fclose(fp);
    }
    return status;
}
 

init():
This function creates the file if not exist and copies the default password (“Joshi”) in file header structure.

void init()
{
    FILE *fp = NULL;
    int status = 0;
    const char defaultUsername[] ="Abhishek";
    const char defaultPassword[] ="Joshi";
    sFileHeader fileHeaderInfo = {0};
    status = isFileExists(FILE_NAME);
    if(!status)
    {
        //create the binary file
        fp = fopen(FILE_NAME,"wb");
        if(fp != NULL)
        {
            //Copy default password
            strncpy(fileHeaderInfo.password,defaultPassword,sizeof(defaultPassword));
            strncpy(fileHeaderInfo.username,defaultUsername,sizeof(defaultUsername));
            fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
            fclose(fp);
        }
    }
}
 

printMessageCenter():
This function prints the message in the middle of the head massage. I have passed the message in this function as per the operation.

void printMessageCenter(const char* message)
{
    int len =0;
    int pos = 0;
    //calculate how many space need to print
    len = (78 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
        //print space
        printf(" ");
    }
    //print message
    printf("%s",message);
}
 

headMessage():
It prints the message on the top of the console and prints the message as per operation.


 
void headMessage(const char *message)
{
    system("cls");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############        Airline Ticket Booking System in C         ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}
 

welcomeMessage():
This function displays the first welcomes screen of the “Airline Ticket Booking System Project in C” and asks the user to press any key to access the library application.

void welcomeMessage()
{
    headMessage("www.aticleworld.com");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                     TO                    =");
    printf("\n\t\t\t        =               Airline Ticket              =");
    printf("\n\t\t\t        =               Booking  SYSTEM             =");
    printf("\n\t\t\t        =                                           =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getchar();
}
 

isNameValid():
It validates the user name, author name ..etc. I have permitted this function to take the space in names.

int isNameValid(const char *name)
{
    int validName = 1;
    int len = 0;
    int index = 0;
    len = strlen(name);
    for(index =0; index <len ; ++index)
    {
        if(!(isalpha(name[index])) && (name[index] != '\n') && (name[index] != ' '))
        {
            validName = 0;
            break;
        }
    }
    return validName;
}
 

isValidMobNumber()
it allowed only digits for the mobile number.

int isValidMobNumber(const char *name)
{
    int validName = 1;
    int len = 0;
    int index = 0;
    len = strlen(name);
    for(index =0; index <len ; ++index)
    {
        if(!(isdigit(name[index])) && (name[index] != '\n') && (name[index] != ' '))
        {
            validName = 0;
            break;
        }
    }
    return validName;
}
 

isValidDate():
This function reads the date in the format of dd/mm/yyyy also validates the entered date.

int  IsLeapYear(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}
// returns 1 if given date is valid.
int isValidDate(Date *validDate)
{
    //check range of year,month and day
    if (validDate->yyyy > MAX_YR ||
            validDate->yyyy < MIN_YR)
        return 0;
    if (validDate->mm < 1 || validDate->mm > 12)
        return 0;
    if (validDate->dd < 1 || validDate->dd > 31)
        return 0;
    //Handle feb days in leap year
    if (validDate->mm == 2)
    {
        if (IsLeapYear(validDate->yyyy))
            return (validDate->dd <= 29);
        else
            return (validDate->dd <= 28);
    }
    //handle months which has only 30 days
    if (validDate->mm == 4 || validDate->mm == 6 ||
            validDate->mm == 9 || validDate->mm == 11)
        return (validDate->dd <= 30);
    return 1;
}
 

menu():
This function displays the library menu and asks the user to select the option. If the user selects 0, then the application will close.

void menu()
{
    int choice = 0;
    do
    {
        headMessage("MAIN MENU");
        printf("\n\n\n\t\t\t1.Add New passenger Record");
        printf("\n\t\t\t2.Search passenger Record");
        printf("\n\t\t\t3.View passenger Record");
        printf("\n\t\t\t4.Delete passenger Record");
        printf("\n\t\t\t5.Update Password");
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter choice => ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            addPassengerInDataBase();
            break;
        case 2:
            searchPassenger();
            break;
        case 3:
            viewPassenger();
            break;
        case 4:
            deletePassenger();
            break;
        case 5:
            updateCredential();
            break;
        case 0:
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            exit(1);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
        }                                            //Switch Ended
    }
    while(choice!=0);                                        //Loop Ended
}
 

addPassengerInDataBase()
This function opens the binary file in append mode and writes the passenger information like name, traveling date, address ..etc.

void addPassengerInDataBase()
{
    s_PassengerInfo addPassengerInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    fp = fopen(FILE_NAME,"ab+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    headMessage("ADD NEW PASSENGER");
    printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\tPassenger ID  = ");
    fflush(stdin);
    scanf("%u",&addPassengerInfoInDataBase.passengerId);
    do
    {
        printf("\n\t\t\tPassenger Name  = ");
        fflush(stdin);
        fgetsRemovedNewLine(addPassengerInfoInDataBase.passengerName,MAX_PASSENGER_NAME,stdin);
        status = isNameValid(addPassengerInfoInDataBase.passengerName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tPassenger Mob: = ");
        fflush(stdin);
        fgetsRemovedNewLine(addPassengerInfoInDataBase.passengerMobNum,MAX_PASSENGER_MOB_NUM,stdin);
        status = isValidMobNumber(addPassengerInfoInDataBase.passengerMobNum);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tPassenger Address  = ");
        fflush(stdin);
        fgetsRemovedNewLine(addPassengerInfoInDataBase.passengerAddr,MAX_PASSENGER_ADDRESS,stdin);
        status = isNameValid(addPassengerInfoInDataBase.passengerAddr);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    printf("\n\t\t\tPassenger Ticket Price = ");
    fflush(stdin);//to clear the output buffer of the stream
    scanf("%f",&addPassengerInfoInDataBase.ticketPrice);
    do
    {
        printf("\n\t\t\tPassenger Traveling Date:- ");
        //get date year,month and day from user
        printf("\n\t\t\tEnter date in format (dd/mm/yyyy): ");
        scanf("%d/%d/%d",&addPassengerInfoInDataBase.passengerTravelingDate.dd,&addPassengerInfoInDataBase.passengerTravelingDate.mm,&addPassengerInfoInDataBase.passengerTravelingDate.yyyy);
        //check date validity
        status = isValidDate(&addPassengerInfoInDataBase.passengerTravelingDate);
        if (!status)
        {
            printf("\n\t\t\tPlease enter a valid date.\n");
        }
    }
    while(!status);
    do
    {
        unsigned int tempSeatNumber = 0;
        printf("\n\t\t\tPassenger Seat number = ");
        fflush(stdin);
        scanf("%u",&tempSeatNumber);
        status = (tempSeatNumber != addPassengerInfoInDataBase.passengerSeatNum);
        if(!status)
        {
            printf("\n\t\t\tAlready allocate Seat, Choose another Seat. \n");
        }
    }
    while(!status);
    fwrite(&addPassengerInfoInDataBase,sizeof(addPassengerInfoInDataBase), 1, fp);
    fclose(fp);
}
 

searchPassenger()
This function opens the binary file in reading mode and asks the user to enter the passenger id number which wants to search.  If the passenger info is not available on the list, it shows the message passenger not find in records.

void searchPassenger()
{
    int found = 0;
    int passengerId =0;
    s_PassengerInfo addPassengerInfoInDataBase = {0};
    FILE *fp = NULL;
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    headMessage("SEARCH PASSENGER");
    //put the control on passenger detail
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while reading file\n");
        exit(1);
    }
    printf("\n\n\t\t\tEnter passenger  ID NO to search:");
    fflush(stdin);
    scanf("%u",&passengerId);
    while (fread (&addPassengerInfoInDataBase, sizeof(addPassengerInfoInDataBase), 1, fp))
    {
        if(addPassengerInfoInDataBase.passengerId == passengerId)
        {
            found = 1;
            break;
        }
    }
    if(found)
    {
        printf("\n\t\t\tPassenger id = %d\n",addPassengerInfoInDataBase.passengerId);
        printf("\n\t\t\tPassenger name = %s\n",addPassengerInfoInDataBase.passengerName);
        printf("\n\t\t\tPassenger Mob = %s\n",addPassengerInfoInDataBase.passengerMobNum);
        printf("\n\t\t\tPassenger Seat Number = %s\n",addPassengerInfoInDataBase.passengerSeatNum);
        printf("\n\t\t\tPassenger Ticket Price = %f\n",addPassengerInfoInDataBase.ticketPrice);
        printf("\n\t\t\tPassenger Address = %s\n",addPassengerInfoInDataBase.passengerAddr);
        printf("\n\t\t\tPassenger Admited Date(day/month/year) =  (%d/%d/%d)\n",addPassengerInfoInDataBase.passengerTravelingDate.dd,
               addPassengerInfoInDataBase.passengerTravelingDate.mm, addPassengerInfoInDataBase.passengerTravelingDate.yyyy);
    }
    else
    {
        printf("\n\t\t\tNo Record");
    }
    fclose(fp);
    printf("\n\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}
 

viewPassenger()
This function is used to view the information of all passengers whose information is saved in the database.

void viewPassenger()
{
    int found = 0;
    s_PassengerInfo addPassengerInfoInDataBase = {0};
    FILE *fp = NULL;
    unsigned int countPassenger = 1;
    headMessage("VIEW PASSENGER DETAILS");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("Facing issue while reading file\n");
        exit(1);
    }
    //Print passenger  count
    printf("\n\t\t\tPassenger Count = %d\n\n",countPassenger);
    while (fread (&addPassengerInfoInDataBase, sizeof(addPassengerInfoInDataBase), 1, fp))
    {
        printf("\n\t\t\tPassenger id = %d\n",addPassengerInfoInDataBase.passengerId);
        printf("\n\t\t\tPassenger name = %s\n",addPassengerInfoInDataBase.passengerName);
        printf("\n\t\t\tPassenger Mob = %s\n",addPassengerInfoInDataBase.passengerMobNum);
        printf("\n\t\t\tPassenger Seat Number = %s\n",addPassengerInfoInDataBase.passengerSeatNum);
        printf("\n\t\t\tPassenger Ticket Price = %f\n",addPassengerInfoInDataBase.ticketPrice);
        printf("\n\t\t\tPassenger Address = %s\n",addPassengerInfoInDataBase.passengerAddr);
        printf("\n\t\t\tPassenger Admited Date(day/month/year) =  (%d/%d/%d)\n",addPassengerInfoInDataBase.passengerTravelingDate.dd,
               addPassengerInfoInDataBase.passengerTravelingDate.mm, addPassengerInfoInDataBase.passengerTravelingDate.yyyy);
        found = 1;
        ++countPassenger;
    }
    fclose(fp);
    if(!found)
    {
        printf("\n\t\t\tNo Record");
    }
    printf("\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}
 

deletePassenger()
This function is used to delete the record of a patient from the database on the basis of passenger id.

void deletePassenger()
{
    int found = 0;
    int passengerDelete = 0;
    sFileHeader fileHeaderInfo = {0};
    s_PassengerInfo addPassengerInfoInDataBase = {0};
    FILE *fp = NULL;
    FILE *tmpFp = NULL;
    headMessage("Delete passenger Record Details");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    tmpFp = fopen("tmp.bin","wb");
    if(tmpFp == NULL)
    {
        fclose(fp);
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, tmpFp);
    printf("\n\t\t\tEnter passenger ID NO. for delete:");
    scanf("%d",&passengerDelete);
    while (fread (&addPassengerInfoInDataBase, sizeof(addPassengerInfoInDataBase), 1, fp))
    {
        if(addPassengerInfoInDataBase.passengerId != passengerDelete)
        {
            fwrite(&addPassengerInfoInDataBase,sizeof(addPassengerInfoInDataBase), 1, tmpFp);
        }
        else
        {
            found = 1;
        }
    }
    (found)? printf("\n\t\t\tRecord deleted successfully....."):printf("\n\t\t\tRecord not found");
    fclose(fp);
    fclose(tmpFp);
    remove(FILE_NAME);
    rename("tmp.bin",FILE_NAME);
}
 

updateCredential():
This function opens the file in rb+ mode (reading and writing). It asks the user for the new username and password. After taking the password and username it closes the application. Now users can use the application with a new password and username.

void updateCredential(void)
{
    sFileHeader fileHeaderInfo = {0};
    FILE *fp = NULL;
    char userName[MAX_SIZE_USER_NAME] = {0};
    char password[MAX_SIZE_PASSWORD] = {0};
    headMessage("Update Credential");
    fp = fopen(FILE_NAME,"rb+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    if (fseek(fp,0,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while updating password\n");
        exit(1);
    }
    printf("\n\n\t\t\tNew Username:");
    fflush(stdin);
    fgetsRemovedNewLine(userName,MAX_SIZE_USER_NAME,stdin);
    printf("\n\n\t\t\tNew Password:");
    fflush(stdin);
    fgetsRemovedNewLine(password,MAX_SIZE_PASSWORD,stdin);
    strncpy(fileHeaderInfo.username,userName,sizeof(userName));
    strncpy(fileHeaderInfo.password,password,sizeof(password));
    fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fclose(fp);
    printf("\n\t\t\tYour Password has been changed successfully");
    printf("\n\t\t\tRe-Run Application and Login with new Credential:");
    fflush(stdin);
    getchar();
    exit(1);
}