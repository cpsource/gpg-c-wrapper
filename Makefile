
all:	gcw_filename gcw_add_filename hello_world

gcw_filename: gcw_filename.c gcw.h
	gcc -o gcw_filename gcw_filename.c

gcw_add_filename: gcw_add_filename.c gcw.h
	gcc -o gcw_add_filename gcw_add_filename.c

hello_world: hello_world.c.gcw
	-rm -f hello_world.c
	./gcw-extract.sh hello_world.c.gcw
	gcc -o hello_world hello_world.c
	./hello_world

clean:
	rm -f *~ *.o *# hello_world gcw_filename gcw_add_filename t
	rm -f hello_world.c
