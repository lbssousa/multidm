#!/bin/bash

# Copyright (C) 2004-2007 Centro de Computacao Cientifica e Software Livre
# Departamento de Informatica - Universidade Federal do Parana - C3SL/UFPR
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
# USA.

set -e

# XXX: get these from multidm-common

TARGET=tree/
BASE_DIR=/

MULTIDM_LOGS=$BASE_DIR/var/log/multidm/
MULTIDM_ETC=$BASE_DIR/etc/multidm/
MULTIDM_SHARE=$BASE_DIR/usr/share/multidm/
MULTIDM_SCRIPTS=$BASE_DIR/usr/sbin/
MULTIDM_LOCALE=$BASE_DIR/usr/share/locale/

CONFIG_FILE=$MULTIDM_ETC/multidm.conf

MULTIDM_DEVICES=$MULTIDM_ETC/devices/
MULTIDM_MODES=$MULTIDM_SHARE/modes/

INITD=/etc/init.d

rm -rf   $TARGET
mkdir -p $TARGET

mkdir -p $TARGET/$MULTIDM_LOGS
mkdir -p $TARGET/$MULTIDM_ETC
mkdir -p $TARGET/$MULTIDM_SHARE
mkdir -p $TARGET/$MULTIDM_SCRIPTS

mkdir -p $TARGET/$MULTIDM_DEVICES

mkdir -p   $TARGET/$INITD
cp src/multidm $TARGET/$INITD

cp src/multidm-bin                  $TARGET/$MULTIDM_SCRIPTS/
cp src/multidm-common               $TARGET/$MULTIDM_SCRIPTS/
cp src/multidm-start-seat           $TARGET/$MULTIDM_SCRIPTS/
cp src/create-xorg-conf         $TARGET/$MULTIDM_SCRIPTS/
cp src/xrandr-functions         $TARGET/$MULTIDM_SCRIPTS/
cp src/write-message            $TARGET/$MULTIDM_SCRIPTS/
cp src/xephyr-wrapper           $TARGET/$MULTIDM_SCRIPTS/
cp src/seat-parent-window       $TARGET/$MULTIDM_SCRIPTS/
cp src/read-devices             $TARGET/$MULTIDM_SCRIPTS/
cp src/discover-devices         $TARGET/$MULTIDM_SCRIPTS/
cp src/multidm-start-monoseat       $TARGET/$MULTIDM_SCRIPTS/
cp -r modes                     $TARGET/$MULTIDM_SHARE/
cp config/multidm.conf              $TARGET/$MULTIDM_ETC/

#Creating and moving .mo files to their directory.

for LANGUAGE in $(ls po/*.po | cut -d'/' -f2 | cut -d'.' -f1); do

        mkdir -p $TARGET/$MULTIDM_LOCALE/$LANGUAGE/LC_MESSAGES/
        cp po/$LANGUAGE.mo $TARGET/$MULTIDM_LOCALE/$LANGUAGE/LC_MESSAGES/multidm.mo
done
