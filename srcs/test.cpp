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
		// vector<int> realstl(3, 9);
		// cout << "STL = " << realstl.capacity() << " content a position 3 = "<< realstl.at(2) << endl;
		// if (realstl.empty())
		// 	cout << "IS EMPTY" << endl;
		// else
		// 	cout << "NOT EMPTY" << endl;


		// //FT
		ft::vector<int> vectest(3, 9);
		// cout << "FT = " << vectest.capacity() << " content a position 3 = "<< vectest.at(2) << endl;
		// if (vectest.empty())
		// 	cout << "IS EMPTY" << endl;
		// else
		// 	cout << "NOT EMPTY" << endl;

		// cout << "Max Size = " << vectest.max_size() << endl;

		// ft::vector<int> copyconstructvec(vectest);
		// cout << "COPY CONSTRUC = " << copyconstructvec.capacity() << endl;

		cout << "FT previous cap = " << vectest.capacity() << " content a position 3 = "<< vectest.at(2) << endl;
		vectest.reserve(10);
		cout << "FT new_cap = " << vectest.capacity() << " content a position 3 = "<< vectest.at(2) << endl;

	return 0;
}