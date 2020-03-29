#include "htree.cc"
#include <iostream>
#include <assert.h>

int main() {
	
	//Test 1
	HTree one = HTree(2,6);
	HTree two = HTree(4,5);
	HTree::tree_ptr_t three_left(new HTree(one));
	HTree::tree_ptr_t three_right(new HTree(two));
	HTree three = HTree(1,3,three_left,three_right);
	
	if (three.get_key() == 1) {
		std::cout << "Key test 1 passed!" << std::endl;
	}
	
	if (three.get_value() == 3) {
		std::cout << "Value test 1 passed!" << std::endl;
	}

	if (three.get_child(HTree::Direction::LEFT) == three_left) {
		std::cout << "Left child test 1 passed!" << std::endl;
	}

	if (three.get_child(HTree::Direction::RIGHT) == three_right) {
		std::cout << "Right child test 1 passed!" << std::endl;
	}

	if (three.path_to(2) == HTree::path_t {HTree::Direction::LEFT}) {
		std::cout << "Path to (2) test passed!" << std::endl;
	}

	if (three.path_to(4) == HTree::path_t {HTree::Direction::RIGHT}) {
		std::cout << "Path to (4) test passed!" << std::endl;
	}
	
	if (three.path_to(1) == HTree::path_t {}) {
		std::cout << "Path to (1) test passed!" << std::endl;
	}


	//Test 2
	HTree seven = HTree(13,12);
	HTree six = HTree(19,30);
	HTree::tree_ptr_t five_left(new HTree(seven));
	HTree::tree_ptr_t five_right(new HTree(six));
	HTree five = HTree(11,177,five_left,five_right);
	HTree::tree_ptr_t four_left(new HTree(five));
	HTree four = HTree(32,2,four_left);
	if (six.get_key() == 19) {
		std::cout << "Key test 2 passed!" << std::endl;
	}
	if (five.get_value() == 177) {
		std::cout << "Value test 2 passed!" << std::endl;
	}
	if (four.get_child(HTree::Direction::LEFT) == four_left) {
		std::cout << "Left child test 2 passed!" << std::endl;
	}
	if (four.get_child(HTree::Direction::RIGHT) == nullptr) {
		std::cout << "Right child test 2 passed!" << std::endl;
	}
	if (four.path_to(13) == HTree::path_t {HTree::Direction{0},HTree::Direction{0}}) {
		std::cout << "Path to (13) test passed!" << std::endl;
	}
	if (four.path_to(32) == HTree::path_t {}) {
		std::cout << "Path to (32) test passed!" << std::endl;
	}
	if (four.path_to(11) == HTree::path_t {HTree::Direction{0}}) {
		std::cout << "Path to (11) test passed!" << std::endl;
	}
	if (four.path_to(19) == HTree::path_t {HTree::Direction{0},HTree::Direction{1}}) {
		std::cout << "Path to (19) test passed!" << std::endl;
	}
	std::cout << "Test 2 Passed!" << std::endl;


	
	//Test 3
	HTree eight = HTree(6,19);
	if (eight.get_key() == 6) {
		std::cout << "Key test 3 passed!" << std::endl;
	}
	if (eight.get_value() == 19) {
		std::cout << "Value test 3 passed!" << std::endl;
	}
	if (eight.get_child(HTree::Direction::LEFT) == nullptr) {
		std::cout << "Left child test 3 passed!" << std::endl;
	}
	if (eight.get_child(HTree::Direction::RIGHT) == nullptr) {
		std::cout << "Right child test 3 passed!" << std::endl;
	}
	if (eight.path_to(6) == HTree::path_t {HTree::Direction{0},HTree::Direction{0}}) {
		std::cout << "Path to (13) test passed!" << std::endl;
	}
	std::cout << "Test 3 Passed!" << std::endl;


	//Test 4
	HTree eleven = HTree(61,44);
	HTree twelve = HTree(55,3);
	HTree::tree_ptr_t ten_left(new HTree(eleven));
	HTree::tree_ptr_t ten_right(new HTree(twelve));
	HTree ten = HTree(15,15,ten_left,ten_right);
	HTree fourteen = HTree(30,2);
	HTree fifteen = HTree(15,0);
	HTree::tree_ptr_t thirteen_left(new HTree(fourteen));
	HTree::tree_ptr_t thirteen_right(new HTree(fifteen));
	HTree thirteen = HTree(5,105,thirteen_left,thirteen_right);
	HTree::tree_ptr_t nine_left(new HTree(ten));
	HTree::tree_ptr_t nine_right(new HTree(thirteen));
	HTree nine = HTree(2,60,nine_left,nine_right);	
	if (nine.get_key() == 2) {
		std::cout << "Key test 4 passed!" << std::endl;
	}
	if (fifteen.get_value() == 0) {
		std::cout << "Value test 4 passed!" << std::endl;
	}
	if (ten.get_child(HTree::Direction::LEFT) == ten_left) {
		std::cout << "Left child test 4 passed!" << std::endl;
	}
	if (thirteen.get_child(HTree::Direction::RIGHT) == thirteen_right) {
		std::cout << "Right child test 4 passed!" << std::endl;
	}
	if (nine.path_to(15) == (HTree::path_t {HTree::Direction{0}}) or nine.path_to(15) == (HTree::path_t {HTree::Direction{1}, HTree::Direction{1}})) {
		std::cout << "Dual path to (15) test passed!" << std::endl;
	}
	if (nine.path_to(55) == HTree::path_t {HTree::Direction{0},HTree::Direction{1}}) {
		std::cout << "Path to (55) test passed!" << std::endl;
	}
	
	
	std::cout << "Test 4 Passed!" << std::endl;

	


	return 0;
}
