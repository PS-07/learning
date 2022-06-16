package main

// print 1-10 in 2 goroutines, odd, even

import (
	"fmt"
	"sync"
)

func main() {
	c := make(chan bool, 1)
	var wg sync.WaitGroup

	c <- false 
	wg.Add(2)

	go odd(c, &wg)
	go even(c, &wg)

	wg.Wait()
	close(c)
}

func odd(c chan bool, wg *sync.WaitGroup) {
	for i := 1; i <= 10; {
		curr := <- c
		if !curr {
			fmt.Printf("odd:  %d \n", i)
			i = i + 2
			c <- true
		} else {
			c <- true
		}
	}
	wg.Done()
}

func even(c chan bool, wg *sync.WaitGroup) {
	for i := 2; i <= 10; {
		curr := <- c
		if curr {
			fmt.Printf("even: %d \n", i)
			i = i + 2
			c <- false
		} else {
			c <- false
		}
	}
	wg.Done()
}