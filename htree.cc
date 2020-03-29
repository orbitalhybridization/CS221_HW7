#include "htree.hh"
#include <iostream>
#include <string>
#include <assert.h>

//A function for creating new subtrees
HTree::HTree(int key,
        	uint64_t value,
            tree_ptr_t left,
            tree_ptr_t right)
	:key_(key), value_(value),left_(left),right_(right)
{}

//destroys tree and its subtrees
HTree::~HTree() {

	//HTree lefty = *(this->get_child(HTree::Direction::LEFT));
	//HTree righty = *(this->get_child(HTree::Direction::RIGHT));	
	//delete lefty;
	//delete righty;
	//delete this;

}

int HTree::get_key() const {return key_;}

uint64_t HTree::get_value() const {return value_;}

HTree::tree_ptr_t HTree::get_child(Direction dir) const {

	if (dir == HTree::Direction{0}) {
		return this->left_;
	}
	
	else if (dir == HTree::Direction{1}) {
		return this->right_;
	}
	
	else {
		return nullptr;
	}
}

bool has_key(HTree::tree_ptr_t tree,int key)
{


	HTree current_tree = *tree;

	HTree::tree_ptr_t lefty = current_tree.get_child(HTree::Direction::LEFT);
	HTree::tree_ptr_t righty = current_tree.get_child(HTree::Direction::RIGHT);

	if (current_tree.get_key() == key) {
		return true;
	}
	
	else if (lefty != nullptr and has_key(lefty,key)) {
		return true;
	}

	else if (righty != nullptr and has_key(righty,key)) {
		return true;
	}
	
	else {
		return false;
	}

}

HTree::path_t HTree::path_to(int key) const {

	HTree::path_t path = {};

	HTree current = *this;

	HTree::tree_ptr_t lefty = current.get_child(HTree::Direction::LEFT);
	HTree::tree_ptr_t righty = current.get_child(HTree::Direction::RIGHT);

	if ((righty == nullptr) and (lefty == nullptr)) {
		assert(current.get_key() == key);
	}
	
	else if (lefty == nullptr) {
		assert(has_key(righty,key) or current.get_key() == key);
	}

	else if (righty == nullptr) {
		assert(has_key(lefty,key) or current.get_key() == key);
	}
	
	assert (this != nullptr);
	
	while (current.get_child(HTree::Direction::LEFT) or current.get_child(HTree::Direction::RIGHT)) {
	
		if (current.get_key() == key) {
			break;
		}
		

		else if (has_key(lefty,key)) {
			path.insert(path.end(),HTree::Direction{0});
			current = *(current.get_child(HTree::Direction::LEFT));
		}


		else if (has_key(righty,key)) {
			path.insert(path.end(),HTree::Direction{1});
			current = *(current.get_child(HTree::Direction::RIGHT));
		}
		
	}
		
	return path;

}

std::string get_direction(HTree::Direction entry) {
		
	std::string left = "LEFT";
	std::string right = "RIGHT";

	if (entry == HTree::Direction{0}) {
		return left;
	}

	else if (entry == HTree::Direction{1}) {
		return right;
	}

	else {
		return "";
	}
}


