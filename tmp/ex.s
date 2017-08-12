.name "zork"
.comment "42just a basic living prog"

sti: live %0

live %123

l2:	sti	r1,%:sti,%0
	and	r1,%0,r1
live:	live	%1
	zjmp	%:live
