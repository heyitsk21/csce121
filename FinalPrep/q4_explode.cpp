// [1,2,3]
// [1,2,2,3,3,3]
void explode(unsigned int *&array, size_t &size)
{
  size_t newSize = 0;

  for(size_t i = 0; i < size; ++i){
    if(array[i] < 0){
      throw std::invalid_argument("Invalid Number");
    }
    newSize = newSize + arr[i];
  }
  
int *arr = new int[newSize]{};
int num = 0;
int startAt = 0;
  
for(size_t i = 0; i < size; i++){
  num = 0;
  num += array[i];
  for(size_t j = 0; j < num; j++)
    arr[startAt] = num;
    ++startAt;
}

for(size_t i = 0; i < size; ++i){
  delete[] array[i];
}
delete array;
  
array = arr;
size = newSize;
}

