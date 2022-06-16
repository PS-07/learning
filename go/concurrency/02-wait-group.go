package main

import (
	"fmt"
	"sync"
	"time"
)

func main() {
	var wg sync.WaitGroup
	wg.Add(1) // increments counter by 1

	go func() {
		count("apple")
		wg.Done() // decrements counter by 1
	}()
	
	wg.Wait() // blocks the main goroutine until count in 0
}

func count(s string) {
	for i := 0; i < 5; i++ {
		fmt.Println(i, s)
		time.Sleep(time.Millisecond * 500)
	}
}