CFLAGS=-O2 -Wall -pedantic -fno-common -Wl,-z,defs,-z,relro,-z,now -fstack-protector-strong -fstack-clash-protection

all: pwsec.c
	$(CC) -s $(CFLAGS) -o pwsec pwsec.c

strip:
	strip -s -R .comment -R .GCC.command.line pwsec

clean:
	$(RM) pwsec

test: all
	./pwsec
	./pwsec|grep  -E '^.{20}$$'
