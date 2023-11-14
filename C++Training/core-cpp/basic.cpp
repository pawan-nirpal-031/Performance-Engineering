#include <iostream>
#include <fstream>
#include <limits>
#include <map>
#include <vector>

// typedef vs using, typedef is c std, but c++ is cpp std :  using
using Map = std::map<int,int>;

template<typename T> 
using Account = std::map<int,std::vector<T>>;
// now you can use Account directly mapping ints to type T 
Account<float> acc;

void stdio(){
    int num;
    std::cin>>num; 
    std::cout<<"Number is : "<<num<<'\n';
}

void fileio(){
    std::ifstream filein("example.txt");
    std::ofstream filewrite("file-io/basic-file-write.txt");
    int num; 
    while(not filein.eof()){
        filein>>num;
        filewrite<<"Writing number to file : "<<num<<"\n";
    }
}

void stdinWithSpaces(){
    std::string name;
    std::cout<<"enter the name : ";
    // args are inputstream ( could be fstream or stdin strem), the string varible, the delimiter could be any ascii char
    std::getline(std::cin,name);
    std::cout<<name<<"\n";
}

void readBinaryFile(){
    std::ifstream fin("test.txt",std::ifstream::binary);
    if(fin){
        // take the file pointer to the end
        fin.seekg(0,fin.end); 
        int fileLenght = fin.tellg();
        fin.seekg(0,fin.beg);
        char *buffer = new char[fileLenght];
        std::cout<<"Reading "<<fileLenght<<" characters ...\n";
        fin.read(buffer,fileLenght); 
        for(int i=0;i<fileLenght;i++){
            std::cout<<buffer[i];
        }
        std::cout<<std::endl;
        fin.close();
        delete[] buffer;
    }
}

void dataOutput(){
    std::ofstream fout;
    fout.open("test.txt",std::ofstream::out | std::ofstream::app);
    fout<<"output\n";
    fout.close();
}

void outputFormatting(){
    int pint = 12234; 
    int nint = -2431324; 
    double dvar = 1234.234;
    std::cout<<"dec : "<<std::dec<<pint;
    std::cout<<"hex : "<<std::hex<<pint;
    std::cout<<"oct : "<<std::oct<<pint;
}

// use to apply compile time checks on numbers or printing ranges 
void nuermicLimits(){// numeric limits is a template class <type> tells us what to operate on and :: func() is a static function which is a non member function of a class which belongs to a class not the object
    std::cout<<"bool : lowest  min , max "<<std::numeric_limits<bool>::lowest()<<" "<<std::numeric_limits<bool>::min()<<" "<<std::numeric_limits<bool>::max();
    std::cout<<"\nint : lowest  min , max "<<std::numeric_limits<int>::lowest()<<" "<<std::numeric_limits<int>::min()<<" "<<std::numeric_limits<int>::max();
}

void literalAssignment(){
    unsigned int dist0 {0x1234};

    unsigned char dist {12};// will throw an error but dist = 4567 won't 
    unsigned int game {24}; // error again if not strict
}

constexpr int constExprsExmpl(int x,int y,int rnd){// adding this idetifier can evaulate this function at compile time itself
    constexpr int lib_ver{1234};
    static_assert(lib_ver==1234);// compile time check 
    if(rnd) return y+x;
    return y;
}// constexpr helps compile time computation, it may be evaulated at compile time or at runtime, it cannot be reassigned again

// template <typename T>
// auto getValue(T t){
//     if constexpr (std::is_pointer<T>){ // compile time if check, id_pointer is also a compile time check
//         return *t;
//     }
//     return t;
// }

// consteval is in c++20 and every call to this function must produce compile time constant, opposed to constexper may be running at runtime   

class X{
public:
    int x;
};

void ptrsAndRefrences(){
    int a = 5;
    int *p = &a;
    int b = 10; 
    p = &b;
    std::cout<<*p<<"\n";

    int x = 5; 
    int &r = x;
    r +=10; 
    std::cout<<r<<"\n";
}

void CppOptional(){// to check if function has succeded in finding something in a data structure and getting it if it has, or else we'll have to check if it was successful and then use the retrun value to check it
    
}

enum class Animal {dog, cat, bird}; // safer than enum 

int main(){
    literalAssignment();
    X *p1 = new X;
    delete p1;
    X *p2 = new X[10];
    delete[] p2;
    ptrsAndRefrences();
}