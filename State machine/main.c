#include <stdio.h>

typedef enum
{
    INIT_PROCESS,
    DATA_CALCULATING,
    END_PROCESS
} ProcessDataState;

void getNextStage(ProcessDataState *state)
{
    switch (*state)
    {
    case INIT_PROCESS:
        printf("Process ready for use!\n");
        *state = DATA_CALCULATING;
        break;

    case DATA_CALCULATING:
        for (int i = 0; i < 3; i++)
        {
            printf("Data calculating: %d\n", i);
        }
        *state = END_PROCESS;
        break;

    case END_PROCESS:
        printf("Process finished!\n");
        *state = INIT_PROCESS;
        break;
    
    default: 
        printf("Invalid state!");
        break;
    }
}

int main()
{
    ProcessDataState currentState = INIT_PROCESS;

    getNextStage(&currentState);
    getNextStage(&currentState);
    getNextStage(&currentState);

    return 0;
}