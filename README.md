# gpg-c-wrapper
Wraps 'c' and 'h' files with a gpg signature.

The public gpg key gcw_public_key.asc should be used to
verify any files in this project. If you haven't imported
it to your keyring, do

  gpg --import gcw_public_key.asc

This package uses *.gcw files to represent signed 'c' and 'h' files,
which by definition have their fourth line of the form:

    // GCW: name-of-file

See hello_world.c.gcw as an example.

To build and test, do

    make clean
    make

If all goes well, you should see:

gcc -o gcw_filename gcw_filename.c
gcc -o gcw_add_filename gcw_add_filename.c
rm -f hello_world.c
./gcw-extract.sh hello_world.c.gcw
make[1]: Entering directory `/tlrs/pi/gpg-c-wrapper'
make[1]: `gcw_filename' is up to date.
make[1]: Leaving directory `/tlrs/pi/gpg-c-wrapper'
hello_world.c.gcw
gpg: Signature made Fri 26 Aug 2016 09:23:41 AM EDT using RSA key ID 928DD135
gpg: Good signature from "Cal Page <page.cal@gmail.com>"
gcc -o hello_world hello_world.c
./hello_world
Hello World

There are three .sh executable files here. Here is the documentation

./gcw-extract.sh filename.gcw

  This tool extracts the file from the gcw file.

./gcw-verify.sh filename.gcw

  This tool verifies the gcw file against the public key provided.

./gcw-sign.sh filename

  This tool produces a .gcw file of the name name.

After the make, you are left with three executables. Here is the
documentation.

hello_world

  This prints out 'Hello World'

gcw_filename

  This extracts the original file name from the gcw file.

gcw_add_filename

  This makes sure filename is formated so it can be converted to a gcw file.
