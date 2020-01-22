#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source & header files in this project (main.cpp is automatically assumed)

include maakfile.mk

HEADERS += note.hpp
HEADERS += note_player.hpp
HEADERS += melody.hpp

HEADERS += note_player_gpio.hpp
SOURCES += note_player_gpio.cpp

SOURCES += melody.cpp

# other places to look for files for this project
SEARCH  := 

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := ..
include $(RELATIVE)/Makefile.due