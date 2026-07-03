#include <stdio.h>

int main()
{
    int busnumber[5] = {101, 102, 103, 104, 105};
    int totalseats[5] = {60, 60, 60, 60, 60};
    int availableseats[5] = {20, 30, 40, 50, 60};
    int fare[5] = {500, 400, 350, 300, 200};
    int i, check, location;
    int j = 0;
    int bookedseats = 0;
    int choice, bus, seats, payment, registered, loginsuccess;
    char username[30], password[20];
    char reusername[30], repassword[20];
    char busname[5][30] = {"rajdeluxe", "highway_king", "bihar_delux", "patliputra_travels", "narmada_express"};
    char bustype[5][20] = {"AC sleeper", "non AC", "sleeper", "AC seater", "non AC sleeper"};

    printf("-----------------BUS RESERVATION SYSTEM---------------------\n");
    printf("------------------------------------------------------------\n");

    do
    {
        printf("----------MENU-------------\n");
        printf("1. register\n");
        printf("2. login\n");
        printf("3. exit\n");
        printf("enter your choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter user name: \n");
            scanf(" %[^\n]s", reusername);
            printf("enter user password: ");
            scanf("%s", repassword);
            printf("-------------------registration successful------------------\n");
            break;

        case 2:

            printf("enter name: \n");
            scanf(" %[^\n]s", username);
            printf("enter password: \n");
            scanf("%s", password);
            printf("\n");
            printf("-----------login successful------\n");
            break;

        case 3:
            printf("exit\n");
            break;

        default:
            printf("invalid choice\n");
            break;
        }

    } while (choice != 3);

    printf("\n***********************login successful***********************\n");

    printf("\n-----------------------AVAILABLE ROUTES----------------------\n");
    printf("\n1. siwan to gorakhpur       01:00pm-03:10pm      2h 10min\n");
    printf("    ------stops:----- \n");
    printf("\tA. siwan to mairwa         01:00pm-01:45pm\n");
    printf("\tB. mairwa to kaptanganj    01:45pm-03:10pm\n");
    printf("\n2. delhi to patna           03:30pm-04:15am     12h 15min\n");
    printf("    --------stops:------ \n");
    printf("\tA. delhi to kanpur           03:30pm-06:30pm \n");
    printf("\tB. kanpur to prayagraj        06:30pm-11:15pm\n");
    printf("\tC. prayagraj to varanasi      11:15pm-01:00am\n");
    printf("\tD. varanshi to buxar          01:00am-04:15am\n");
    printf("\n3. patna to chhapra         01:00pm-05:30pm      5h 30min\n");
    printf("    -------stops:------ \n");
    printf("\tA. patna to hajipur           01:00pm-02:30pm\n");
    printf("\tB. hajipur to sonpur          02:30pm-05:30pm\n");
    printf("\n4. bhopal to patna          04:10pm-08:10am           16h\n");
    printf("    ------stops:-------- \n");
    printf("\tA. bhopal to sagar            04:10pm-07:10pm\n");
    printf("\tB. sagar to prayagraj         07:10pm-02:10am\n");
    printf("\tC. prayagraj to varansi      02:10am-08:10am\n");
    printf("\n5. gopalganj to chhapra     07:15pm-10:15pm            3h\n");
    printf("    -------stops: --------\n");
    printf("\tA. gopalganj to barauli        07:15pm-8:00pm\n");
    printf("\tB. barauli to mirganj         08:00pm-09:25pm\n");
    printf("\tC. mirganj to siwan         09:25pm-10:15pm\n\n");

    printf("\nselect route(1-5): \n");
    scanf("%d", &location);
    if (location < 1 || location > 5)
    {
        printf("invalid route\n");
        return 0;
    }
    printf("selected routes: %d\n", location);

    do
    {
        printf("\n-----------------------USER MENU---------------------------\n");
        printf("1. book a ticket\n");
        printf("2. cancel a ticket\n");
        printf("3. modify ticket\n");
        printf("4. check bus status\n");
        printf("5. receipt \n");
        printf("6. logout\n");

        printf("enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("available buses: \n");
            for (i = 0; i < 5; i++)
            {
                printf("bus no: %d    busname:   %s      bustype:  %s      seats:  %d        fare:  %d\n "
                    , busnumber[i], busname[i], bustype[i], availableseats[i], fare[i]);
            }

            printf("enter bus number: ");
            scanf("%d", &bus);
            printf("enter seats number: ");
            scanf("%d", &seats);
            if (seats <= 0)
            {
                printf("invalid seats\n");
                break;
            }

            check = 0;

            for (i = 0; i < 5; i++)
            {
                if (busnumber[i] == bus)
                {
                    check = 1;

                    if (availableseats[i] >= seats)
                    {
                        availableseats[i] -= seats;
                        j = i;
                        bookedseats = seats;
                        printf("-----booking successful---- \n");
                        printf("bus number: %d\n", bus);
                        printf("booked seats: %d\n", seats);
                        printf("total fare: %d\n", fare[i] * seats);
                        printf("available seats: %d", availableseats[i]);
                        printf("\n\nselect payment mode: \n");
                        printf("1. UPI\n");
                        printf("2. debit card\n");
                        printf("3. cash\n");
                        printf("enter payment choice: \n");
                        scanf(" %d", &payment);

                        if (payment == 1)
                            printf("payment successful via UPI\n******thank you*****\n");
                        else if (payment == 2)
                            printf("payment successful via debit card\n******thank you*****\n");
                        else if (payment == 3)
                            printf("------------payment successful via cash----------\n******thank you*****\n");

                        else
                        {
                            printf("invalid payment\n");
                            availableseats[i] += seats;
                            j = -1;
                            bookedseats = 0;
                        }
                    }
                    else
                    {
                        printf("seats not available\n");
                    }
                }
            }
            if (check == 0)
                printf("invalid bus number\n");
            break;

        case 2:
            printf("enter bus number: ");
            scanf(" %d", &bus);
            printf("enter seats to cancel: ");
            scanf(" %d", &seats);

            check = 0;
            for (i = 0; i < 5; i++)
            {
                if (busnumber[i] == bus)
                {
                    check = 1;

                    if (i == j && seats <= bookedseats)
                    {
                        availableseats[i] += seats;
                        bookedseats -= seats;
                        if (bookedseats == 0)
                        {
                            j = -1;
                        }

                        printf("-----------cancel successful-----------------\n");
                        printf("available seats: %d\n", availableseats[i]);
                    }
                    else
                        printf("------invalid cancel seats---- \n");
                }
            }
            if (check == 0)
                printf("invalid bus number\n");
            break;

        case 3:
            if (j == -1 || bookedseats == 0)
            {
                printf("no booking \n");
                break;
            }
            printf("current booked seats: %d\n", bookedseats);
            printf("enter new seats \n");
            scanf("%d", &seats);

            if (seats <= 0)
            {
                printf("invalid seats\n");
            }
            else if (availableseats[j] + bookedseats >= seats)
            {
                availableseats[j] =
                    availableseats[j] + bookedseats - seats;

                bookedseats = seats;
                printf("--------------ticket modified successfully----------\n");
                printf("new booked seats: %d\n", bookedseats);
            }
            else
            {
                printf("not seats available\n");
            }
            break;

        case 4:
            printf("enter bus number: \n");
            scanf("%d", &bus);

            check = 0;

            for (i = 0; i < 5; i++)
            {
                if (busnumber[i] == bus)
                {
                    check = 1;

                    printf("bus number:             %d\n", busnumber[i]);
                    printf("total seats:            %d\n", totalseats[i]);
                    printf("available seats:        %d\n", availableseats[i]);
                    printf("fare:                   %d\n", fare[i]);
                }
            }

            if (check == 0)
                printf("invalid bus number\n");
            break;
        case 5:
            printf("------------------BUS BOOKING RECEIPT---------------------\n");
            if (j = -1)

            {

                printf("passenger name:    %s\n", username);
                printf("bus number:        %d\n", busnumber[j]);
                printf("bus name:          %s\n", busname[j]);
                printf("bus type:          %s\n", bustype[j]);
                printf("booked seats:      %d\n", bookedseats);
                printf("total fare:        %d\n", fare[j] * bookedseats);
                printf("available seats:   %d\n", availableseats[j]);
                printf("payment mode:     \n");
                if (payment == 1)
                    printf("UPI\n");
                else if (payment == 2)
                    printf("debit card\n");
                else if (payment == 3)
                    printf("cash\n");
                else
                    printf("unknown\n");

                printf("----------------thank you for booking---------------------- \n");
            }
            else
            {
                printf("---no booked --- \n");
            }
            break;

        case 6:
            printf("------------------logout successful---------------------\n");
            break;

        default:
            printf("invalid choice\n");
        }

    } while (choice != 6);

    return 0;
}