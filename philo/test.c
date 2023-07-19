#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

int main(void)
{
    int i = 0;
    unsigned int ask = 295967294;
    struct timeval time;
    unsigned long long sec;
    unsigned int mil;

    ask += 4000000000;
    printf("%lu %lu\n", sizeof(unsigned long), sizeof(useconds_t));
    printf("%lu %lu\n", sizeof(time.tv_sec), sizeof(time.tv_usec));
    while (i < 5)
    {
        gettimeofday(&time, 0);
        sec = time.tv_sec;
        mil = time.tv_usec / 1000000;
        sec += (unsigned long long)mil;
        printf("%llu\n", sec);
        usleep(ask);
        i++;
    }
    return (0);
}