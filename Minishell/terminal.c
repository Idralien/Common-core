#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main(void)
{
    char input[256];

    while (1)
    {
/*        printf("\033[H\033[J");
        time_t now = time(NULL);
        char    *time_str = ctime(&now);
        printf("Current Date and Time: %s", time_str);
        printf("Running...");
        fflush(stdout);
        sleep(2);
*/
        printf("Enter a command (or 'exit' to quit): ");

        if (fgets(input, sizeof(input), stdin) != NULL)
        {
            input[strcspn(input, "\n")] = '\0';
            if (strcmp(input, "exit") == 0)
            {
                printf("Exiting...\n");
                break;
            }
            printf("%s\n", input);
        } else {
            printf("Error reading input. Exiting...\n");
            break;
        }
    }
    return (0);
}
