#include <stdio.h>

int main()
{
    int busnumber[5] = {101, 102, 103, 104, 105};
    int totalseats[5] = {60, 60, 60, 60, 60};
    int availableseats[5] = {60, 60, 60, 60, 60};
    int fare[5] = {300, 350, 400, 450, 500};

    char source[5][30] = {
        "Gorakhpur",
        "Mumbai",                         //  printf("enter name: \n");
                                           //  scanf("%[^\n]",username);
                                           //  printf("enter password: \n");
                                           //  scanf("%s",password);
                                           //  printf("\n");

        "Delhi",
        "MP",
        "MP"
    };

    char destination[5][30] = {
        "Delhi",
        "Bihar",
        "Patna",
        "UP",
        "Bihar"
    };

    int choice, bus, seats;
    char username[30];
    char password[20];
    int i, check;

    printf("=========== BUS RESERVATION SYSTEM ===========\n");

    printf("Enter your name: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    printf("\n***** Login Successful *****\n");

    do
    {
        printf("\n========== USER MENU ==========\n");
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. Check Bus Status\n");
        printf("4. Logout\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:

            printf("\nAvailable Buses:\n");

            for(i=0; i<5; i++)
            {
                printf("Bus No: %d\n", busnumber[i]);
                printf("Route : %s --> %s\n", source[i], destination[i]);
                printf("Available Seats: %d\n", availableseats[i]);
                printf("Fare: %d\n", fare[i]);
                printf("-----------------------------\n");
            }

            printf("Enter Bus Number: ");
            scanf("%d",&bus);

            printf("Enter Number of Seats: ");
            scanf("%d",&seats);

            check = 0;

            for(i=0; i<5; i++)
            {
                if(busnumber[i]==bus)
                {
                    check=1;

                    if(availableseats[i]>=seats)
                    {
                        availableseats[i]-=seats;

                        printf("\nBooking Successful!\n");
                        printf("Bus Number : %d\n",busnumber[i]);
                        printf("Route      : %s --> %s\n",source[i],destination[i]);
                        printf("Booked Seats : %d\n",seats);
                        printf("Total Amount : %d\n",fare[i]*seats);
                        printf("Available Seats : %d\n",availableseats[i]);
                    }
                    else
                    {
                        printf("Seats Not Available!\n");
                    }
                }
            }

            if(check==0)
                printf("Invalid Bus Number!\n");

            break;

        case 2:

            printf("Enter Bus Number: ");
            scanf("%d",&bus);

            printf("Enter Seats to Cancel: ");
            scanf("%d",&seats);

            check=0;

            for(i=0;i<5;i++)
            {
                if(busnumber[i]==bus)
                {
                    check=1;

                    if(availableseats[i]+seats<=totalseats[i])
                    {
                        availableseats[i]+=seats;
                        printf("Ticket Cancelled Successfully!\n");
                        printf("Available Seats : %d\n",availableseats[i]);
                    }
                    else
                    {
                        printf("Invalid Cancellation!\n");
                    }
                }
            }

            if(check==0)
                printf("Invalid Bus Number!\n");

            break;

        case 3:

            printf("Enter Bus Number: ");
            scanf("%d",&bus);

            check=0;

            for(i=0;i<5;i++)
            {
                if(busnumber[i]==bus)
                {
                    check=1;

                    printf("\n===== BUS STATUS =====\n");
                    printf("Bus Number      : %d\n",busnumber[i]);
                    printf("Route           : %s --> %s\n",source[i],destination[i]);
                    printf("Total Seats     : %d\n",totalseats[i]);
                    printf("Available Seats : %d\n",availableseats[i]);
                    printf("Fare            : %d\n",fare[i]);
                }
            }

            if(check==0)
                printf("Invalid Bus Number!\n");

            break;

        case 4:
            printf("Logout Successful!\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    }while(choice!=4);

    return 0;
}