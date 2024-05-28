template <class T>
Array<T>::Array() : arr_(new T[0]), size_(0) {
}

template <class T>
Array<T>::Array(unsigned int n) : arr_(new T[n]), size_(n) {
    for (int i = 0; i < size_; i++)
        arr_[i] = 0;
}

template<class T>
Array<T>::Array(const Array &copy) {
    arr_ = new T[copy.size_];
    size_ = copy.size_;
    for (int i = 0 ; i < copy.size_ ; i++) {
		arr_[i] = copy.arr_[i];
	}
}

template <class T>
Array<T> &Array<T>::operator=(const Array &copy) {
	if (this != &copy)
     {
        delete arr_;
        arr_ = NULL;
        arr_ = new T[copy.size_];
        size_ = copy.size_;
     }
	for (int i = 0 ; i < copy.size_ ; i++) {
		arr_[i] = copy.arr_[i];
	}
    return (*this);
}

template <class T>
Array<T>::~Array() {
    delete[] arr_;
    arr_ = NULL;
}

template<class T>
T& Array<T>::operator[](int index) {
	if (index < 0 || index >= size_)
		throw OutOfBoundException();
	return arr_[index];
}

template <class T>
int Array<T>::size() const {
	return size_;
}