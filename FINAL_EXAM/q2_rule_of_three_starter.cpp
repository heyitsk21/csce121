/*
struct Chair{
    double sitHeight;
    double seatWidth;
    bool hasBack;
};

class DynamicChair{
    *Chair data;
 public:
    DynamicChair(Chair d) : data(new Chair(d)) {}

    //value access by dereference
    const Chair& operator*()const { return *data; }
    Chair operator*() {return *data;}

    // value assignment (not a rule of three function)
    DynamicChair& operator=(const Chair& d){
        *data = d;
        return *this;
    }

    //DynamicChair rule of 3
    DynamicChair(const DynamicChair& rhs);//copy constructor
    ~DynamicChair();//destructor
    DynamicChair& operator=(const DynamicChair& rhs);//copy assignment operator
    
};
*/


// TODO: declare and define rule of three

DynamicChair::DynamicChair(const DynamicChair& rhs){
    //if the souce has nothing, just quick return
    if(rhs.data == nullptr){
        return;
    }

    //if the source has stuff... copy it over 
    if(rhs.data != nullptr){
        //DynamicChair* newChair = new DynamicChair();
        this->data.sitHeight = rhs.data->sitHeight;
        this->data.seatWidth = rhs.data->seatWidth;
        this->data.hasBack = rhs.data->hasBack;
    }
}
/*data(sitHeight, seatWidth, hasBack)*/
/*sitHeight{rhs.sitHeight}, seatWidth{rhs.seatWidth}, hasBack{rhs.hasBack}*/


DynamicChair::~DynamicChair(){
    //delete the data as long as it isn't a nullptr
    if (this->data != nullptr){
        delete this->data;
    }

    //set data to nullptr
    data = nullptr;
}


DynamicChair& operator=(const DynamicChair& rhs){
    //if they're already equal, quick return
    if (this == &rhs){
        return *this;
    }

    //clear the calling variable, if it isn't already empty
    delete[] data;

    //copy each thing from the original DynamicChair (rhs) to the new variable calling the operator=
    if (this->Chair != nullptr){
        this->data.sitHeight = rhs.data->sitHeight;
        this->data.seatWidth = rhs.data->seatWidth;
        this->data.hasBack = rhs.data->hasBack;
    }

    //return the calling variable, which is now deep copied
    return *this;
}