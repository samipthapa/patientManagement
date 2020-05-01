#include <stdio.h>
#include <string.h>

typedef struct {
    int serialNo;
    char name[30], address[30];
    int age;
    char disease[20];
} record;

FILE *fptr;
int num; //total no of records
int i;
record patient[100];

void addRecord();
void viewRecord();
void deleteRecord();
void searchRecord();

int main()
{
    fptr = fopen("record.txt", "r");
    if (fptr == NULL)
    {
        fptr = fopen("record.txt", "w");
        fclose(fptr);
    }
    num = fread(patient, sizeof(record),100, fptr);     //no of records in the file
    fclose(fptr);
    char ch;
    printf("*****WELCOME TO PATIENT MANAGEMENT SYSTEM***** \n\n");
    printf(" 1. Add New Record: \n 2. Check Existing Records: \n");
    printf(" 3. Delete Record: \n 4. Search Record: \n 5. Exit: \n");
    printf("Enter Your Choice: \n");
    scanf(" %c", &ch);
    if (ch=='1')
    {
        system("cls");
        addRecord();

    }
    else if (ch=='2')
    {
        system("cls");
        viewRecord();
    }
    else if (ch=='3')
    {
        system("cls");
        deleteRecord();
    }
    else if (ch=='4')
    {
        system("cls");
        searchRecord();
    }
    else if (ch=='5')
    {
        return 0;
    }
    else
        printf("\n Invalid Input");
}

void addRecord()
{
    int sum=0;
    int n;  //no of new records
    fptr = fopen("record.txt", "r+");
    printf("How many records do you want to add?");
    scanf("%d", &n);
    sum=num+n;
    for (i=num; i<sum; i++)
    {
        printf("\n");
        patient[i].serialNo=i;
        printf("Enter Name: ");
        fflush(stdin);
        gets(patient[i].name);
        printf("Enter Address: ");
        fflush(stdin);
        gets(patient[i].address);
        printf("Enter Age: ");
        fflush(stdin);
        scanf("%d", &patient[i].age);
        printf("Enter Disease: ");
        fflush(stdin);
        gets(patient[i].disease);
        }
    fwrite(patient, sizeof(record), sum, fptr);
}

void viewRecord()
{
    for(i=0; i<num; i++)
    {
        printf("Serial Number = %d\n", patient[i].serialNo);
        printf("Name = %s\n", patient[i].name);
        printf("Address = %s\n", patient[i].address);
        printf("Age = %d\n", patient[i].age);
        printf("Disease = %s\n\n", patient[i].disease);
    }
}

void deleteRecord()
{
    fptr = fopen("record.txt", "r");
    FILE *fptr2 = fopen("file2.txt", "a");
    int sn, c;
    int counter=0;
    printf("Please select an option: \n");
    printf(" 1. Enter the serial number \n 2. Enter the patient's name");
    printf("\n Enter your choice: ");
    scanf("%d", &c);
    if (c==1)
    {
        system("cls");
        printf("Enter the serial number: ");
        scanf("%d", &sn);
        for(i=0;i<num;i++)
        {
            while (counter!=num)
            {
                fread(patient, sizeof(record),1, fptr);
                if(patient[i].serialNo==sn)
                {
                    //skips the record
                }
                else
                {
                    fwrite(patient, sizeof(record),1,fptr2);
                }
                counter++;
            }
        }
        printf("\nSuccessfully deleted\n");
    }
    else if(c==2)
    {
        system("cls");
        char flag[30];
        printf("Enter the patient's name: ");
        fflush(stdin);
        gets(flag);
        for(i=0;i<num;i++)
            {
            while (counter!=num)
                {
            fread(patient, sizeof(record),1, fptr);
            if(strcmp(flag, patient[i].name)==0)
                    {

                    }
            else
                    {
            fwrite(patient, sizeof(record),1,fptr2);
                    }
            counter++;
                }
            }
        printf("\nSuccessfully deleted\n");
    }
    else printf("\nIncorrect Input");
    fclose(fptr);
    fclose(fptr2);
    remove("record.txt");
    rename("file2.txt", "record.txt");
}

void searchRecord()
{
    char ch;
    char flag[30];
    int serialNo;
    printf("From what criteria do you wish to search? \n");
    printf(" 1. Serial Number \n 2. Name \n 3. Address \n 4. Age \n 5. Disease\n");
    printf("\nEnter Your Choice: ");
    scanf(" %c", &ch);
    if(ch=='1')
    {
        printf("Enter the serial number of the patient: ");
        scanf("%d", &serialNo);
        if(serialNo<num)
        {
            printf("\n\nSerial Number: %d\n", serialNo);
            printf("Name: %s\n", patient[serialNo].name);
            printf("Address : %s\n", patient[serialNo].address);
            printf("Age: %d\n", patient[serialNo].age);
            printf("Disease: %s\n", patient[serialNo].disease);
        }
        else if (serialNo>num)
            printf("\nPatient Not Found");
    }
    else if (ch=='2')
    {
        printf("Enter the name: ");
        fflush(stdin);
        gets(flag);
        for(i=0; i<num; i++)
        {
            if(strcmp(flag, patient[i].name)==0)
            {
                printf("\n\nSerial Number = %d\n", i);
                printf("Name: %s\n", patient[i].name);
                printf("Address: %s\n", patient[i].address);
                printf("Age: %d\n", patient[i].age);
                printf("Disease: %s\n", patient[i].disease);
            }
        }
    }
    else if (ch=='3')
    {
        printf("Enter the address: ");
        fflush(stdin);
        gets(flag);
        for(i=0; i<num; i++)
        {
            if(strcmp(flag, patient[i].address)==0)
            {
                printf("\n\nSerial Number = %d\n", i);
                printf("Name: %s\n", patient[i].name);
                printf("Address: %s\n", patient[i].address);
                printf("Age: %d\n", patient[i].age);
                printf("Disease: %s\n", patient[i].disease);
            }
        }
    }
    else if (ch=='4')
    {
        int a;
        printf("Enter the age: ");
        scanf("%d", &a);
        for(i=0; i<num; i++)
        {
            if(a==patient[i].age)
            {
                printf("\n\nSerial Number = %d\n", i);
                printf("Name: %s\n", patient[i].name);
                printf("Address: %s\n", patient[i].address);
                printf("Age: %d\n", patient[i].age);
                printf("Disease: %s\n", patient[i].disease);
            }
        }
    }
    else if (ch=='5')
    {
        printf("Enter the disease: ");
        fflush(stdin);
        gets(flag);
        for(i=0; i<num; i++)
        {
            if(strcmp(flag, patient[i].disease)==0)
            {
                printf("\n\nSerial Number = %d\n", i);
                printf("Name: %s\n", patient[i].name);
                printf("Address: %s\n", patient[i].address);
                printf("Age: %d\n", patient[i].age);
                printf("Disease: %s\n", patient[i].disease);
            }
        }
    }
    else
        printf("\nInvalid Input");
}
