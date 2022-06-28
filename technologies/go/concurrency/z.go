package main

import (
	"fmt"
	"sync"
	"time"
)

func f(a []int, wg *sync.WaitGroup) {
	for i:=0; i<len(a); i++ {
		fmt.Println(a[i])
		time.Sleep(time.Millisecond * 500)
	}
	wg.Done()
}

func main() {
	arr := []int{1,2,3,4,5,6,7,8,9,10,11,12}
	var wg sync.WaitGroup

	fmt.Println(time.Now())

	for i:=0; i<len(arr); i = i+3 {
		wg.Add(1)
		go f(arr[i:i+3], &wg)
	} 

	wg.Wait()
	fmt.Println(time.Now())
	
}
