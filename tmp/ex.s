.name "zork"
.comment "42just a basic living prog"

sti: sti	r1,%:live,%:l2

l2:	sti	r1,%:live,%0 #sdf
	and	r1,%0,r1
live:	live	%1
	zjmp	%1
