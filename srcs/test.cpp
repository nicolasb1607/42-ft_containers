#include <iostream>
#include <cstring>


#include <vector.hpp>
#include <vector>

using namespace std;

int main()
{
	/*----------------------------------------TEST CONSTRUTOR------------------------------------*/

	// DEFAULT		
		//STL
		// vector<int> realstl(std::allocator<int>);
		// cout << realstl.capacity() << endl;

		// FT
		// ft::vector<int> vectest(std::allocator<int>);
		// cout << vectest.capacity() << endl;

	//FILL CONSTRUCTOR
		//STL
		vector<int> realstl(3, 9);
		cout << "STL = " << realstl.capacity() << endl;

		//FT
		ft::vector<int> vectest(3, 9);
		cout << "FT = " << vectest.capacity() << endl;


		ft::vector<int> copyconstructvec(vectest);
		cout << "COPY CONSTRUC = " << copyconstructvec.capacity() << endl;

	return 0;
}