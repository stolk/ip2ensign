# ip2ensign

Converts an IP number to a flag image in a texture atlas.

Simply pass in an ip address and this code will look up the country in which the IP resides.
It then looks up a flag for this country in a 16x16 texture atlas, returning the proper UV coordinates for rendering the flag.

To do this it has access to an internal database of IP ranges, so no online network access is required to use this.

Output:
```
$ make
cc -c -Wall ip2ensign.c
cc -o tst-ip2ensign tst-ip2ensign.c ip2ensign.o
./tst-ip2ensign
www.stolk.org is in us and has UV=0.093750,0.906250
www.rogers.ca is in ca and has UV=0.281250,0.156250
www.ferrari.it is in it and has UV=0.656250,0.406250
www.shell.com is in us and has UV=0.093750,0.906250
www.bbc.co.uk is in uk and has UV=0.031250,0.906250
```

![Screenshot](/art/flagatlas.png)
<br>
The texture atlas with flag images.

![Screenshot](/screenshot/US-versus-CA.png)
<br>
Example use of ip2ensign in an online game.

## TODO
* Only tested on LSB architecture. May not work on MSB.
* Should maybe return four UV coordinates, not just one? For now, opposite corner is at +1/16, +1/16.

