README

HTree and HForest

Author: Ian Jackson
Email: orbitalhybridization@gmail.com

HTree
----------
This collection of files implements a Tree-like data structure
that stores keys and values.

The header file tree.hh contains the declaration of types
and functions to be used with the struct. The underlying implementations
of these functions are written in tree.cc. All methods written run in either 
constant or linear time. Finally, the unit test file, test_tree.cc, was used 
to test the implementation of the new data structure.

Importantly, this data structure is not ordered and does not
rely on values to determine the location of the next connection.
It is simply an iterative representation of a binary tree.

To compile these scripts together: 
g++ -g -Wall -Wextra -std=c++17 tree.cc htree test_tree

To run them:
./test_tree



The 



HForest
-----------


Design Choices:
- Did not check for assertion fail cases in test files, due to this causing the program to (rightfully) crash. 
  If there is a crash due to an erroneous assertion, please contact: orbitalhybridization@gmail.com

	basura
		/*
		int place_index = this->size()-1;
		HTree::tree_ptr_t place = heap.operator[](place_index);
		int parent_index = (place_index - 1) / 2;
		HTree::tree_ptr_t parent = heap.operator[](parent_index);
		
		HTree place_tree = *place;
		HTree parent_tree = *parent;
		std::cout << place_tree.get_value() << std::endl;
		std::cout << parent_tree.get_value() << std::endl;

		while ((place_tree.get_value() < parent_tree.get_value()) and parent_index >= 0) {
			
			place_index = parent_index;
			place = heap.operator[](place_index);
			HTree place_tree = *place;
			
			parent_index = (parent_index - 1) / 2;
			parent = heap.operator[](parent_index);
			HTree parent_tree = *parent;
		}

		*/

	/*
	int place_index = 0;
	heap_t switch_tree; //create a sample vector for switching values
	switch_tree.insert(switch_tree.begin(),1,this->heap[place_index]); //place new root into sample vector
	int child1_index = 1; //set up parent and child indices
	int child2_index = 2;
	HTree::tree_ptr_t child1 = this->heap[child1_index];
	HTree::tree_ptr_t child2 = this->heap[child2_index];
	std::cout << switch_tree[0]->get_value() << std::endl;
	while ((switch_tree[0]->get_value() > child1->get_value()) or (switch_tree[0]->get_value() > child2->get_value())) {
		if (switch_tree[0]->get_value() > child1->get_value()) {
			switch_tree.push_back(this->heap[child1_index]); //place child1 in sample vector for switch
			this->heap[child1_index] = switch_tree[0]; //parent pointer goes to child
			this->heap[place_index] = switch_tree[1]; //child pointer goes to parent
			place_index = child1_index;
			child1_index = 2 * child1_index + 1;
			switch_tree.erase(switch_tree.begin(),switch_tree.end()); 
			switch_tree.insert(switch_tree.begin(),1,this->heap[place_index]); //place value to switch into sample vector
			
		}

		else if (switch_tree[0]->get_value() > child2->get_value()) {
			
			switch_tree.push_back(this->heap[child2_index]); //place child2 in sample vector for switch
			this->heap[child2_index] = switch_tree[0]; //parent pointer goes to child
			this->heap[place_index] = switch_tree[1]; //child pointer goes to parent
			place_index = child2_index;
			child2_index = 2 * child2_index + 1;
			switch_tree.erase(switch_tree.begin(),switch_tree.end()); 
			switch_tree.insert(switch_tree.begin(),1,this->heap[place_index]); //place new value to switch into sample vector
			

		}
		*/
	
