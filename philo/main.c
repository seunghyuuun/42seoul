#include "philo.h"

int main(int argc, char **argv)
{
    t_rule rules;
    t_phil *plist;
    unsigned int i;

    if (argc != 5 && argc != 6)
        return (-1);
    initset(&plist, &rules, argc, argv);
    i = 0;
    while (i < rules.num_of_phil)
    {
        pthread_create(plist[i].thread, 0, aa/*함수*/, &(plist[i]));
        i++;
    }
    return (0);
}

// 상태를 실시간으로 송출하는 함수를 만들기. mutex로 겹치지 않도록, while문. 상태변경후 출력이 안 된 것이 있는지의 플래그를 구조체에 넣기. 가장 먼저 굶어죽었는지 확인.
// 포크를 복제하지 않도록, 포크가 없다면 먹지않도록 하는 법? 포크 플래그배열. 식사입장을 mutex를 통해 겹치지 않도록.