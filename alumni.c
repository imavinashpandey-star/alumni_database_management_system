#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure (DSA Concept)
struct Alumni {
    int id;
    char name[50];
    char branch[50];
    int passingYear;
    char company[50];
};

struct Alumni list[MAX];
int count = 0;

// Function Prototypes
void addAlumni();
void displayAlumni();
void searchAlumni();
void deleteAlumni();
void updateAlumni();
void saveToFile();
void loadFromFile();
void sortAlumni();

// MAIN FUNCTION
int main() {
    int choice;

    loadFromFile();

    while (1) {
        printf("\n===== Alumni Database System =====\n");
        printf("1. Add Alumni\n");
        printf("2. Display Alumni\n");
        printf("3. Search Alumni\n");
        printf("4. Update Alumni\n");
        printf("5. Delete Alumni\n");
        printf("6. Sort by Passing Year\n");
        printf("7. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addAlumni(); break;
            case 2: displayAlumni(); break;
            case 3: searchAlumni(); break;
            case 4: updateAlumni(); break;
            case 5: deleteAlumni(); break;
            case 6: sortAlumni(); break;
            case 7: saveToFile(); exit(0);
            default: printf("Invalid Choice!\n");
        }
    }
}

// ADD
void addAlumni() {
    if (count >= MAX) {
        printf("Database Full!\n");
        return;
    }

    printf("\nEnter ID: ");
    scanf("%d", &list[count].id);
    printf("Enter Name: ");
    scanf(" %[^\n]", list[count].name);
    printf("Enter Branch: ");
    scanf(" %[^\n]", list[count].branch);
    printf("Enter Passing Year: ");
    scanf("%d", &list[count].passingYear);
    printf("Enter Company: ");
    scanf(" %[^\n]", list[count].company);

    count++;
    printf("Alumni Added Successfully!\n");
}

// DISPLAY
void displayAlumni() {
    if (count == 0) {
        printf("No Records Found!\n");
        return;
    }

    printf("\n--- Alumni List ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nID: %d\nName: %s\nBranch: %s\nYear: %d\nCompany: %s\n",
               list[i].id, list[i].name, list[i].branch,
               list[i].passingYear, list[i].company);
    }
}

// SEARCH (Linear Search - DSA)
void searchAlumni() {
    int id, found = 0;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (list[i].id == id) {
            printf("\nRecord Found!\n");
            printf("Name: %s\nBranch: %s\nYear: %d\nCompany: %s\n",
                   list[i].name, list[i].branch,
                   list[i].passingYear, list[i].company);
            found = 1;
            break;
        }
    }

    if (!found) printf("Record Not Found!\n");
}

// DELETE
void deleteAlumni() {
    int id, found = 0;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (list[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                list[j] = list[j + 1];
            }
            count--;
            printf("Record Deleted!\n");
            found = 1;
            break;
        }
    }

    if (!found) printf("Record Not Found!\n");
}

// UPDATE
void updateAlumni() {
    int id, found = 0;
    printf("Enter ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (list[i].id == id) {
            printf("Enter New Name: ");
            scanf(" %[^\n]", list[i].name);
            printf("Enter New Branch: ");
            scanf(" %[^\n]", list[i].branch);
            printf("Enter New Year: ");
            scanf("%d", &list[i].passingYear);
            printf("Enter New Company: ");
            scanf(" %[^\n]", list[i].company);

            printf("Record Updated!\n");
            found = 1;
            break;
        }
    }

    if (!found) printf("Record Not Found!\n");
}

// SORT (Bubble Sort - DSA)
void sortAlumni() {
    struct Alumni temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (list[j].passingYear > list[j + 1].passingYear) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

    printf("Sorted by Passing Year!\n");
}

// SAVE TO FILE
void saveToFile() {
    FILE *fp = fopen("alumni.txt", "w");

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d %s %s %d %s\n",
                list[i].id,
                list[i].name,
                list[i].branch,
                list[i].passingYear,
                list[i].company);
    }

    fclose(fp);
    printf("Data Saved Successfully!\n");
}

// LOAD FROM FILE
void loadFromFile() {
    FILE *fp = fopen("alumni.txt", "r");

    if (fp == NULL) return;

    while (fscanf(fp, "%d %s %s %d %s",
                  &list[count].id,
                  list[count].name,
                  list[count].branch,
                  &list[count].passingYear,
                  list[count].company) != EOF) {
        count++;
    }

    fclose(fp);
}
