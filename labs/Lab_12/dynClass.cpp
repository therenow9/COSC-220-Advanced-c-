//constructor
// use constructor initialization list to give member1 the
// value m1 and allocate dynamic memory associated with member2
// and initialize it to with the value m2

dynClass::dynClass(int m1, int m2)
{
    member1=m1;
    member2=new int(m2);
}
//copy constructor
// initialize new object to have the
// same data as obj. use constructor initialization
// list to give member1 the value member1 of obj and
// allocate dynamic memory associated with member2 and
// initialize it with the value pointed by member2 of obj.

dynClass::dynClass(const dynClass& obj)
{
    member1=obj.member1;
    member2=new int;
    *member2=*obj.member2;
}

// destructor. deallocates the dynamic memory allocated
// by the constructor and display “Destructor is called
//

dynClass::~dynClass()
{
    cout << "Destructor is called\n";
}

// overloaded assignment operator=. returns a reference to
// current object.
// copy static data member from obj to the current object
// contents of dynamic memory must be same as that of obj

dynClass& dynClass::operator=(const dynClass& obj)
{
    member1=obj.member1;
    *member2=*obj.member2;

    return *this;
}
