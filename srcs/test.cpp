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
		vectest.reserve(2);
		cout << "FT new_cap = " << vectest.capacity() << " content a position 3 = "<< vectest.at(2) << endl;


		vectest.push_back(5);
		vectest.push_back(7);
		vectest.push_back(8);
		vectest.push_back(45);
		vectest.push_back(45);
		vectest.push_back(45);
		vectest.push_back(45);
		vectest.push_back(45);
		vectest.push_back(45);
		vectest.push_back(45);
		vectest.push_back(12);

		for(ft::vector<int>::iterator it = vectest.begin(); it != vectest.end(); it++)
		{
			std::cout << "content = " << *it << std::endl;
		}

		//vectest.pop_back();

		ft::vector<int>::iterator pos = vectest.begin();
		pos += 3;
		vectest.erase(pos, vectest.end());

		for(ft::vector<int>::iterator it = vectest.begin(); it != vectest.end(); it++)
		{
			std::cout << "content after pop = " << *it << std::endl;
		}
		std::cout << "_capacity after pop = " << vectest.capacity() << std::endl;
		std::cout << "_size after pop = " << vectest.size() << std::endl;

		vectest.clear();

	return 0;
}