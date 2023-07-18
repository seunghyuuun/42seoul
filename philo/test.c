#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int i = 0;
    unsigned int ask = 295967294;

    ask += 4000000000;
    printf("%lu %lu\n", sizeof(unsigned long), sizeof(useconds_t));
    while (i < 5)
    {
        printf("Hello\n");
        usleep(ask);
        i++;
    }
    return (0);
}