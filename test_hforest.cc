#include "hforest.cc"
#include <iostream>
#include <algorithm>


HTree::tree_ptr_t create_htree_from_vector(std::vector<int> vector) {

	//assert(vector.size() % 2 == 0);
	
	if (vector.size() == 0) {
		return nullptr;
	}

	else if (vector.size() == 2) {
		HTree root = HTree(vector.at(0),vector.at(1));
		HTree::tree_ptr_t root_ptr(new HTree(root));
		return root_ptr;
	}

	else if (vector.size() == 4) {
		HTree left = HTree(vector.at(0),vector.at(1));
		HTree::tree_ptr_t left_ptr(new HTree(left));
		HTree root = HTree(vector.at(2),vector.at(3),left_ptr,nullptr);
		HTree::tree_ptr_t root_ptr(new HTree(root));
		return root_ptr;
	}

	else if (vector.size() == 6) {

		HTree left = HTree(vector.at(0),vector.at(1));
		HTree::tree_ptr_t left_ptr(new HTree(left));
		HTree right = HTree(vector.at(2),vector.at(3));
		HTree::tree_ptr_t right_ptr(new HTree(left));
		HTree root = HTree(vector.at(4),vector.at(5),left_ptr,right_ptr);
		HTree::tree_ptr_t root_ptr(new HTree(root));
		return root_ptr;
	}
/*
	else if (vector.size() == 8) {

		int halfway = vector.size() / 2;
		std::vector<int> left_vector (halfway);
		std::vector<int> right_vector (halfway);
		for (int n=2;n<=halfway;n++) {
			left_vector.at(n) = vector.at(n);
			right_vector.at(n) = vector.at(n+halfway);
		}
		HTree root = HTree(vector.at(0),vector.at(1),create_htree_from_vector(left_vector),create_htree_from_vector(right_vector));
		HTree::tree_ptr_t root_ptr(new HTree(root));
		return root_ptr;
		
		HTree left = HTree(vector.at(0),vector.at(1));
		HTree::tree_ptr_t left_ptr(new HTree(left));
		HTree right = HTree(vector.at(2),vector.at(3));
		HTree::tree_ptr_t right_ptr(new HTree(left));
		HTree root = HTree(vector.at(4),vector.at(5),left_ptr,right_ptr);
		HTree::tree_ptr_t root_ptr(new HTree(root));
		return root_ptr;
	} */

	else {

		int halfway = ((vector.size() - 2) / 2);
		std::vector<int> left_vector (halfway);
		std::vector<int> right_vector (halfway);
		for (int n=2;n<halfway;n++) {
			left_vector.push_back(vector.at(n));
			right_vector.push_back(vector.at(n+halfway));
		}
		HTree root = HTree(vector.at(0),vector.at(1),create_htree_from_vector(left_vector),create_htree_from_vector(right_vector));
		HTree::tree_ptr_t root_ptr(new HTree(root));
		return root_ptr;
	}

}

std::vector<int> generate_random_vector() {
	
	std::vector<int> output (16);
	for (unsigned i=0;i<output.size();i++) {
		output[i] = ((rand() % 50));
	}

	return output;
}


int main() {

	//Test 1
	HForest test = HForest();
	HTree::tree_ptr_t tree_one = create_htree_from_vector(generate_random_vector());
	HTree::tree_ptr_t tree_two = create_htree_from_vector(generate_random_vector());
	HTree::tree_ptr_t tree_three = create_htree_from_vector(generate_random_vector());
	HTree::tree_ptr_t tree_four = create_htree_from_vector(generate_random_vector());
	HTree::tree_ptr_t tree_five = create_htree_from_vector(generate_random_vector());
	HTree::tree_ptr_t tree_six = create_htree_from_vector(generate_random_vector());
	HTree::tree_ptr_t tree_seven = create_htree_from_vector(generate_random_vector());

	test.add_tree(tree_one);

	if (test.size() == 1) {
		std::cout << "Size test 1 passed!" << std::endl;
	}
	else {
		std::cout << "Size test 1 failed!" << std::endl;
	}
	if (test.heap[0] == tree_one) {
		std::cout << "Add tree test 1 passed!" << std::endl;
	}
	else {
		std::cout << "Add tree test 1 failed!" << std::endl;
	}

	test.add_tree(tree_two);
	test.add_tree(tree_three);
	test.add_tree(tree_four);
	test.add_tree(tree_five);
	test.add_tree(tree_six);
	test.add_tree(tree_seven);

	if (test.size() == 7) {
		std::cout << "Size test 2 passed!" << std::endl;
	}
	else {
		std::cout << "Size test 2 failed!" << std::endl;
	}

	int good_count = 0;
	for(int index=0;index<=(test.size() / 2) - 1;index++) {
		int child1 = index * 2 + 1;
		int child2 = index * 2 + 2;
		if (test.heap[index]->get_value() <= test.heap[child1]->get_value() and test.heap[index]->get_value() <= test.heap[child2]->get_value()) 			{
			good_count++;
		}
		else {continue;}
	}
	
	if (good_count == (test.size() / 2) - 1) {
		std::cout << "Add tree test 2 passed!" << std::endl;
	}
	else {
		std::cout << "Add tree test 2 failed!" << std::endl;
	}

	//test.pop_tree(

	return 0;
	
	/*
	
	//Test 2
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

	*/

}
