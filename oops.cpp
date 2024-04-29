//classes in c++
class myClass{
    //class data
    string name;
};
//constructor in c++
{
    string name;
    public:
    int age;
    bool gender;
    student(){
        cout<< "Default constructor" << endl;
    } //default const
    student(string s, int a, int g){
        cout << "Parameterised constructor" << endl;
    name = s;
    age = a;
    gender = g;}//parameterised constructor
}
//copy constructor
student(student &a){
    cout << "Copy constructor" << endl;
    name = a.name;
    age = a.age;
    gender = a.gender;
}
//destructors in c++
~student(){
    coutt << "Destructor called" << endl;
}
//getters
string getName(){
    return name;
}
//setters
void setName(string s){
    name =s;
}
//operator overloading
bool operator == (student &a){
    if(name == a.name && age == a.age && gender == a.gender){
        return true;
    }return false;
}
//function overloading
//area of circle
float area(int r){
    return 3.141 * r * r;
}
//area of rectangle
int area(int l, int r){
    return l*r;
}