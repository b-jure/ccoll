BIN = build/cvec_test
LEAKBIN = build/cvec_test_memleak
SRCDIR = .
OBJDIR = build/obj
INCLUDES = ../../../src
SRCPATH = ../../../src

SRCFILE := $(SRCPATH)/cvec.c
SRCOBJ := $(SRCPATH)/cvec.o
SRCOBJ_NEW = $(OBJDIR)/cvec.o
DEP_NEW = $(OBJDIR)/cvec.d

CFILES := $(wildcard $(SRCDIR)/*.c) 
OBJECTS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(CFILES))
DEPS := $(patsubst %.o,%.d,$(OBJECTS))

CC = gcc
DEPFLAGS = -MD -MP
OPT = -O0
SANITIZER_FLAGS = -fsanitize=address -O1 -fno-omit-frame-pointer
CFLAGS := -Werror -Wall -Wextra $(foreach dir,$(INCLUDES),-I$(dir)) $(DEPFLAGS) $(OPT)

all: $(SRCOBJ) $(BIN)

$(BIN): $(SRCOBJ)
	@$(CC) -o $@ $(OBJECTS) $(SRCOBJ_NEW) -lstest

$(SRCOBJ): $(OBJECTS)
	@$(CC) -c -o $(OBJDIR)/$(notdir $(SRCOBJ)) $(CFLAGS) $(SRCFILE)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	@$(CC) -c -o $@ $< $(CFLAGS)

clean:
	@rm -rf $(OBJECTS) $(DEPS) $(BIN) $(SRCOBJ_NEW) $(DEP_NEW) $(LEAKBIN)

test: $(BIN)
	@./$(BIN)

test-leak: $(LEAKBIN)
	@./$(LEAKBIN)

$(LEAKBIN): $(SRCOBJ)
	@$(CC) $(SANITIZER_FLAGS) -o $@ $(OBJECTS) $(SRCOBJ_NEW) -lstest

-include $(DEPS)

.PHONY: all clean test test-leak
