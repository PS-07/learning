package main

import (
	"fmt"
	"sync"
)

func main() {
	x := 1
	var wg_odd sync.WaitGroup
	var wg_even sync.WaitGroup

	go odd(&x, &wg_odd, &wg_even)
	go even(&x, &wg_even, &wg_odd)

	wg_odd.Wait()
	wg_even.Wait()

}

func odd(x *int, wg_odd *sync.WaitGroup, wg_even *sync.WaitGroup) {
	wg_odd.Wait()
	fmt.Printf("odd:  %d \n", x)
	*x++
	wg_even.Add(1)
}

func even(x *int, wg_even *sync.WaitGroup, wg_odd *sync.WaitGroup) {
	wg_even.Wait()
	fmt.Printf("even: %d \n", x)
	*x++
	wg_odd.Add(1)
}