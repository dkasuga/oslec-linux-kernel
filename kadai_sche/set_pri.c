#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>

static int 
check_priority(void){
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

int
main(void){
    int rc = 0;

    rc = setpriority(PRIO_PROCESS, 0, -20);
    if(rc < 0){
        printf("Error: setpriority(%d) %s\n", errno, strerror(errno));
        return -1;
    }

    rc = check_priority();
    if(rc != 0) return -1;

    return 0;
}
