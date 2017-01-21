CC			= gcc
FC			= gfortran
CFLAGS		= -c -O3
CLIB		= /home/xiaosha/lapack-3.7.0/LAPACKE/include/
FLIB		= /home/xiaosha/lapack-3.7.0/liblapacke.a /home/xiaosha/lapack-3.7.0/liblapack.a /home/xiaosha/lapack-3.7.0/librefblas.a
SRCFILES	= dgels_ex.c
OBJFILES	= dgels_ex.o
TARGET		= dgels_ex

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(FC) $(OBJFILES) $(FLIB) -o $(TARGET)

$(OBJFILES): $(SRCFILES)
	$(CC) $(SRCFILES) $(CFLAGS) -I $(CLIB) -o ${OBJFILES}

clean:
	rm -r $(OBJFILES) $(TARGET) *~
