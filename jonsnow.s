.name "Jon Snow. King of the North"
.comment "You know nothing, Jon Snow"

	sti		r1, %:nightswatch, %1
	sti		r1, %:winterfell, %1
	sti 	r1, %:dragonglass, %1
	fork	%:winterfell
	sti		r1,%:jonsnowalive,%1
	sti		r1,%:l1,%1
	sti		r1,%:l2,%1
	sti		r1,%:l3,%1
	sti		r1,%:l4,%1
	sti     r1, %:lfork, %1
	sti     r1, %:lfork, %9
	sti     r1, %:lfork, %17


nightswatch:
	live	%13
	st		r2, -9
	st		r2, -18
	st		r2, -27
	st		r2, -36
	st		r2, -45
	st		r2, -54
	st		r2, -63
	st		r2, -72
	st		r2, -81
	st		r2, -90
	st		r2, -99
	st		r2, -108
	st		r2, -117
	st		r2, -126
	st		r2, -135
	st		r2, -144
	st		r2, -153
	st		r2, -162
	st		r2, -171
	st		r2, -180
	st		r2, -189
	st		r2, -198
	st		r2, -207
	st		r2, -216
	st		r2, -225
	st		r2, -234
	st		r2, -243
	st		r2, -252
	st		r2, -261
	st		r2, -270
	st		r2, -279
	st		r2, -288
	st		r2, -297
	st		r2, -306
	st		r2, -315
	st		r2, -324
	st		r2, -333
	st		r2, -342
	st		r2, 294
	st		r2, 293
	st		r2, 292
	st		r2, 291
	st		r2, 290
	st		r2, 289
	st		r2, 288
	st		r2, 287
	st		r2, 286
	st		r2, 285
	st		r2, 284
	st		r2, 283
	st		r2, 282
	st		r2, 281
	st		r2, 280
	st		r2, 279
	st		r2, 278
	st		r2, 277
	st		r2, 276
	st		r2, 275
	st		r2, 274
	st		r2, 273
	st		r2, 272
	st		r2, 271
	st		r2, 270
	st		r2, 269
	st		r2, 268
	st		r2, 267
	st		r2, 266
	st		r2, 265
	st		r2, 264
	st		r2, 263
	st		r2, 262
	st		r2, 261
	st		r2, 260
	st		r2, 259
	st		r2, 258
	ld		%0, r2
	zjmp	%:nightswatch

winterfell:
	live	%13
	fork	%:winterfell
	live	%13
	fork	%:dragonglass
	live	%13
	fork	%:nightswatch
	live	%13
	fork	%:dragonglass

jonsnowalive:		
			live 	%13
l1:		
			live 	%13
l2:		
			live 	%13
l3:		
			live 	%13
l4:		
			live 	%13
			ld		%0, r2
			zjmp	%:jonsnowalive
dragonglass:
	live	%13
	fork 	%:nightswatch	

lfork:
	live	%34	
	lfork	%925
	live    %567
	lfork   %1941
	live    %689
	lfork   %2957
	
