int findDuplicate(vector<int> &arr, int n){
	/*
	1st Approach-
	->We can sort the arr and check if element and its next element are same then return the ans
	->TC - O(nlog(n)) && SC - O(1)

	2nd Approach-
	->We can use a hashmap to store the frequency of the element and then iterate over hashmap and 
		check if the element has a frequency of 2 return the ans
	->TC - O(n) && SC - O(n)

	3rd Approach-
	->We can approach the question as the to detect a cycle.
	->We can use two pointers slow(one step) and fast(two steps) and we will run the while loop until the both the pointer
		stops at the same node/element
	->It can be proved that the both pointers will collide using floyd-warshal algorithm
	->Now we can reassign the fast pointer to starting node/element and move both pointer by one step
		until both pointer collide and that will be our ans
	->Fast will move L1 + L2 + nC whereas slow will move L1 + L2
	->Now L1 + L2 + nC = 2(L1 + L2) ==> L1 = nC-L2 
	->TC - O(n) && SC - O(1) 
	*/

	int fast = arr[0], slow = arr[0];
	
	while(true){
		fast = arr[arr[fast]];
		slow = arr[slow];
		if(fast==slow){
			break;
		}
	}
	fast = arr[0];
	while(fast != slow){
		fast = arr[fast];
		slow = arr[slow];
	}
	return slow;
	
}