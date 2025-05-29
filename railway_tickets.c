#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Passenger
{
    char name[50];
    int age;
    char gender;
    char t_name[20];
    int seat_no;
};
void booktickets();
void displaytickets();
void canceltickets();
int main()
{
    int choice;
    while (1)
    {
        printf("\nRailway Reservation System\n");
        printf("1. Book Ticket\n2. View Tickets\n3. Cancel Ticket\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            booktickets();
            break;

        case 2:
            displaytickets();
            break;
        case 3:
            canceltickets();
            break;
        case 4:
            exit(0);
        default:
            printf("Enter valid argument\n");
            break;
        }
    }

    return 0;
}
void booktickets()
{
    struct Passenger p;

    printf("enter name\n");
    fgets(p.name, 50, stdin);
    p.name[strcspn(p.name, "\n")] = '\0';

    printf("Enter the age\n");
    scanf("%d", &p.age);
    getchar();

    printf("Enter the gender (M/F):\n");
    scanf("%c", &p.gender);
    getchar();

    printf("Enter the train Name\n");
    fgets(p.t_name, 20, stdin);
    p.t_name[strcspn(p.t_name, "\n")] = '\0';
    printf("Enter the seat number\n");
    scanf("%d", &p.seat_no);

    FILE *fp = fopen("tickets.txt", "ab");
    if (fp == NULL)
    {
        printf("File not opened");
    }
    fwrite(&p, sizeof(struct Passenger), 1, fp);
    fclose(fp);
    printf("Tickets Booked succesfully\n");
}
void displaytickets()
{
    FILE *fp = fopen("tickets.txt", "r");
    if (fp == NULL)
    {
        printf("File not opened\n");
    }
    struct Passenger p;
    while (fread(&p, sizeof(struct Passenger), 1, fp))
    {
        printf("\nName:%s\nAge:%d\nGender:%c\nTrain:%s\nSeat No:%d\n",
               p.name, p.age, p.gender, p.t_name, p.seat_no);
    }
    fclose(fp);
}
void canceltickets()
{
    char search_name[50];
    printf("Enter the name to delete \n");
    fgets(search_name, 50, stdin);
    search_name[strcspn(search_name, "\n")] = '\0';

    FILE *fp = fopen("tickets.txt", "r");
    FILE *temp = fopen("temp.txt", "a");
    if (fp == NULL || temp == NULL)
    {
        printf("File not opened\n");
    }

    int found = 1;
    struct Passenger p;
    while (fread(&p, sizeof(struct Passenger), 1, fp))
    {
        if (strcmp(p.name, search_name) != 0)
        {
            fwrite(&p, sizeof(struct Passenger), 1, temp);
        }
        else
        {
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);
    remove("tickets.txt");
    rename("temp.txt", "tickets.txt");
    if (found)
        printf("Ticket Canceled Successfully!\n");
    else
        printf("Ticket Not Found!\n");
}