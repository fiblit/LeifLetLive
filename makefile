SRCDIR = src/
INCDIR = inc/
OBJDIR = obj/
BINDIR = bin/

#ADD SOURCE/HEADER FILE NAMES HERE
NAME = main
SRC = $(addprefix $(SRCDIR), $(addsuffix .cpp, $(NAME)))
OBJ = $(addprefix $(OBJDIR), $(addsuffix .o, $(NAME)))
INC = $(addprefix $(INCDIR), $(addsuffix .hpp, $(NAME)))

EXE = $(BINDIR)leifLetLive

CC = g++
CVER = -std=c++11
WARN = -Wall -W
OPT = -g $(CVER) $(WARN) -I$(INCDIR)
LIB =#-lncurses

all: $(EXE)

$(EXE): $(OBJ) $(INC) | $(BINDIR)
	$(CC) -o $@ $(LIB) $(OBJ)

#while this is general, it is not accurate if the header file includes other header files. 
#I would then have to replace this in favor of a more specific compilation.
$(OBJ): $(addprefix $(SRCDIR), $(addsuffix .cpp, $(basename $(notdir $@)))) $(addprefix $(SRCDIR), $(addsuffix .hpp, $(basename $(notdir $@)))) | $(OBJDIR)
	$(CC) -c $(OPT) $(addprefix $(SRCDIR), $(addsuffix .cpp, $(basename $(notdir $@)))) -o $@

obj/:
	mkdir obj

bin/:
	mkdir bin

clean:
	rm -rf bin/ obj/

