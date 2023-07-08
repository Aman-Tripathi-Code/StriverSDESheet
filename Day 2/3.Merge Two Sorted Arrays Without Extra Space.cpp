#include<vector>

void swapIt(vector<long long> &a, vector<long long> &b, int ind1, int ind2){
	if(a[ind1] > b[ind2]){
		swap(a[ind1],b[ind2]);
	}
}

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	/*
	Sorting Approach-
	->We can place a pointer at end of first array and starting of second array and check if the element
		of first array is greater than second array element.If it is then we will swap both the element
		else we will break out of the loop.
	->TC-O((n+m)log(m+n)) SC-O(1)

	Gap Method-
	->We can set a gap of ceil(m+n/2) and at gap we will sort the element
	->We will decrease the size of gap by ceil(gap/2) in each step.Intuition is shell sort which uses
		the fact that element are sorted at distance of the gap and decreasing the gap size will sort
		the entire array.
	->TC- O(log(m+n)*(m+n)) SC-O(1)

	Euclidean Division Lemma-


	*/

	int n = a.size(), m = b.size();
	int len = m + n;
	int gap = (len)/2 + (len) % 2;
	while(gap > 0){
		int left = 0, right = left+gap;
		while(right < len){
			//if both pointer in first array
			if(left < n && right < n){
				swapIt(a,a,left,right);
			}
			//if both pointer in different arrays
			else if(left < n && right >= n){
				swapIt(a,b,left,right-n);
			}
			//if both pointer in second array
			else{
				swapIt(b,b,left-n,right-n);
			}
			left++;
			right++;
		}
		if(gap == 1) break;
		gap = gap/2 + gap % 2;
	}
}