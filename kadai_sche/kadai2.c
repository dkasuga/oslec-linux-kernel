#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sched.h>


void 
check_scheduler_policy(int pid){
    int policy;
    policy = sched_getscheduler(pid);

    switch(policy){
        case SCHED_OTHER: printf("SCHED_OTHER\n"); break;
        case SCHED_RR:   printf("SCHED_RR\n"); break;
        case SCHED_FIFO:  printf("SCHED_FIFO\n"); break;
        default:   printf("Unknown...\n");
    }
}

int
main(){
    struct sched_param param;
    int pid = 0;
    int ret;
    int policy;

    printf("Original Scheduler Policy:");
    check_scheduler_policy(pid);

    param.sched_priority = 99;
    ret = sched_setscheduler(pid, SCHED_FIFO, &param);

    if(ret == -1){
        perror("sched_setscheduler");
        return 1;
    }

    printf("New Scheduler Policy:");
    check_scheduler_policy(pid);


    return 0;
}
