package main

import (
	"fmt"
	"sync"
)

func main() {
	var wg sync.WaitGroup
	var x int = 1
	var max int = 10

	wg.Add(2)

	go func () {
		for {
			if x > max {
				wg.Done()
				break
			}
			if x % 2 != 0 {
				fmt.Printf("odd:  %d \n", x)
				x++
			}
		}
	} ()

	go func () {
		for {
			if x > max {
				wg.Done()
				break
			}
			if x % 2 == 0 {
				fmt.Printf("even: %d \n", x)
				x++
			}
		}
	} ()

	wg.Wait()

}
