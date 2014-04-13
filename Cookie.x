struct input_data {
	int isTina;
};

typedef struct input_data input_data;

program COOKIE {
	version COOKIE_1 {
		int GET_COOKIE(input_data) = 1;
	} = 1;
} = 33633;