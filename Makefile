# XXX This will soon be replaced by cool autostuff

# If DESTDIR wasn't set, set it now as /
export DESTDIR ?= /
all:
	cd mdm && make
	cd extra-modes/xephyr-gdm && make

install:
	cd mdm && make install
	cd extra-modes/xephyr-gdm && make install

clean:
	cd mdm && make clean
	cd extra-modes/xephyr-gdm && make clean
