#include <stdio.h>
#include <stdbool.h>
#include<string.h>
typedef struct book {
    char book_name[100];
    char author_name[100];
    int pages;
} nwbk;

typedef struct issuer {
    char name[50];
    int rollnumber;
    nwbk bookname;
} issue;

int main() {
    nwbk arr[1000];
    int number_of_books = 0;
    issue arriss[1000];
    int number_of_issuers = 0;

    main_menu:
    printf("\n.............W E L C O M E  T O  L I B R A R Y  M A N A G E M E N T  S Y S T E M !...........\n\n");
    printf("FOR ENTERING BOOK          -> 1\n");
    printf("FOR ISSUE BOOK             -> 2\n");
    printf("FOR ACCESSING BOOK DETAILS -> 3\n");
    printf("FOR EXITING                -> 4\n\n");
    printf("ENTER YOUR CHOICE  -> ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        bool exit_to_main = false;
        while (!exit_to_main) {
            if (number_of_books >= 1000) {
                printf("Book storage is full. Cannot add more books.\n");
                goto main_menu;
            }
            printf("\nEnter details for book %d:\n", number_of_books + 1);
            printf("Book Name: ");
            scanf(" %[^\n]s", arr[number_of_books].book_name);
            printf("Author Name: ");
            scanf(" %[^\n]s", arr[number_of_books].author_name);
            printf("Number of Pages: ");
            scanf("%d", &arr[number_of_books].pages);

            number_of_books++;

            printf("\nDo you want to return to the main menu? (y/n): ");
            char yes_no;
            scanf(" %c", &yes_no);
            if (yes_no == 'y' || yes_no == 'Y') {
                exit_to_main = true;
                goto main_menu;
            }
        }
    } 
    else if (choice == 2) {
        bool exit_to_main = false;
        while (!exit_to_main) {
            if (number_of_issuers >= 1000) {
                printf("Issuer storage is full. Cannot add more issuers.\n");
                goto main_menu;
            }

            printf("\nEnter details for issuer %d:\n", number_of_issuers + 1);
            printf("Issuer Name: ");
            scanf(" %[^\n]s", arriss[number_of_issuers].name);
            printf("Roll Number: ");
            scanf("%d", &arriss[number_of_issuers].rollnumber);
            printf("Book Name: ");
            scanf(" %[^\n]s", arriss[number_of_issuers].bookname.book_name);
            printf("Author Name: ");
            scanf(" %[^\n]s", arriss[number_of_issuers].bookname.author_name);
            printf("Number of Pages: ");
            scanf("%d", &arriss[number_of_issuers].bookname.pages);

            number_of_issuers++;

            printf("\nDo you want to return to the main menu? (y/n): ");
            char yes_no;
            scanf(" %c", &yes_no);
            if (yes_no == 'y' || yes_no == 'Y') {
                exit_to_main = true;
                goto main_menu;
            }
        }
    }
    else if (choice == 3) {
    if (number_of_books == 0) {
        printf("\n............. NO BOOK AVAILABLE TO SHOW :( ...............\n");
        goto main_menu;
    }

    printf("ENTER BOOK NAME -> ");
    char book_find[50];
    scanf(" %[^\n]s", book_find);

    bool found = false;
    for (int i = 0; i < number_of_books; i++) {
        if (strcmp(arr[i].book_name, book_find) == 0) {
            printf("\nBook name -> %s\n", arr[i].book_name);
            printf("Author name -> %s\n", arr[i].author_name);
            printf("Pages -> %d\n", arr[i].pages);
            found = true;
            break;
        }
    }

    if (!found) {
        printf("BOOK NOT FOUND\n");
    }

    printf("\nDo you want to return to the main menu? (y/n): ");
    char yes_no;
    scanf(" %c", &yes_no);
    if (yes_no == 'y' || yes_no == 'Y') {
        goto main_menu;
    }
}
    if(choice==4){
        printf("\nGOOD BYE :).....\n");
        printf("Exited successfully!!");
        return 0;
    }
    return 0;
}

