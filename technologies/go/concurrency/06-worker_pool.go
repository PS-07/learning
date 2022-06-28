package main3

import (
	"fmt"
	"sync"
	"time"
)

func main() {
	N := 50
	var wg sync.WaitGroup

	for i := 1; i <= 5; i++ {
		wg.Add(1)
		i := i
		go func ()  {
			defer wg.Done()
			run(N, i)
		}()
	}

	wg.Wait()
}

func run(N int, W int) {
	start := time.Now()
	jobs := make(chan int, N)
	results := make(chan int, N)

	for i := 0; i < W; i++ {
		go worker(jobs, results)
	}

	for i := 0; i < N; i++ {
		jobs <- i
	}
	close(jobs)

	for i := 0; i < N; i++ {
		_ = <-results
	}

	elapsed := time.Since(start)
	fmt.Printf("time taken by %d workers: %s\n", W, elapsed)
} 

func worker(jobs <-chan int, results chan<- int) {
	for n := range jobs {
		results <- fib(n)
	}
}

func fib(n int) int {
	if n<=1 {
		return n
	}
	return fib(n-1) + fib(n-2)
}

// output (N=50):
// time taken by 5 workers: 1m35.917995171s
// time taken by 4 workers: 1m39.703499284s
// time taken by 3 workers: 1m46.17172047s
// time taken by 2 workers: 2m0.074884675s
// time taken by 1 workers: 2m42.062223758s