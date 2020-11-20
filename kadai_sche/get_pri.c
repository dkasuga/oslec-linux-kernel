#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>

int
main(void){
    int prio=0;

    /* need to set errno to 0 */
    errno = 0;

    prio = getpriority(PRIO_PROCESS, 0);
    if(errno != 0){
        printf("Error: getpriority(%d)%s\n", errno, strerror(errno));
        return(-1);
    }
    printf("priority=%d\n",prio);

    return 0;
}
