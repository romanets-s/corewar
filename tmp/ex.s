.name "zork"
.comment "42just a basic living prog"

live %5

sti: live %0

l2:	sti	r1,%:live,%0
	and	r1,%0,r1
live:	live	%1
	zjmp	%:live
