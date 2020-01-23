#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := decompressor.asm compressed.asm

# header files in this project
HEADERS := 

# other places to look for files for this project
SEARCH  := ../07-library

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there

cleaning:
	make -f compressor.mk clean
	make clean

compress_and_build:
	make -f compressor.mk
	sudo ./compressor.exe
	make 

RELATIVE := ..
include $(RELATIVE)/Makefile.due
