all: counter counter_array counter_array_mutex
	
counter: counter.c
	gcc -Wall -o counter counter.c -lpthread

counter_array: counter_array.c
	gcc -Wall -o counter_array counter_array.c -lpthread

<<<<<<< HEAD
counter_array_mutex: mutex.c counter_array_mutex.c
	gcc -Wall -o counter_array_mutex mutex.c counter_array_mutex.c -lpthread
=======
barrier: barrier.c utils.c
	gcc -Wall -std=c99 -o barrier barrier.c utils.c -lpthread

barrier_soln: barrier_soln.c utils.c
	gcc -Wall -std=c99 -o barrier_soln barrier_soln.c utils.c -lpthread
>>>>>>> 2eb34b55a445205fcd24f378435b99c86d925853
