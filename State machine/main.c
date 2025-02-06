#include <stdio.h>

enum dataStates
{
    INIT_PROCESS,
    DATA_CALCULATING,
    END_PROCESS
} state;

enum processEvents
{
    START_CALCULATING,
    CALCULATE_DATA,
    STOP_CALCULATING
} event;

void getNextStage(enum processEvents event)
{
    switch (state) 
    {
        case INIT_PROCESS: //INIT_PROCESS sets by default (0), if not explicitly set
            switch (event) {
                case START_CALCULATING: 
                    printf("Process ready for use!\n");
                    state = DATA_CALCULATING;
                    break;

                default:
                    printf("Used wrong event: (%d)!\n", event);
                    break;
                }
        break;

        case DATA_CALCULATING:
            switch (event) {
                case CALCULATE_DATA:
                    for (int i = 1; i <= 3; i++)
                    {
                        printf("Data calculating: %d\n", i);
                    }
                    break;

                case STOP_CALCULATING:
                    printf("Calculation stopped!\n");
                    state = END_PROCESS;
                    break;

                default:
                    printf("Used wrong event: (%d)!\n", event);
                    break;
                }
        break;

        case END_PROCESS:
            printf("Process finished!\n");
            state = INIT_PROCESS;
            break;

    default:
        printf("Invalid state!");
        break;
    }
}

//Some simulation of data processing, also would be cool to add some INPUT event 
// for interaction.

int main()
{
    getNextStage(START_CALCULATING);
    getNextStage(CALCULATE_DATA);
    getNextStage(STOP_CALCULATING);
    getNextStage(START_CALCULATING);
    return 0;
}