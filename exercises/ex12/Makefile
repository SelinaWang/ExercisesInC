all: counter counter_array counter_array_mutex
	
counter: counter.c
	gcc -Wall -o counter counter.c -lpthread

counter_array: counter_array.c
	gcc -Wall -o counter_array counter_array.c -lpthread

counter_array_mutex: mutex.c counter_array_mutex.c
	gcc -Wall -o counter_array_mutex mutex.c counter_array_mutex.c -lpthread
