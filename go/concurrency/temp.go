package main

import (
	"fmt"
	"time"
)

func main() {
	start := time.Now()
	ch := make(chan int)

	for i := 0; i < 5; i++ {
		go func() {
			sleep()
			ch <- 1
		}()
	}

	for i := 0; i < 5; i++ { 
		<- ch
	}

	elapsed := time.Since(start)
	fmt.Printf("time taken: %s\n", elapsed)
}

func sleep() int {
	fmt.Println("sleeping for 2 sec..")
	time.Sleep(time.Second * 2)
	return 1
}