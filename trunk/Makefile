# Project: opencv-macbook2008-tests
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.
# @file
# Makefile for the iSight camera software tests
# @author Lucas Guerrero

#-- Configuration

TARGET := om2008t.bin

C_SRC := \
	main.cpp \
	bufferImg.cpp

#-- Tools

BITTINESS = -m64
CC := gcc ${BITTINESS}
CXX := g++ ${BITTINESS}
LD := g++
OPENCV = $(shell pkg-config --libs opencv)
OPENCVCFL = $(shell pkg-config opencv --cflags)
OBJ := $(C_SRC:%.c=%.o) $(CXX_SRC:%.cpp=%.o)

#-- Flags

CFLAGS := -I/opt/local/include 
DEPS = bufferImg.hpp
CXXFLAGS := $(CFLAGS)
LDLIBS := $(OPENCV) -arch x86_64

$(TARGET): $(OBJ)
	$(LD) $(LDFLAGS) -o $@ $^ $(LDLIBS) $(OPENCVCFL)


bin: $(TARGET)
clean:
	$(RM) $(TARGET) 
