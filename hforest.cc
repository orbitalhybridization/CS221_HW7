#include <iostream>
#include "hforest.hh"
#include <vector>
#include <algorithm>

HForest::HForest()
{}

HForest::~HForest() {}

int HForest::size() {return this->heap.size();}

void HForest::add_tree(HTree::tree_ptr_t htree) {


	if (this->size() == 0) {
		heap_t::iterator place = heap.begin();
		heap.insert(place,1,htree);
	}

	else {
		int place_index = this->size();
		int parent_index = (place_index - 1) / 2;
		HTree::tree_ptr_t parent = this->heap[parent_index];
		heap.insert(heap.end(),1,htree);

		while (parent->get_value() > htree->get_value() and parent_index >= 0) {
		
			//HTree::tree_ptr_t switch_place(new HTree(*htree));
			//HTree::tree_ptr_t switch_parent(new HTree(*parent));
			//htree.swap(switch_parent);
			//parent.swap(switch_place);
			//int switch_index_parent = parent_index;
			//int switch_index_place = place_index;
			heap.at(parent_index) = htree;
			heap.at(place_index) = parent;
			int place_index = parent_index;
			int parent_index = (place_index - 1) / 2;
			HTree::tree_ptr_t parent = this->heap[parent_index];
		
		}
		
		heap_t::iterator place_here = find(this->heap.begin(),this->heap.end(),parent);
		this->heap.insert(place_here,1,htree);
	
	}
}

HTree::tree_ptr_t HForest::pop_tree() {

	if (this->heap.size() == 1) {
		HTree::tree_ptr_t tree_root = this->heap[0];		
		this->heap.pop_back();
		return tree_root;
	}

	assert(this->heap.size() > 0);
	HTree::tree_ptr_t tree_root = this->heap[0];
	this->heap.erase(this->heap.begin()); //delete first element in heap
	HTree::tree_ptr_t last_tree = this->heap[this->heap.size()-1];
	this->heap.insert(this->heap.begin(),1,last_tree); //put last tree pointer at the beginning of heap vector
	this->heap.pop_back(); //delete last element in heap vector
	
	unsigned int place_index = 0;
	unsigned int child1_index = 1;
	unsigned int child2_index = 2;
	HTree::tree_ptr_t child1 = this->heap[child1_index];
	HTree::tree_ptr_t child2 = this->heap[child2_index];
	HTree::tree_ptr_t parent = this->heap[place_index];

	while (((parent->get_value() > child1->get_value()) or (parent->get_value() > child2->get_value())) and child2_index >= this->heap.size()) {
		
		if ((parent->get_value() > child1->get_value())) {
			HTree::tree_ptr_t switch_child(new HTree(*child1));
			HTree::tree_ptr_t switch_parent(new HTree(*parent));
			child1.swap(switch_parent);
			parent.swap(switch_child);
			unsigned int place_index = child1_index;
			unsigned int child1_index = place_index * 2 + 1;
			unsigned int child2_index = place_index * 2 + 2;
			HTree::tree_ptr_t child1 = this->heap[child1_index];
			HTree::tree_ptr_t child2 = this->heap[child2_index];
			HTree::tree_ptr_t parent = this->heap[place_index];
			continue;	
		}
		else if ((parent->get_value() > child2->get_value())) {
			HTree::tree_ptr_t switch_child(new HTree(*child2));
			HTree::tree_ptr_t switch_parent(new HTree(*parent));
			child2.swap(switch_parent);
			parent.swap(switch_child);
			int place_index = child2_index;
			int child1_index = place_index * 2 + 1;
			int child2_index = place_index * 2 + 2;
			HTree::tree_ptr_t child1 = this->heap[child1_index];
			HTree::tree_ptr_t child2 = this->heap[child2_index];
			HTree::tree_ptr_t parent = this->heap[place_index];
		}
		
	}
	
	return tree_root; //returns first element in heap (lowest value)
}
