/*
ret = 0;
while(ret != -2) {
	GetMeMyCookie(&ret, false);
	if(ret == -1) {
		printf("No cookie for judy\n");
	} else if(ret == 1) {
		printf("Got a cookie\n");
	}
	sleep(rand() % 5);
}
printf("terminating");
*/

#include <stdio.h>
#include <stdlib.h>
#include "Cookie.h"

void tina(char *host, int argc, char *argv[]) {
    CLIENT *client;
    int *result_1;
    input_data arg;
    arg.isTina = 0;

    client = clnt_create(host, COOKIE, COOKIE_1, "udp");
    if(client == NULL) {
        clnt_pcreateerror(host);
        exit(1);
    }

    result_1 = get_cookie_1(&arg, client);
    if(result_1 == NULL) {
        clnt_perror(client, "RPC failed:");
    }

    clnt_destroy(client);
    printf("Result = %d\n", *result_1);
}

main(int argc, char* argv[]) {
    char *host;
    host = argv[1];
    tina(host, argc, argv);
}