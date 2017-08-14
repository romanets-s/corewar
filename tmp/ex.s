.name "zork"
.comment "42just a basic living prog"

l1:

sti: sti	r1,%:l3,%:l2

l2:	sti	r1,%:live,%:l1#sdf
	and	r1,%0,r1
live:	live	%1
	zjmp	%:l3


l3: live %:l1

live %:l2

l5:#lsjflsf