pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	/*
	1st Approach->
	->Run a loop for each number from 1 to N in which we run a inside loop for every element  
	->If its count is 2 or 0 then we get our ans
	->TC - O(N*N) SC - O(1)
	2nd Approach->
	->Declare a frequency array for each num 1 to N and check which has freq as 2 and 0
	->TC - O(N) SC - O(N)
	3rd Approach->
	->We xor all elements of the array and store it.
	->Now find the first right bit which is set as now this separate the duplicate and missing number
	->Now Xor 1 to N on basic of set and notset bit and again do the same for the array element
	->Now we has two variable one which is missing and other is duplicate
	*/	

	int res = 0;
	for(int i = 0; i<n; i++){
		res ^= arr[i];
		res ^= (i+1);
	}
	int num = res & ~(res-1);
	int zero = 0, one = 0;
	for(int i = 0; i<n; i++){
		if(arr[i] & num){
			one ^= arr[i];
		}
		else zero ^= arr[i];
	}
	for(int i = 1; i<=n; i++){
		if(i & num){
			one ^= i;
		}
		else zero ^= i;
	}
	bool flag = false;
	for(int i = 0; i<n; i++){
		if(arr[i] == one){
			flag = true;
			break;
		}
		else if(arr[i] == zero){
			break;
		}
	}
	if(flag) return {zero,one};
	return {one,zero};

}