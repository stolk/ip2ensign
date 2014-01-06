ip2ensign
=========

Converts an IP number to a flag image in a texture atlas.

Simply pass in an ip address and this code look up the country in which the IP resides.
It then looks up a flag for this country in a 16x16 texture atlas, returning the proper UV coordinates for rendering the flag.

To do this it has access to an internal database of IP ranges, so no online network access is required to use this.

