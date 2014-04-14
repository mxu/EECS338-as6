#include <stdio.h>
#include <stdlib.h>
#include "Cookie.h"
#include "Main.h"

void judy(char *host, int argc, char *argv[]) {
    CLIENT *client;
    int cookies;	/* number of cookies Judy has gotten */
    int *result_1;	/* RPC return value */
    input_data arg;	/* RPC argument data structure */
    arg.isTina = 0;	/* indicate that this is Judy, not Judy */

    /* create client */
    client = clnt_create(host, COOKIE, COOKIE_1, "udp");
    if(client == NULL) {
        clnt_pcreateerror(host);
        exit(1);
    }

    cookies = 0;
    /* try to cookies until Mother says there are no more */
    do {
    	/* wait up to 5 seconds */
		sleep(rand() % 5);
    	printInfo("Judy", "Asking mother for a cookie");
    	/* try to get a cookie */
	    result_1 = get_cookie_1(&arg, client);
	    if(result_1 == NULL)
	    	clnt_perror(client, "RPC failed:");
	    else if(*result_1 == 1) {
	    	cookies++;
		 	printInfo("Judy", "Got a cookie from Mother");
		} else if(*result_1 == -1)
			printInfo("Judy", "Wait for Tina to get more cookies");
	} while(*result_1 != -2);

	printInfo("Judy", "Mother says no more cookies");
	sprintf(buf, "Got %d cookies", cookies);
	printInfo("Judy", buf);
	/* destroy the client */
    clnt_destroy(client);
}

main(int argc, char* argv[]) {
    char *host;
    if(argc > 1)
	    host = argv[1];
	else
		host = "localhost";
	
    judy(host, argc, argv);
    return(0);
}