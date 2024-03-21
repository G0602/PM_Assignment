#include "../glbl_vars.h"
#include "menu.h"
#include "../data/data.h"

int seed; //seed value for the ran function
int n; // to see the details of the Es
bool s; // for returning to menu
char *temp; //to store the temperory pointer values

bool mainMenu(void){

    int mo1;// main menu option

    top:

    printf("Main Menu:\n");
    printf("\t1. Start Simulation\n");
    printf("\t2. View Instructions\n");
    printf("\t3. Simulation Statistics\n");
    printf("\t4. Exit\n\n");
    printf("Enter Your Choice: ");
    scanf("%d", &mo1);

    switch(mo1){
        case 1: s = opt1();
                if (s == 1){
                    s = 0;
                    goto top;
                }
                return 0;// this will start the simulation
        case 2: opt2();
                goto top;
        case 3: opt3();
                goto top;
        case 4: return 1; //this will exit the programm

        default  : printf("\nWrong entry please enter the correct number.\n");
                goto top;
    }
}

bool opt1(void){

    int mo2;// simulation option

    middle:

    printf("Simulation Options:\n");
    printf("\t1. Setup\n");
    printf("\t2. Run Simulation\n");
    printf("\t3. Go back\n\n");
    printf("Enter Your Choice: ");
    scanf(" %d", &mo2);
    switch(mo2){
        case 1: s = subMenu();
                if (s == 1){
                    s = 0;
                    return 1;
                }
                goto middle;
        case 2: return 0;

        case 3: return 1;

        default  : printf("\nWrong entry please enter the correct number.\n");
                goto middle;
    }
}

void opt2(void){
    //function to display instructions
    printf("Upcomming cange\n");
}

//function to display files and select them
void opt3(void){
    temp = btlList();
    if (temp != NULL){
        selBtl(temp);
        temp = NULL;
    }
    //not finisded
}


bool subMenu(void){
    last:
    int smo = 0;// sub menu option
    char cho; //to get user decision
    printf("Setup Options:\n");
    printf("\t1. Battle ship Properties\n");
    printf("\t2. Escort ship Properties\n");
    printf("\t3. Seed value\n");
    printf("\t4. Go back\n");
    printf("\t5. Return to Main Menu\n\n");
    printf("Enter Your Choice: ");
    scanf(" %d", &smo);
    switch(smo){
        case 1: B_Dtl( stdout);
                cho1:
                printf("Would you like to change anything?(y/n)\n");
                scanf("%c",&cho);
                if(cho == 'y'){

                } else if (cho == 'n'){
                    n = '\0';
                } else {
                    printf("\nNot a valid choice.\n");
                    goto cho1;
                }
                break;

        case 2: printf("Enter the number of the escort ship you want to see the details of (1 - %d).\nEnter 0 if you want to see the details of all the escort ships: ", N);
                scanf(" %d", &n);
                for(int i = 0; i < N; i++){
                    if(i != n-1 && n != 0){
                        continue;
                    }
                    E_Dtl(i, stdout);
                }
                cho2:
                printf("Would you like to change anything?(y/n)\n");
                scanf("%c", &cho);
                if(cho == 'y'){

                } else if (cho == 'n'){
                    n = '\0';
                } else {
                    printf("\nNot a valid choice.\n");
                    goto cho2;
                }
                break;

        case 3: printf("Enter the new seed value for the random number generator:\n");
                scanf("%d", &seed);
                srand(seed);
                break;

        case 4: break;

        case 5: return 1;

        default: printf("\nWrong entry please enter the correct number.\n");
                goto last;
    }
    return 0;
}