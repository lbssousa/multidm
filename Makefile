# XXX This will soon be replaced by cool autostuff

# If DESTDIR wasn't set, set it now as /
export DESTDIR ?= /
all:
	cd multidm && make
	cd extra-modes/xephyr-mdm && make

install:
	cd multidm && make install
	cd extra-modes/xephyr-mdm && make install

clean:
	cd multidm && make clean
	cd extra-modes/xephyr-mdm && make clean
