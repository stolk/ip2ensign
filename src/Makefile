run: tst-ip2ensign
	./tst-ip2ensign

tst-ip2ensign: tst-ip2ensign.c ip2ensign.o
	cc -std=c99 -o tst-ip2ensign tst-ip2ensign.c ip2ensign.o

ip2ensign.o: ip2ensign.c iptable.inl
	cc -std=c99 -c -Wall ip2ensign.c

iptable.inl: ../scripts/mkiptable.py
	../scripts/mkiptable.py > iptable.inl

