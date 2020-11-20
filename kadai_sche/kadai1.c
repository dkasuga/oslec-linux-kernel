#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>

int
main(void){
    int rc = 0;

    rc = setpriority(PRIO_PROCESS, 0, -20);
    if(rc < 0){
        printf("Error: setpriority(%d) %s\n", errno, strerror(errno));
        return -1;
    }

    return 0;
}
