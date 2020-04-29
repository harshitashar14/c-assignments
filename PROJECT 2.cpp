#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

using namespace std;
int main()
{
    FILE *a, *b;
    char another, choice;

    struct student
    {
        char first_name[50], last_name[50];
        char course[100];
        int section;
    };

    struct student e;
    char xfirst_name[50], xlast_name[50];
    long int recsize;

    a=fopen("users.txt","rb+");

    if (a == NULL)
    {
        a = fopen("users.txt","wb+");

        if (a==NULL)
        {
            puts("Cannot open file");
            return 0;
        }
    }


    recsize = sizeof(e);

    while(1)
    {
        system("cls");

        cout << "\t\t        Database management           ";
        cout <<"\n\n                                          ";
        cout << "\n\n";
        cout << "\n  1. Add    ";
        cout << "\n  2. List   ";
        cout << "\n  3. Modify ";
        cout << "\n  4. Delete ";
        cout << "\n  5. Exit   ";
        cout << "\n\n";
        cout << "\t\t\t Select Your Choice :=> ";
        fflush(stdin);
        choice = getche();
        switch(choice)
        {
        case '1' :
            fseek(a,0,SEEK_END);
            another ='Y';
            while(another == 'Y' || another == 'y')
            {
                system("cls");
                cout << "Enter the First Name : ";
                cin >> e.first_name;
                cout << "Enter the Last Name : ";
                cin >> e.last_name;
                cout << "Enter the Course    : ";
                cin >> e.course;
                cout << "Enter the Section   : ";
                cin >> e.section;
                fwrite(&e,recsize,1,a);
                cout << "\n Add Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
        case '2':
            system("cls");
            rewind(a);
            cout << "=== View the Records in the Database ===";
            cout << "\n";
            while (fread(&e,recsize,1,a) == 1)
            {
                cout << "\n";
                cout <<"\n" << e.first_name << setw(10)  << e.last_name;
                cout << "\n";
                cout <<"\n" <<e.course <<  setw(8)  << e.section;
            }
            cout << "\n\n";
            system("pause");
            break;

        case '3' :
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter the last name of the student : ";
                cin >> xlast_name;

                rewind(a);
                while (fread(&e,recsize,1,a) == 1)
                {
                    if (strcmp(e.last_name,xlast_name) == 0)
                    {
                        cout << "Enter new the Firt Name : ";
                        cin >> e.first_name;
                        cout << "Enter new the Last Name : ";
                        cin >> e.last_name;
                        cout << "Enter new Course    : ";
                        cin >> e.course;
                        cout << "Enter new Section   : ";
                        cin >> e.section;
                        fseek(a, - recsize, SEEK_CUR);
                        fwrite(&e,recsize,1,a);
                        break;
                    }
                    else
                        cout<<"record not found";
                }
                cout << "\n Modify Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;


        case '4':
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter the last name of the student to delete : ";
                cin >> xlast_name;

                b = fopen("temp.dat", "wb");

                rewind(a);
                while (fread (&e, recsize,1,a) == 1)

                    if (strcmp(e.last_name,xlast_name) != 0)
                    {
                        fwrite(&e,recsize,1,b);
                    }
                fclose(a);
                fclose(b);
                remove("users.txt");
                rename("temp.dat","users.txt");

                a=fopen("users.txt","rb+");

                cout << "\n Delete Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }

            break;

        case '5':
            fclose(a);
            cout << "\n\n";
            cout << "\t\t    ";
            cout << "\n\n";
            exit(0);
        }
    }


    system("pause");
    return 0;
}
