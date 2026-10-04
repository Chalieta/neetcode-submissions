type LRUCache struct {
    cache		[][2]int
	capacity	int
}

func Constructor(capacity int) LRUCache {
    return LRUCache{
		cache: make([][2]int, 0),
		capacity: capacity,
	}
}

func (this *LRUCache) Get(key int) int {
    for i := range this.cache {
		if this.cache[i][0] == key {
			tmp := this.cache[i]
			this.cache = append(this.cache[:i], this.cache[i + 1:]...)
			this.cache = append(this.cache, tmp) // Move the accessed key to the last position (most recent)
			return tmp[1]
		}
	}
	return -1
}

func (this *LRUCache) Put(key int, value int) {
    for i := range this.cache {
		if this.cache[i][0] == key {
			tmp := this.cache[i]
			this.cache = append(this.cache[:i], this.cache[i + 1:]...)
			tmp[1] = value // Update the value
			this.cache = append(this.cache, tmp) // Move the updated key:value pair to the last position (most recent)
			return
		}
	}

	if len(this.cache) == this.capacity {
		this.cache = this.cache[1:] // Remove the first element (0th)
	}

	this.cache = append(this.cache, [2]int{key, value})
}
