
Make sure all the Folders are in Desktop/SimpleScalar

f2c-1994.09.27
gcc-2.7.2.3
glibc-1.09
simplesim-3.0
simpleutils-990811
ssbig-na-sstrix
sslittle-na-sstrix

open terminal inside Desktop/SimpleScalar then follow along the steps

Step 1:

export IDIR=~/Desktop/SimpleScalar
export HOST=i686-pc-linux
export TARGET=sslittle-na-sstrix
cd $IDIR

Step 2:

cd $IDIR/simpleutils-990811
sed -i 's/yy_current_buffer/YY_CURRENT_BUFFER/g' ld/ldlex.l
./configure --host=$HOST --target=$TARGET --with-gnu-as --with-gnu-ld --prefix=$IDIR
make CFLAGS=-O
make install

Step 3:

cd $IDIR/simplesim-3.0
make config-pisa
make

Step 4:

#replace ar & ranlib (inside sslittle-na-sstrix/bin/)

cd $IDIR/gcc-2.7.2.3
./configure --host=$HOST --target=$TARGET --with-gnu-as --with-gnu-ld --prefix=$IDIR
chmod -R +w .

make LANGUAGES=c CFLAGS=-O CC="gcc -m64" (#this will obviously give error)

#replace insn-output.c (inside gcc-2.7.2.3)
#replace gcc.c (inside gcc-2.7.2.3)

make LANGUAGES=c CFLAGS=-O CC="gcc -m64" (#run again)

#edit Makefile at line #130 & append -I/usr/include to the end of that line.

make LANGUAGES=c CFLAGS=-O CC="gcc -m64" (#run again)

Step 5:

cp ./patched/sys/cdefs.h ../sslittle-na-sstrix/include/sys/cdefs.h
cp ../sslittle-na-sstrix/lib/libc.a ../lib/
cp ../sslittle-na-sstrix/lib/crt0.o ../lib/ 

make LANGUAGES=c CFLAGS=-O CC="gcc -m64" install

#copy/move hello.c (inside gcc-2.7.2.3)

$IDIR/bin/sslittle-na-sstrix-gcc -o hello hello.c 

$IDIR/simplesim-3.0/sim-safe hello

done
