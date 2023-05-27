.global reset_section
reset_section:
	ldr sp, = stack_top
	bl main
	
stop: b stop
