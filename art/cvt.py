#!/usr/bin/python

import os

files = os.listdir('.')
pngs = [ x for x in files if len(x)==6 and ".png" in x ]
pngs.sort()

cnt = len( pngs )

i=0
while i < cnt :
	oname = "row%03d.png" % ( i, )
	cmd = "convert +append "
	for j in range(16) :
		if i+j < cnt :
			cmd += pngs[ i+j ]
			cmd += " "
	cmd += oname
	print cmd
	os.system(cmd)
	i += 16

cmd = "convert -append row*png flagatlas.png"
os.system(cmd)

print [ x.split('.')[0] for x in pngs ]

