
# Directories #
SRCDIR=.
INCDIR=../include
TCODDIR=../include/libtcod1.5.0

OBJDIR=../objs

CFLAGS=$(FLAGS) -I./include -I$(INCDIR) -I$(TCODDIR) -Wall -g -ansi -pedantic -std=c++0x
CC=gcc
CPP=g++
.SUFFIXES: .o .h .c .hpp .cpp

OBJS = 	$(OBJDIR)/Actions/ActionPickUp.o $(OBJDIR)/BasicItems.o \
		$(OBJDIR)/BasicMapObject.o $(OBJDIR)/Being.o \
		$(OBJDIR)/DisplayTile.o $(OBJDIR)/Game.o \
		$(OBJDIR)/Graphics.o $(OBJDIR)/Interface.o \
		$(OBJDIR)/Inventory.o $(OBJDIR)/InventoryGraphics.o \
		$(OBJDIR)/Item.o $(OBJDIR)/ItemContainer.o \
		$(OBJDIR)/Main.o $(OBJDIR)/Map.o \
		$(OBJDIR)/MapObject.o $(OBJDIR)/Menu.o \
		$(OBJDIR)/Actions/ActionDrop.o $(OBJDIR)/MenuInventory.o \
		$(OBJDIR)/Message.o $(OBJDIR)/Object.o \
		$(OBJDIR)/Races.o $(OBJDIR)/Reference.o \
		$(OBJDIR)/Spawn.o $(OBJDIR)/StandardItemFunctions.o \


$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CPP) $(CFLAGS) -o $@ -c $<



all : release

#Debug Build#
debug : $(OBJS)
	$(CPP) $(OBJS) -g -o ../bin/scourge_of_westnor_d.exe -mwindows -L../lib -ltcod-mingw-debug

#Release Build#
release : $(OBJS)
	$(CPP) $(OBJS) -O3 -o ../bin/scourge_of_westnor.exe -mwindows -L../lib -ltcod-mingw

rebuild: rebuild_release

rebuild_release: clean_objs release
rebuild_debug: clean_objs debug
	
	
#Cleaning#
clean : clean_objs clean_bin

clean_objs:
	rm -f $(OBJS)
clean_bin:
	rm -f ../bin/scourge_of_westnor.exe
	rm -f ../bin/scourge_of_westnor_d.exe