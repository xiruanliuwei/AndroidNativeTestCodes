
#include <iostream>

using namespace std;

class DispSync {
public:
    explicit DispSync(const char* name);
	
    ~DispSync();
};

DispSync::DispSync(const char* name) {
    cout << "explicit constructor is called!" << endl;
}

DispSync::~DispSync() {
    cout << "default destructor is called!" << endl;
}

class SurfaceFlinger {
public:
    SurfaceFlinger();

private:
    DispSync mPrimaryDispSync;    
};

SurfaceFlinger::SurfaceFlinger() : mPrimaryDispSync("PrimaryDispSync") {

}

int main(int argc, char** argv) {

    // DispSync mPrimaryDispSync;

    SurfaceFlinger* sf = new SurfaceFlinger();

    return 0;
}

