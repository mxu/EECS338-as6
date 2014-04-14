#include <stdio.h>
#include <stdlib.h>
#include "Cookie.h"
#include "Main.h"

static int cookies = 20;
static int tinaCount = 0;
static int tinaEmpty = 0;
static int judyEmpty = 0;
static int ret;

int * get_cookie_1(input_data *input, CLIENT *client) {
    int isTina = input->isTina;		/* 1 = Tina, 0 = Judy */
    if(cookies > 0) {				/* As long as there are cookies left... */
	    if(isTina == 1) {
	    	ret = 1;				/* Tina gets a cookie whenever she wants */
	    	cookies--;
	    	tinaCount++;			/* Number of cookies since Judy got one */
	    	printInfo("Mother", "Cookie for Tina");
	    } else {
	    	if(tinaCount > 1) {		/* If Tina has had at least 2 cookies... */
	    		ret = 1;			/* Judy gets a cookie */
	    		cookies--;
	    		printInfo("Mother", "Cookie for Judy");
	    		tinaCount = 0;		/* Reset Tina's cookie count */
	    	} else {
	    		ret = -1;			/* No cookie for Judy until Tina has more*/
	    		sprintf(buf, "Tina needs %d more before Judy", 2 - tinaCount);
	    		printInfo("Mother", buf);
	    	}
	    }
	} else {						/* No cookies left in the jar */
		ret = -2;
		if(isTina == 1) {
			tinaEmpty = 1;			/* Tina knows there are none left */
			printInfo("Mother", "No more cookies Tina");
		} else {
			judyEmpty = 1;			/* Judy knows there are none left */
			printInfo("Mother", "No more cookies Judy");
		}
	}
    sprintf(buf, "%d cookies remaining", cookies);
    printInfo("Mother", buf);

    return(&ret);
}

int * get_cookie_1_svc(input_data *input, struct svc_req *svc) {
    CLIENT *client;
    return(get_cookie_1(input, client));
}