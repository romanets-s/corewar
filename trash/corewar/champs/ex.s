.name "zork"
.comment "just a basic living prog"
	


l2:	sti	r1,%:lslsl,%0
	and	r1,%0,r1
	live %:lslsl

lslsl: live %3

live:	live %:lslsl
live	%1
	
	zjmp	%:live
