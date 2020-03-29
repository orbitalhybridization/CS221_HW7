/*
 * HForest: a class to represent a collection of independent HTrees (see HTree.hh), each with two values: a key
 * and a value. Each HTree in the collection is the root of its own tree.
 */

//#pragma once

#include <iostream>
#include "htree.cc"
#include <vector>

class HForest {

	public:
  		
		using heap_t = std::vector<HTree::tree_ptr_t>;
		
		heap_t heap;

		HForest();
  
		~HForest();
		
		int size();

		void add_tree(HTree::tree_ptr_t htree);

		HTree::tree_ptr_t pop_tree();

};
