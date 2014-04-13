#include <stdio.h>
#include <stdlib.h>
#include "Cookie.h"

static int ret;

int * get_cookie_1(input_data *input, CLIENT *client) {
    int isTina = input->isTina;
    if(isTina == 1) ret = 1;
    else ret = -1;
    return(&ret);
}

int * get_cookie_1_svc(input_data *input, struct svc_req *svc) {
    CLIENT *client;
    return(get_cookie_1(input, client));
}