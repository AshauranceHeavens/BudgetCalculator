#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    struct tm * ptr;
    time_t lt;
    lt = time(NULL);
    ptr = localtime(&lt);

    char userinput;
    char usersalary[20];
    char items[20];
    int controller = 0;
    double price = 0;
    char price2[20];
    char list[50];
    int i = 0;
    int j = 1;
    int y = 0;
    double usertotal;
    double useravailable;
    char filecont[500];
    int v = 0;


    system("color 02");

    printf("Welcome!\n");
    printf("What would you like to do?\n");
    printf("A = Budget calculator.\n");
    printf("B = View previous budget.\n");
    printf("C = Delete the previous budget file.\n");
    printf("D = Learn more about the application\n");
    scanf("%c", &userinput);

    switch(userinput){
    case 'a' :case 'A' :
        system("color 02");
        printf("Budget calculator\n");
        printf("Please enter your monthly income: \n");
        printf("R");
        scanf("%s", usersalary);

        while(i < strlen(usersalary) ){
            if(usersalary[i] > 47 && usersalary[i] < 58){
                controller++;
            }else{
                controller--;
            }
            i++;
        }

        if(controller == strlen(usersalary) ){
            controller = 0;
            i = 0;

                controller = 0;
                printf("Enter your items and their prices below: \n");
                printf("Example: \"Item:Ice_cream \nPrice:R2000\"\n");
                int sandile = 0;

                //THIS CODE PRINTS TIME IN A FILE
                FILE * fpointer = fopen("budget file.txt", "a");

                fprintf(fpointer, "%s\n", asctime(ptr));

                fclose(fpointer);

                    while(list != 35 && sandile == 0){
                        printf("Item: \n");
                        scanf("%s", list);

                        //this while loop is not be executed for some reason, leading to an error
                        //test();
                        int mini = 0;
                         if(list != NULL){
                                for(v = 0; v < strlen(list); v++){
                                    if( (list[v] > 96 && list[v] < 123) || (list[v] > 64 && list[v] < 91) || ( list[v] == 45 || list[v] == 95) || list[v] == 39){
                                         controller++;
                                         //printf("index position previous to %d\n", v);
                                    }else if(list[v] == 35){
                                        printf("breaking 1...\n");
                                        controller++;
                                        mini = 1;
                                        break;
                                    }else{
                                        controller--;
                                    }

                                }
                         }else{
                             printf("Error A!");
                         }

                        if( controller == strlen(list) && mini != 1){
                            controller = 0;
                            i = 0;
                            printf("Price: R\n");
                            scanf("%s", price2);
                            while(i < strlen(price2) ){
                                if(price2[i] > 47 && price2[i] < 58){
                                    controller++;
                                }else{
                                    controller--;
                                }
                                i++;
                            }

                            if( controller == strlen(price2)){
                                printf("---%d %s : R%.2f\n", j, list, atof(price2) );
                                usertotal = usertotal + atof(price2);
                                controller = 0;

                            }else{
                                system("color 04");
                                printf("Error 1!\nA non numeric value was entered.\n");
                                printf("Calculations cannot proceed.\n");
                                sandile = 1;
                            }
                        }else if(mini == 1){
                            printf("breaking number unknown...\n");
                            break;
                        }else{
                            system("color 04");
                            printf("Error 2!\nA numeric value was entered.\n");
                            printf("Calculations cannot proceed.\n");
                            //system("pause");
                            //system("exit");
                            sandile = 1;
                        }
                        j++;
                        y++;

                        FILE * fpointer = fopen("budget file.txt", "a");
                        //THERE SHOULD BE A CODE HERE THAT PRINTS SYSTEM TIME AND SYSTEM DATE TO THE FILE

                        fprintf(fpointer, "%s: R%.2f\n", list, atof(price2));

                        fclose(fpointer);
                    }
                    useravailable = atof(usersalary) - usertotal;

                     fpointer = fopen("budget file.txt", "a");

                    fprintf(fpointer, "Please note that if the value of \'total expenses\' is a \nnegative value it means you are short with the amount displayed\n");
                    fprintf(fpointer, "For the above calculations your income was: R%.2f\n", atof(usersalary));
                    fprintf(fpointer, "Your total expenses were: R%.2f\n", usertotal);
                    fprintf(fpointer, "You were left with: R%.2f\n\n\n", useravailable);
                    fprintf(fpointer, "************************************\n\n\n\n\n");


                    fclose(fpointer);

                    if(useravailable < 0){
                        system("color 0c");
                        printf("You do not have enough funds to afford all the items above\n");
                        printf("You wish to spend R%.2f\n", usertotal);
                        printf("Your income is R%.2f\n", atof(usersalary));
                        printf("You are short with +/-R%.2f\n", useravailable);

                    }else if(sandile == 0){
                        system("color 06");
                        printf("With your current budget you will spend R%.2f ", usertotal);
                        printf("and be left with R%.2f \n", useravailable);
                    }else{
                        //nothing
                    }
               // }
            //}else{
                //system("color 04");
                //printf("Error 3!\nA non numeric value was entered.\n");
                //printf("Calculations cannot proceed.\n");
            }else{
                system("color 04");
                printf("Error number Unknown: You entered a letter(s) instead of a number.\n");
            }
        //}else{
            //system("color 04");
            //printf("Error 4!\nA non numeric value was entered.\n");
            //printf("Calculations cannot proceed.\n");
        //}




        break;

      case 'b' :case 'B' :
             system("color 0e");
             printf("Previous budget(s):\n\n");


             FILE * fpointer = fopen("budget file.txt", "r");

             while(fgets(filecont, 500, fpointer) != NULL){
                printf("%s", filecont);
             }
               //printf("%s", filecont);

             fclose(fpointer);


             break;
        case 'c': case 'C':
            system("color 0b");
            fpointer = fopen("budget file.txt", "w");

            fclose(fpointer);
            printf("Previous budget(s) deleted!.\n");
            break;
        case 'd': case 'D':
            system("color 07");
            printf("Selecting \'A\' will allow you access to the budget calculator.\n");
            printf("In the budget calculator these are the only characters allowed:\n");
            printf("  Under \'items\' you can only enter characters: \'A - Z\' , \'a - z\' , \'-\' , \'_\' and (') .\n");
            printf("  The character \'#\' is allowed in items but it is used to tell the program to start calculating.\n");
            printf("  It is recommended to use the \(#\)when all the needed items have been entered\n");
            printf("  and the user is ready for the exe application to start calculating.\n");
            printf("  NB: Do not enter the \(#\) under price R.\n");
            printf("  NB: No numbers are allowed in items and no spaces are allowed.\n");
            printf("  If you need to make a space(s), use the characters \'-\' and \'_\'.\n\n");
            printf("selecting \'B\' will let you view previous budget(s).\n");
            printf("  You cannot modify previous budget(s), you can only delete them(Unless you do the modification directly on the file,\n  which is not recommended).\n");
            printf("  Modifying the budget directly from the file may result in INCORRECT calculations, therefore it is not recommended.\n");
            printf("  Rather delete the file and write a new budget through the use of the exe application.\n\n");
            printf("Selecting \'C\' will delete the budget file\n");
            printf("  file deletion or budget deletion is done WITHOUT WARNING, so please be careful.\n\n");
            printf("Selecting \'D\' lets you learn more about the budget calculator.\n");
            break;
        default:
            printf("Unknown entry, sorry!");
    }

    system("pause");


    return 0;
}
