DynamicPhone::DynamicPhone() : data(nullptr) {}

//Destructor
DynamicPhone::~DynamicPhone(){
  delete[] data;
  data = nullptr;
}


//copy constructor
DynamicPhone::DynamicPhone(const Phone& d) : data(nullptr) {
  this->data->width = d.data->width;
  this->data->height = d.data->height;
  this->data->isAndroid = d.data->isAndroid;
}

//copy assignment constructor
DynamicPhone &DynamicPhone::operator=(const Phone& d){
  
  if(this == &d){
    return *this;
  }
  delete[] data;
  
this->data->width = d.data->width;
this->data->height = d.data->height;
this->data->isAndroid = d.data->isAndroid;


return *this;
}

};