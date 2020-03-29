#include "tree.cc"
#include <iostream>

int main() {
	//Initialize tree objects with given values for testing
	//this also tests create_tree
	tree_ptr_t first = create_tree(5,6);
	std::cout << "Created tree at " << first << std::endl;
	tree_ptr_t second = create_tree(6,7);
	std::cout << "Created tree at " << second << std::endl;
	tree_ptr_t third = create_tree(8,9,second,first);
	std::cout << "Created tree at " << third << std::endl;
	tree_ptr_t fourth = create_tree(4,4);
	std::cout << "Created tree at " << fourth << std::endl;
	tree_ptr_t fifth = create_tree(32,41);
	std::cout << "Created tree at " << fifth << std::endl;
	tree_ptr_t sixth = create_tree(11,0,fourth,fifth);
	std::cout << "Created tree at " << sixth << std::endl;
	tree_ptr_t seventh = create_tree(45,2,sixth,third);
	std::cout << "Created tree at " << seventh << std::endl;

	//test path_to
	std::cout << "The path to 32 is " << path_to(seventh,32) << std::endl; //should return "LR"
	std::cout << "The path to 5 is " << path_to(seventh,5) << std::endl; //should return "RR"
	std::cout << "The path to 11 is " << path_to(seventh,11) << std::endl; //should return "L"
	std::cout << "The path to 45 is " << path_to(seventh,45) << std::endl; //should return ""


	//test node_at
	std::cout << "The node at _ is " << node_at(seventh,"") << std::endl; //should return seventh
	std::cout << "The node at LR is " << node_at(seventh,"LR") << std::endl; //should return fifth
	std::cout << "The node at RR is " << node_at(seventh,"RR") << std::endl; //should return first
	std::cout << "The node at L is " << node_at(seventh,"L") << std::endl; //should return sixth
	std::cout << "The node at LRL is " << node_at(seventh,"LRL") << std::endl; //should return nullptr

	//test destroy tree
	destroy_tree(first);
	std::cout << "Tree destroyed." << std::endl;
	destroy_tree(seventh);
	std::cout << "Tree destroyed." << std::endl;

	return 0;
}