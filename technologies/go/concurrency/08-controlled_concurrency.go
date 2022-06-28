package main

import (
	"fmt"
	"time"
)

const concurrencyLevel = 3
var requestIDs = []int{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15} 

func main() {
	queue := make(chan bool, concurrencyLevel)

	for _, _ID := range requestIDs {
		queue <- true
		go func (ID int) {
			defer func ()  { <- queue }()
			makeRequest(ID)
		}(_ID)
	}

	for i := 0; i < concurrencyLevel; i++ {
		queue <- true
	}

	fmt.Println("done")
}

func makeRequest(ID int) {
	time.Sleep(time.Second * 2)
	fmt.Println(ID)
}