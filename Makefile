obj-m := project2.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules	
	#make -C usr/src/kernels/$(KDIR)/include M=$(PWD) modules	 
	
clean:
	clean -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean 
	#make -C usr/src/kernels/$(KDIR)/include M=$(PWD) clean
