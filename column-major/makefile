CC			= gcc
FC			= gfortran
CFLAGS		= -c
CLIB		= /home/xiaosha/lapack-3.7.0/LAPACKE/include/
FLIB		= /home/xiaosha/lapack-3.7.0/liblapacke.a /home/xiaosha/lapack-3.7.0/liblapack.a /home/xiaosha/lapack-3.7.0/librefblas.a
SRCFILES	= test.c aux.c
OBJFILES	= test.o aux.o
TARGET		= test

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(FC) $(OBJFILES) $(FLIB) -o $@

$(OBJFILES): $(SRCFILES)
	$(CC) $< $(CFLAGS) -I. -I $(CLIB) -o $@

clean:
	rm -r $(OBJFILES) $(TARGET) *~
