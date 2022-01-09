#include <MyLib/MyLib.h>

#include <iostream>
#include <MyHeaderLib/MyHeaderLib.h>
#include <PrivateHeader.h>

using namespace std;

namespace mylib
{

void func()
{
	myheaderlib::func();
	cout << "mylib::func()" << endl;
}

} // namespace mylib
