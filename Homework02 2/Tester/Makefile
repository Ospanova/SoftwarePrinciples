#****************************************************************************************************************************************************
#
# Copyright (C) 2018 - 2020 Selim Temizer.
#
# This program is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License
# as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.
#
#****************************************************************************************************************************************************




# Variables *****************************************************************************************************************************************

# Required for variadic macros: -std=c99
# Required for valgrind       : -O0 -g

CC                    = gcc
CFLAGS                = -Wall -ansi -pedantic-errors -std=c99 -O0 -g
LIBS                  = -lm
INCLUDE_DIRS          = -I.
LIBRARY_DIRS          = -L.

# Source Files, Configuration Files and Desired Executables *****************************************************************************************

APPLICATION_FILES     = ArrayList.c          \
                        LinkedList.c         \
                        ListImplementation.c

TESTER_FILES          = Tester.c

SOURCE_FILES          = $(APPLICATION_FILES) $(TESTER_FILES)

FILE_LISTER_CONFIG    = FileListerConfiguration.properties

TESTS_INCLUDER        = Tests_All.c

EXE                   = Tester.exe

# Object Files **************************************************************************************************************************************

OBJECT_FILES          = $(SOURCE_FILES:.c=.o)

# Rules *********************************************************************************************************************************************

.PHONY                : all val clean cleanall

all                   : $(FILE_LISTER_CONFIG) $(TESTS_INCLUDER) $(EXE)

$(FILE_LISTER_CONFIG) :
	                java -jar FileLister.jar -c $(FILE_LISTER_CONFIG)

$(TESTS_INCLUDER)     : $(FILE_LISTER_CONFIG)
	                java -jar FileLister.jar $(FILE_LISTER_CONFIG)

.c.o                  :
	                $(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $<

$(EXE)                : $(OBJECT_FILES)
	                $(CC) $(CFLAGS) $(LIBRARY_DIRS) -o $(EXE) $(OBJECT_FILES) $(LIBS)

val                   :
	                valgrind --tool=memcheck --leak-check=yes $(EXE)

clean                 :
	                rm -f $(OBJECT_FILES)

cleanall              :
	                rm -f $(OBJECT_FILES) $(FILE_LISTER_CONFIG) $(TESTS_INCLUDER) $(EXE)

#****************************************************************************************************************************************************
