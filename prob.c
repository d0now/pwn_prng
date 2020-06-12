/*
 * $ gcc -o prob prob.c
 * $ gcc -o prob_debug prob.c -DDEBUG
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// Initialize the PRNG.
extern inline void prng_init(time_t seed)
{
    srand(seed);
}

// Get PRNG number.
extern inline int prng_get(void)
{
    return rand();
}

// Give flag to solver by this func.
void give_flag(void)
{
    return;
}

int main(void)
{
    int input, passwd;
    time_t t_now;

    t_now = time(NULL);
    if (t_now == (time_t)-1)
        goto err;

    printf("Now: %ld\n", t_now);
    prng_init(t_now);

    for (int i=0 ; i<10 ; i++)
    {
        // Get password here
        passwd = prng_get();
#ifdef DEBUG
        printf("passwd = %d\n", passwd);
#endif
        // Get input of user
        scanf("%d", &input);
        getchar();

        // Check input
        if (input != passwd) {
            printf("Wrong: %d\n", input);
            goto done;
        }
    }

    puts("Good Job!");
    give_flag();

done:
    return 0;

err:
    puts("Unknown error occured.");
    return -1;
}