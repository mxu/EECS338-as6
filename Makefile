BIN = Mother Tina Judy
GEN = Cookie_clnt.c Cookie_svc.c Cookie_xdr.c Cookie.h
RPCCOM = rpcgen

all: $(BIN)

Tina: Tina.o Cookie_clnt.o Cookie_xdr.o
	$(CC) -o $@ Tina.o Cookie_clnt.o Cookie_xdr.o

Tina.o: Tina.c Cookie.h
	$(CC) -g Tina.c -c

Judy: Judy.o Cookie_clnt.o Cookie_xdr.o
	$(CC) -o $@ Judy.o Cookie_clnt.o Cookie_xdr.o

Judy.o: Judy.c Cookie.h
	$(CC) -g Judy.c -c

Mother: Mother.o Cookie_svc.o Cookie_xdr.o
	$(CC) -o $@ Mother.o Cookie_svc.o Cookie_xdr.o

Mother.o: Mother.c Cookie.h

$(GEN): Cookie.x
	$(RPCCOM) Cookie.x

clean:
	rm -f $(GEN) *.o $(BIN)