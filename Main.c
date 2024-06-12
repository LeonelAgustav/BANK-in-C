/*
Fungsi Aplikasi Sistem Manajemen Bank disebutkan di bawah ini:
1. Transfer Uang ke Rekening
2. Pembuatan Akun
3. Periksa Jumlah
4. Fungsi Masuk

Menu:
1. Login
2. Register
3. Exit

Fitur:
1. Transfer Money
2. Check Balance
3. Logout
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Data {
    char name[100];
    struct Date birth;
    char email[100];
    char phonenumber[20];
    char password[100];
    char bankID[20];
};

int getCurrentYear() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    return tm.tm_year + 1900;
}

int generate_random_digit() {
    return rand() % 10;
}

void generate_bankID(char* bankID) // Generate a 16-digit bank ID and format it as XXXX XXXX XXXX XXXX
{
    for (int i = 0; i < 16; i++) {
        if (i > 0 && i % 4 == 0) {
            *bankID++ = ' ';
        }
        *bankID++ = '0' + generate_random_digit();
    }
    *bankID = '\0';
}

void menu()
{
    
}

void transfermoney()
{

}

void checkbalance()
{
    
}

void registerUser() 
{
    system("cls");
    srand(time(0));
    struct Data data;
    char confirmpassword[100];

    FILE *file = fopen("User.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    do {
        printf("Enter Name: ");
        scanf(" %99[^\n]", data.name);
        if (strlen(data.name) < 1 || strlen(data.name) > 100) {
            printf("Invalid name. Please enter a name between 1 and 100 characters.\n");
        }
    } while (strlen(data.name) < 1 || strlen(data.name) > 100);

    do {
        printf("Enter Date of Birth [DD MM YYYY]: ");
        scanf("%d %d %d", &data.birth.day, &data.birth.month, &data.birth.year);
        int currentYear = getCurrentYear();
        if (data.birth.day < 1 || data.birth.day > 31 || data.birth.month < 1 || data.birth.month > 12 || data.birth.year > (currentYear - 17)) {
            printf("Invalid date. Please enter a valid date.\n");
        } else if (data.birth.year > (currentYear - 17)) {
            printf("You must be at least 17 years old to register.\n");
        }
    } while (data.birth.day < 1 || data.birth.day > 31 || data.birth.month < 1 || data.birth.month > 12 || data.birth.year > (getCurrentYear() - 17));

    do {
        printf("Enter Email: ");
        scanf(" %99[^\n]", data.email);
        if (strlen(data.email) < 6 || strstr(data.email, "@") == NULL || (strstr(data.email, ".com") == NULL && strstr(data.email, ".co.id") == NULL)) {
            printf("Invalid email. Please enter an email address with length greater than 6 characters, containing '@' and either '.com' or '.co.id' as the domain.\n");
        }
    } while (strlen(data.email) < 6 || strstr(data.email, "@") == NULL || (strstr(data.email, ".com") == NULL && strstr(data.email, ".co.id") == NULL));

    printf("Enter Phone Number: ");
    scanf(" %19[^\n]", data.phonenumber);

    printf("Enter Password: ");
    scanf(" %99s", data.password);

    do {
        printf("Enter Confirm Password: ");
        scanf(" %99s", confirmpassword);

        if (strcmp(data.password, confirmpassword) == 0) 
        {
            generate_bankID(data.bankID);
            fprintf(file, "%s, %d/%d/%d, %s, %s, %s, %s\n", data.name, data.birth.day, data.birth.month, data.birth.year, data.email, data.phonenumber, data.password, data.bankID);
            printf("Registration Successful!\n");
            printf("Press any key to continue...");
            getch();
        } else {
            printf("Passwords do not match! Please try again.\n");
        }
    } while (strcmp(data.password, confirmpassword) != 0);

    fclose(file);
}

void login()
{
    struct Data data;
    
    int choose;

    FILE *file = fopen("User.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    do
    {
        system("cls");
        printf("|=========================|\n");
        printf("|------ Login Using ------|\n");
        printf("|=========================|\n");
        printf("| 1 | %-19s |\n", "Email");
        printf("| 2 | %-19s |\n", "Phone Number");
        printf("| 3 | %-19s |\n", "Back");
        printf("|=========================|\n");
        printf(">> ");
        scanf("%d", &choose);

        switch (choose)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            break;
        default:
            break;
        }
    } while (choose != 1 && choose != 2 && choose != 3);
    

    fclose(file);
}

void Menuawal()
{
    int Menu;

    do
    {
        system("cls");
        printf("|==============================|\n");
        printf("|----- Welcome To Leo Bank ----|\n");
        printf("|==============================|\n");
        printf("| 1 | %-24s |\n", "Login/Sign in");
        printf("| 2 | %-24s |\n", "Register/Create Account");
        printf("| 3 | %-24s |\n", "Back");
        printf("|==============================|\n");
        printf(">> ");
        scanf("%d", &Menu);

        switch (Menu)
        {
        case 1:
            login();
            break;
        case 2:
            registerUser();
            break;
        case 3:
            return;
        default:
            break;
        }
    } while (Menu != 3);
}

int main()
{
    int choice;

    do
    {
        system("cls");
        printf("|==============================|\n");
        printf("|----- Welcome To Leo Bank ----|\n");
        printf("|---------- Login as ----------|\n");
        printf("|==============================|\n");
        printf("| 1 | %-24s |\n", "Admin");
        printf("| 2 | %-24s |\n", "User");
        printf("| 3 | %-24s |\n", "Exit");
        printf("|==============================|\n");
        printf(">> ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2)
        {
            Menuawal();
        }
        else if (choice == 3)
        {
            system("cls");
            printf("Thanks For Using This Program\nHave a Nice Day!");
            printf("Press Enter to Exit...");
            getch();
            system("cls");
        }
    } while (choice != 3);
    
    return 0;
}