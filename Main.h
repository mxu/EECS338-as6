#include <time.h>

char buf[64];

time_t c_time(time_t *t) {
    time_t time_val = time(t);
    if(time_val == ((time_t) -1)) {
        perror("time");
        exit(EXIT_FAILURE);
    }
    return time_val;
}

void printInfo(char *pname, char *msg) {
	char hostname[255];
	if(gethostname(hostname, 255) == -1) perror("Hostname error");
    printf(" %-10d | %-8s | %-6s | %s\n", (int) c_time(NULL), hostname, pname, msg);
    fflush(stdout);
}